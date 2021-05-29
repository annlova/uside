//
// Created by Anton on 2021-05-28.
//

#ifndef USIDE_LIBRARIES_ABSYN_BNF_DEF_H
#define USIDE_LIBRARIES_ABSYN_BNF_DEF_H

#include "label.h"
#include "cat.h"
#include "list_item.h"
#include "reg.h"
#include "list_ident.h"
#include "minimum_size.h"
#include "list_rhs.h"
#include "list_string.h"

namespace absyn::bnf {
    struct Def {
        Def() = default;
        virtual ~Def() = default;
        Def(Def& def) = delete;
        Def(Def&& def) = delete;

        Def& operator=(Def& other) = delete;
        Def& operator=(Def&& other) = delete;

        virtual void accept(struct DefVisitor* v) = 0;
    };

    class DefLabel : public Def {
	public:
		DefLabel() : mV1{nullptr}, mV2{nullptr}, mV3{nullptr} {}
		~DefLabel() override { delete mV1; delete mV2; delete mV3; }
		DefLabel(DefLabel& defLabel) = delete;
		DefLabel(DefLabel&& defLabel) = delete;

		DefLabel& operator=(DefLabel& other) = delete;
		DefLabel& operator=(DefLabel&& other) = delete;

        void accept(DefVisitor* v) override;
        [[nodiscard]] const Label* v1() const { return mV1; }
        [[nodiscard]] const Cat* v2() const { return mV2; }
        [[nodiscard]] const ListItem* v3() const { return mV3; }
    private:
        const Label* mV1;
        const Cat* mV2;
        const ListItem* mV3;
    };

    class DefLineComment : public Def {
	public:
		DefLineComment() : mV1{nullptr} {}
		~DefLineComment() override { delete[] mV1; }
		DefLineComment(DefLineComment& defLineComment) = delete;
		DefLineComment(DefLineComment&& defLineComment) = delete;

		DefLineComment& operator=(DefLineComment& other) = delete;
		DefLineComment& operator=(DefLineComment&& other) = delete;

        void accept(DefVisitor* v) override;
        [[nodiscard]] const char* v1() const { return mV1; }
    private:
        const char* mV1;
    };

    class DefBlockComment : public Def {
	public:
		DefBlockComment() : mV1{nullptr}, mV2{nullptr} {}
		~DefBlockComment() override { delete[] mV1; delete[] mV2; }
		DefBlockComment(DefBlockComment& defBlockComment) = delete;
		DefBlockComment(DefBlockComment&& defBlockComment) = delete;

		DefBlockComment& operator=(DefBlockComment& other) = delete;
		DefBlockComment& operator=(DefBlockComment&& other) = delete;

        void accept(DefVisitor* v) override;
        [[nodiscard]] const char* v1() const { return mV1; }
        [[nodiscard]] const char* v2() const { return mV2; }
    private:
        const char* mV1;
        const char* mV2;
    };

    class DefInternal : public Def {
	public:
		DefInternal() : mV1{nullptr}, mV2{nullptr}, mV3{nullptr} {}
		~DefInternal() override { delete mV1; delete mV2; delete mV3; }
		DefInternal(DefInternal& defInternal) = delete;
		DefInternal(DefInternal&& defInternal) = delete;

		DefInternal& operator=(DefInternal& other) = delete;
		DefInternal& operator=(DefInternal&& other) = delete;

        void accept(DefVisitor* v) override;
        [[nodiscard]] const Label* v1() const { return mV1; }
        [[nodiscard]] const Cat* v2() const { return mV2; }
        [[nodiscard]] const ListItem* v3() const { return mV3; }
    private:
        const Label* mV1;
        const Cat* mV2;
        const ListItem* mV3;
    };

    class DefToken : public Def {
	public:
		DefToken() : mV1{nullptr}, mV2{nullptr} {}
		~DefToken() override { delete[] mV1; delete mV2; }
		DefToken(DefToken& defToken) = delete;
		DefToken(DefToken&& defToken) = delete;

		DefToken& operator=(DefToken& other) = delete;
		DefToken& operator=(DefToken&& other) = delete;

        void accept(DefVisitor* v) override;
        [[nodiscard]] const char* v1() const { return mV1; }
        [[nodiscard]] const Reg* v2() const { return mV2; }
    private:
        const char* mV1;
        const Reg* mV2;
    };

    class DefPositionToken : public Def {
	public:
		DefPositionToken() : mV1{nullptr}, mV2{nullptr} {}
		~DefPositionToken() override { delete[] mV1; delete mV2; }
		DefPositionToken(DefPositionToken& defPositionToken) = delete;
		DefPositionToken(DefPositionToken&& defPositionToken) = delete;

		DefPositionToken& operator=(DefPositionToken& other) = delete;
		DefPositionToken& operator=(DefPositionToken&& other) = delete;

        void accept(DefVisitor* v) override;
        [[nodiscard]] const char* v1() const { return mV1; }
        [[nodiscard]] const Reg* v2() const { return mV2; }
    private:
        const char* mV1;
        const Reg* mV2;
    };

    class DefEntryPoints : public Def {
	public:
		DefEntryPoints() : mV1{nullptr} {}
		~DefEntryPoints() override { delete mV1; }
		DefEntryPoints(DefEntryPoints& defEntryPoints) = delete;
		DefEntryPoints(DefEntryPoints&& defEntryPoints) = delete;

		DefEntryPoints& operator=(DefEntryPoints& other) = delete;
		DefEntryPoints& operator=(DefEntryPoints&& other) = delete;

        void accept(DefVisitor* v) override;
        [[nodiscard]] const ListIdent* v1() const { return mV1; }
    private:
        const ListIdent* mV1;
    };

