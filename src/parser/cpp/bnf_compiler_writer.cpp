//
// Created by Anton on 2021-06-01.
//

#include "../h/bnf_compiler_writer.h"

#include <charconv>
#include <regex>

#include <assertion/include/assertion_include.h>
#include <file/include/file_include.h>
#include <globals/debug_code_maco.h>

parser::BnfCompilerWriter::BnfCompilerWriter(std::string projectName, std::string absynName, std::string absynDirPath, std::string templatesDirPath,
                                             const std::unordered_map<std::string, std::unordered_set<std::string>>& catLabelMap,
                                             const std::unordered_map<std::string, std::vector<std::string>>& labelVarMap)
    :   mBuffer(),
        mProjectName (std::move(projectName)),
        mAbsynName(std::move(absynName)),
        mAbsynDirPath(std::move(absynDirPath)),
        mTemplatesDirPath(std::move(templatesDirPath)),
        mTemplateMappingsPath(mTemplatesDirPath + "absyn_class_template_mappings.txt"),
        mTemplateClassHeaderPath(mTemplatesDirPath + "absyn_class_template.txt"),
        mTemplateLabelClassPath(mTemplatesDirPath + "absyn_label_class_template.txt"),
        mTemplateLabelClassFuncPath(mTemplatesDirPath + "absyn_label_class_data_func_template.txt"),
        mTemplateLabelClassVarPath(mTemplatesDirPath + "absyn_label_class_data_var_template.txt"),
        mTemplateClassVisitFuncPath(mTemplatesDirPath + "absyn_class_visit_func_template.txt"),
        mTemplateClassCppPath(mTemplatesDirPath + "absyn_class_cpp_template.txt"),
        mTemplateClassCppAcceptFuncPath(mTemplatesDirPath + "absyn_class_cpp_accept_func_template.txt"),
        mDigitRegex("\\d", std::regex_constants::optimize | std::regex_constants::ECMAScript),
        mCatLabelMap(catLabelMap),
        mLabelVarMap(labelVarMap),
        mCurrentCat(nullptr),
        mCurrentLabel(nullptr),
        mCurrentVar(-1) {
    std::stringstream templateMappings;
    templateMappings << file::FileLoader::readText(mTemplateMappingsPath.c_str());
    std::string line;
    while (std::getline(templateMappings, line)) {
        std::stringstream lineStream;
        lineStream << line;
        std::string id;
        std::string name;
        if (!(lineStream >> id >> name)) {
            ASSERT_MSG(false, "Absyn template mappings is formatted wrong.");
        }
        mIdToCommandMap[stringToInt(id)] = getCommand(name);
    }
}

void parser::BnfCompilerWriter::writeAbsyn() {
    LOG_TRC() << "Writing abstract syntax tree files." << LOG_END;
    //
    std::string headerTemplate = file::FileLoader::readText(mTemplateClassHeaderPath.c_str());
    std::string cppTemplate = file::FileLoader::readText(mTemplateClassCppPath.c_str());

    for (auto& cat: mCatLabelMap) {
        mCurrentCat = &cat.first;

        auto headerSource = std::pair<const std::string&, std::size_t>(headerTemplate, 0);
        while (headerSource.second < headerSource.first.size()) {
            auto cmd = bufferTillNextCommand(headerSource);
            handleCommand(cmd);
        }
        std::string headerPath = mAbsynDirPath + toSnakeCase(cat.first) + ".h";
        file::FileLoader::writeText(headerPath.c_str(), mBuffer.str().c_str(), file::TRUNCATE);
        LOG_TRC() << "Wrote abstract syntax tree file \"" << headerPath << "\"." << LOG_END;
        mBuffer.str(std::string()); // Clear the buffer for next file

        auto cppSource = std::pair<const std::string&, std::size_t>(cppTemplate, 0);
        while (cppSource.second < cppSource.first.size()) {
            auto cmd = bufferTillNextCommand(cppSource);
            handleCommand(cmd);
        }
        std::string cppPath = mAbsynDirPath + toSnakeCase(cat.first) + ".cpp";
        file::FileLoader::writeText(cppPath.c_str(), mBuffer.str().c_str(), file::TRUNCATE);
        LOG_TRC() << "Wrote abstract syntax tree file \"" << cppPath << "\"." << LOG_END;
        mBuffer.str(std::string()); // Clear the buffer for next file
    }
    mCurrentCat = nullptr;

    LOG_TRC() << "Writing complete." << LOG_END;
}

