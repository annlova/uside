//
// Created by anton on 2021-05-30.
//

#include "../h/bnf_interpreter.h"

#include <charconv>

#include "../h/bnf_compiler_writer.h"

int parser::BnfInterpreter::interpret(const absyn::bnf::Grammar& grammar) {

    mTerminals.insert();

    GrammarVisitor visitor(*this);
    grammar.accept(visitor);
    LOG_TRC() << "Attempting to write absyn files..." << LOG_END;
    writeAbsyn("test");
    return 0;
}

void parser::BnfInterpreter::writeAbsyn(const std::string& absynName) {
    // TODO: Move to more logical place
    std::string absynDirPath                = "res/parser/out/absyn/" + absynName + "/";
    std::string templatesDirPath            = "res/parser/templates/";

    BnfCompilerWriter writer(mscProjectName, absynName, absynDirPath, templatesDirPath, mCatLabelMap, mLabelVarMap);
    writer.writeAbsyn();
}

void parser::BnfInterpreter::GrammarVisitor::visit(const absyn::bnf::GrammarListDef& token) {
	LOG_TRC() << "Visiting GrammarListDef" << LOG_END;
	ListDefVisitor visitor(mEnv);
	token.v1().accept(visitor);
}

void parser::BnfInterpreter::ListDefVisitor::visit(const absyn::bnf::ListDefEpsilon& token) {
	LOG_TRC() << "Visiting ListDefEpsilon" << LOG_END;
}

void parser::BnfInterpreter::ListDefVisitor::visit(const absyn::bnf::ListDefList& token) {
	LOG_TRC() << "Visiting ListDefList" << LOG_END;
	DefVisitor visitor1(mEnv);
	token.v1().accept(visitor1);
    ListDefVisitor visitor2(mEnv);
	token.v2().accept(visitor2);
}

void parser::BnfInterpreter::ListItemVisitor::visit(const absyn::bnf::ListItemEpsilon& token) {
	LOG_TRC() << "Visiting ListItemEpsilon" << LOG_END;
	mEnv.mReturnStack->push("$Epsilon");
}

void parser::BnfInterpreter::ListItemVisitor::visit(const absyn::bnf::ListItemItemList& token) {
	LOG_TRC() << "Visiting ListItemItemList" << LOG_END;
	ItemVisitor visitor1(mEnv);
	token.v1().accept(visitor1);
    ListItemVisitor visitor2(mEnv);
    token.v2().accept(visitor2);
}

void parser::BnfInterpreter::DefVisitor::visit(const absyn::bnf::DefLabel& token) {
	LOG_TRC() << "Visiting DefLabel" << LOG_END;
    ASSERT(mEnv.mLabelReturnStack.empty());
    ASSERT(mEnv.mCatReturnStack.empty());
    ASSERT(mEnv.mItemReturnStack.empty());

	mEnv.mReturnStack = &mEnv.mLabelReturnStack;
	LabelVisitor visitor1(mEnv);
	token.v1().accept(visitor1);
	mEnv.mReturnStack = &mEnv.mCatReturnStack;
    CatVisitor visitor2(mEnv);
	token.v2().accept(visitor2);
	mEnv.mReturnStack = &mEnv.mItemReturnStack;
    ListItemVisitor visitor3(mEnv);
    token.v3().accept(visitor3); // TODO

    // Gp through cat stack
    const char* catName = nullptr;
    while (!mEnv.mCatReturnStack.empty()) {
        auto* str = mEnv.mCatReturnStack.top();
        mEnv.mCatReturnStack.pop();
        // Check if stack contains command
        if (str[0] == '$') { // NOLINT(cppcoreguidelines-pro-bounds-pointer-arithmetic)
            handleCatStackCommand(str);
        } else {
            catName = str;
        }
    }
    ASSERT(catName != nullptr);

    // Go through label stack
    const char* labelName = nullptr;
    while (!mEnv.mLabelReturnStack.empty()) {
        auto* str = mEnv.mLabelReturnStack.top();
        mEnv.mLabelReturnStack.pop();
        // Check if stack contains command
        if (str[0] == '$') { // NOLINT(cppcoreguidelines-pro-bounds-pointer-arithmetic)
            handleLabelStackCommand(str); // TODO
        } else {
            labelName = str;
        }
    }
    ASSERT(labelName != nullptr);

    // Insert label into mCatLabelMap
    {
        auto& map = mEnv.mCatLabelMap;
        (void) map.emplace(catName, std::unordered_set<std::string>()).first->second.insert(labelName);
    }

    // Go through item stack
    {
        auto& map = mEnv.mLabelVarMap;
        auto inserted = map.emplace(labelName, std::vector<std::string>());
        ASSERT_MSG(inserted.second, "Duplicate labels.");
        while (!mEnv.mItemReturnStack.empty()) {
            auto* str = mEnv.mItemReturnStack.top();
            mEnv.mItemReturnStack.pop();
            if (str[0] == '$') { // NOLINT(cppcoreguidelines-pro-bounds-pointer-arithmetic)
                handleItemStackCommand(str, inserted.first->second);
            } else {
                ASSERT(false);
            }
        }
    }
}

