//
// Created by anton on 2021-05-30.
//

#include "../h/bnf_interpreter.h"

int parser::BnfInterpreter::interpret(absyn::bnf::Grammar* grammar) {
    GrammarVisitor grammarVisitor;
    grammar->accept(&grammarVisitor);
    return 0;
}

void parser::BnfInterpreter::GrammarVisitor::visit(absyn::bnf::GrammarListDef* token) {
    ListDefVisitor listDefVisitor;
    token->v1()->accept(listDefVisitor);
    a = 5;
}

void parser::BnfInterpreter::ListDefVisitor::visit(const absyn::bnf::ListDefEpsilon& token, bnf::Env& env) const {

}

void parser::BnfInterpreter::ListDefVisitor::visit(const absyn::bnf::ListDefList& token, bnf::Env& env) const {

}

void parser::BnfInterpreter::ListItemVisitor::visit(absyn::bnf::ListItemEpsilon* token) {

}

void parser::BnfInterpreter::ListItemVisitor::visit(absyn::bnf::ListItemItemList* token) {

}

void parser::BnfInterpreter::DefVisitor::visit(absyn::bnf::DefLabel* v) {

}

void parser::BnfInterpreter::DefVisitor::visit(absyn::bnf::DefLineComment* v) {

}

void parser::BnfInterpreter::DefVisitor::visit(absyn::bnf::DefBlockComment* v) {

}

void parser::BnfInterpreter::DefVisitor::visit(absyn::bnf::DefInternal* v) {

}

void parser::BnfInterpreter::DefVisitor::visit(absyn::bnf::DefToken* v) {

}

void parser::BnfInterpreter::DefVisitor::visit(absyn::bnf::DefPositionToken* v) {

}

void parser::BnfInterpreter::DefVisitor::visit(absyn::bnf::DefEntryPoints* v) {

}

void parser::BnfInterpreter::DefVisitor::visit(absyn::bnf::DefSeparator* v) {

}

void parser::BnfInterpreter::DefVisitor::visit(absyn::bnf::DefTerminator* v) {

}

void parser::BnfInterpreter::DefVisitor::visit(absyn::bnf::DefCoercions* v) {

}

void parser::BnfInterpreter::DefVisitor::visit(absyn::bnf::DefRules* v) {

}

void parser::BnfInterpreter::DefVisitor::visit(absyn::bnf::DefLayout* v) {

}

void parser::BnfInterpreter::DefVisitor::visit(absyn::bnf::DefLayoutStop* v) {

}

void parser::BnfInterpreter::DefVisitor::visit(absyn::bnf::DefLayoutTopLevel* v) {

}

void parser::BnfInterpreter::ItemVisitor::visit(absyn::bnf::ItemString* token) {

}

void parser::BnfInterpreter::ItemVisitor::visit(absyn::bnf::ItemCat* token) {

}

void parser::BnfInterpreter::CatVisitor::visit(absyn::bnf::CatSquare* token) {

}

void parser::BnfInterpreter::CatVisitor::visit(absyn::bnf::CatIdent* token) {

}

void parser::BnfInterpreter::LabelVisitor::visit(absyn::bnf::LabelLabelId* token) {

}

void parser::BnfInterpreter::LabelVisitor::visit(absyn::bnf::LabelLabelIdListProfItem* token) {

}

void parser::BnfInterpreter::LabelVisitor::visit(absyn::bnf::LabelDoubleLabelIdListProfItem* token) {

}

void parser::BnfInterpreter::LabelIdVisitor::visit(absyn::bnf::LabelIdIdent* token) {

}

void parser::BnfInterpreter::LabelIdVisitor::visit(absyn::bnf::LabelIdUnderscore* token) {

}

void parser::BnfInterpreter::LabelIdVisitor::visit(absyn::bnf::LabelIdSquareBrackets* token) {

}

void parser::BnfInterpreter::LabelIdVisitor::visit(absyn::bnf::LabelIdBracketsColon* token) {

}

void parser::BnfInterpreter::LabelIdVisitor::visit(absyn::bnf::LabelIdBracketsColonSquare* token) {

}

