//
// Created by anton on 2021-05-30.
//
// THIS FILE IS NOT MEANT TO BE #INCLUDED!
// This file contains the skeleton header code for going through the "bnf" abstract syntax tree.

#include <bnf/bnf_include.h>

namespace parser {
    namespace bnf = absyn::bnf;

    class BnfInterpreter {
    public:
        int interpret(bnf::Grammar *);

    private:
        struct GrammarVisitor : public bnf::GrammarVisitor {
            void visit(bnf::GrammarListDef *token) override;
        };

        struct ListDefVisitor : public bnf::ListDefVisitor {
            void visit(bnf::ListDefEpsilon *token) override;

            void visit(bnf::ListDefList *token) override;
        };

        struct ListItemVisitor : public bnf::ListItemVisitor {
            void visit(bnf::ListItemEpsilon *token) override;

            void visit(bnf::ListItemItemList *token) override;
        };

        struct DefVisitor : public bnf::DefVisitor {
            void visit(bnf::DefLabel *v) override;

            void visit(bnf::DefLineComment *v) override;

            void visit(bnf::DefBlockComment *v) override;

            void visit(bnf::DefInternal *v) override;

            void visit(bnf::DefToken *v) override;

            void visit(bnf::DefPositionToken *v) override;

            void visit(bnf::DefEntryPoints *v) override;

            void visit(bnf::DefSeparator *v) override;

            void visit(bnf::DefTerminator *v) override;

            void visit(bnf::DefCoercions *v) override;

            void visit(bnf::DefRules *v) override;

            void visit(bnf::DefLayout *v) override;

            void visit(bnf::DefLayoutStop *v) override;

            void visit(bnf::DefLayoutTopLevel *v) override;
        };

        struct ItemVisitor : public bnf::ItemVisitor {
            void visit(bnf::ItemString *token) override;

            void visit(bnf::ItemCat *token) override;
        };

        struct CatVisitor : public bnf::CatVisitor {
            void visit(bnf::CatSquare *token) override;

            void visit(bnf::CatIdent *token) override;
        };

        struct LabelVisitor : public bnf::LabelVisitor {
            void visit(bnf::LabelLabelId *token) override;

            void visit(bnf::LabelLabelIdListProfItem *token) override;

            void visit(bnf::LabelDoubleLabelIdListProfItem *token) override;
        };

        struct LabelIdVisitor : public bnf::LabelIdVisitor {
            void visit(bnf::LabelIdIdent *token) override;

            void visit(bnf::LabelIdUnderscore *token) override;

            void visit(bnf::LabelIdSquareBrackets *token) override;

            void visit(bnf::LabelIdBracketsColon *token) override;

            void visit(bnf::LabelIdBracketsColonSquare *token) override;
        };

        struct ProfItemVisitor : public bnf::ProfItemVisitor {
            void visit(bnf::ProfItemBrackets *token) override;
        };

        struct IntListVisitor : public bnf::IntListVisitor {
            void visit(bnf::IntListListInteger *token) override;
        };

        struct ListIntegerVisitor : public bnf::ListIntegerVisitor {
            void visit(bnf::ListIntegerEmpty *token) override;

            void visit(bnf::ListIntegerInteger *token) override;

            void visit(bnf::ListIntegerIntegerList *token) override;
        };

        struct ListIntListVisitor : public bnf::ListIntListVisitor {
            void visit(bnf::ListIntListEpsilon *token) override;

            void visit(bnf::ListIntListIntList *token) override;

            void visit(bnf::ListIntListIntListList *token) override;
        };

        struct ListProfItemVisitor : public bnf::ListProfItemVisitor {
            void visit(bnf::ListProfItemProfItem *token) override;

            void visit(bnf::ListProfItemList *token) override;
        };

        struct ListStringVisitor : public bnf::ListStringVisitor {
            void visit(bnf::ListStringString *token) override;

            void visit(bnf::ListStringList *token) override;
        };

        struct ListRHSVisitor : public bnf::ListRHSVisitor {
            void visit(bnf::ListRHSRHS *token) override;

            void visit(bnf::ListRHSList *token) override;
        };

        struct RHSVisitor : public bnf::RHSVisitor {
            void visit(bnf::RHSListItem *token) override;
        };

        struct MinimumSizeVisitor : public bnf::MinimumSizeVisitor {
            void visit(bnf::MinimumSizeNonempty *token) override;

            void visit(bnf::MinimumSizeEpsilon *token) override;
        };

        struct RegVisitor : public bnf::RegVisitor {
            void visit(bnf::RegReg *token) override;

            void visit(bnf::RegOr *token) override;

            void visit(bnf::RegMinus *token) override;

            void visit(bnf::RegDoubleReg *token) override;

            void visit(bnf::RegStar *token) override;

            void visit(bnf::RegPlus *token) override;

            void visit(bnf::RegQuestion *token) override;

            void visit(bnf::RegEps *token) override;

            void visit(bnf::RegRealChar *token) override;

            void visit(bnf::RegSquareString *token) override;

            void visit(bnf::RegCurlyString *token) override;

            void visit(bnf::RegDigit *token) override;

            void visit(bnf::RegLetter *token) override;

            void visit(bnf::RegUpper *token) override;

            void visit(bnf::RegLower *token) override;

            void visit(bnf::RegChar *token) override;
        };

        struct ListIdentVisitor : public bnf::ListIdentVisitor {
            void visit(bnf::ListIdentIdent *token) override;

            void visit(bnf::ListIdentIdentList *token) override;
        };
    };
}