void parser::BnfInterpreter::DefVisitor::handleCatStackCommand(const std::string& cmd) {
    if (cmd == "$List") {
        ASSERT_MSG(false, "Not implemented."); // TODO
    }
}

void parser::BnfInterpreter::DefVisitor::handleLabelStackCommand(const std::string& cmd) {
    ASSERT_MSG(false, "Not implemented.");
}

void parser::BnfInterpreter::DefVisitor::handleItemStackCommand(const std::string& cmd, std::vector<std::string>& vec) {
    if (cmd == "$List") {
        ASSERT(false);
    } else if (cmd == "$Epsilon") {
        LOG_ERR() << "epsilon" << LOG_END;
    } else if (cmd == "$Term") {
        // Calculate regex
        // TODO
        mEnv.mItemReturnStack.pop();
    } else if (cmd == "$NonTerm") {
        // Insert item into mLabelVarMap
        (void) vec.emplace_back(mEnv.mItemReturnStack.top());
        mEnv.mItemReturnStack.pop();
    } else {
        ASSERT_MSG(false, "Unhandled item stack command.");
    }
}

void parser::BnfInterpreter::DefVisitor::visit(const absyn::bnf::DefLineComment& token) {
    LOG_TRC() << "Visiting DefLineComment" << LOG_END;
    LOG() << token.v1() << LOG_END;
    LOG_ERR() << "NOT IMPLEMENTED YET!" << LOG_END; // TODO
}

void parser::BnfInterpreter::DefVisitor::visit(const absyn::bnf::DefBlockComment& token) {
    LOG_TRC() << "Visiting DefBlockComment" << LOG_END;
    LOG() << token.v1() << LOG_END;
    LOG() << token.v2() << LOG_END;
    LOG_ERR() << "NOT IMPLEMENTED YET!" << LOG_END; // TODO
}

void parser::BnfInterpreter::DefVisitor::visit(const absyn::bnf::DefInternal& token) {
	LOG_TRC() << "Visiting DefInternal" << LOG_END;
	LabelVisitor visitor1(mEnv);
	token.v1().accept(visitor1);
    CatVisitor visitor2(mEnv);
    token.v2().accept(visitor2);
    ListItemVisitor visitor3(mEnv);
    token.v3().accept(visitor3);
}

void parser::BnfInterpreter::DefVisitor::visit(const absyn::bnf::DefToken& token) {
	LOG_TRC() << "Visiting DefToken" << LOG_END;
	LOG() << token.v1() << LOG_END;

	// A new token is being declared
    ASSERT(mEnv.mCurrentTerminalData == nullptr);
    BnfCompilerTerminalData data{token.v1()};
    mEnv.mCurrentTerminalData = &data;

    // Construct the regex
	RegVisitor visitor2(mEnv);
	token.v2().accept(visitor2);

    auto inserted = mEnv.mTerminals.insert(std::move(data));
    if (inserted.second) {
        LOG() << "DefToken complete - regex: " << inserted.first->mCompleteRegex << LOG_END;
    } else {
        LOG_ERR() << "Duplicate token \"" << token.v1() << "\"declared!" << LOG_END;
        ASSERT(false); // TODO: Better error handling
    }
    mEnv.mCurrentTerminalData = nullptr;
}

void parser::BnfInterpreter::DefVisitor::visit(const absyn::bnf::DefPositionToken& token) {
	LOG_TRC() << "Visiting DefPositionToken" << LOG_END;
    LOG() << token.v1() << LOG_END;
    RegVisitor visitor2(mEnv);
    token.v2().accept(visitor2);
}

