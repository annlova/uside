//
// Created by Anton on 2021-05-28.
//

#ifndef USIDE_LIBRARIES_ABSYN_BNF_LIST_INTEGER_H
#define USIDE_LIBRARIES_ABSYN_BNF_LIST_INTEGER_H

namespace absyn::bnf {
    struct ListInteger {
        ListInteger() = default;
        virtual ~ListInteger() = default;
        ListInteger(ListInteger& grammar) = delete;
        ListInteger(ListInteger&& grammar) = delete;

        ListInteger& operator=(ListInteger& other) = delete;
        ListInteger& operator=(ListInteger&& other) = delete;

        virtual void accept(struct ListIntegerVisitor* v) = 0;
    };

    class ListIntegerEmpty : public ListInteger {
	public:
        void accept(ListIntegerVisitor* v) override;
    };

    class ListIntegerInteger : public ListInteger {
	public:
		ListIntegerInteger() : mV1{0} {}
        void accept(ListIntegerVisitor* v) override;
        [[nodiscard]] int v1() const { return mV1; }
    private:
        int mV1;
    };

    class ListIntegerIntegerList : public ListInteger {
	public:
		ListIntegerIntegerList() : mV1{0}, mV2{nullptr} {}
		~ListIntegerIntegerList() override { delete mV2; }
		ListIntegerIntegerList(ListIntegerIntegerList& listIntegerIntegerList) = delete;
		ListIntegerIntegerList(ListIntegerIntegerList&& listIntegerIntegerList) = delete;

		ListIntegerIntegerList& operator=(ListIntegerIntegerList& other) = delete;
		ListIntegerIntegerList& operator=(ListIntegerIntegerList&& other) = delete;

        void accept(ListIntegerVisitor* v) override;
        [[nodiscard]] int v1() const { return mV1; }
        [[nodiscard]] const ListInteger* v2() const { return mV2; }
    private:
        int mV1;
        const ListInteger* mV2;
    };

    struct ListIntegerVisitor {
        virtual void visit(ListIntegerEmpty* token) = 0;
        virtual void visit(ListIntegerInteger* token) = 0;
        virtual void visit(ListIntegerIntegerList* token) = 0;
    };

    typedef void (DestructFn)(void*);
    typedef void (ListIntegerAcceptFn)(void*, ListIntegerVisitor* v);
    struct ListIntegerVTable {
        DestructFn* mDestructFn1;
        DestructFn* mDestructFn2;
        ListIntegerAcceptFn* mAcceptFn;
    };

    inline ListIntegerVTable* getVTable(ListInteger* obj) {
        auto** vtablePtr = reinterpret_cast<ListIntegerVTable**>(obj); // NOLINT(cppcoreguidelines-pro-type-reinterpret-cast)
        return *(vtablePtr);
    }
}
#endif //USIDE_LIBRARIES_ABSYN_BNF_LIST_INTEGER_H