parser::TemplateCommand parser::BnfCompilerWriter::bufferTillNextCommand(std::pair<const std::string&, std::size_t>& src) {
    for (auto i = src.second; i < src.first.size(); i++) {
        if (src.first[i] == '$') {
            // Convert digits following '$' into an int to find the corresponding templateCommand
            i++;
            DEBUG_CODE(int startIndex = i; )
            std::stringstream digits;
            while (std::regex_match(std::string(1, src.first[i]), mDigitRegex)) {
                digits << src.first[i];
                i++;
            }
            DEBUG_CODE(ASSERT(i > startIndex); )
            int mappingRule = stringToInt(digits.str());
            src.second = i;
            return mIdToCommandMap.at(mappingRule);
        } else {
            mBuffer << src.first[i];
        }
    }

    src.second = src.first.size();
    return TemplateCommand::DONE;
}

void parser::BnfCompilerWriter::handleAbsynNameUpper() {
    mBuffer << toUpper(mAbsynName);
}

void parser::BnfCompilerWriter::handleCatNameUpper() {
    ASSERT(mCurrentCat != nullptr);
    mBuffer << toUpper(*mCurrentCat);
}

void parser::BnfCompilerWriter::handleIncludes() {
    // Calculate the includes needed
    std::unordered_set<std::string> includes;
    for (auto& labelName: mCatLabelMap.at(*mCurrentCat)) {
        for (auto& varName: mLabelVarMap.at(labelName)) {
            static_cast<void>(includes.insert(varName));
        }
    }
    for (auto& include: includes) {
        mBuffer << "#include \"" << include << ".h\"\n";
    }
}

void parser::BnfCompilerWriter::handleAbsynName() {
    mBuffer << mAbsynName;
}

void parser::BnfCompilerWriter::handleCatName() {
    ASSERT(mCurrentCat != nullptr);
    mBuffer << *mCurrentCat;
}

void parser::BnfCompilerWriter::handleCatNameCamel() {
    ASSERT(mCurrentCat != nullptr);
    mBuffer << pascalToCamel(*mCurrentCat);
}

void parser::BnfCompilerWriter::handleLabelClasses() {
    ASSERT(mCurrentCat != nullptr);
    auto labelClassTemplate = file::FileLoader::readText(mTemplateLabelClassPath.c_str());

    for (auto& label: mCatLabelMap.at(*mCurrentCat)) {
        mCurrentLabel = &label;

        auto labelClassSource = std::pair<const std::string&, std::size_t>(labelClassTemplate, 0);
        while (labelClassSource.second < labelClassSource.first.size()) {
            auto cmd = bufferTillNextCommand(labelClassSource);
            handleCommand(cmd);
        }
    }
    mCurrentLabel = nullptr;
}

void parser::BnfCompilerWriter::handleVisitFunctionDeclarations() {
    ASSERT(mCurrentCat != nullptr);
    auto visitFuncTemplate = file::FileLoader::readText(mTemplateClassVisitFuncPath.c_str());

    for (auto& label: mCatLabelMap.at(*mCurrentCat)) {
        mCurrentLabel = &label;

        auto visitFuncSource = std::pair<const std::string&, std::size_t>(visitFuncTemplate, 0);
        while (visitFuncSource.second < visitFuncSource.first.size()) {
            auto cmd = bufferTillNextCommand(visitFuncSource);
            handleCommand(cmd);
        }
    }
    mCurrentLabel = nullptr;
}

void parser::BnfCompilerWriter::handleProjectNameUpper() {
    mBuffer << toUpper(mProjectName);
}

void parser::BnfCompilerWriter::handleLabelName() {
    ASSERT(mCurrentCat != nullptr);
    ASSERT(mCurrentLabel != nullptr);
    mBuffer << *mCurrentLabel;
}

