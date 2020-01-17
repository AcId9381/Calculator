#include "TypePrintVisitor.hpp"
#include "ArithExpr.hpp"
#include <typeinfo>
#include <iostream>

namespace Calculator {

TypePrintVisitor::TypePrintVisitor()
{
    //ctor
}

TypePrintVisitor::~TypePrintVisitor()
{
    //dtor
}

void TypePrintVisitor::Visit(const AssExpr& expr)
{
    std::cout << typeid(expr).name() << " ";
    expr.Expr->Accept(*this);
}

void TypePrintVisitor::Visit(const NameExpr& expr)
{
    std::cout << typeid(expr).name() << " ";
}

void TypePrintVisitor::Visit(const ParExpr& expr)
{
    std::cout << typeid(expr).name() << " ";
    expr.Expr->Accept(*this);
}

void TypePrintVisitor::Visit(const AddExpr& expr)
{
    expr.Lhs->Accept(*this);
    std::cout << typeid(expr).name() << " ";
    expr.Rhs->Accept(*this);
}

void TypePrintVisitor::Visit(const SubExpr& expr)
{
    expr.Lhs->Accept(*this);
    std::cout << typeid(expr).name() << " ";
    expr.Rhs->Accept(*this);
}

void TypePrintVisitor::Visit(const MultExpr& expr)
{
    expr.Lhs->Accept(*this);
    std::cout << typeid(expr).name() << " ";
    expr.Rhs->Accept(*this);
}

void TypePrintVisitor::Visit(const DivExpr& expr)
{
    expr.Lhs->Accept(*this);
    std::cout << typeid(expr).name() << " ";
    expr.Rhs->Accept(*this);
}

void TypePrintVisitor::Visit(const PowExpr& expr)
{
    expr.Lhs->Accept(*this);
    std::cout << typeid(expr).name() << " ";
    expr.Rhs->Accept(*this);
}

void TypePrintVisitor::Visit(const SquareExpr& expr)
{
    expr.Expr->Accept(*this);
    std::cout << typeid(expr).name() << " ";
}

void TypePrintVisitor::Visit(const RootExpr& expr)
{
    expr.Lhs->Accept(*this);
    std::cout << typeid(expr).name() << " ";
    expr.Rhs->Accept(*this);
}

void TypePrintVisitor::Visit(const SqrtExpr& expr)
{
    expr.Expr->Accept(*this);
    std::cout << typeid(expr).name() << " ";
}

void TypePrintVisitor::Visit(const ANegExpr& expr)
{
    std::cout << typeid(expr).name() << " ";
    expr.Expr->Accept(*this);
}

void TypePrintVisitor::Visit(const NumExpr& expr)
{
    std::cout << typeid(expr).name() << " ";
}

} // namespace Calculator
