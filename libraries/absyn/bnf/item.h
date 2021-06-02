//
// Created by Anton on 2021-05-28.
//

#ifndef USIDE_LIBRARIES_ABSYN_BNF_ITEM_H
#define USIDE_LIBRARIES_ABSYN_BNF_ITEM_H

#include "cat.h"

namespace absyn::bnf {
    struct Item {
        Item() = default;
        virtual ~Item() = default;
        Item(Item& grammar) = delete;
        Item(Item&& grammar) = delete;

        Item& operator=(Item& other) = delete;
        Item& operator=(Item&& other) = delete;

        virtual void accept(struct ItemVisitor& v) const = 0;
    };

    class ItemString : public Item {
	public:
		ItemString() : mV1{nullptr} {}
		~ItemString() override { delete[] mV1; }
		ItemString(ItemString& itemString) = delete;
		ItemString(ItemString&& itemString) = delete;

		ItemString& operator=(ItemString& other) = delete;
		ItemString& operator=(ItemString&& other) = delete;

        void accept(ItemVisitor& v) const override;
        [[nodiscard]] const char* v1() const { return mV1; }
    private:
        const char* mV1;
    };

    class ItemCat : public Item {
	public:
		ItemCat() : mV1{nullptr} {}
		~ItemCat() override { delete mV1; }
		ItemCat(ItemCat& itemCat) = delete;
		ItemCat(ItemCat&& itemCat) = delete;

		ItemCat& operator=(ItemCat& other) = delete;
		ItemCat& operator=(ItemCat&& other) = delete;

        void accept(ItemVisitor& v) const override;
        [[nodiscard]] const Cat& v1() const { return *mV1; }
    private:
        const Cat* mV1;
    };

    struct ItemVisitor {
        virtual void visit(const ItemString& token) = 0;
        virtual void visit(const ItemCat& token) = 0;
    };

    typedef void (DestructFn)(void*);
    typedef void (ItemAcceptFn)(void*, ItemVisitor& v);
    struct ItemVTable {
        DestructFn* mDestructFn1;
        DestructFn* mDestructFn2;
        ItemAcceptFn* mAcceptFn;
    };

    inline ItemVTable* getVTable(Item* obj) {
        auto** vtablePtr = reinterpret_cast<ItemVTable**>(obj); // NOLINT(cppcoreguidelines-pro-type-reinterpret-cast)
        return *(vtablePtr);
    }
}

#endif //USIDE_LIBRARIES_ABSYN_BNF_ITEM_H
