//
// Created by anton on 2021-05-30.
//

#include "bnf_skeleton.h"

int parser::BnfSkeleton::interpret(const absyn::bnf::Grammar& grammar) {
    return 0;
}

void parser::BnfSkeleton::GrammarVisitor::visit(const absyn::bnf::GrammarListDef& token) {

}

void parser::BnfSkeleton::ListDefVisitor::visit(const absyn::bnf::ListDefEpsilon& token) {

}

void parser::BnfSkeleton::ListDefVisitor::visit(const absyn::bnf::ListDefList& token) {

}

void parser::BnfSkeleton::ListItemVisitor::visit(const absyn::bnf::ListItemEpsilon& token) {

}

void parser::BnfSkeleton::ListItemVisitor::visit(const absyn::bnf::ListItemItemList& token) {

}

void parser::BnfSkeleton::DefVisitor::visit(const absyn::bnf::DefLabel& token) {

}

void parser::BnfSkeleton::DefVisitor::visit(const absyn::bnf::DefLineComment& token) {

}

void parser::BnfSkeleton::DefVisitor::visit(const absyn::bnf::DefBlockComment& token) {

}

void parser::BnfSkeleton::DefVisitor::visit(const absyn::bnf::DefInternal& token) {

}

void parser::BnfSkeleton::DefVisitor::visit(const absyn::bnf::DefToken& token) {

}

void parser::BnfSkeleton::DefVisitor::visit(const absyn::bnf::DefPositionToken& token) {

}

void parser::BnfSkeleton::DefVisitor::visit(const absyn::bnf::DefEntryPoints& token) {

}

void parser::BnfSkeleton::DefVisitor::visit(const absyn::bnf::DefSeparator& token) {

}

void parser::BnfSkeleton::DefVisitor::visit(const absyn::bnf::DefTerminator& token) {

}

void parser::BnfSkeleton::DefVisitor::visit(const absyn::bnf::DefCoercions& token) {

}

void parser::BnfSkeleton::DefVisitor::visit(const absyn::bnf::DefRules& token) {

}

void parser::BnfSkeleton::DefVisitor::visit(const absyn::bnf::DefLayout& token) {

}

void parser::BnfSkeleton::DefVisitor::visit(const absyn::bnf::DefLayoutStop& token) {

}

void parser::BnfSkeleton::DefVisitor::visit(const absyn::bnf::DefLayoutTopLevel& token) {

}

void parser::BnfSkeleton::ItemVisitor::visit(const absyn::bnf::ItemString& token) {

}

void parser::BnfSkeleton::ItemVisitor::visit(const absyn::bnf::ItemCat& token) {

}

void parser::BnfSkeleton::CatVisitor::visit(const absyn::bnf::CatSquare& token) {

}

void parser::BnfSkeleton::CatVisitor::visit(const absyn::bnf::CatIdent& token) {

}

void parser::BnfSkeleton::LabelVisitor::visit(const absyn::bnf::LabelLabelId& token) {

}

void parser::BnfSkeleton::LabelVisitor::visit(const absyn::bnf::LabelLabelIdListProfItem& token) {

}

void parser::BnfSkeleton::LabelVisitor::visit(const absyn::bnf::LabelDoubleLabelIdListProfItem& token) {

}

void parser::BnfSkeleton::LabelIdVisitor::visit(const absyn::bnf::LabelIdIdent& token) {

}

void parser::BnfSkeleton::LabelIdVisitor::visit(const absyn::bnf::LabelIdUnderscore& token) {

}

void parser::BnfSkeleton::LabelIdVisitor::visit(const absyn::bnf::LabelIdSquareBrackets& token) {

}

void parser::BnfSkeleton::LabelIdVisitor::visit(const absyn::bnf::LabelIdBracketsColon& token) {

}

void parser::BnfSkeleton::LabelIdVisitor::visit(const absyn::bnf::LabelIdBracketsColonSquare& token) {

}

void parser::BnfSkeleton::ProfItemVisitor::visit(const absyn::bnf::ProfItemBrackets& token) {

}

