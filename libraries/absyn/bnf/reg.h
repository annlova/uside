//
// Created by Anton on 2021-05-28.
//

#ifndef USIDE_LIBRARIES_ABSYN_BNF_REG_H
#define USIDE_LIBRARIES_ABSYN_BNF_REG_H

namespace absyn::bnf {
    struct Reg {
        Reg() = default;
        virtual ~Reg() = default;
        Reg(Reg& grammar) = delete;
        Reg(Reg&& grammar) = delete;

        Reg& operator=(Reg& other) = delete;
        Reg& operator=(Reg&& other) = delete;

        virtual void accept(struct RegVisitor& v) const = 0;
    };

    class RegReg : public Reg {
	public:
		RegReg() : mV1{nullptr} {}
		~RegReg() override { delete mV1; }
		RegReg(RegReg& regReg) = delete;
		RegReg(RegReg&& regReg) = delete;

		RegReg& operator=(RegReg& other) = delete;
		RegReg& operator=(RegReg&& other) = delete;

        void accept(RegVisitor& v) const override;
        [[nodiscard]] const Reg& v1() const { return *mV1; }
    private:
        const Reg* mV1;
    };

    class RegChar : public Reg {
	public:
        void accept(RegVisitor& v) const override;
    };

    class RegLower : public Reg {
	public:
        void accept(RegVisitor& v) const override;
    };

    class RegUpper : public Reg {
	public:
        void accept(RegVisitor& v) const override;
    };

    class RegLetter : public Reg {
	public:
        void accept(RegVisitor& v) const override;
    };

    class RegDigit : public Reg {
	public:
        void accept(RegVisitor& v) const override;
    };

    class RegSquareString : public Reg {
	public:
		RegSquareString() : mV1{nullptr} {}
		~RegSquareString() override { delete[] mV1; }
		RegSquareString(RegSquareString& regSquareString) = delete;
		RegSquareString(RegSquareString&& regSquareString) = delete;

		RegSquareString& operator=(RegSquareString& other) = delete;
		RegSquareString& operator=(RegSquareString&& other) = delete;

        void accept(RegVisitor& v) const override;
        [[nodiscard]] const char* v1() const { return mV1; }
    private:
        const char* mV1;
    };

    class RegCurlyString : public Reg {
	public:
		RegCurlyString() : mV1{nullptr} {}
		~RegCurlyString() override { delete[] mV1; }
		RegCurlyString(RegCurlyString& regCurlyString) = delete;
		RegCurlyString(RegCurlyString&& regCurlyString) = delete;

		RegCurlyString& operator=(RegCurlyString& other) = delete;
		RegCurlyString& operator=(RegCurlyString&& other) = delete;

        void accept(RegVisitor& v) const override;
        [[nodiscard]] const char* v1() const { return mV1; }
    private:
        const char* mV1;
    };

    class RegEps : public Reg {
	public:
        void accept(RegVisitor& v) const override;
    };

    class RegRealChar : public Reg {
	public:
		RegRealChar() : mV1{'\0'} {}
        void accept(RegVisitor& v) const override;
        [[nodiscard]] char v1() const { return mV1; }
    private:
        char mV1;
    };

    class RegStar : public Reg {
	public:
        RegStar() : mV1{nullptr} {}
        ~RegStar() override { delete mV1; }
        RegStar(RegStar& regStar) = delete;
        RegStar(RegStar&& regStar) = delete;

        RegStar& operator=(RegStar& other) = delete;
        RegStar& operator=(RegStar&& other) = delete;

        void accept(RegVisitor& v) const override;
        [[nodiscard]] const Reg& v1() const { return *mV1; }
    private:
        const Reg* mV1;
    };

    class RegPlus : public Reg {
	public:
        RegPlus() : mV1{nullptr} {}
        ~RegPlus() override { delete mV1; }
        RegPlus(RegPlus& regPlus) = delete;
        RegPlus(RegPlus&& regPlus) = delete;

        RegPlus& operator=(RegPlus& other) = delete;
        RegPlus& operator=(RegPlus&& other) = delete;

        void accept(RegVisitor& v) const override;
        [[nodiscard]] const Reg& v1() const { return *mV1; }
    private:
        const Reg* mV1;
    };

