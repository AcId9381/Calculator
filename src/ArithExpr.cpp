#include "Expression.hpp"
#include "ArithExpr.hpp"
#include "ExpressionVisitor.hpp"

namespace Calculator {

/* ArithExpr */
ArithExpr::~ArithExpr()
{}


/* AddExpr */
AddExpr::AddExpr(Expression* lhs, Expression* rhs)
    : BinOpExpr(lhs, rhs) {}

AddExpr::AddExpr(const AddExpr& expr)
    : BinOpExpr(expr) {}

AddExpr::~AddExpr()
{}

AddExpr* AddExpr::Clone() const
{
    return new AddExpr(*this);
}

void AddExpr::Accept(ExpressionVisitor& visitor)
{
    visitor.Visit(*this);
}


/* SubExpr */
SubExpr::SubExpr(Expression* lhs, Expression* rhs)
    : BinOpExpr(lhs, rhs) {}

SubExpr::SubExpr(const SubExpr& expr)
    : BinOpExpr(expr) {}

SubExpr::~SubExpr()
{}

SubExpr* SubExpr::Clone() const
{
    return new SubExpr(*this);
}

void SubExpr::Accept(ExpressionVisitor& visitor)
{
    visitor.Visit(*this);
}


/* MultExpr */
MultExpr::MultExpr(Expression* lhs, Expression* rhs)
    : BinOpExpr(lhs, rhs) {}

MultExpr::MultExpr(const MultExpr& expr)
    : BinOpExpr(expr) {}

MultExpr::~MultExpr()
{}

MultExpr* MultExpr::Clone() const
{
    return new MultExpr(*this);
}

void MultExpr::Accept(ExpressionVisitor& visitor)
{
    visitor.Visit(*this);
}


/* DivExpr */
DivExpr::DivExpr(Expression* lhs, Expression* rhs)
    : BinOpExpr(lhs, rhs) {}

DivExpr::DivExpr(const DivExpr& expr)
    : BinOpExpr(expr) {}

DivExpr::~DivExpr()
{}

DivExpr* DivExpr::Clone() const
{
    return new DivExpr(*this);
}

void DivExpr::Accept(ExpressionVisitor& visitor)
{
    visitor.Visit(*this);
}


/* PowExpr */
PowExpr::PowExpr(Expression* lhs, Expression* rhs)
    : BinOpExpr(lhs, rhs) {}

PowExpr::PowExpr(const PowExpr& expr)
    : BinOpExpr(expr) {}

PowExpr::~PowExpr()
{}

PowExpr* PowExpr::Clone() const
{
    return new PowExpr(*this);
}

void PowExpr::Accept(ExpressionVisitor& visitor)
{
    visitor.Visit(*this);
}


/* SquareExpr */
SquareExpr::SquareExpr(Expression* expr)
    : UnOpExpr(expr) {}

SquareExpr::SquareExpr(const SquareExpr& expr)
    : UnOpExpr(expr) {}

SquareExpr::~SquareExpr()
{}

SquareExpr* SquareExpr::Clone() const
{
    return new SquareExpr(*this);
}

void SquareExpr::Accept(ExpressionVisitor& visitor)
{
    visitor.Visit(*this);
}


/* RootExpr */
RootExpr::RootExpr(Expression* lhs, Expression* rhs)
    : BinOpExpr(lhs, rhs) {}

RootExpr::RootExpr(const RootExpr& expr)
    : BinOpExpr(expr) {}

RootExpr::~RootExpr()
{}

RootExpr* RootExpr::Clone() const
{
    return new RootExpr(*this);
}

void RootExpr::Accept(ExpressionVisitor& visitor)
{
    visitor.Visit(*this);
}


/* SqrtExpr */
SqrtExpr::SqrtExpr(Expression* expr)
    : UnOpExpr(expr) {}

SqrtExpr::SqrtExpr(const SqrtExpr& expr)
    : UnOpExpr(expr) {}

SqrtExpr::~SqrtExpr()
{}

SqrtExpr* SqrtExpr::Clone() const
{
    return new SqrtExpr(*this);
}

void SqrtExpr::Accept(ExpressionVisitor& visitor)
{
    visitor.Visit(*this);
}


/* ANegExpr */
ANegExpr::ANegExpr(Expression* expr)
    : UnOpExpr(expr) {}

ANegExpr::ANegExpr(const ANegExpr& expr)
    : UnOpExpr(expr) {}

ANegExpr::~ANegExpr() {}

ANegExpr* ANegExpr::Clone() const
{
    return new ANegExpr(*this);
}

void ANegExpr::Accept(ExpressionVisitor& visitor)
{
    visitor.Visit(*this);
}


/* NumExpr */
NumExpr::NumExpr()
    : NumExpr(0) {}

NumExpr::NumExpr(double val)
    : Value(val) {}

NumExpr::NumExpr(const NumExpr& expr)
    : NumExpr(expr.Value) {}

NumExpr::~NumExpr()
{}

NumExpr* NumExpr::Clone() const
{
    return new NumExpr(*this);
}

void NumExpr::Accept(ExpressionVisitor& visitor)
{
    visitor.Visit(*this);
}


} // namespace Calculator
