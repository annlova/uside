//
// Created by Anton on 2021-05-28.
//

#ifndef USIDE_LIBRARIES_ABSYN_BNF_INT_LIST_H
#define USIDE_LIBRARIES_ABSYN_BNF_INT_LIST_H

#include "list_integer.h"

namespace absyn::bnf {
    struct IntList {
        IntList() = default;
        virtual ~IntList() = default;
        IntList(IntList& grammar) = delete;
        IntList(IntList&& grammar) = delete;

        IntList& operator=(IntList& other) = delete;
        IntList& operator=(IntList&& other) = delete;

        virtual void accept(struct IntListVisitor* v) = 0;
    };

    class IntListListInteger : public IntList {
	public:
		IntListListInteger() : mV1{nullptr} {}
		~IntListListInteger() override { delete mV1; }
		IntListListInteger(IntListListInteger& intListListInteger) = delete;
		IntListListInteger(IntListListInteger&& intListListInteger) = delete;

		IntListListInteger& operator=(IntListListInteger& other) = delete;
		IntListListInteger& operator=(IntListListInteger&& other) = delete;

        void accept(IntListVisitor* v) override;
        [[nodiscard]] const ListInteger* v1() const { return mV1; }
    private:
        const ListInteger* mV1;
    };

    struct IntListVisitor {
        virtual void visit(IntListListInteger* token) = 0;
    };

    typedef void (DestructFn)(void*);
    typedef void (IntListAcceptFn)(void*, IntListVisitor* v);
    struct IntListVTable {
        DestructFn* mDestructFn1;
        DestructFn* mDestructFn2;
        IntListAcceptFn* mAcceptFn;
    };

    inline IntListVTable* getVTable(IntList* obj) {
        auto** vtablePtr = reinterpret_cast<IntListVTable**>(obj); // NOLINT(cppcoreguidelines-pro-type-reinterpret-cast)
        return *(vtablePtr);
    }
}

#endif //USIDE_LIBRARIES_ABSYN_BNF_INT_LIST_H
