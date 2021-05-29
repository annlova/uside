//
// Created by Anton on 2021-05-28.
//

#ifndef USIDE_LIBRARIES_ABSYN_BNF_LIST_INT_LIST_H
#define USIDE_LIBRARIES_ABSYN_BNF_LIST_INT_LIST_H

#include "int_list.h"

namespace absyn::bnf {
    struct ListIntList {
        ListIntList() = default;
        virtual ~ListIntList() = default;
        ListIntList(ListIntList& grammar) = delete;
        ListIntList(ListIntList&& grammar) = delete;

        ListIntList& operator=(ListIntList& other) = delete;
        ListIntList& operator=(ListIntList&& other) = delete;

        virtual void accept(struct ListIntListVisitor* v) = 0;
    };

    class ListIntListEpsilon : public ListIntList {
	public:
        void accept(ListIntListVisitor* v) override;
    };

    class ListIntListIntList : public ListIntList {
	public:
		ListIntListIntList() : mV1{nullptr} {}
		~ListIntListIntList() override { delete mV1; }
		ListIntListIntList(ListIntListIntList& listIntListIntList) = delete;
		ListIntListIntList(ListIntListIntList&& listIntListIntList) = delete;

		ListIntListIntList& operator=(ListIntListIntList& other) = delete;
		ListIntListIntList& operator=(ListIntListIntList&& other) = delete;

        void accept(ListIntListVisitor* v) override;
        [[nodiscard]] const IntList* v1() const { return mV1; }
    private:
        const IntList* mV1;
    };

    class ListIntListIntListList : public ListIntList {
	public:
		ListIntListIntListList() : mV1{nullptr}, mV2{nullptr} {}
		~ListIntListIntListList() override { delete mV1; delete mV2; }
		ListIntListIntListList(ListIntListIntListList& listIntListIntListList) = delete;
		ListIntListIntListList(ListIntListIntListList&& listIntListIntListList) = delete;

		ListIntListIntListList& operator=(ListIntListIntListList& other) = delete;
		ListIntListIntListList& operator=(ListIntListIntListList&& other) = delete;

        void accept(ListIntListVisitor* v) override;
        [[nodiscard]] const IntList* v1() const { return mV1; }
        [[nodiscard]] const ListIntList* v2() const { return mV2; }
    private:
        const IntList* mV1;
        const ListIntList* mV2;
    };

    struct ListIntListVisitor {
        virtual void visit(ListIntListEpsilon* token) = 0;
        virtual void visit(ListIntListIntList* token) = 0;
        virtual void visit(ListIntListIntListList* token) = 0;
    };

    typedef void (DestructFn)(void*);
    typedef void (ListIntListAcceptFn)(void*, ListIntListVisitor* v);
    struct ListIntListVTable {
        DestructFn* mDestructFn1;
        DestructFn* mDestructFn2;
        ListIntListAcceptFn* mAcceptFn;
    };

    inline ListIntListVTable* getVTable(ListIntList* obj) {
        auto** vtablePtr = reinterpret_cast<ListIntListVTable**>(obj); // NOLINT(cppcoreguidelines-pro-type-reinterpret-cast)
        return *(vtablePtr);
    }
}

#endif //USIDE_LIBRARIES_ABSYN_BNF_LIST_INT_LIST_H
