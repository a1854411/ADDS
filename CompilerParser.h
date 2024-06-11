#ifndef COMPILERPARSER_H
#define COMPILERPARSER_H

#include <list>
#include <exception>
#include "ParseTree.h"
#include "Token.h"

class CompilerParser {
private:
    std::list<Token*> tokens;
    std::list<Token*>::iterator it;

public:
    CompilerParser(std::list<Token*> tokens);
    ParseTree* compileProgram();
    ParseTree* compileClass();
    ParseTree* compileClassVarDec();
    ParseTree* compileSubroutine();
    ParseTree* compileParameterList();
    ParseTree* compileSubroutineBody();
    ParseTree* compileVarDec();
    ParseTree* compileStatements();
    ParseTree* compileLet();
    ParseTree* compileIf();
    ParseTree* compileWhile();
    ParseTree* compileDo();
    ParseTree* compileReturn();
    ParseTree* compileExpression();
    ParseTree* compileTerm();
    ParseTree* compileExpressionList();
    void next();
    Token* current();
    bool have(std::string expectedType, std::string expectedValue);
    Token* mustBe(std::string expectedType, std::string expectedValue);
    bool mustHave(std::string expectedType, std::string expectedValue);
};

class ParseException : public std::exception {
public:
    const char* what() const noexcept override;
};

#endif