void parser::BnfCompilerWriter::handleLabelNameCamel() {
    ASSERT(mCurrentCat != nullptr);
    ASSERT(mCurrentLabel != nullptr);
    mBuffer << pascalToCamel(*mCurrentLabel);
}

void parser::BnfCompilerWriter::handleLabelDataFunctions() {
    ASSERT(mCurrentCat != nullptr);
    ASSERT(mCurrentLabel != nullptr);
    auto labelClassFuncTemplate = file::FileLoader::readText(mTemplateLabelClassFuncPath.c_str());

    auto& vars = mLabelVarMap.at(*mCurrentLabel);
    for (std::size_t i = 0; i < vars.size(); i++) {
        mCurrentVar = i;

        auto labelClassFuncSource = std::pair<const std::string&, std::size_t>(labelClassFuncTemplate, 0);
        while (labelClassFuncSource.second < labelClassFuncSource.first.size()) {
            auto cmd = bufferTillNextCommand(labelClassFuncSource);
            handleCommand(cmd);
        }
    }
    mCurrentVar = -1;
}

void parser::BnfCompilerWriter::handleLabelDataVars() {
    ASSERT(mCurrentCat != nullptr);
    ASSERT(mCurrentLabel != nullptr);
    auto labelClassVarTemplate = file::FileLoader::readText(mTemplateLabelClassVarPath.c_str());

    auto& vars = mLabelVarMap.at(*mCurrentLabel);
    for (std::size_t i = 0; i < vars.size(); i++) {
        mCurrentVar = i;

        auto labelClassVarSource = std::pair<const std::string&, std::size_t>(labelClassVarTemplate, 0);
        while (labelClassVarSource.second < labelClassVarSource.first.size()) {
            auto cmd = bufferTillNextCommand(labelClassVarSource);
            handleCommand(cmd);
        }
    }
    mCurrentVar = -1;
}

void parser::BnfCompilerWriter::handleLabelDataType() {
    ASSERT(mCurrentCat != nullptr);
    ASSERT(mCurrentLabel != nullptr);
    ASSERT(mCurrentVar < mLabelVarMap.at(*mCurrentLabel).size());
    mBuffer << mLabelVarMap.at(*mCurrentLabel).at(mCurrentVar);
}

void parser::BnfCompilerWriter::handleLabelDataVarNum() {
    ASSERT(mCurrentCat != nullptr);
    ASSERT(mCurrentLabel != nullptr);
    ASSERT(mCurrentVar < mLabelVarMap.at(*mCurrentLabel).size());
    mBuffer << (mCurrentVar + 1);
}

void parser::BnfCompilerWriter::handleLabelFuncReturnChar() {
    ASSERT(mCurrentCat != nullptr);
    ASSERT(mCurrentLabel != nullptr);
    ASSERT(mCurrentVar < mLabelVarMap.at(*mCurrentLabel).size());
    auto& type = mLabelVarMap.at(*mCurrentLabel).at(mCurrentVar);
    if (std::isupper(type[0]) != 0) {
        mBuffer << "&";
    }
}

void parser::BnfCompilerWriter::handleDate() {
    mBuffer << "DATE NOT IMPLEMENTED";
}

void parser::BnfCompilerWriter::handleLabelVarListInit() {
    ASSERT(mCurrentCat != nullptr);
    ASSERT(mCurrentLabel != nullptr);
    auto& vars = mLabelVarMap.at(*mCurrentLabel);
    for (std::size_t i = 0; i < vars.size(); i++) {
        mBuffer << "mV" << i << "{";
        auto& type = vars[i];
        if (std::isupper(type[0]) != 0) {
            mBuffer << "nullptr";
        } else if (type == "char*") {
            mBuffer << "nullptr";
        } else {
            mBuffer << "0";
        }
        mBuffer << "},";
    }
}

