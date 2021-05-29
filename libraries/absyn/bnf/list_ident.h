//
// Created by Anton on 2021-05-28.
//

#ifndef USIDE_LIBRARIES_ABSYN_BNF_LIST_IDENT_H
#define USIDE_LIBRARIES_ABSYN_BNF_LIST_IDENT_H

namespace absyn::bnf {
    struct ListIdent {
        ListIdent() = default;
        virtual ~ListIdent() = default;
        ListIdent(ListIdent& grammar) = delete;
        ListIdent(ListIdent&& grammar) = delete;

        ListIdent& operator=(ListIdent& other) = delete;
        ListIdent& operator=(ListIdent&& other) = delete;

        virtual void accept(struct ListIdentVisitor* v) = 0;
    };

    class ListIdentIdent : public ListIdent {
	public:
		ListIdentIdent() : mV1{nullptr} {}
		~ListIdentIdent() override { delete[] mV1; }
		ListIdentIdent(ListIdentIdent& listIdentIdent) = delete;
		ListIdentIdent(ListIdentIdent&& listIdentIdent) = delete;

		ListIdentIdent& operator=(ListIdentIdent& other) = delete;
		ListIdentIdent& operator=(ListIdentIdent&& other) = delete;

        void accept(ListIdentVisitor* v) override;
        [[nodiscard]] const char* v1() const { return mV1; }
    private:
        const char* mV1;
    };

    class ListIdentIdentList : public ListIdent {
	public:
		ListIdentIdentList() : mV1{nullptr}, mV2{nullptr} {}
		~ListIdentIdentList() override { delete[] mV1; delete mV2; }
		ListIdentIdentList(ListIdentIdentList& listIdentIdentList) = delete;
		ListIdentIdentList(ListIdentIdentList&& listIdentIdentList) = delete;

		ListIdentIdentList& operator=(ListIdentIdentList& other) = delete;
		ListIdentIdentList& operator=(ListIdentIdentList&& other) = delete;

        void accept(ListIdentVisitor* v) override;
        [[nodiscard]] const char* v1() const { return mV1; }
        [[nodiscard]] const ListIdent* v2() const { return mV2; }
    private:
        const char* mV1;
        const ListIdent* mV2;
    };

    struct ListIdentVisitor {
        virtual void visit(ListIdentIdent* token) = 0;
        virtual void visit(ListIdentIdentList* token) = 0;
    };

    typedef void (DestructFn)(void*);
    typedef void (ListIdentAcceptFn)(void*, ListIdentVisitor* v);
    struct ListIdentVTable {
        DestructFn* mDestructFn1;
        DestructFn* mDestructFn2;
        ListIdentAcceptFn* mAcceptFn;
    };

    inline ListIdentVTable* getVTable(ListIdent* obj) {
        auto** vtablePtr = reinterpret_cast<ListIdentVTable**>(obj); // NOLINT(cppcoreguidelines-pro-type-reinterpret-cast)
        return *(vtablePtr);
    }
}

#endif //USIDE_LIBRARIES_ABSYN_BNF_LIST_IDENT_H
