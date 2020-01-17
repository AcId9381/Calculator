#ifndef EXPRESSIONVISITOR_HPP_INCLUDED
#define EXPRESSIONVISITOR_HPP_INCLUDED

#include "ArithExpr.hpp"

namespace Calculator {

class ExpressionVisitor
{
    public:
        virtual ~ExpressionVisitor() = 0;
        virtual void Visit(const AssExpr& expr) = 0;
        virtual void Visit(const NameExpr& expr) = 0;
        virtual void Visit(const ParExpr& expr) = 0;
        virtual void Visit(const AddExpr& expr) = 0;
        virtual void Visit(const SubExpr& expr) = 0;
        virtual void Visit(const MultExpr& expr) = 0;
        virtual void Visit(const DivExpr& expr) = 0;
        virtual void Visit(const PowExpr& expr) = 0;
        virtual void Visit(const SquareExpr& expr) = 0;
        virtual void Visit(const RootExpr& expr) = 0;
        virtual void Visit(const SqrtExpr& expr) = 0;
        virtual void Visit(const ANegExpr& expr) = 0;
        virtual void Visit(const NumExpr& expr) = 0;
};

template <class T>
class ResultVisitor : public ExpressionVisitor
{
protected:
    T _Result;

public:
        virtual ~ResultVisitor<T>() {};
        virtual void Visit(const AssExpr& expr) = 0;
        virtual void Visit(const NameExpr& expr) = 0;
        virtual void Visit(const ParExpr& expr) = 0;
        virtual void Visit(const AddExpr& expr) = 0;
        virtual void Visit(const SubExpr& expr) = 0;
        virtual void Visit(const MultExpr& expr) = 0;
        virtual void Visit(const DivExpr& expr) = 0;
        virtual void Visit(const PowExpr& expr) = 0;
        virtual void Visit(const SquareExpr& expr) = 0;
        virtual void Visit(const RootExpr& expr) = 0;
        virtual void Visit(const SqrtExpr& expr) = 0;
        virtual void Visit(const ANegExpr& expr) = 0;
        virtual void Visit(const NumExpr& expr) = 0;

        virtual T Result() { return _Result; };
};

} // namespace Calculator
#endif // EXPRESSIONVISITOR_HPP_INCLUDED