    class RegQuestion : public Reg {
    public:
        RegQuestion() : mV1{nullptr} {}
        ~RegQuestion() override { delete mV1; }
        RegQuestion(RegQuestion& regQuestion) = delete;
        RegQuestion(RegQuestion&& regQuestion) = delete;

        RegQuestion& operator=(RegQuestion& other) = delete;
        RegQuestion& operator=(RegQuestion&& other) = delete;

        void accept(RegVisitor& v) const override;
        [[nodiscard]] const Reg& v1() const { return *mV1; }
    private:
        const Reg* mV1;
    };

    class RegMinus : public Reg {
	public:
		RegMinus() : mV1{nullptr}, mV2{nullptr} {}
		~RegMinus() override { delete mV1; delete mV2; }
		RegMinus(RegMinus& regMinus) = delete;
		RegMinus(RegMinus&& regMinus) = delete;

		RegMinus& operator=(RegMinus& other) = delete;
		RegMinus& operator=(RegMinus&& other) = delete;

        void accept(RegVisitor& v) const override;
        [[nodiscard]] const Reg& v1() const { return *mV1; }
        [[nodiscard]] const Reg& v2() const { return *mV2; }
    private:
        const Reg* mV1;
        const Reg* mV2;
    };

    class RegOr : public Reg {
	public:
		RegOr() : mV1{nullptr}, mV2{nullptr} {}
		~RegOr() override { delete mV1; delete mV2; }
		RegOr(RegOr& regOr) = delete;
		RegOr(RegOr&& regOr) = delete;

		RegOr& operator=(RegOr& other) = delete;
		RegOr& operator=(RegOr&& other) = delete;

        void accept(RegVisitor& v) const override;
        [[nodiscard]] const Reg& v1() const { return *mV1; }
        [[nodiscard]] const Reg& v2() const { return *mV2; }
    private:
        const Reg* mV1;
        const Reg* mV2;
    };

    class RegDoubleReg : public Reg {
	public:
		RegDoubleReg() : mV1{nullptr}, mV2{nullptr} {}
		~RegDoubleReg() override { delete mV1; delete mV2; }
		RegDoubleReg(RegDoubleReg& regDoubleReg) = delete;
		RegDoubleReg(RegDoubleReg&& regDoubleReg) = delete;

		RegDoubleReg& operator=(RegDoubleReg& other) = delete;
		RegDoubleReg& operator=(RegDoubleReg&& other) = delete;

        void accept(RegVisitor& v) const override;
        [[nodiscard]] const Reg& v1() const { return *mV1; }
        [[nodiscard]] const Reg& v2() const { return *mV2; }
    private:
        const Reg* mV1;
        const Reg* mV2;
    };

    struct RegVisitor {
        virtual void visit(const RegReg& token) = 0;
        virtual void visit(const RegOr& token) = 0;
        virtual void visit(const RegMinus& token) = 0;
        virtual void visit(const RegDoubleReg& token) = 0;
        virtual void visit(const RegStar& token) = 0;
        virtual void visit(const RegPlus& token) = 0;
        virtual void visit(const RegQuestion& token) = 0;
        virtual void visit(const RegEps& token) = 0;
        virtual void visit(const RegRealChar& token) = 0;
        virtual void visit(const RegSquareString& token) = 0;
        virtual void visit(const RegCurlyString& token) = 0;
        virtual void visit(const RegDigit& token) = 0;
        virtual void visit(const RegLetter& token) = 0;
        virtual void visit(const RegUpper& token) = 0;
        virtual void visit(const RegLower& token) = 0;
        virtual void visit(const RegChar& token) = 0;
    };

    typedef void (DestructFn)(void*);
    typedef void (RegAcceptFn)(void*, RegVisitor& v);
    struct RegVTable {
        DestructFn* mDestructFn1;
        DestructFn* mDestructFn2;
        RegAcceptFn* mAcceptFn;
    };

    inline RegVTable* getVTable(Reg* obj) {
        auto** vtablePtr = reinterpret_cast<RegVTable**>(obj); // NOLINT(cppcoreguidelines-pro-type-reinterpret-cast)
        return *(vtablePtr);
    }
}


#endif //USIDE_LIBRARIES_ABSYN_BNF_REG_H
