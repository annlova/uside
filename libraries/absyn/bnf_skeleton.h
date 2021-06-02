//
// Created by anton on 2021-05-30.
//
// THIS FILE IS NOT MEANT TO BE #INCLUDED!
// This file contains the skeleton header code for going through the "bnf" abstract syntax tree.

#include <bnf/bnf_include.h>

namespace parser {
    namespace bnf = absyn::bnf;

    class BnfSkeleton {
    public:
        int interpret(const bnf::Grammar& grammar);

    private:
        struct GrammarVisitor : public bnf::GrammarVisitor {
			BnfSkeleton& mBnfSkeleton;
			GrammarVisitor(BnfSkeleton& bnfSkeleton) : mBnfSkeleton(bnfSkeleton) {}
            void visit(const bnf::GrammarListDef& token) override;
        };

        struct ListDefVisitor : public bnf::ListDefVisitor {
			BnfSkeleton& mBnfSkeleton;
			ListDefVisitor(BnfSkeleton& bnfSkeleton) : mBnfSkeleton(bnfSkeleton) {}
            void visit(const bnf::ListDefEpsilon& token) override;

            void visit(const bnf::ListDefList& token) override;
        };

        struct ListItemVisitor : public bnf::ListItemVisitor {
			BnfSkeleton& mBnfSkeleton;
			ListItemVisitor(BnfSkeleton& bnfSkeleton) : mBnfSkeleton(bnfSkeleton) {}
            void visit(const bnf::ListItemEpsilon& token) override;

            void visit(const bnf::ListItemItemList& token) override;
        };

        struct DefVisitor : public bnf::DefVisitor {
			BnfSkeleton& mBnfSkeleton;
			DefVisitor(BnfSkeleton& bnfSkeleton) : mBnfSkeleton(bnfSkeleton) {}
            void visit(const bnf::DefLabel& token) override;

            void visit(const bnf::DefLineComment& token) override;

            void visit(const bnf::DefBlockComment& token) override;

            void visit(const bnf::DefInternal& token) override;

            void visit(const bnf::DefToken& token) override;

            void visit(const bnf::DefPositionToken& token) override;

            void visit(const bnf::DefEntryPoints& token) override;

            void visit(const bnf::DefSeparator& token) override;

            void visit(const bnf::DefTerminator& token) override;

            void visit(const bnf::DefCoercions& token) override;

            void visit(const bnf::DefRules& token) override;

            void visit(const bnf::DefLayout& token) override;

            void visit(const bnf::DefLayoutStop& token) override;

            void visit(const bnf::DefLayoutTopLevel& token) override;
        };

        struct ItemVisitor : public bnf::ItemVisitor {
			BnfSkeleton& mBnfSkeleton;
			ItemVisitor(BnfSkeleton& bnfSkeleton) : mBnfSkeleton(bnfSkeleton) {}
            void visit(const bnf::ItemString& token) override;

            void visit(const bnf::ItemCat& token) override;
        };

        struct CatVisitor : public bnf::CatVisitor {
			BnfSkeleton& mBnfSkeleton;
			CatVisitor(BnfSkeleton& bnfSkeleton) : mBnfSkeleton(bnfSkeleton) {}
            void visit(const bnf::CatSquare& token) override;

            void visit(const bnf::CatIdent& token) override;
        };

        struct LabelVisitor : public bnf::LabelVisitor {
			BnfSkeleton& mBnfSkeleton;
			LabelVisitor(BnfSkeleton& bnfSkeleton) : mBnfSkeleton(bnfSkeleton) {}
            void visit(const bnf::LabelLabelId& token) override;

            void visit(const bnf::LabelLabelIdListProfItem& token) override;

            void visit(const bnf::LabelDoubleLabelIdListProfItem& token) override;
        };

        struct LabelIdVisitor : public bnf::LabelIdVisitor {
			BnfSkeleton& mBnfSkeleton;
			LabelIdVisitor(BnfSkeleton& bnfSkeleton) : mBnfSkeleton(bnfSkeleton) {}
            void visit(const bnf::LabelIdIdent& token) override;

            void visit(const bnf::LabelIdUnderscore& token) override;

            void visit(const bnf::LabelIdSquareBrackets& token) override;

            void visit(const bnf::LabelIdBracketsColon& token) override;

            void visit(const bnf::LabelIdBracketsColonSquare& token) override;
        };

        struct ProfItemVisitor : public bnf::ProfItemVisitor {
			BnfSkeleton& mBnfSkeleton;
			ProfItemVisitor(BnfSkeleton& bnfSkeleton) : mBnfSkeleton(bnfSkeleton) {}
            void visit(const bnf::ProfItemBrackets& token) override;
        };

