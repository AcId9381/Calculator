#ifndef ArithExpr_HPP_INCLUDED
#define ArithExpr_HPP_INCLUDED

#include "Expression.hpp"

namespace Calculator {

class ExpressionVisitor;

class ArithExpr : public virtual Expression
{
public:
    virtual ~ArithExpr() = 0;
};


class AddExpr : public ArithExpr, public BinOpExpr
{
public:
    AddExpr(Expression* lhs, Expression* rhs);
    AddExpr(const AddExpr& expr);
    virtual ~AddExpr();
    virtual AddExpr* Clone() const override;
    virtual void Accept(ExpressionVisitor& visitor) override;
};


class SubExpr : public ArithExpr, public BinOpExpr
{
public:
    SubExpr(Expression* lhs, Expression* rhs);
    SubExpr(const SubExpr& expr);
    virtual ~SubExpr();
    virtual SubExpr* Clone() const override;
    virtual void Accept(ExpressionVisitor& visitor) override;
};


class MultExpr : public ArithExpr, public BinOpExpr
{
public:
    MultExpr(Expression* lhs, Expression* rhs);
    MultExpr(const MultExpr& expr);
    virtual ~MultExpr();
    virtual MultExpr* Clone() const override;
    virtual void Accept(ExpressionVisitor& visitor) override;
};


class DivExpr : public ArithExpr, public BinOpExpr
{
public:
    DivExpr(Expression* lhs, Expression* rhs);
    DivExpr(const DivExpr& expr);
    virtual ~DivExpr();
    virtual DivExpr* Clone() const override;
    virtual void Accept(ExpressionVisitor& visitor) override;
};


class PowExpr : public ArithExpr, public BinOpExpr
{
public:
    PowExpr(Expression* lhs, Expression* rhs);
    PowExpr(const PowExpr& expr);
    virtual ~PowExpr();
    virtual PowExpr* Clone() const override;
    virtual void Accept(ExpressionVisitor& visitor) override;
};


class SquareExpr : public ArithExpr, public UnOpExpr
{
public:
    SquareExpr(Expression* expr);
    SquareExpr(const SquareExpr& expr);
    virtual ~SquareExpr();
    virtual SquareExpr* Clone() const override;
    virtual void Accept(ExpressionVisitor& visitor) override;
};


class RootExpr : public ArithExpr, public BinOpExpr
{
public:
    RootExpr(Expression* lhs, Expression* rhs);
    RootExpr(const RootExpr& expr);
    virtual ~RootExpr();
    virtual RootExpr* Clone() const override;
    virtual void Accept(ExpressionVisitor& visitor) override;
};


class SqrtExpr : public ArithExpr, public UnOpExpr
{
public:
    SqrtExpr(Expression* expr);
    SqrtExpr(const SqrtExpr& expr);
    virtual ~SqrtExpr();
    virtual SqrtExpr* Clone() const override;
    virtual void Accept(ExpressionVisitor& visitor) override;
};


class ANegExpr : public ArithExpr, public UnOpExpr
{
public:
    ANegExpr(Expression* expr);
    ANegExpr(const ANegExpr& expr);
    virtual ~ANegExpr();
    virtual ANegExpr* Clone() const override;
    virtual void Accept(ExpressionVisitor& visitor) override;
};


class NumExpr : public ArithExpr
{
public:
    double Value;

    NumExpr();
    NumExpr(double val);
    NumExpr(const NumExpr& exrp);
    virtual ~NumExpr();
    virtual NumExpr* Clone() const override;
    virtual void Accept(ExpressionVisitor& visitor) override;
};


} // namespace Calculator

#endif // ArithExpr_HPP_INCLUDED