void parser::BnfSkeleton::IntListVisitor::visit(const absyn::bnf::IntListListInteger& token) {

}

void parser::BnfSkeleton::ListIntegerVisitor::visit(const absyn::bnf::ListIntegerEmpty& token) {

}

void parser::BnfSkeleton::ListIntegerVisitor::visit(const absyn::bnf::ListIntegerInteger& token) {

}

void parser::BnfSkeleton::ListIntegerVisitor::visit(const absyn::bnf::ListIntegerIntegerList& token) {

}

void parser::BnfSkeleton::ListIntListVisitor::visit(const absyn::bnf::ListIntListEpsilon& token) {

}

void parser::BnfSkeleton::ListIntListVisitor::visit(const absyn::bnf::ListIntListIntList& token) {

}

void parser::BnfSkeleton::ListIntListVisitor::visit(const absyn::bnf::ListIntListIntListList& token) {

}

void parser::BnfSkeleton::ListProfItemVisitor::visit(const absyn::bnf::ListProfItemProfItem& token) {

}

void parser::BnfSkeleton::ListProfItemVisitor::visit(const absyn::bnf::ListProfItemList& token) {

}

void parser::BnfSkeleton::ListStringVisitor::visit(const absyn::bnf::ListStringString& token) {

}

void parser::BnfSkeleton::ListStringVisitor::visit(const absyn::bnf::ListStringList& token) {

}

void parser::BnfSkeleton::ListRHSVisitor::visit(const absyn::bnf::ListRHSRHS& token) {

}

void parser::BnfSkeleton::ListRHSVisitor::visit(const absyn::bnf::ListRHSList& token) {

}

void parser::BnfSkeleton::RHSVisitor::visit(const absyn::bnf::RHSListItem& token) {

}

void parser::BnfSkeleton::MinimumSizeVisitor::visit(const absyn::bnf::MinimumSizeNonempty& token) {

}

void parser::BnfSkeleton::MinimumSizeVisitor::visit(const absyn::bnf::MinimumSizeEpsilon& token) {

}

void parser::BnfSkeleton::RegVisitor::visit(const absyn::bnf::RegReg& token) {

}

void parser::BnfSkeleton::RegVisitor::visit(const absyn::bnf::RegOr& token) {

}

void parser::BnfSkeleton::RegVisitor::visit(const absyn::bnf::RegMinus& token) {

}

void parser::BnfSkeleton::RegVisitor::visit(const absyn::bnf::RegDoubleReg& token) {

}

void parser::BnfSkeleton::RegVisitor::visit(const absyn::bnf::RegStar& token) {

}

void parser::BnfSkeleton::RegVisitor::visit(const absyn::bnf::RegPlus& token) {

}

void parser::BnfSkeleton::RegVisitor::visit(const absyn::bnf::RegQuestion& token) {

}

void parser::BnfSkeleton::RegVisitor::visit(const absyn::bnf::RegEps& token) {

}

void parser::BnfSkeleton::RegVisitor::visit(const absyn::bnf::RegRealChar& token) {

}

void parser::BnfSkeleton::RegVisitor::visit(const absyn::bnf::RegSquareString& token) {

}

void parser::BnfSkeleton::RegVisitor::visit(const absyn::bnf::RegCurlyString& token) {

}

void parser::BnfSkeleton::RegVisitor::visit(const absyn::bnf::RegDigit& token) {

}

void parser::BnfSkeleton::RegVisitor::visit(const absyn::bnf::RegLetter& token) {

}

void parser::BnfSkeleton::RegVisitor::visit(const absyn::bnf::RegUpper& token) {

}

void parser::BnfSkeleton::RegVisitor::visit(const absyn::bnf::RegLower& token) {

}

void parser::BnfSkeleton::RegVisitor::visit(const absyn::bnf::RegChar& token) {

}

void parser::BnfSkeleton::ListIdentVisitor::visit(const absyn::bnf::ListIdentIdent& token) {

}

void parser::BnfSkeleton::ListIdentVisitor::visit(const absyn::bnf::ListIdentIdentList& token) {

}
