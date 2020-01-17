#ifndef CALCULATEVISITOR_HPP_INCLUDED
#define CALCULATEVISITOR_HPP_INCLUDED

#include "ExpressionVisitor.hpp"
#include "ArithExpr.hpp"
#include <map>
#include <string>

namespace Calculator {

class CalculateVisitor : public ResultVisitor<double>
{
private:
    std::map<std::string,double> Names;

public:
    CalculateVisitor();
    virtual ~CalculateVisitor();
    void Visit(const AssExpr& expr);
    void Visit(const NameExpr& expr);
    void Visit(const ParExpr& expr);
    void Visit(const AddExpr& expr);
    void Visit(const SubExpr& expr);
    void Visit(const MultExpr& expr);
    void Visit(const DivExpr& expr);
    void Visit(const PowExpr& expr);
    void Visit(const SquareExpr& expr);
    void Visit(const RootExpr& expr);
    void Visit(const SqrtExpr& expr);
    void Visit(const ANegExpr& expr);
    void Visit(const NumExpr& expr);

    struct math_error : std::runtime_error
    {
        math_error(const std::string& msg) : runtime_error(msg) {};
    };
};

} // namespace Calculator

#endif // CALCULATEVISITOR_HPP_INCLUDED
