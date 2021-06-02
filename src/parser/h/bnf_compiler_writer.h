//
// Created by Anton on 2021-06-01.
//

#ifndef USIDE_SRC_PARSER_H_BNF_COMPILER_WRITER_H
#define USIDE_SRC_PARSER_H_BNF_COMPILER_WRITER_H

#include <string>
#include <regex>
#include <unordered_map>
#include <unordered_set>

namespace parser {
    enum class TemplateCommand {
        ABSYN_NAME_UPPER,
        CAT_NAME_UPPER,
        INCLUDES,
        ABSYN_NAME,
        CAT_NAME,
        CAT_NAME_CAMEL,
        LABEL_CLASSES,
        VISIT_FUNCTION_DECLARATIONS,
        PROJECT_NAME_UPPER,
        LABEL_NAME,
        LABEL_NAME_CAMEL,
        LABEL_DATA_FUNCTIONS,
        LABEL_DATA_VARS,
        LABEL_DATA_TYPE,
        LABEL_DATA_VAR_NUM,
        LABEL_FUNC_RETURN_CHAR,
        DATE,
        LABEL_VAR_LIST_INIT,
        LABEL_VAR_LIST_DELETE,
        CPP_INCLUDE,
        CPP_ACCEPT_FUNCS,
        DONE,
    };
    TemplateCommand getCommand(const std::string& name);

    class BnfCompilerWriter {
    public:
        BnfCompilerWriter(std::string projectName, std::string absynName, std::string absynDirPath, std::string templatesDirPath,
                          const std::unordered_map<std::string, std::unordered_set<std::string>>& catLabelMap,
                          const std::unordered_map<std::string, std::vector<std::string>>& labelVarMap);

    public:
        void writeAbsyn();

    private:
        TemplateCommand bufferTillNextCommand(std::pair<const std::string&, std::size_t>& src);

        void handleAbsynNameUpper();
        void handleCatNameUpper();
        void handleIncludes();
        void handleAbsynName();
        void handleCatName();
        void handleCatNameCamel();
        void handleLabelClasses();
        void handleVisitFunctionDeclarations();
        void handleProjectNameUpper();
        void handleLabelName();
        void handleLabelNameCamel();
        void handleLabelDataFunctions();
        void handleLabelDataVars();
        void handleLabelDataType();
        void handleLabelDataVarNum();
        void handleLabelFuncReturnChar();
        void handleDate();
        void handleLabelVarListInit();
        void handleLabelVarListDelete();
        void handleCppInclude();
        void handleCppAcceptFuncs();
        void handleCommand(TemplateCommand cmd);

    private:
        static int stringToInt(const std::string& str);
        static std::string toUpper(const std::string& str);
        static std::string toLower(const std::string& str);
        static std::string pascalToCamel(const std::string& str);
        static std::string toSnakeCase(const std::string& str);

    private:
        std::stringstream mBuffer;

        std::string mProjectName;
        std::string mAbsynName;

        std::string mAbsynDirPath;
        std::string mTemplatesDirPath;
        std::string mTemplateMappingsPath;
        std::string mTemplateClassHeaderPath;
        std::string mTemplateLabelClassPath;
        std::string mTemplateLabelClassFuncPath;
        std::string mTemplateLabelClassVarPath;
        std::string mTemplateClassVisitFuncPath;
        std::string mTemplateClassCppPath;
        std::string mTemplateClassCppAcceptFuncPath;

        std::regex mDigitRegex;

        std::unordered_map<int, TemplateCommand> mIdToCommandMap;

        const std::unordered_map<std::string, std::unordered_set<std::string>>& mCatLabelMap;
        const std::unordered_map<std::string, std::vector<std::string>>& mLabelVarMap;

        const std::string* mCurrentCat;
        const std::string* mCurrentLabel;
        std::size_t mCurrentVar;
    };
}
#endif //USIDE_SRC_PARSER_H_BNF_COMPILER_WRITER_H
