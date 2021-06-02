//
// Created by Anton on 2021-05-28.
//

#ifndef USIDE_LIBRARIES_ABSYN_BNF_LIST_STRING_H
#define USIDE_LIBRARIES_ABSYN_BNF_LIST_STRING_H

namespace absyn::bnf {
    struct ListString {
        ListString() = default;
        virtual ~ListString() = default;
        ListString(ListString& grammar) = delete;
        ListString(ListString&& grammar) = delete;

        ListString& operator=(ListString& other) = delete;
        ListString& operator=(ListString&& other) = delete;

        virtual void accept(struct ListStringVisitor& v) const = 0;
    };

    class ListStringString : public ListString {
	public:
		ListStringString() : mV1{nullptr} {}
		~ListStringString() override { delete[] mV1; }
		ListStringString(ListStringString& listStringString) = delete;
		ListStringString(ListStringString&& listStringString) = delete;

		ListStringString& operator=(ListStringString& other) = delete;
		ListStringString& operator=(ListStringString&& other) = delete;

        void accept(ListStringVisitor& v) const override;
        [[nodiscard]] const char* v1() const { return mV1; }
    private:
        const char* mV1;
    };

    class ListStringList : public ListString {
	public:
		ListStringList() : mV1{nullptr}, mV2{nullptr} {}
		~ListStringList() override { delete[] mV1; delete mV2; }
		ListStringList(ListStringList& listStringList) = delete;
		ListStringList(ListStringList&& listStringList) = delete;

		ListStringList& operator=(ListStringList& other) = delete;
		ListStringList& operator=(ListStringList&& other) = delete;

        void accept(ListStringVisitor& v) const override;
        [[nodiscard]] const char* v1() const { return mV1; }
        [[nodiscard]] const ListString& v2() const { return *mV2; }
    private:
        const char* mV1;
        const ListString* mV2;
    };

    struct ListStringVisitor {
        virtual void visit(const ListStringString& token) = 0;
        virtual void visit(const ListStringList& token) = 0;
    };

    typedef void (DestructFn)(void*);
    typedef void (ListStringAcceptFn)(void*, ListStringVisitor& v);
    struct ListStringVTable {
        DestructFn* mDestructFn1;
        DestructFn* mDestructFn2;
        ListStringAcceptFn* mAcceptFn;
    };

    inline ListStringVTable* getVTable(ListString* obj) {
        auto** vtablePtr = reinterpret_cast<ListStringVTable**>(obj); // NOLINT(cppcoreguidelines-pro-type-reinterpret-cast)
        return *(vtablePtr);
    }
}

#endif //USIDE_LIBRARIES_ABSYN_BNF_LIST_STRING_H
