//
// Created by Anton on 2021-05-28.
//

#ifndef USIDE_LIBRARIES_ABSYN_BNF_LABEL_ID_H
#define USIDE_LIBRARIES_ABSYN_BNF_LABEL_ID_H

namespace absyn::bnf {
    struct LabelId {
        LabelId() = default;
        virtual ~LabelId() = default;
        LabelId(LabelId& grammar) = delete;
        LabelId(LabelId&& grammar) = delete;

        LabelId& operator=(LabelId& other) = delete;
        LabelId& operator=(LabelId&& other) = delete;

        virtual void accept(struct LabelIdVisitor* v) = 0;
    };

    class LabelIdIdent : public LabelId {
	public:
		LabelIdIdent() : mV1{nullptr} {}
		~LabelIdIdent() override { delete[] mV1; }
		LabelIdIdent(LabelIdIdent& labelIdIdent) = delete;
		LabelIdIdent(LabelIdIdent&& labelIdIdent) = delete;

		LabelIdIdent& operator=(LabelIdIdent& other) = delete;
		LabelIdIdent& operator=(LabelIdIdent&& other) = delete;

        void accept(LabelIdVisitor* v) override;
        [[nodiscard]] const char* v1() const { return mV1; }
    private:
        const char* mV1;
    };

    class LabelIdUnderscore : public LabelId {
	public:
        void accept(LabelIdVisitor* v) override;
    };

    class LabelIdSquareBrackets : public LabelId {
	public:
        void accept(LabelIdVisitor* v) override;
    };

    class LabelIdBracketsColon : public LabelId {
	public:
        void accept(LabelIdVisitor* v) override;
    };

    class LabelIdBracketsColonSquare : public LabelId {
	public:
        void accept(LabelIdVisitor* v) override;
    };

    struct LabelIdVisitor {
        virtual void visit(LabelIdIdent* token) = 0;
        virtual void visit(LabelIdUnderscore* token) = 0;
        virtual void visit(LabelIdSquareBrackets* token) = 0;
        virtual void visit(LabelIdBracketsColon* token) = 0;
        virtual void visit(LabelIdBracketsColonSquare* token) = 0;
    };

    typedef void (DestructFn)(void*);
    typedef void (LabelIdAcceptFn)(void*, LabelIdVisitor* v);
    struct LabelIdVTable {
        DestructFn* mDestructFn1;
        DestructFn* mDestructFn2;
        LabelIdAcceptFn* mAcceptFn;
    };

    inline LabelIdVTable* getVTable(LabelId* obj) {
        auto** vtablePtr = reinterpret_cast<LabelIdVTable**>(obj); // NOLINT(cppcoreguidelines-pro-type-reinterpret-cast)
        return *(vtablePtr);
    }
}

#endif //USIDE_LIBRARIES_ABSYN_BNF_LABEL_ID_H
