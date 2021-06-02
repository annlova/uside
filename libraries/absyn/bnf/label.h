//
// Created by Anton on 2021-05-28.
//

#ifndef USIDE_LIBRARIES_ABSYN_BNF_LABEL_H
#define USIDE_LIBRARIES_ABSYN_BNF_LABEL_H

#include "label_id.h"
#include "list_prof_item.h"

namespace absyn::bnf {
    struct Label {
        Label() = default;
        virtual ~Label() = default;
        Label(Label& grammar) = delete;
        Label(Label&& grammar) = delete;

        Label& operator=(Label& other) = delete;
        Label& operator=(Label&& other) = delete;

        virtual void accept(struct LabelVisitor& v) const = 0;
    };

    class LabelLabelId : public Label {
	public:
		LabelLabelId() : mV1{nullptr} {}
		~LabelLabelId() override { delete mV1; }
		LabelLabelId(LabelLabelId& labelLabelId) = delete;
		LabelLabelId(LabelLabelId&& labelLabelId) = delete;

		LabelLabelId& operator=(LabelLabelId& other) = delete;
		LabelLabelId& operator=(LabelLabelId&& other) = delete;

        void accept(LabelVisitor& v) const override;
        [[nodiscard]] const LabelId& v1() const { return *mV1; }
    private:
        const LabelId* mV1;
    };

    class LabelLabelIdListProfItem : public Label {
	public:
		LabelLabelIdListProfItem() : mV1{nullptr}, mV2{nullptr} {}
		~LabelLabelIdListProfItem() override { delete mV1; delete mV2; }
		LabelLabelIdListProfItem(LabelLabelIdListProfItem& labelLabelIdListProfItem) = delete;
		LabelLabelIdListProfItem(LabelLabelIdListProfItem&& labelLabelIdListProfItem) = delete;

		LabelLabelIdListProfItem& operator=(LabelLabelIdListProfItem& other) = delete;
		LabelLabelIdListProfItem& operator=(LabelLabelIdListProfItem&& other) = delete;

        void accept(LabelVisitor& v) const override;
        [[nodiscard]] const LabelId& v1() const { return *mV1; }
        [[nodiscard]] const ListProfItem& v2() const { return *mV2; }
    private:
        const LabelId* mV1;
        const ListProfItem* mV2;
    };

    class LabelDoubleLabelIdListProfItem : public Label {
	public:
		LabelDoubleLabelIdListProfItem() : mV1{nullptr}, mV2{nullptr}, mV3{nullptr} {}
		~LabelDoubleLabelIdListProfItem() override { delete mV1; delete mV2; delete mV3; }
		LabelDoubleLabelIdListProfItem(LabelDoubleLabelIdListProfItem& labelDoubleLabelIdListProfItem) = delete;
		LabelDoubleLabelIdListProfItem(LabelDoubleLabelIdListProfItem&& labelDoubleLabelIdListProfItem) = delete;

		LabelDoubleLabelIdListProfItem& operator=(LabelDoubleLabelIdListProfItem& other) = delete;
		LabelDoubleLabelIdListProfItem& operator=(LabelDoubleLabelIdListProfItem&& other) = delete;

        void accept(LabelVisitor& v) const override;
        [[nodiscard]] const LabelId& v1() const { return *mV1; }
        [[nodiscard]] const LabelId& v2() const { return *mV2; }
        [[nodiscard]] const ListProfItem& v3() const { return *mV3; }
    private:
        const LabelId* mV1;
        const LabelId* mV2;
        const ListProfItem* mV3;
    };

    struct LabelVisitor {
        virtual void visit(const LabelLabelId& token) = 0;
        virtual void visit(const LabelLabelIdListProfItem& token) = 0;
        virtual void visit(const LabelDoubleLabelIdListProfItem& token) = 0;
    };

    typedef void (DestructFn)(void*);
    typedef void (LabelAcceptFn)(void*, LabelVisitor& v);
    struct LabelVTable {
        DestructFn* mDestructFn1;
        DestructFn* mDestructFn2;
        LabelAcceptFn* mAcceptFn;
    };

    inline LabelVTable* getVTable(Label* obj) {
        auto** vtablePtr = reinterpret_cast<LabelVTable**>(obj); // NOLINT(cppcoreguidelines-pro-type-reinterpret-cast)
        return *(vtablePtr);
    }
}

#endif //USIDE_LIBRARIES_ABSYN_BNF_LABEL_H