void parser::BnfCompilerWriter::handleLabelVarListDelete() {
    ASSERT(mCurrentCat != nullptr);
    ASSERT(mCurrentLabel != nullptr);
    auto& vars = mLabelVarMap.at(*mCurrentLabel);
    for (std::size_t i = 0; i < vars.size(); i++) {
        auto& type = vars[i];
        if (std::isupper(type[0]) != 0) {
            mBuffer << "delete mV" << i << "; ";
        } else if (type == "char*") {
            mBuffer << "delete[] mV" << i << "; ";
        } else {
            // Do not output anything if var is not a pointer.
        }
    }
}

void parser::BnfCompilerWriter::handleCppInclude() {
    ASSERT(mCurrentCat != nullptr);
    mBuffer << "#include \"" << toSnakeCase(*mCurrentCat) << ".h\"";
}

void parser::BnfCompilerWriter::handleCppAcceptFuncs() {
    ASSERT(mCurrentCat != nullptr);
    auto cppAcceptFuncTemplate = file::FileLoader::readText(mTemplateClassCppAcceptFuncPath.c_str());

    for (auto& label: mCatLabelMap.at(*mCurrentCat)) {
        mCurrentLabel = &label;

        auto cppAcceptFuncSource = std::pair<const std::string&, std::size_t>(cppAcceptFuncTemplate, 0);
        while (cppAcceptFuncSource.second < cppAcceptFuncSource.first.size()) {
            auto cmd = bufferTillNextCommand(cppAcceptFuncSource);
            handleCommand(cmd);
        }
    }
    mCurrentLabel = nullptr;
}

void parser::BnfCompilerWriter::handleCommand(parser::TemplateCommand cmd) {
    switch (cmd) {
        case TemplateCommand::ABSYN_NAME_UPPER:
            handleAbsynNameUpper();
            break;
        case TemplateCommand::CAT_NAME_UPPER:
            handleCatNameUpper();
            break;
        case TemplateCommand::INCLUDES:
            handleIncludes();
            break;
        case TemplateCommand::ABSYN_NAME:
            handleAbsynName();
            break;
        case TemplateCommand::CAT_NAME:
            handleCatName();
            break;
        case TemplateCommand::CAT_NAME_CAMEL:
            handleCatNameCamel();
            break;
        case TemplateCommand::LABEL_CLASSES:
            handleLabelClasses();
            break;
        case TemplateCommand::VISIT_FUNCTION_DECLARATIONS:
            handleVisitFunctionDeclarations();
            break;
        case TemplateCommand::PROJECT_NAME_UPPER:
            handleProjectNameUpper();
            break;
        case TemplateCommand::LABEL_NAME:
            handleLabelName();
            break;
        case TemplateCommand::LABEL_NAME_CAMEL:
            handleLabelNameCamel();
            break;
        case TemplateCommand::LABEL_DATA_FUNCTIONS:
            handleLabelDataFunctions();
            break;
        case TemplateCommand::LABEL_DATA_VARS:
            handleLabelDataVars();
            break;
        case TemplateCommand::LABEL_DATA_TYPE:
            handleLabelDataType();
            break;
        case TemplateCommand::LABEL_DATA_VAR_NUM:
            handleLabelDataVarNum();
            break;
        case TemplateCommand::LABEL_FUNC_RETURN_CHAR:
            handleLabelFuncReturnChar();
            break;
        case TemplateCommand::DATE:
            handleDate();
            break;
        case TemplateCommand::LABEL_VAR_LIST_INIT:
            handleLabelVarListInit();
            break;
        case TemplateCommand::LABEL_VAR_LIST_DELETE:
            handleLabelVarListDelete();
            break;
        case TemplateCommand::CPP_INCLUDE:
            handleCppInclude();
            break;
        case TemplateCommand::CPP_ACCEPT_FUNCS:
            handleCppAcceptFuncs();
            break;
        case TemplateCommand::DONE:
            // Nothing needs to be done
            break;
    }
}

int parser::BnfCompilerWriter::stringToInt(const std::string& str) {
    int parsed = 0;
    auto result = std::from_chars(&str[0], &str[str.size()], parsed);
    ASSERT(!static_cast<bool>(result.ec) && result.ptr == &str[str.size()]); // TODO: Better error handling?
    return parsed;
}

