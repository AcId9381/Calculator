#ifndef TYPEPRINTVISITOR_HPP_INCLUDED
#define TYPEPRINTVISITOR_HPP_INCLUDED

#include "ExpressionVisitor.hpp"
#include "ArithExpr.hpp"

namespace Calculator {

class TypePrintVisitor : public ExpressionVisitor
{
    public:
        TypePrintVisitor();
        virtual ~TypePrintVisitor();
        virtual void Visit(const AssExpr& expr);
        virtual void Visit(const NameExpr& expr);
        virtual void Visit(const ParExpr& expr);
        virtual void Visit(const AddExpr& expr);
        virtual void Visit(const SubExpr& expr);
        virtual void Visit(const MultExpr& expr);
        virtual void Visit(const DivExpr& expr);
        virtual void Visit(const PowExpr& expr);
        virtual void Visit(const SquareExpr& expr);
        virtual void Visit(const RootExpr& expr);
        virtual void Visit(const SqrtExpr& expr);
        virtual void Visit(const ANegExpr& expr);
        virtual void Visit(const NumExpr& expr);
};

} // namespace Calculator

#endif // TYPEPRINTVISITOR_HPP_INCLUDED
