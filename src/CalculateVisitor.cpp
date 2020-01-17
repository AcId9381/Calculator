#include "CalculateVisitor.hpp"
#include "ArithExpr.hpp"
#include <cmath>
#include <map>
#include <string>

namespace Calculator {

CalculateVisitor::CalculateVisitor()
{
    //ctor
}

CalculateVisitor::~CalculateVisitor()
{
    //dtor
}

void CalculateVisitor::Visit(const AssExpr& expr)
{
    expr.Expr->Accept(*this);
    Names.insert_or_assign(expr.Id, _Result);
}

void CalculateVisitor::Visit(const NameExpr& expr)
{
    auto search = Names.find(expr.Id);
    if(search != Names.end())
    {
        _Result = search->second;
    }
    else
    {
        // TODO: Implement exception thrown if name is not found.
        _Result = 0;
    }
}

void CalculateVisitor::Visit(const ParExpr& expr)
{
    expr.Expr->Accept(*this);
}

void CalculateVisitor::Visit(const AddExpr& expr)
{
    double a, b;

    expr.Lhs->Accept(*this);
    a = _Result;

    expr.Rhs->Accept(*this);
    b = _Result;

    _Result = a + b;
}

void CalculateVisitor::Visit(const SubExpr& expr)
{
    double a, b;

    expr.Lhs->Accept(*this);
    a = _Result;

    expr.Rhs->Accept(*this);
    b = _Result;

    _Result = a - b;
}

void CalculateVisitor::Visit(const MultExpr& expr)
{
    double a, b;

    expr.Lhs->Accept(*this);
    a = _Result;

    expr.Rhs->Accept(*this);
    b = _Result;

    _Result = a * b;
}

void CalculateVisitor::Visit(const DivExpr& expr)
{
    double a, b;

    expr.Lhs->Accept(*this);
    a = _Result;

    expr.Rhs->Accept(*this);
    b = _Result;

    if(b == 0)
    {
        throw math_error("Math error: attempted to divide by zero.");
        return;
    }

    _Result = a / b;
}

void CalculateVisitor::Visit(const PowExpr& expr)
{
    double a, b;

    expr.Lhs->Accept(*this);
    a = _Result;

    expr.Rhs->Accept(*this);
    b = _Result;

    _Result = pow(a,b);
}

void CalculateVisitor::Visit(const SquareExpr& expr)
{
    expr.Expr->Accept(*this);
    _Result = pow(_Result, 2);
}

void CalculateVisitor::Visit(const RootExpr& expr)
{
    double a, b;

    expr.Lhs->Accept(*this);
    a = _Result;

    expr.Rhs->Accept(*this);
    b = _Result;

    if(b == 0)
    {
        throw math_error("Math error: attempted to find 0th root.");
        return;
    }

    _Result = pow(a, (1.0 / b));
}

void CalculateVisitor::Visit(const SqrtExpr& expr)
{
    expr.Expr->Accept(*this);
    _Result = sqrt(_Result);
}

void CalculateVisitor::Visit(const ANegExpr& expr)
{
    expr.Expr->Accept(*this);
    _Result = -_Result;
}

void CalculateVisitor::Visit(const NumExpr& expr)
{
    _Result = expr.Value;
}


} // namespace Calculator
