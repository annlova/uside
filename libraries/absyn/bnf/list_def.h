//
// Created by Anton on 2021-05-28.
//

#ifndef USIDE_LIBRARIES_ABSYN_BNF_LIST_DEF_H
#define USIDE_LIBRARIES_ABSYN_BNF_LIST_DEF_H

#include "def.h"

namespace absyn::bnf {
    struct ListDef {
        ListDef() = default;
        virtual ~ListDef() = default;
        ListDef(ListDef& grammar) = delete;
        ListDef(ListDef&& grammar) = delete;

        ListDef& operator=(ListDef& other) = delete;
        ListDef& operator=(ListDef&& other) = delete;

        virtual void accept(struct ListDefVisitor* v) = 0;
    };

    class ListDefEpsilon : public ListDef {
	public:
        void accept(ListDefVisitor* v) override;
    };

    class ListDefList : public ListDef {
	public:
		ListDefList() : mV1{nullptr}, mV2{nullptr} {}
		~ListDefList() override { delete mV1; delete mV2; }
		ListDefList(ListDefList& listDefList) = delete;
		ListDefList(ListDefList&& listDefList) = delete;

		ListDefList& operator=(ListDefList& other) = delete;
		ListDefList& operator=(ListDefList&& other) = delete;

        void accept(ListDefVisitor* v) override;
        [[nodiscard]] const Def* v1() const { return mV1; }
        [[nodiscard]] const ListDef* v2() const { return mV2; }
    private:
        const Def* mV1;
        const ListDef* mV2;
    };

    struct ListDefVisitor {
        virtual void visit(ListDefEpsilon* token) = 0;
        virtual void visit(ListDefList* token) = 0;
    };

    typedef void (DestructFn)(void*);
    typedef void (ListDefAcceptFn)(void*, ListDefVisitor* v);
    struct ListDefVTable {
        DestructFn* mDestructFn1;
        DestructFn* mDestructFn2;
        ListDefAcceptFn* mAcceptFn;
    };

    inline ListDefVTable* getVTable(ListDef* obj) {
        auto** vtablePtr = reinterpret_cast<ListDefVTable**>(obj); // NOLINT(cppcoreguidelines-pro-type-reinterpret-cast)
        return *(vtablePtr);
    }
}

#endif //USIDE_LIBRARIES_ABSYN_BNF_LIST_DEF_H
