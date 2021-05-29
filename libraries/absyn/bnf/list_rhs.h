//
// Created by Anton on 2021-05-28.
//

#ifndef USIDE_LIBRARIES_ABSYN_BNF_LIST_RHS_H
#define USIDE_LIBRARIES_ABSYN_BNF_LIST_RHS_H

#include "rhs.h"

namespace absyn::bnf {
    struct ListRHS {
        ListRHS() = default;
        virtual ~ListRHS() = default;
        ListRHS(ListRHS& grammar) = delete;
        ListRHS(ListRHS&& grammar) = delete;

        ListRHS& operator=(ListRHS& other) = delete;
        ListRHS& operator=(ListRHS&& other) = delete;

        virtual void accept(struct ListRHSVisitor* v) = 0;
    };

    class ListRHSRHS : public ListRHS {
	public:
		ListRHSRHS() : mV1{nullptr} {}
		~ListRHSRHS() override { delete mV1; }
		ListRHSRHS(ListRHSRHS& listRHSRHS) = delete;
		ListRHSRHS(ListRHSRHS&& listRHSRHS) = delete;

		ListRHSRHS& operator=(ListRHSRHS& other) = delete;
		ListRHSRHS& operator=(ListRHSRHS&& other) = delete;

        void accept(ListRHSVisitor* v) override;
        [[nodiscard]] const RHS* v1() const { return mV1; }
    private:
        const RHS* mV1;
    };

    class ListRHSList : public ListRHS {
	public:
		ListRHSList() : mV1{nullptr}, mV2{nullptr} {}
		~ListRHSList() override { delete mV1; delete mV2; }
		ListRHSList(ListRHSList& listRHSList) = delete;
		ListRHSList(ListRHSList&& listRHSList) = delete;

		ListRHSList& operator=(ListRHSList& other) = delete;
		ListRHSList& operator=(ListRHSList&& other) = delete;

        void accept(ListRHSVisitor* v) override;
        [[nodiscard]] const RHS* v1() const { return mV1; }
        [[nodiscard]] const ListRHS* v2() const { return mV2; }
    private:
        const RHS* mV1;
        const ListRHS* mV2;
    };

    struct ListRHSVisitor {
        virtual void visit(ListRHSRHS* token) = 0;
        virtual void visit(ListRHSList* token) = 0;
    };

    typedef void (DestructFn)(void*);
    typedef void (ListRHSAcceptFn)(void*, ListRHSVisitor* v);
    struct ListRHSVTable {
        DestructFn* mDestructFn1;
        DestructFn* mDestructFn2;
        ListRHSAcceptFn* mAcceptFn;
    };

    inline ListRHSVTable* getVTable(ListRHS* obj) {
        auto** vtablePtr = reinterpret_cast<ListRHSVTable**>(obj); // NOLINT(cppcoreguidelines-pro-type-reinterpret-cast)
        return *(vtablePtr);
    }
}

#endif //USIDE_LIBRARIES_ABSYN_BNF_LIST_RHS_H