void parser::BnfInterpreter::ProfItemVisitor::visit(absyn::bnf::ProfItemBrackets* token) {

}

void parser::BnfInterpreter::IntListVisitor::visit(absyn::bnf::IntListListInteger* token) {

}

void parser::BnfInterpreter::ListIntegerVisitor::visit(absyn::bnf::ListIntegerEmpty* token) {

}

void parser::BnfInterpreter::ListIntegerVisitor::visit(absyn::bnf::ListIntegerInteger* token) {

}

void parser::BnfInterpreter::ListIntegerVisitor::visit(absyn::bnf::ListIntegerIntegerList* token) {

}

void parser::BnfInterpreter::ListIntListVisitor::visit(absyn::bnf::ListIntListEpsilon* token) {

}

void parser::BnfInterpreter::ListIntListVisitor::visit(absyn::bnf::ListIntListIntList* token) {

}

void parser::BnfInterpreter::ListIntListVisitor::visit(absyn::bnf::ListIntListIntListList* token) {

}

void parser::BnfInterpreter::ListProfItemVisitor::visit(absyn::bnf::ListProfItemProfItem* token) {

}

void parser::BnfInterpreter::ListProfItemVisitor::visit(absyn::bnf::ListProfItemList* token) {

}

void parser::BnfInterpreter::ListStringVisitor::visit(absyn::bnf::ListStringString* token) {

}

void parser::BnfInterpreter::ListStringVisitor::visit(absyn::bnf::ListStringList* token) {

}

void parser::BnfInterpreter::ListRHSVisitor::visit(absyn::bnf::ListRHSRHS* token) {

}

void parser::BnfInterpreter::ListRHSVisitor::visit(absyn::bnf::ListRHSList* token) {

}

void parser::BnfInterpreter::RHSVisitor::visit(absyn::bnf::RHSListItem* token) {

}

void parser::BnfInterpreter::MinimumSizeVisitor::visit(absyn::bnf::MinimumSizeNonempty* token) {

}

void parser::BnfInterpreter::MinimumSizeVisitor::visit(absyn::bnf::MinimumSizeEpsilon* token) {

}

void parser::BnfInterpreter::RegVisitor::visit(absyn::bnf::RegReg* token) {

}

void parser::BnfInterpreter::RegVisitor::visit(absyn::bnf::RegOr* token) {

}

void parser::BnfInterpreter::RegVisitor::visit(absyn::bnf::RegMinus* token) {

}

void parser::BnfInterpreter::RegVisitor::visit(absyn::bnf::RegDoubleReg* token) {

}

void parser::BnfInterpreter::RegVisitor::visit(absyn::bnf::RegStar* token) {

}

void parser::BnfInterpreter::RegVisitor::visit(absyn::bnf::RegPlus* token) {

}

void parser::BnfInterpreter::RegVisitor::visit(absyn::bnf::RegQuestion* token) {

}

void parser::BnfInterpreter::RegVisitor::visit(absyn::bnf::RegEps* token) {

}

void parser::BnfInterpreter::RegVisitor::visit(absyn::bnf::RegRealChar* token) {

}

void parser::BnfInterpreter::RegVisitor::visit(absyn::bnf::RegSquareString* token) {

}

void parser::BnfInterpreter::RegVisitor::visit(absyn::bnf::RegCurlyString* token) {

}

void parser::BnfInterpreter::RegVisitor::visit(absyn::bnf::RegDigit* token) {

}

void parser::BnfInterpreter::RegVisitor::visit(absyn::bnf::RegLetter* token) {

}

void parser::BnfInterpreter::RegVisitor::visit(absyn::bnf::RegUpper* token) {

}

void parser::BnfInterpreter::RegVisitor::visit(absyn::bnf::RegLower* token) {

}

void parser::BnfInterpreter::RegVisitor::visit(absyn::bnf::RegChar* token) {

}

void parser::BnfInterpreter::ListIdentVisitor::visit(absyn::bnf::ListIdentIdent* token) {

}

void parser::BnfInterpreter::ListIdentVisitor::visit(absyn::bnf::ListIdentIdentList* token) {

}