        struct IntListVisitor : public bnf::IntListVisitor {
			BnfSkeleton& mBnfSkeleton;
			IntListVisitor(BnfSkeleton& bnfSkeleton) : mBnfSkeleton(bnfSkeleton) {}
            void visit(const bnf::IntListListInteger& token) override;
        };

        struct ListIntegerVisitor : public bnf::ListIntegerVisitor {
			BnfSkeleton& mBnfSkeleton;
			ListIntegerVisitor(BnfSkeleton& bnfSkeleton) : mBnfSkeleton(bnfSkeleton) {}
            void visit(const bnf::ListIntegerEmpty& token) override;

            void visit(const bnf::ListIntegerInteger& token) override;

            void visit(const bnf::ListIntegerIntegerList& token) override;
        };

        struct ListIntListVisitor : public bnf::ListIntListVisitor {
			BnfSkeleton& mBnfSkeleton;
			ListIntListVisitor(BnfSkeleton& bnfSkeleton) : mBnfSkeleton(bnfSkeleton) {}
            void visit(const bnf::ListIntListEpsilon& token) override;

            void visit(const bnf::ListIntListIntList& token) override;

            void visit(const bnf::ListIntListIntListList& token) override;
        };

        struct ListProfItemVisitor : public bnf::ListProfItemVisitor {
			BnfSkeleton& mBnfSkeleton;
			ListProfItemVisitor(BnfSkeleton& bnfSkeleton) : mBnfSkeleton(bnfSkeleton) {}
            void visit(const bnf::ListProfItemProfItem& token) override;

            void visit(const bnf::ListProfItemList& token) override;
        };

        struct ListStringVisitor : public bnf::ListStringVisitor {
			BnfSkeleton& mBnfSkeleton;
			ListStringVisitor(BnfSkeleton& bnfSkeleton) : mBnfSkeleton(bnfSkeleton) {}
            void visit(const bnf::ListStringString& token) override;

            void visit(const bnf::ListStringList& token) override;
        };

        struct ListRHSVisitor : public bnf::ListRHSVisitor {
			BnfSkeleton& mBnfSkeleton;
			ListRHSVisitor(BnfSkeleton& bnfSkeleton) : mBnfSkeleton(bnfSkeleton) {}
            void visit(const bnf::ListRHSRHS& token) override;

            void visit(const bnf::ListRHSList& token) override;
        };

        struct RHSVisitor : public bnf::RHSVisitor {
			BnfSkeleton& mBnfSkeleton;
			RHSVisitor(BnfSkeleton& bnfSkeleton) : mBnfSkeleton(bnfSkeleton) {}
            void visit(const bnf::RHSListItem& token) override;
        };

        struct MinimumSizeVisitor : public bnf::MinimumSizeVisitor {
			BnfSkeleton& mBnfSkeleton;
			MinimumSizeVisitor(BnfSkeleton& bnfSkeleton) : mBnfSkeleton(bnfSkeleton) {}
            void visit(const bnf::MinimumSizeNonempty& token) override;

            void visit(const bnf::MinimumSizeEpsilon& token) override;
        };

        struct RegVisitor : public bnf::RegVisitor {
			BnfSkeleton& mBnfSkeleton;
			RegVisitor(BnfSkeleton& bnfSkeleton) : mBnfSkeleton(bnfSkeleton) {}
            void visit(const bnf::RegReg& token) override;

            void visit(const bnf::RegOr& token) override;

            void visit(const bnf::RegMinus& token) override;

            void visit(const bnf::RegDoubleReg& token) override;

            void visit(const bnf::RegStar& token) override;

            void visit(const bnf::RegPlus& token) override;

            void visit(const bnf::RegQuestion& token) override;

            void visit(const bnf::RegEps& token) override;

            void visit(const bnf::RegRealChar& token) override;

            void visit(const bnf::RegSquareString& token) override;

            void visit(const bnf::RegCurlyString& token) override;

            void visit(const bnf::RegDigit& token) override;

            void visit(const bnf::RegLetter& token) override;

            void visit(const bnf::RegUpper& token) override;

            void visit(const bnf::RegLower& token) override;

            void visit(const bnf::RegChar& token) override;
        };

        struct ListIdentVisitor : public bnf::ListIdentVisitor {
			BnfSkeleton& mBnfSkeleton;
			ListIdentVisitor(BnfSkeleton& bnfSkeleton) : mBnfSkeleton(bnfSkeleton) {}
            void visit(const bnf::ListIdentIdent& token) override;

            void visit(const bnf::ListIdentIdentList& token) override;
        };
    };
}