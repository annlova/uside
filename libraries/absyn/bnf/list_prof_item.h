//
// Created by Anton on 2021-05-28.
//

#ifndef USIDE_LIBRARIES_ABSYN_BNF_LIST_PROF_ITEM_H
#define USIDE_LIBRARIES_ABSYN_BNF_LIST_PROF_ITEM_H

#include "prof_item.h"

namespace absyn::bnf {
    struct ListProfItem {
        ListProfItem() = default;
        virtual ~ListProfItem() = default;
        ListProfItem(ListProfItem& grammar) = delete;
        ListProfItem(ListProfItem&& grammar) = delete;

        ListProfItem& operator=(ListProfItem& other) = delete;
        ListProfItem& operator=(ListProfItem&& other) = delete;

        virtual void accept(struct ListProfItemVisitor* v) = 0;
    };

    class ListProfItemProfItem : public ListProfItem {
	public:
		ListProfItemProfItem() : mV1{nullptr} {}
		~ListProfItemProfItem() override { delete mV1; }
		ListProfItemProfItem(ListProfItemProfItem& listProfItemProfItem) = delete;
		ListProfItemProfItem(ListProfItemProfItem&& listProfItemProfItem) = delete;

		ListProfItemProfItem& operator=(ListProfItemProfItem& other) = delete;
		ListProfItemProfItem& operator=(ListProfItemProfItem&& other) = delete;

        void accept(ListProfItemVisitor* v) override;
        [[nodiscard]] const ProfItem* v1() const { return mV1; }
    private:
        const ProfItem* mV1;
    };

    class ListProfItemList : public ListProfItem {
	public:
		ListProfItemList() : mV1{nullptr}, mV2{nullptr} {}
		~ListProfItemList() override { delete mV1; delete mV2; }
		ListProfItemList(ListProfItemList& listProfItemList) = delete;
		ListProfItemList(ListProfItemList&& listProfItemList) = delete;

		ListProfItemList& operator=(ListProfItemList& other) = delete;
		ListProfItemList& operator=(ListProfItemList&& other) = delete;

        void accept(ListProfItemVisitor* v) override;
        [[nodiscard]] const ProfItem* v1() const { return mV1; }
        [[nodiscard]] const ListProfItem* v2() const { return mV2; }
    private:
        const ProfItem* mV1;
        const ListProfItem* mV2;
    };

    struct ListProfItemVisitor {
        virtual void visit(ListProfItemProfItem* token) = 0;
        virtual void visit(ListProfItemList* token) = 0;
    };

    typedef void (DestructFn)(void*);
    typedef void (ListProfItemAcceptFn)(void*, ListProfItemVisitor* v);
    struct ListProfItemVTable {
        DestructFn* mDestructFn1;
        DestructFn* mDestructFn2;
        ListProfItemAcceptFn* mAcceptFn;
    };

    inline ListProfItemVTable* getVTable(ListProfItem* obj) {
        auto** vtablePtr = reinterpret_cast<ListProfItemVTable**>(obj); // NOLINT(cppcoreguidelines-pro-type-reinterpret-cast)
        return *(vtablePtr);
    }
}


#endif //USIDE_LIBRARIES_ABSYN_BNF_LIST_PROF_ITEM_H
