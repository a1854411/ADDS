#include "CompilerParser.h"

CompilerParser::CompilerParser(std::list<Token*> tokens) : tokens(tokens) {
    it = this->tokens.begin();
}

ParseTree* CompilerParser::compileProgram() {
    ParseTree* newTree = new ParseTree("class", "");
    if (mustBe("keyword", "class")) {
        newTree->addChild(new ParseTree(current()->getType(), current()->getValue()));
        next();
    } else {
        throw ParseException();
    }

    if (mustBe("identifier", "MyClass")) {
        newTree->addChild(new ParseTree(current()->getType(), current()->getValue()));
        next();
    } else {
        throw ParseException();
    }

    if (mustBe("symbol", "{")) {
        newTree->addChild(new ParseTree(current()->getType(), current()->getValue()));
        next();
    } else {
        throw ParseException();
    }

    if (mustBe("symbol", "}")) {
        newTree->addChild(new ParseTree(current()->getType(), current()->getValue()));
        next();
    } else {
        throw ParseException();
    }

    return newTree;
}

/**
 * Generates a parse tree for a single class
 * @return a ParseTree
 */
ParseTree* CompilerParser::compileClass() {
    return NULL;
}

/**
 * Generates a parse tree for a static variable declaration or field declaration
 * @return a ParseTree
 */
ParseTree* CompilerParser::compileClassVarDec() {
    return NULL;
}

/**
 * Generates a parse tree for a method, function, or constructor
 * @return a ParseTree
 */
ParseTree* CompilerParser::compileSubroutine() {
    return NULL;
}

/**
 * Generates a parse tree for a subroutine's parameters
 * @return a ParseTree
 */
ParseTree* CompilerParser::compileParameterList() {
    return NULL;
}

/**
 * Generates a parse tree for a subroutine's body
 * @return a ParseTree
 */
ParseTree* CompilerParser::compileSubroutineBody() {
    return NULL;
}

/**
 * Generates a parse tree for a subroutine variable declaration
 * @return a ParseTree
 */
ParseTree* CompilerParser::compileVarDec() {
    return NULL;
}

/**
 * Generates a parse tree for a series of statements
 * @return a ParseTree
 */
ParseTree* CompilerParser::compileStatements() {
    return NULL;
}

/**
 * Generates a parse tree for a let statement
 * @return a ParseTree
 */
ParseTree* CompilerParser::compileLet() {
    return NULL;
}

/**
 * Generates a parse tree for an if statement
 * @return a ParseTree
 */
ParseTree* CompilerParser::compileIf() {
    return NULL;
}

/**
 * Generates a parse tree for a while statement
 * @return a ParseTree
 */
ParseTree* CompilerParser::compileWhile() {
    return NULL;
}

/**
 * Generates a parse tree for a do statement
 * @return a ParseTree
 */
ParseTree* CompilerParser::compileDo() {
    return NULL;
}

/**
 * Generates a parse tree for a return statement
 * @return a ParseTree
 */
ParseTree* CompilerParser::compileReturn() {
    return NULL;
}

/**
 * Generates a parse tree for an expression
 * @return a ParseTree
 */
ParseTree* CompilerParser::compileExpression() {
    return NULL;
}

/**
 * Generates a parse tree for an expression term
 * @return a ParseTree
 */
ParseTree* CompilerParser::compileTerm() {
    return NULL;
}

/**
 * Generates a parse tree for an expression list
 * @return a ParseTree
 */
ParseTree* CompilerParser::compileExpressionList() {
    return NULL;
}

void CompilerParser::next() {
    if (it != tokens.end()) {
        ++it;
    }
}

Token* CompilerParser::current() {
    if (it != tokens.end()) {
        return *it;
    }
    return nullptr;
}

bool CompilerParser::have(std::string expectedType, std::string expectedValue) {
    Token* token = current();
    if (token) {
        return token->getType() == expectedType && token->getValue() == expectedValue;
    }
    return false;
}

Token* CompilerParser::mustBe(std::string expectedType, std::string expectedValue) {
    if (have(expectedType, expectedValue)) {
        Token* token = current();
        next();
        return token;
    } else {
        throw ParseException();
    }
}

const char* ParseException::what() const noexcept {
    return "An exception occurred while parsing!";
}

