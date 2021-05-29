//
// Created by Anton on 2021-05-28.
//

#ifndef USIDE_SRC_PARSER_H_BNF_ABSYN_RHS_H
#define USIDE_SRC_PARSER_H_BNF_ABSYN_RHS_H

#include "list_item.h"

namespace absyn::bnf {
    struct RHS {
        RHS() = default;
        virtual ~RHS() = default;
        RHS(RHS& grammar) = delete;
        RHS(RHS&& grammar) = delete;

        RHS& operator=(RHS& other) = delete;
        RHS& operator=(RHS&& other) = delete;

        virtual void accept(struct RHSVisitor* v) = 0;
    };

    class RHSListItem : public RHS {
	public:
		RHSListItem() : mV1{nullptr} {}
		~RHSListItem() override { delete mV1; }
		RHSListItem(RHSListItem& rHSListItem) = delete;
		RHSListItem(RHSListItem&& rHSListItem) = delete;

		RHSListItem& operator=(RHSListItem& other) = delete;
		RHSListItem& operator=(RHSListItem&& other) = delete;

        void accept(RHSVisitor* v) override;
        [[nodiscard]] const ListItem* v1() const { return mV1; }
    private:
        const ListItem* mV1;
    };

    struct RHSVisitor {
        virtual void visit(RHSListItem* token) = 0;
    };

    typedef void (DestructFn)(void*);
    typedef void (RHSAcceptFn)(void*, RHSVisitor* v);
    struct RHSVTable {
        DestructFn* mDestructFn1;
        DestructFn* mDestructFn2;
        RHSAcceptFn* mAcceptFn;
    };

    inline RHSVTable* getVTable(RHS* obj) {
        auto** vtablePtr = reinterpret_cast<RHSVTable**>(obj); // NOLINT(cppcoreguidelines-pro-type-reinterpret-cast)
        return *(vtablePtr);
    }
}

#endif //USIDE_SRC_PARSER_H_BNF_ABSYN_RHS_H