void parser::BnfInterpreter::DefVisitor::visit(const absyn::bnf::DefEntryPoints& token) {
	LOG_TRC() << "Visiting DefEntryPoints" << LOG_END;
	ListIdentVisitor visitor(mEnv);
	token.v1().accept(visitor);
}

void parser::BnfInterpreter::DefVisitor::visit(const absyn::bnf::DefSeparator& token) {
	LOG_TRC() << "Visiting DefSeparator" << LOG_END;
	LOG() << token.v3() << LOG_END;
	MinimumSizeVisitor visitor1(mEnv);
	token.v1().accept(visitor1);
    CatVisitor visitor2(mEnv);
    token.v2().accept(visitor2);
}

void parser::BnfInterpreter::DefVisitor::visit(const absyn::bnf::DefTerminator& token) {
	LOG_TRC() << "Visiting DefTerminator" << LOG_END;
    LOG() << token.v3() << LOG_END;
    MinimumSizeVisitor visitor1(mEnv);
    token.v1().accept(visitor1);
    CatVisitor visitor2(mEnv);
    token.v2().accept(visitor2);
}

void parser::BnfInterpreter::DefVisitor::visit(const absyn::bnf::DefCoercions& token) {
	LOG_TRC() << "Visiting DefCoercions" << LOG_END;
    LOG() << token.v1() << LOG_END;
	LOG() << token.v2() << LOG_END;
}

void parser::BnfInterpreter::DefVisitor::visit(const absyn::bnf::DefRules& token) {
	LOG_TRC() << "Visiting DefRules" << LOG_END;
    LOG() << token.v1() << LOG_END;
    ListRHSVisitor visitor(mEnv);
    token.v2().accept(visitor);
}

void parser::BnfInterpreter::DefVisitor::visit(const absyn::bnf::DefLayout& token) {
	LOG_TRC() << "Visiting DefLayout" << LOG_END;
	ListStringVisitor visitor(mEnv);
	token.v1().accept(visitor);
}

void parser::BnfInterpreter::DefVisitor::visit(const absyn::bnf::DefLayoutStop& token) {
	LOG_TRC() << "Visiting DefLayoutStop" << LOG_END;
	ListStringVisitor visitor(mEnv);
	token.v1().accept(visitor);
}

void parser::BnfInterpreter::DefVisitor::visit(const absyn::bnf::DefLayoutTopLevel& token) {
	LOG_TRC() << "Visiting DefLayoutTopLevel" << LOG_END;
}

void parser::BnfInterpreter::ItemVisitor::visit(const absyn::bnf::ItemString& token) {
	LOG_TRC() << "Visiting ItemString" << LOG_END;
	LOG() << token.v1() << LOG_END;
	mEnv.mReturnStack->push(token.v1());
	mEnv.mReturnStack->push("$Term");
}

void parser::BnfInterpreter::ItemVisitor::visit(const absyn::bnf::ItemCat& token) {
	LOG_TRC() << "Visiting ItemCat" << LOG_END;
	CatVisitor visitor(mEnv);
	token.v1().accept(visitor);
	mEnv.mReturnStack->push("$NonTerm");
}

void parser::BnfInterpreter::CatVisitor::visit(const absyn::bnf::CatSquare& token) {
	LOG_TRC() << "Visiting CatSquare" << LOG_END;
	CatVisitor visitor(mEnv);
	token.v1().accept(visitor);
	mEnv.mReturnStack->push("$List");
}

void parser::BnfInterpreter::CatVisitor::visit(const absyn::bnf::CatIdent& token) {
	LOG_TRC() << "Visiting CatIdent" << LOG_END;
	LOG() << token.v1() << LOG_END;
	mEnv.mReturnStack->push(token.v1());
}

void parser::BnfInterpreter::LabelVisitor::visit(const absyn::bnf::LabelLabelId& token) {
	LOG_TRC() << "Visiting LabelLabelId" << LOG_END;
	LabelIdVisitor visitor(mEnv);
	token.v1().accept(visitor);
}

void parser::BnfInterpreter::LabelVisitor::visit(const absyn::bnf::LabelLabelIdListProfItem& token) {
	LOG_TRC() << "Visiting LabelLabelIdListProfItem" << LOG_END;
	LabelIdVisitor visitor1(mEnv);
	token.v1().accept(visitor1);
    ListProfItemVisitor visitor2(mEnv);
    token.v2().accept(visitor2);
}

