//
// Created by Anton on 2021-05-28.
//

#ifndef USIDE_LIBRARIES_ABSYN_BNF_GRAMMAR_H
#define USIDE_LIBRARIES_ABSYN_BNF_GRAMMAR_H

#include "list_def.h"

namespace absyn::bnf {
    struct Grammar {
        Grammar() = default;
        virtual ~Grammar() = default;
        Grammar(Grammar& grammar) = delete;
        Grammar(Grammar&& grammar) = delete;

        Grammar& operator=(Grammar& other) = delete;
        Grammar& operator=(Grammar&& other) = delete;

        virtual void accept(struct GrammarVisitor* v) = 0;
    };

    class GrammarListDef : public Grammar {
	public:
		GrammarListDef() : mV1{nullptr} {}
		~GrammarListDef() override { delete mV1; }
		GrammarListDef(GrammarListDef& grammarListDef) = delete;
		GrammarListDef(GrammarListDef&& grammarListDef) = delete;

		GrammarListDef& operator=(GrammarListDef& other) = delete;
		GrammarListDef& operator=(GrammarListDef&& other) = delete;

        void accept(GrammarVisitor* v) override;
        [[nodiscard]] const ListDef* v1() const { return mV1; }
    private:
        const ListDef* mV1;
    };

    struct GrammarVisitor {
        virtual void visit(GrammarListDef* token) = 0;
    };

    typedef void (DestructFn)(void*);
    typedef void (GrammarAcceptFn)(void*, GrammarVisitor* v);
    struct GrammarVTable {
        DestructFn* mDestructFn1;
        DestructFn* mDestructFn2;
        GrammarAcceptFn* mAcceptFn;
    };

    inline GrammarVTable* getVTable(Grammar* obj) {
        auto** vtablePtr = reinterpret_cast<GrammarVTable**>(obj); // NOLINT(cppcoreguidelines-pro-type-reinterpret-cast)
        return *(vtablePtr);
    }
}

#endif //USIDE_LIBRARIES_ABSYN_BNF_GRAMMAR_H
