//
// Created by Anton on 2021-05-28.
//

#ifndef USIDE_LIBRARIES_ABSYN_BNF_MINIMUM_SIZE_H
#define USIDE_LIBRARIES_ABSYN_BNF_MINIMUM_SIZE_H

namespace absyn::bnf {
    struct MinimumSize {
        MinimumSize() = default;
        virtual ~MinimumSize() = default;
        MinimumSize(MinimumSize& grammar) = delete;
        MinimumSize(MinimumSize&& grammar) = delete;

        MinimumSize& operator=(MinimumSize& other) = delete;
        MinimumSize& operator=(MinimumSize&& other) = delete;

        virtual void accept(struct MinimumSizeVisitor* v) = 0;
    };

    class MinimumSizeNonempty : public MinimumSize {
	public:
        void accept(MinimumSizeVisitor* v) override;
    };

    class MinimumSizeEpsilon : public MinimumSize {
	public:
        void accept(MinimumSizeVisitor* v) override;
    };

    struct MinimumSizeVisitor {
        virtual void visit(MinimumSizeNonempty* token) = 0;
        virtual void visit(MinimumSizeEpsilon* token) = 0;
    };

    typedef void (DestructFn)(void*);
    typedef void (MinimumSizeAcceptFn)(void*, MinimumSizeVisitor* v);
    struct MinimumSizeVTable {
        DestructFn* mDestructFn1;
        DestructFn* mDestructFn2;
        MinimumSizeAcceptFn* mAcceptFn;
    };

    inline MinimumSizeVTable* getVTable(MinimumSize* obj) {
        auto** vtablePtr = reinterpret_cast<MinimumSizeVTable**>(obj); // NOLINT(cppcoreguidelines-pro-type-reinterpret-cast)
        return *(vtablePtr);
    }
}

#endif //USIDE_LIBRARIES_ABSYN_BNF_MINIMUM_SIZE_H