void parser::BnfInterpreter::LabelVisitor::visit(const absyn::bnf::LabelDoubleLabelIdListProfItem& token) {
	LOG_TRC() << "Visiting LabelDoubleLabelIdListProfItem" << LOG_END;
	LabelIdVisitor visitor(mEnv);
	token.v1().accept(visitor);
	token.v2().accept(visitor);
	ListProfItemVisitor visitor3(mEnv);
	token.v3().accept(visitor3);
}

void parser::BnfInterpreter::LabelIdVisitor::visit(const absyn::bnf::LabelIdIdent& token) {
	LOG_TRC() << "Visiting LabelIdIdent" << LOG_END;
	LOG() << token.v1() << LOG_END;
	mEnv.mReturnStack->push(token.v1());
}

void parser::BnfInterpreter::LabelIdVisitor::visit(const absyn::bnf::LabelIdUnderscore& token) {
	LOG_TRC() << "Visiting LabelIdUnderscore" << LOG_END;
	LOG_ERR() << "NOT IMPLEMENTED!" << LOG_END;
}

void parser::BnfInterpreter::LabelIdVisitor::visit(const absyn::bnf::LabelIdSquareBrackets& token) {
	LOG_TRC() << "Visiting LabelIdSquareBrackets" << LOG_END;
    LOG_ERR() << "NOT IMPLEMENTED!" << LOG_END;
}

void parser::BnfInterpreter::LabelIdVisitor::visit(const absyn::bnf::LabelIdBracketsColon& token) {
	LOG_TRC() << "Visiting LabelIdBracketsColon" << LOG_END;
    LOG_ERR() << "NOT IMPLEMENTED!" << LOG_END;
}

void parser::BnfInterpreter::LabelIdVisitor::visit(const absyn::bnf::LabelIdBracketsColonSquare& token) {
	LOG_TRC() << "Visiting LabelIdBracketsColonSquare" << LOG_END;
    LOG_ERR() << "NOT IMPLEMENTED!" << LOG_END;
}

void parser::BnfInterpreter::ProfItemVisitor::visit(const absyn::bnf::ProfItemBrackets& token) {
	LOG_TRC() << "Visiting ProfItemBrackets" << LOG_END;
	ListIntListVisitor visitor1(mEnv);
	token.v1().accept(visitor1);
    ListIntegerVisitor visitor2(mEnv);
    token.v2().accept(visitor2);
}

void parser::BnfInterpreter::IntListVisitor::visit(const absyn::bnf::IntListListInteger& token) {
	LOG_TRC() << "Visiting IntListListInteger" << LOG_END;
	ListIntegerVisitor visitor(mEnv);
	token.v1().accept(visitor);
}

void parser::BnfInterpreter::ListIntegerVisitor::visit(const absyn::bnf::ListIntegerEmpty& token) {
	LOG_TRC() << "Visiting ListIntegerEmpty" << LOG_END;
}

void parser::BnfInterpreter::ListIntegerVisitor::visit(const absyn::bnf::ListIntegerInteger& token) {
	LOG_TRC() << "Visiting ListIntegerInteger" << LOG_END;
	LOG() << token.v1() << LOG_END;
}

void parser::BnfInterpreter::ListIntegerVisitor::visit(const absyn::bnf::ListIntegerIntegerList& token) {
	LOG_TRC() << "Visiting ListIntegerIntegerList" << LOG_END;
	LOG() << token.v1() << LOG_END;
	ListIntegerVisitor visitor2(mEnv);
	token.v2().accept(visitor2);
}

void parser::BnfInterpreter::ListIntListVisitor::visit(const absyn::bnf::ListIntListEpsilon& token) {
	LOG_TRC() << "Visiting ListIntListEpsilon" << LOG_END;
}

void parser::BnfInterpreter::ListIntListVisitor::visit(const absyn::bnf::ListIntListIntList& token) {
	LOG_TRC() << "Visiting ListIntListIntList" << LOG_END;
	IntListVisitor visitor(mEnv);
	token.v1().accept(visitor);
}

void parser::BnfInterpreter::ListIntListVisitor::visit(const absyn::bnf::ListIntListIntListList& token) {
	LOG_TRC() << "Visiting ListIntListIntListList" << LOG_END;
	IntListVisitor visitor1(mEnv);
	token.v1().accept(visitor1);
    ListIntListVisitor visitor2(mEnv);
    token.v2().accept(visitor2);
}

