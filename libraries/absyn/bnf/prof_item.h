//
// Created by Anton on 2021-05-28.
//

#ifndef USIDE_LIBRARIES_ABSYN_BNF_PROF_ITEM_H
#define USIDE_LIBRARIES_ABSYN_BNF_PROF_ITEM_H

#include "list_int_list.h"
#include "list_integer.h"

namespace absyn::bnf {
    struct ProfItem {
        ProfItem() = default;
        virtual ~ProfItem() = default;
        ProfItem(ProfItem& grammar) = delete;
        ProfItem(ProfItem&& grammar) = delete;

        ProfItem& operator=(ProfItem& other) = delete;
        ProfItem& operator=(ProfItem&& other) = delete;

        virtual void accept(struct ProfItemVisitor* v) = 0;
    };

    class ProfItemBrackets : public ProfItem {
	public:
		ProfItemBrackets() : mV1{nullptr}, mV2{nullptr} {}
		~ProfItemBrackets() override { delete mV1; delete mV2; }
		ProfItemBrackets(ProfItemBrackets& profItemBrackets) = delete;
		ProfItemBrackets(ProfItemBrackets&& profItemBrackets) = delete;

		ProfItemBrackets& operator=(ProfItemBrackets& other) = delete;
		ProfItemBrackets& operator=(ProfItemBrackets&& other) = delete;

        void accept(ProfItemVisitor* v) override;
        [[nodiscard]] const ListIntList* v1() const { return mV1; }
        [[nodiscard]] const ListInteger* v2() const { return mV2; }
    private:
        const ListIntList* mV1;
        const ListInteger* mV2;
    };

    struct ProfItemVisitor {
        virtual void visit(ProfItemBrackets* token) = 0;
    };

    typedef void (DestructFn)(void*);
    typedef void (ProfItemAcceptFn)(void*, ProfItemVisitor* v);
    struct ProfItemVTable {
        DestructFn* mDestructFn1;
        DestructFn* mDestructFn2;
        ProfItemAcceptFn* mAcceptFn;
    };

    inline ProfItemVTable* getVTable(ProfItem* obj) {
        auto** vtablePtr = reinterpret_cast<ProfItemVTable**>(obj); // NOLINT(cppcoreguidelines-pro-type-reinterpret-cast)
        return *(vtablePtr);
    }
}

#endif //USIDE_LIBRARIES_ABSYN_BNF_PROF_ITEM_H
