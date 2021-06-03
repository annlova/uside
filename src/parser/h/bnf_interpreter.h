//
// Created by anton on 2021-05-30.
//

#ifndef USIDE_SRC_PARSER_H_BNF_INTERPRETER_H
#define USIDE_SRC_PARSER_H_BNF_INTERPRETER_H

#include <string>
#include <sstream>
#include <regex>
#include <unordered_map>
#include <unordered_set>
#include <stack>

#include <bnf/bnf_include.h>

#include <globals/debug_code_maco.h>
#include <file/include/file_include.h>
#include <assertion/h/assertion_macro.h>

#include "bnf_compiler_terminal_data.h"

namespace parser {
    namespace bnf = absyn::bnf;

    class BnfInterpreter {
    public:
        int interpret(const bnf::Grammar& grammar);

    private:
        constexpr static const char* const mscProjectName = "uside"; // TODO: Move
        void writeAbsyn(const std::string& absynName);

    private:
        std::unordered_map<std::string, std::unordered_set<std::string>> mCatLabelMap;
        std::unordered_map<std::string, std::vector<std::string>> mLabelVarMap;

        std::unordered_set<BnfCompilerTerminalData, BnfCompilerTerminalDataHasher> mTerminals;
        BnfCompilerTerminalData* mCurrentTerminalData;

        std::stack<const char*> mLabelReturnStack;
        std::stack<const char*> mCatReturnStack;
        std::stack<const char*> mItemReturnStack;
        std::stack<const char*>* mReturnStack;

    private:
        struct GrammarVisitor : public bnf::GrammarVisitor {
            BnfInterpreter& mEnv;
            GrammarVisitor(BnfInterpreter& bnfInterpreter) : mEnv(bnfInterpreter) {}
            void visit(const bnf::GrammarListDef& token) override;
        };

        struct ListDefVisitor : public bnf::ListDefVisitor {
            BnfInterpreter& mEnv;
            ListDefVisitor(BnfInterpreter& bnfInterpreter) : mEnv(bnfInterpreter) {}
            void visit(const bnf::ListDefEpsilon& token) override;

            void visit(const bnf::ListDefList& token) override;
        };

        struct ListItemVisitor : public bnf::ListItemVisitor {
            BnfInterpreter& mEnv;
            ListItemVisitor(BnfInterpreter& bnfInterpreter) : mEnv(bnfInterpreter) {}
            void visit(const bnf::ListItemEpsilon& token) override;

            void visit(const bnf::ListItemItemList& token) override;
        };

        struct DefVisitor : public bnf::DefVisitor {
            BnfInterpreter& mEnv;
            DefVisitor(BnfInterpreter& bnfInterpreter) : mEnv(bnfInterpreter) {}
            void visit(const bnf::DefLabel& token) override;
            void handleCatStackCommand(const std::string& cmd);
            void handleLabelStackCommand(const std::string& cmd);
            void handleItemStackCommand(const std::string& cmd, std::vector<std::string>& vec);

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
            BnfInterpreter& mEnv;
            ItemVisitor(BnfInterpreter& bnfInterpreter) : mEnv(bnfInterpreter) {}
            void visit(const bnf::ItemString& token) override;

            void visit(const bnf::ItemCat& token) override;
        };

        struct CatVisitor : public bnf::CatVisitor {
            BnfInterpreter& mEnv;
            CatVisitor(BnfInterpreter& bnfInterpreter) : mEnv(bnfInterpreter) {}
            void visit(const bnf::CatSquare& token) override;

            void visit(const bnf::CatIdent& token) override;
        };

        struct LabelVisitor : public bnf::LabelVisitor {
            BnfInterpreter& mEnv;
            LabelVisitor(BnfInterpreter& bnfInterpreter) : mEnv(bnfInterpreter) {}
            void visit(const bnf::LabelLabelId& token) override;

            void visit(const bnf::LabelLabelIdListProfItem& token) override;

            void visit(const bnf::LabelDoubleLabelIdListProfItem& token) override;
        };

        struct LabelIdVisitor : public bnf::LabelIdVisitor {
            BnfInterpreter& mEnv;
            LabelIdVisitor(BnfInterpreter& bnfInterpreter) : mEnv(bnfInterpreter) {}
            void visit(const bnf::LabelIdIdent& token) override;