void parser::BnfInterpreter::ListProfItemVisitor::visit(const absyn::bnf::ListProfItemProfItem& token) {
	LOG_TRC() << "Visiting ListProfItemProfItem" << LOG_END;
	ProfItemVisitor visitor(mEnv);
	token.v1().accept(visitor);
}

void parser::BnfInterpreter::ListProfItemVisitor::visit(const absyn::bnf::ListProfItemList& token) {
	LOG_TRC() << "Visiting ListProfItemList" << LOG_END;
    ProfItemVisitor visitor1(mEnv);
    token.v1().accept(visitor1);
    ListProfItemVisitor visitor2(mEnv);
    token.v2().accept(visitor2);
}

void parser::BnfInterpreter::ListStringVisitor::visit(const absyn::bnf::ListStringString& token) {
	LOG_TRC() << "Visiting ListStringString" << LOG_END;
	LOG() << token.v1() << LOG_END;
}

void parser::BnfInterpreter::ListStringVisitor::visit(const absyn::bnf::ListStringList& token) {
	LOG_TRC() << "Visiting ListStringList" << LOG_END;
	LOG() << token.v1() << LOG_END;
    ListStringVisitor visitor2(mEnv);
    token.v2().accept(visitor2);
}

void parser::BnfInterpreter::ListRHSVisitor::visit(const absyn::bnf::ListRHSRHS& token) {
	LOG_TRC() << "Visiting ListRHSRHS" << LOG_END;
	RHSVisitor visitor(mEnv);
	token.v1().accept(visitor);
}

void parser::BnfInterpreter::ListRHSVisitor::visit(const absyn::bnf::ListRHSList& token) {
	LOG_TRC() << "Visiting ListRHSList" << LOG_END;
	RHSVisitor visitor1(mEnv);
	token.v1().accept(visitor1);
    ListRHSVisitor visitor2(mEnv);
    token.v2().accept(visitor2);
}

void parser::BnfInterpreter::RHSVisitor::visit(const absyn::bnf::RHSListItem& token) {
	LOG_TRC() << "Visiting RHSListItem" << LOG_END;
	ListItemVisitor visitor(mEnv);
	token.v1().accept(visitor);
}

void parser::BnfInterpreter::MinimumSizeVisitor::visit(const absyn::bnf::MinimumSizeNonempty& token) {
	LOG_TRC() << "Visiting MinimumSizeNonempty" << LOG_END;
}

void parser::BnfInterpreter::MinimumSizeVisitor::visit(const absyn::bnf::MinimumSizeEpsilon& token) {
	LOG_TRC() << "Visiting MinimumSizeEpsilon" << LOG_END;
}

void parser::BnfInterpreter::RegVisitor::visit(const absyn::bnf::RegReg& token) {
	LOG_TRC() << "Visiting RegReg" << LOG_END;
	RegVisitor visitor(mEnv);
	token.v1().accept(visitor);
}

void parser::BnfInterpreter::RegVisitor::visit(const absyn::bnf::RegOr& token) {
	LOG_TRC() << "Visiting RegOr" << LOG_END;
	RegVisitor visitor(mEnv);
	token.v1().accept(visitor);
	auto* t = mEnv.mCurrentTerminalData;
	t->mCompleteRegex += "|";
	token.v2().accept(visitor);
}

void parser::BnfInterpreter::RegVisitor::visit(const absyn::bnf::RegMinus& token) {
	LOG_TRC() << "Visiting RegMinus" << LOG_END;
	LOG_ERR() << "NOT IMPLEMENTED!" << LOG_END;
	RegVisitor visitor(mEnv);
	token.v1().accept(visitor);
	token.v2().accept(visitor);
}

void parser::BnfInterpreter::RegVisitor::visit(const absyn::bnf::RegDoubleReg& token) {
	LOG_TRC() << "Visiting RegDoubleReg" << LOG_END;
    RegVisitor visitor(mEnv);
    auto* t = mEnv.mCurrentTerminalData;
	t->mCompleteRegex += "(";
	token.v1().accept(visitor);
    t->mCompleteRegex += ")(";
	token.v2().accept(visitor);
    t->mCompleteRegex += ")";
}

