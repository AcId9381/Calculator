#ifndef EXPRESSION_HPP_INCLUDED
#define EXPRESSION_HPP_INCLUDED

#include <string>

namespace Calculator {

class ExpressionVisitor;

class Expression
{
    public:
        virtual ~Expression() = 0;
        virtual Expression* Clone() const = 0;
        virtual void Accept(ExpressionVisitor& visitor) = 0;
};


class BinOpExpr : public virtual Expression
{
public:
    Expression* Lhs;
    Expression* Rhs;

protected:
    BinOpExpr(Expression* lhs, Expression* rhs);
    BinOpExpr(const BinOpExpr& expr);
    virtual ~BinOpExpr() = 0;
};


class UnOpExpr : public virtual Expression
{
public:
    Expression* Expr;

protected:
    UnOpExpr(Expression* expr);
    UnOpExpr(const UnOpExpr& expr);
    virtual ~UnOpExpr() = 0;
};


class AssExpr : public Expression
{
public:
    std::string Id;
    Expression* Expr;

    AssExpr(std::string id, Expression* val);
    AssExpr(const AssExpr& expr);
    virtual ~AssExpr();
    virtual AssExpr* Clone() const override;
    virtual void Accept(ExpressionVisitor& visitor) override;
};


class NameExpr : public Expression
{
public:
    std::string Id;

    NameExpr(std::string id);
    NameExpr(const NameExpr& expr);
    virtual ~NameExpr();
    virtual NameExpr* Clone() const override;
    virtual void Accept(ExpressionVisitor& visitor) override;
};


class ParExpr : public Expression
{
public:
    Expression* Expr;

    ParExpr(Expression* expr);
    ParExpr(const ParExpr& expr);
    virtual ~ParExpr();
    virtual ParExpr* Clone() const override;
    virtual void Accept(ExpressionVisitor& visitor) override;
};

} // namespace Calculator

#endif // EXPRESSION_HPP_INCLUDED
