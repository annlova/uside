//
// Created by Anton on 2021-05-28.
//

#ifndef USIDE_LIBRARIES_ABSYN_BNF_CAT_H
#define USIDE_LIBRARIES_ABSYN_BNF_CAT_H

namespace absyn::bnf {
    struct Cat {
        Cat() = default;
        virtual ~Cat() = default;
        Cat(Cat& cat) = delete;
        Cat(Cat&& cat) = delete;

        Cat& operator=(Cat& other) = delete;
        Cat& operator=(Cat&& other) = delete;

        virtual void accept(struct CatVisitor* v) = 0;
    };

    class CatSquare : public Cat {
	public:
		CatSquare() : mV1{nullptr} {}
		~CatSquare() override { delete mV1; }
		CatSquare(CatSquare& catSquare) = delete;
		CatSquare(CatSquare&& catSquare) = delete;

		CatSquare& operator=(CatSquare& other) = delete;
		CatSquare& operator=(CatSquare&& other) = delete;

        void accept(CatVisitor* v) override;
        [[nodiscard]] const Cat* v1() const { return mV1; }
    private:
        const Cat* mV1;
    };

    class CatIdent : public Cat {
	public:
		CatIdent() : mV1{nullptr} {}
		~CatIdent() override { delete[] mV1; }
		CatIdent(CatIdent& catIdent) = delete;
		CatIdent(CatIdent&& catIdent) = delete;

		CatIdent& operator=(CatIdent& other) = delete;
		CatIdent& operator=(CatIdent&& other) = delete;

        void accept(CatVisitor* v) override;
        [[nodiscard]] const char* v1() const { return mV1; }
    private:
        const char* mV1;
    };

    struct CatVisitor {
        virtual void visit(CatSquare* token) = 0;
        virtual void visit(CatIdent* token) = 0;
    };

    typedef void (DestructFn)(void*);
    typedef void (CatAcceptFn)(void*, CatVisitor* v);
    struct CatVTable {
        DestructFn* mDestructFn1;
        DestructFn* mDestructFn2;
        CatAcceptFn* mAcceptFn;
    };

    inline CatVTable* getVTable(Cat* obj) {
        auto** vtablePtr = reinterpret_cast<CatVTable**>(obj); // NOLINT(cppcoreguidelines-pro-type-reinterpret-cast)
        return *(vtablePtr);
    }
}

#endif //USIDE_LIBRARIES_ABSYN_BNF_CAT_H