            void visit(const bnf::LabelIdUnderscore& token) override;

            void visit(const bnf::LabelIdSquareBrackets& token) override;

            void visit(const bnf::LabelIdBracketsColon& token) override;

            void visit(const bnf::LabelIdBracketsColonSquare& token) override;
        };

        struct ProfItemVisitor : public bnf::ProfItemVisitor {
            BnfInterpreter& mEnv;
            ProfItemVisitor(BnfInterpreter& bnfInterpreter) : mEnv(bnfInterpreter) {}
            void visit(const bnf::ProfItemBrackets& token) override;
        };

        struct IntListVisitor : public bnf::IntListVisitor {
            BnfInterpreter& mEnv;
            IntListVisitor(BnfInterpreter& bnfInterpreter) : mEnv(bnfInterpreter) {}
            void visit(const bnf::IntListListInteger& token) override;
        };

        struct ListIntegerVisitor : public bnf::ListIntegerVisitor {
            BnfInterpreter& mEnv;
            ListIntegerVisitor(BnfInterpreter& bnfInterpreter) : mEnv(bnfInterpreter) {}
            void visit(const bnf::ListIntegerEmpty& token) override;

            void visit(const bnf::ListIntegerInteger& token) override;

            void visit(const bnf::ListIntegerIntegerList& token) override;
        };

        struct ListIntListVisitor : public bnf::ListIntListVisitor {
            BnfInterpreter& mEnv;
            ListIntListVisitor(BnfInterpreter& bnfInterpreter) : mEnv(bnfInterpreter) {}
            void visit(const bnf::ListIntListEpsilon& token) override;

            void visit(const bnf::ListIntListIntList& token) override;

            void visit(const bnf::ListIntListIntListList& token) override;
        };

        struct ListProfItemVisitor : public bnf::ListProfItemVisitor {
            BnfInterpreter& mEnv;
            ListProfItemVisitor(BnfInterpreter& bnfInterpreter) : mEnv(bnfInterpreter) {}
            void visit(const bnf::ListProfItemProfItem& token) override;

            void visit(const bnf::ListProfItemList& token) override;
        };

        struct ListStringVisitor : public bnf::ListStringVisitor {
            BnfInterpreter& mEnv;
            ListStringVisitor(BnfInterpreter& bnfInterpreter) : mEnv(bnfInterpreter) {}
            void visit(const bnf::ListStringString& token) override;

            void visit(const bnf::ListStringList& token) override;
        };

        struct ListRHSVisitor : public bnf::ListRHSVisitor {
            BnfInterpreter& mEnv;
            ListRHSVisitor(BnfInterpreter& bnfInterpreter) : mEnv(bnfInterpreter) {}
            void visit(const bnf::ListRHSRHS& token) override;

            void visit(const bnf::ListRHSList& token) override;
        };

        struct RHSVisitor : public bnf::RHSVisitor {
            BnfInterpreter& mEnv;
            RHSVisitor(BnfInterpreter& bnfInterpreter) : mEnv(bnfInterpreter) {}
            void visit(const bnf::RHSListItem& token) override;
        };

        struct MinimumSizeVisitor : public bnf::MinimumSizeVisitor {
            BnfInterpreter& mEnv;
            MinimumSizeVisitor(BnfInterpreter& bnfInterpreter) : mEnv(bnfInterpreter) {}
            void visit(const bnf::MinimumSizeNonempty& token) override;

            void visit(const bnf::MinimumSizeEpsilon& token) override;
        };

        struct RegVisitor : public bnf::RegVisitor {
            BnfInterpreter& mEnv;
            RegVisitor(BnfInterpreter& bnfInterpreter) : mEnv(bnfInterpreter) {}
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
            BnfInterpreter& mEnv;
            ListIdentVisitor(BnfInterpreter& bnfInterpreter) : mEnv(bnfInterpreter) {}
            void visit(const bnf::ListIdentIdent& token) override;

            void visit(const bnf::ListIdentIdentList& token) override;
        };
    };
}

#endif //USIDE_SRC_PARSER_H_BNF_INTERPRETER_H
