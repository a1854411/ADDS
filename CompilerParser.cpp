#include "CompilerParser.h"

CompilerParser::CompilerParser(std::list<Token*> tokens) : tokens(tokens) {
    it = this->tokens.begin();
}

ParseTree* CompilerParser::compileProgram() {
    //check if program doesn't begin with class
    if(current()->getValue() != "class"){
        throw ParseException();
    }
    else{
    //get class
    ParseTree* newTree = new ParseTree("class", "");
    if (have("keyword", "class")) {
        newTree->addChild(new ParseTree(current()->getType(), current()->getValue()));
        next();
    } else {
        throw ParseException();
    }

    //get identifier
    if (have("identifier", "")) {
        newTree->addChild(new ParseTree(current()->getType(), current()->getValue()));
        next();
    } else {
        throw ParseException();
    }

    //get symbols
    if (have("symbol", "{")) {
        newTree->addChild(new ParseTree(current()->getType(), current()->getValue()));
        next();
    } else {
        throw ParseException();
    }

    if (have("symbol", "}")) {
        newTree->addChild(new ParseTree(current()->getType(), current()->getValue()));
        next();
    } else {
        throw ParseException();
    }

    return newTree;
    }
}

/**
 * Generates a parse tree for a single class
 * @return a ParseTree
 */
ParseTree* CompilerParser::compileClass() {
    //get class
    ParseTree* newTree = new ParseTree("class", "");
    if (have("keyword", "class")) {
        newTree->addChild(new ParseTree(current()->getType(), current()->getValue()));
        next();
    } else {
        throw ParseException();
    }

    //get identifier
    if (have("identifier", "MyClass")) {
        newTree->addChild(new ParseTree(current()->getType(), current()->getValue()));
        next();
    } else {
        throw ParseException();
    }

    //get symbol {
    if (have("symbol", "{")) {
        newTree->addChild(new ParseTree(current()->getType(), current()->getValue()));
        next();
    } else {
        throw ParseException();
    }

    //get static
    if (have("keyword", "static") || have("keyword", "field")) {
        newTree->addChild(new ParseTree(current()->getType(), current()->getValue()));
        next();
    } else {
        throw ParseException();
    }

    compileClassVarDec();

    //get symbol }
    if (have("symbol", "}")) {
        newTree->addChild(new ParseTree(current()->getType(), current()->getValue()));
        next();
    } else {
        throw ParseException();
    }

    return newTree;
}


/**
 * Generates a parse tree for a static variable declaration or field declaration
 * @return a ParseTree
 */
ParseTree* CompilerParser::compileClassVarDec() {
    ParseTree* newTree = new ParseTree("classVarDec", "");

    //get static or field
    if (have("keyword", "static") || mustBe("keyword", "field")) {
        newTree->addChild(new ParseTree(current()->getType(), current()->getValue()));
        next();
    } else {
        throw ParseException();
    }

    // get var type
    if (have("keyword", "int") || mustBe("keyword", "char") || mustBe("keyword", "boolean")) {
        newTree->addChild(new ParseTree(current()->getType(), current()->getValue()));
        next();
    } else {
        throw ParseException();
    }

    //get identifier
    if (have("identifier", "")) {
        newTree->addChild(new ParseTree(current()->getType(), current()->getValue()));
        next();
    } else {
        throw ParseException();
    }

    //get symbol ;
    if (have("symbol", ";")) {
        newTree->addChild(new ParseTree(current()->getType(), current()->getValue()));
        next();
    } else {
        throw ParseException();
    }

    return newTree;
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
    ParseTree* newTree = new ParseTree("parameterList", "");

    // get var type
    if (have("keyword", "int") || mustBe("keyword", "char") || mustBe("keyword", "boolean")) {
        newTree->addChild(new ParseTree(current()->getType(), current()->getValue()));
        next();
    } else {
        throw ParseException();
    }

    //get identifier
    if (have("identifier", "")) {
        newTree->addChild(new ParseTree(current()->getType(), current()->getValue()));
        next();
    } else {
        throw ParseException();
    }

    //get symbol ,
    if (have("symbol", ",")) {
        newTree->addChild(new ParseTree(current()->getType(), current()->getValue()));
        next();
    } else {
        throw ParseException();
    }

    // get var type
    if (have("keyword", "int") || mustBe("keyword", "char") || mustBe("keyword", "boolean")) {
        newTree->addChild(new ParseTree(current()->getType(), current()->getValue()));
        next();
    } else {
        throw ParseException();
    }

    //get identifier
    if (have("identifier", "")) {
        newTree->addChild(new ParseTree(current()->getType(), current()->getValue()));
        next();
    } else {
        throw ParseException();
    }

    return newTree;
}

/**
 * Generates a parse tree for a subroutine's body
 * @return a ParseTree
 */
ParseTree* CompilerParser::compileSubroutineBody() {
    ParseTree* newTree = new ParseTree("subroutineBody", "");

    //get symbol {
    if (have("symbol", "{")) {
        newTree->addChild(new ParseTree(current()->getType(), current()->getValue()));
        next();
    } else {
        throw ParseException();
    }
}


/**
 * Generates a parse tree for a subroutine variable declaration
 * @return a ParseTree
 */
ParseTree* CompilerParser::compileVarDec() {
    ParseTree* newTree = new ParseTree("varDec", "");

    //get keyword var
    if (have("keyword", "var")) {
        newTree->addChild(new ParseTree(current()->getType(), current()->getValue()));
        next();
    } else {
        throw ParseException();
    }

    // get var type
    if (have("keyword", "int") || mustBe("keyword", "char") || mustBe("keyword", "boolean")) {
        newTree->addChild(new ParseTree(current()->getType(), current()->getValue()));
        next();
    } else {
        throw ParseException();
    }

    //get identifier
    if (have("identifier", "")) {
        newTree->addChild(new ParseTree(current()->getType(), current()->getValue()));
        next();
    } else {
        throw ParseException();
    }

    //get symbol ;
    if (have("symbol", ";")) {
        newTree->addChild(new ParseTree(current()->getType(), current()->getValue()));
        next();
    } else {
        throw ParseException();
    }
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