std::string parser::BnfCompilerWriter::toUpper(const std::string& str) {
    std::ostringstream builder;
    for (unsigned char c: str) {
        builder << static_cast<char>(std::toupper(c));
    }
    return builder.str();
}

std::string parser::BnfCompilerWriter::toLower(const std::string& str) {
    std::ostringstream builder;
    for (unsigned char c: str) {
        builder << static_cast<char>(std::tolower(c));
    }
    return builder.str();
}

std::string parser::BnfCompilerWriter::pascalToCamel(const std::string& str) {
    std::ostringstream builder;
    builder << static_cast<char>(std::tolower(str[0]));
    for (int i = 1; i < str.size(); i++) {
        builder << str[i];
    }
    return builder.str();
}

std::string parser::BnfCompilerWriter::toSnakeCase(const std::string& str) {
    std::ostringstream builder;
    builder << static_cast<char>(std::tolower(str[0]));
    for (int i = 1; i < str.size(); i++) {
        if (std::islower(str[i]) == 0) {
            builder << "_" << static_cast<char>(std::tolower(str[i]));
        } else {
            builder << str[i];
        }
    }
    return builder.str();
}

parser::TemplateCommand parser::getCommand(const std::string& name) {
    if (name == "ABSYN_NAME_UPPER") {
        return parser::TemplateCommand::ABSYN_NAME_UPPER;
    } else if (name == "CAT_NAME_UPPER") {
        return parser::TemplateCommand::CAT_NAME_UPPER;
    } else if (name == "INCLUDES") {
        return parser::TemplateCommand::INCLUDES;
    } else if (name == "ABSYN_NAME") {
        return parser::TemplateCommand::ABSYN_NAME;
    } else if (name == "CAT_NAME") {
        return parser::TemplateCommand::CAT_NAME;
    } else if (name == "CAT_NAME_CAMEL") {
        return parser::TemplateCommand::CAT_NAME_CAMEL;
    } else if (name == "LABEL_CLASSES") {
        return parser::TemplateCommand::LABEL_CLASSES;
    } else if (name == "VISIT_FUNCTION_DECLARATIONS") {
        return parser::TemplateCommand::VISIT_FUNCTION_DECLARATIONS;
    } else if (name == "PROJECT_NAME_UPPER") {
        return parser::TemplateCommand::PROJECT_NAME_UPPER;
    } else if (name == "LABEL_NAME") {
        return parser::TemplateCommand::LABEL_NAME;
    } else if (name == "LABEL_NAME_CAMEL") {
        return parser::TemplateCommand::LABEL_NAME_CAMEL;
    } else if (name == "LABEL_DATA_FUNCTIONS") {
        return parser::TemplateCommand::LABEL_DATA_FUNCTIONS;
    } else if (name == "LABEL_DATA_VARS") {
        return parser::TemplateCommand::LABEL_DATA_VARS;
    } else if (name == "LABEL_DATA_TYPE") {
        return parser::TemplateCommand::LABEL_DATA_TYPE;
    } else if (name == "LABEL_DATA_VAR_NUM") {
        return parser::TemplateCommand::LABEL_DATA_VAR_NUM;
    } else if (name == "LABEL_FUNC_RETURN_CHAR") {
        return parser::TemplateCommand::LABEL_FUNC_RETURN_CHAR;
    } else if (name == "DATE") {
        return parser::TemplateCommand::DATE;
    } else if (name == "LABEL_VAR_LIST_INIT") {
        return parser::TemplateCommand::LABEL_VAR_LIST_INIT;
    } else if (name == "LABEL_VAR_LIST_DELETE") {
        return parser::TemplateCommand::LABEL_VAR_LIST_DELETE;
    } else if (name == "CPP_INCLUDE") {
        return parser::TemplateCommand::CPP_INCLUDE;
    } else if (name == "CPP_ACCEPT_FUNCS") {
        return parser::TemplateCommand::CPP_ACCEPT_FUNCS;
    } else if (name == "DONE") {
        return parser::TemplateCommand::DONE;
    } else {
        ASSERT(false); // TODO: Better error handling
        return parser::TemplateCommand::DATE;
    }
}
