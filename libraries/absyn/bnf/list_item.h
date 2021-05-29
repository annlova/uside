//
// Created by Anton on 2021-05-28.
//

#ifndef USIDE_LIBRARIES_ABSYN_BNF_LIST_ITEM_H
#define USIDE_LIBRARIES_ABSYN_BNF_LIST_ITEM_H

#include "item.h"

namespace absyn::bnf {
    struct ListItem {
        ListItem() = default;
        virtual ~ListItem() = default;
        ListItem(ListItem& grammar) = delete;
        ListItem(ListItem&& grammar) = delete;

        ListItem& operator=(ListItem& other) = delete;
        ListItem& operator=(ListItem&& other) = delete;

        virtual void accept(struct ListItemVisitor* v) = 0;
    };

    class ListItemEpsilon : public ListItem {
	public:
        void accept(ListItemVisitor* v) override;
    };

    class ListItemItemList : public ListItem {
	public:
		ListItemItemList() : mV1{nullptr}, mV2{nullptr} {}
		~ListItemItemList() override { delete mV1; delete mV2; }
		ListItemItemList(ListItemItemList& listItemItemList) = delete;
		ListItemItemList(ListItemItemList&& listItemItemList) = delete;

		ListItemItemList& operator=(ListItemItemList& other) = delete;
		ListItemItemList& operator=(ListItemItemList&& other) = delete;

        void accept(ListItemVisitor* v) override;
        [[nodiscard]] const Item* v1() const { return mV1; }
        [[nodiscard]] const ListItem* v2() const { return mV2; }
    private:
        const Item* mV1;
        const ListItem* mV2;
    };

    struct ListItemVisitor {
        virtual void visit(ListItemEpsilon* token) = 0;
        virtual void visit(ListItemItemList* token) = 0;
    };

    typedef void (DestructFn)(void*);
    typedef void (ListItemAcceptFn)(void*, ListItemVisitor* v);
    struct ListItemVTable {
        DestructFn* mDestructFn1;
        DestructFn* mDestructFn2;
        ListItemAcceptFn* mAcceptFn;
    };

    inline ListItemVTable* getVTable(ListItem* obj) {
        auto** vtablePtr = reinterpret_cast<ListItemVTable**>(obj); // NOLINT(cppcoreguidelines-pro-type-reinterpret-cast)
        return *(vtablePtr);
    }
}

#endif //USIDE_LIBRARIES_ABSYN_BNF_LIST_ITEM_H