    class DefSeparator : public Def {
	public:
		DefSeparator() : mV1{nullptr}, mV2{nullptr}, mV3{nullptr} {}
		~DefSeparator() override { delete mV1; delete mV2; delete[] mV3; }
		DefSeparator(DefSeparator& defSeparator) = delete;
		DefSeparator(DefSeparator&& defSeparator) = delete;

		DefSeparator& operator=(DefSeparator& other) = delete;
		DefSeparator& operator=(DefSeparator&& other) = delete;

        void accept(DefVisitor* v) override;
        [[nodiscard]] const MinimumSize* v1() const { return mV1; }
        [[nodiscard]] const Cat* v2() const { return mV2; }
        [[nodiscard]] const char* v3() const { return mV3; }
    private:
        const MinimumSize* mV1;
        const Cat* mV2;
        const char* mV3;
    };

    class DefTerminator : public Def {
	public:
		DefTerminator() : mV1{nullptr}, mV2{nullptr}, mV3{nullptr} {}
		~DefTerminator() override { delete mV1; delete mV2; delete[] mV3; }
		DefTerminator(DefTerminator& defTerminator) = delete;
		DefTerminator(DefTerminator&& defTerminator) = delete;

		DefTerminator& operator=(DefTerminator& other) = delete;
		DefTerminator& operator=(DefTerminator&& other) = delete;

        void accept(DefVisitor* v) override;
        [[nodiscard]] const MinimumSize* v1() const { return mV1; }
        [[nodiscard]] const Cat* v2() const { return mV2; }
        [[nodiscard]] const char* v3() const { return mV3; }
    private:
        const MinimumSize* mV1;
        const Cat* mV2;
        const char* mV3;
    };

    class DefCoercions : public Def {
	public:
		DefCoercions() : mV1{nullptr}, mV2{0} {}
		~DefCoercions() override { delete[] mV1; }
		DefCoercions(DefCoercions& defCoercions) = delete;
		DefCoercions(DefCoercions&& defCoercions) = delete;

		DefCoercions& operator=(DefCoercions& other) = delete;
		DefCoercions& operator=(DefCoercions&& other) = delete;

        void accept(DefVisitor* v) override;
        [[nodiscard]] const char* v1() const { return mV1; }
        [[nodiscard]] int v2() const { return mV2; }
    private:
        const char* mV1;
        int mV2;
    };

    class DefRules : public Def {
	public:
		DefRules() : mV1{nullptr}, mV2{nullptr} {}
		~DefRules() override { delete[] mV1; }
		DefRules(DefRules& defRules) = delete;
		DefRules(DefRules&& defRules) = delete;

		DefRules& operator=(DefRules& other) = delete;
		DefRules& operator=(DefRules&& other) = delete;

        void accept(DefVisitor* v) override;
        [[nodiscard]] const char* v1() const { return mV1; }
        [[nodiscard]] const ListRHS* v2() const { return mV2; }
    private:
        const char* mV1;
        const ListRHS* mV2;
    };

    class DefLayout : public Def {
	public:
		DefLayout() : mV1{nullptr} {}
		~DefLayout() override { delete mV1; }
		DefLayout(DefLayout& defLayout) = delete;
		DefLayout(DefLayout&& defLayout) = delete;

		DefLayout& operator=(DefLayout& other) = delete;
		DefLayout& operator=(DefLayout&& other) = delete;

        void accept(DefVisitor* v) override;
        [[nodiscard]] const ListString* v1() const { return mV1; }
    private:
        const ListString* mV1;
    };

    class DefLayoutStop : public Def {
	public:
		DefLayoutStop() : mV1{nullptr} {}
		~DefLayoutStop() override { delete mV1; }
		DefLayoutStop(DefLayoutStop& defLayoutStop) = delete;
		DefLayoutStop(DefLayoutStop&& defLayoutStop) = delete;

		DefLayoutStop& operator=(DefLayoutStop& other) = delete;
		DefLayoutStop& operator=(DefLayoutStop&& other) = delete;

        void accept(DefVisitor* v) override;
        [[nodiscard]] const ListString* v1() const { return mV1; }
    private:
        const ListString* mV1;
    };

    class DefLayoutTopLevel : public Def {
	public:
        void accept(DefVisitor* v) override;
    };

    struct DefVisitor {
        virtual void visit(DefLabel* v) = 0;
        virtual void visit(DefLineComment* v) = 0;
        virtual void visit(DefBlockComment* v) = 0;
        virtual void visit(DefInternal* v) = 0;
        virtual void visit(DefToken* v) = 0;
        virtual void visit(DefPositionToken* v) = 0;
        virtual void visit(DefEntryPoints* v) = 0;
        virtual void visit(DefSeparator* v) = 0;
        virtual void visit(DefTerminator* v) = 0;
        virtual void visit(DefCoercions* v) = 0;
        virtual void visit(DefRules* v) = 0;
        virtual void visit(DefLayout* v) = 0;
        virtual void visit(DefLayoutStop* v) = 0;
        virtual void visit(DefLayoutTopLevel* v) = 0;
    };

    typedef void (DestructFn)(void*);
    typedef void (DefAcceptFn)(void*, DefVisitor* v);
    struct DefVTable {
        DestructFn* mDestructFn1;
        DestructFn* mDestructFn2;
        DefAcceptFn* mAcceptFn;
    };

    inline DefVTable* getVTable(Def* obj) {
        auto** vtablePtr = reinterpret_cast<DefVTable**>(obj); // NOLINT(cppcoreguidelines-pro-type-reinterpret-cast)
        return *(vtablePtr);
    }
}

#endif //USIDE_LIBRARIES_ABSYN_BNF_DEF_H
