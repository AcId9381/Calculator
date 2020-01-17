#include "Expression.hpp"
#include "ExpressionVisitor.hpp"
#include <string>

namespace Calculator {

/* Expression */
Expression::~Expression()
{
    //dtor
}


/* BinOpExpr */
BinOpExpr::BinOpExpr(Expression* lhs, Expression* rhs)
    : Lhs(lhs), Rhs(rhs)
{
    //ctor
}

BinOpExpr::BinOpExpr(const BinOpExpr& expr)
    : Lhs(expr.Lhs->Clone()), Rhs(expr.Rhs->Clone())
{
    //ctor
}

BinOpExpr::~BinOpExpr()
{
    delete(Lhs);
    delete(Rhs);
}


/* UnOpExpr */
UnOpExpr::UnOpExpr(Expression* expr)
    : Expr(expr)
{
    //ctor
}

UnOpExpr::UnOpExpr(const UnOpExpr& expr)
    : Expr(expr.Expr->Clone())
{
    //ctor
}

UnOpExpr::~UnOpExpr()
{
    delete(Expr);
}


/* AssExpr */
AssExpr::AssExpr(std::string id, Expression* expr)
    : Id(id), Expr(expr)
{
    //ctor
}

AssExpr::AssExpr(const AssExpr& expr)
{
    Id = expr.Id;
    Expr = Expr->Clone();
}

AssExpr::~AssExpr()
{
    delete(Expr);
}

AssExpr* AssExpr::Clone() const
{
    return new AssExpr(*this);
}

void AssExpr::Accept(ExpressionVisitor& visitor)
{
    visitor.Visit(*this);
}


/* NameExpr */
NameExpr::NameExpr(std::string id)
    : Id(id)
{
    //ctor
}

NameExpr::NameExpr(const NameExpr& expr)
    : Id(expr.Id)
{
    //ctor
}

NameExpr::~NameExpr()
{
    //dtor
}

NameExpr* NameExpr::Clone() const
{
    return new NameExpr(*this);
}

void NameExpr::Accept(ExpressionVisitor& visitor)
{
    visitor.Visit(*this);
}


/* ParExpr */
ParExpr::ParExpr(Expression* expr)
    : Expr(expr)
{
    //ctor
}

ParExpr::ParExpr(const ParExpr& expr)
{
    *Expr = *expr.Expr;
}

ParExpr::~ParExpr()
{
    delete(Expr);
}

ParExpr* ParExpr::Clone() const
{
    return new ParExpr(*this);
}

void ParExpr::Accept(ExpressionVisitor& visitor)
{
    visitor.Visit(*this);
}


} // namespace Calculator