void parser::BnfInterpreter::RegVisitor::visit(const absyn::bnf::RegStar& token) {
	LOG_TRC() << "Visiting RegStar" << LOG_END;
    auto* t = mEnv.mCurrentTerminalData;
    t->mCompleteRegex += "(";
    RegVisitor visitor(mEnv);
    token.v1().accept(visitor);
    t->mCompleteRegex += ")*";
}

void parser::BnfInterpreter::RegVisitor::visit(const absyn::bnf::RegPlus& token) {
	LOG_TRC() << "Visiting RegPlus" << LOG_END;
    auto* t = mEnv.mCurrentTerminalData;
    t->mCompleteRegex += "(";
    RegVisitor visitor(mEnv);
    token.v1().accept(visitor);
    t->mCompleteRegex += ")+";
}

void parser::BnfInterpreter::RegVisitor::visit(const absyn::bnf::RegQuestion& token) {
	LOG_TRC() << "Visiting RegQuestion" << LOG_END;
    auto* t = mEnv.mCurrentTerminalData;
    t->mCompleteRegex += "(";
    RegVisitor visitor(mEnv);
    token.v1().accept(visitor);
    t->mCompleteRegex += ")?";
}

void parser::BnfInterpreter::RegVisitor::visit(const absyn::bnf::RegEps& token) {
	LOG_TRC() << "Visiting RegEps" << LOG_END;
}

void parser::BnfInterpreter::RegVisitor::visit(const absyn::bnf::RegRealChar& token) {
	LOG_TRC() << "Visiting RegRealChar" << LOG_END;
	LOG() << token.v1() << LOG_END;
    auto* t = mEnv.mCurrentTerminalData;
    t->mCompleteRegex += token.v1();
}

void parser::BnfInterpreter::RegVisitor::visit(const absyn::bnf::RegSquareString& token) {
	LOG_TRC() << "Visiting RegSquareString" << LOG_END;
	LOG() << token.v1() << LOG_END;
    auto* t = mEnv.mCurrentTerminalData;
    t->mCompleteRegex += token.v1();
}

void parser::BnfInterpreter::RegVisitor::visit(const absyn::bnf::RegCurlyString& token) {
	LOG_TRC() << "Visiting RegCurlyString" << LOG_END;
    LOG() << token.v1() << LOG_END;
    auto* t = mEnv.mCurrentTerminalData;
    t->mCompleteRegex = t->mCompleteRegex + "[" + token.v1() + "]";
}

void parser::BnfInterpreter::RegVisitor::visit(const absyn::bnf::RegDigit& token) {
	LOG_TRC() << "Visiting RegDigit" << LOG_END;
    auto* t = mEnv.mCurrentTerminalData;
    t->mCompleteRegex += "\\d";
}

void parser::BnfInterpreter::RegVisitor::visit(const absyn::bnf::RegLetter& token) {
	LOG_TRC() << "Visiting RegLetter" << LOG_END;
    auto* t = mEnv.mCurrentTerminalData;
    t->mCompleteRegex += "[:alpha:]";
}

void parser::BnfInterpreter::RegVisitor::visit(const absyn::bnf::RegUpper& token) {
	LOG_TRC() << "Visiting RegUpper" << LOG_END;
    auto* t = mEnv.mCurrentTerminalData;
    t->mCompleteRegex += "[:upper:]";
}

void parser::BnfInterpreter::RegVisitor::visit(const absyn::bnf::RegLower& token) {
	LOG_TRC() << "Visiting RegLower" << LOG_END;
    auto* t = mEnv.mCurrentTerminalData;
    t->mCompleteRegex += "[:lower:]";
}

void parser::BnfInterpreter::RegVisitor::visit(const absyn::bnf::RegChar& token) {
	LOG_TRC() << "Visiting RegChar" << LOG_END;
	LOG_ERR() << "NOT IMPLEMENTED!" << LOG_END;
	// TODO: figure out
}

void parser::BnfInterpreter::ListIdentVisitor::visit(const absyn::bnf::ListIdentIdent& token) {
	LOG_TRC() << "Visiting ListIdentIdent" << LOG_END;
	LOG() << token.v1() << LOG_END;
}

void parser::BnfInterpreter::ListIdentVisitor::visit(const absyn::bnf::ListIdentIdentList& token) {
	LOG_TRC() << "Visiting ListIdentIdentList" << LOG_END;
    LOG() << token.v1() << LOG_END;
	ListIdentVisitor visitor2(mEnv);
	token.v2().accept(visitor2);
}
