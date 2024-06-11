#include "CompilerParser.h"

CompilerParser::CompilerParser(std::list<Token*> tokens) {
  this->tokens = tokens;
}


ParseTree* CompilerParser::compileProgram() {
    return compileClass();
}

ParseTree* CompilerParser::compileClass() {
    ParseTree* newTree = new ParseTree("class", "");
    newTree->addChild(mustBe("keyword", "class"));
    newTree->addChild(mustBe("identifier", ""));
    newTree->addChild(mustBe("symbol", "{"));

    while (mustHave("keyword", "static") || mustHave("keyword", "field")) {
        newTree->addChild(compileClassVarDec());
    }

    while (mustHave("keyword", "constructor") || mustHave("keyword", "function") || mustHave("keyword", "method")) {
        newTree->addChild(compileSubroutine());

        while (mustHave("keyword", "static") || mustHave("keyword", "field")) {
            newTree->addChild(compileClassVarDec());
        }
    }

    newTree->addChild(mustBe("symbol", "}"));

  return newTree;
}


ParseTree* CompilerParser::compileClassVarDec() {
    ParseTree* newTree = new ParseTree("classVarDec", "");

    newTree->addChild(mustBe("keyword", ""));
    newTree->addChild(mustBe("keyword", ""));
    newTree->addChild(mustBe("identifier", ""));

    while (mustHave("symbol", ",")) {
        newTree->addChild(mustBe("symbol", ","));
        newTree->addChild(mustBe("identifier", ""));
    }
    newTree->addChild(mustBe("symbol", ";"));
    return newTree;
}


ParseTree* CompilerParser::compileSubroutine() {
    std::string class_name;
    ParseTree* newTree = new ParseTree("subroutine", "");

    if (mustHave("keyword", "function")) {
        newTree->addChild(mustBe("keyword", "function"));
        newTree->addChild(mustBe("keyword", ""));
    }
    else if (mustHave("keyword", "constructor")) {
        newTree->addChild(mustBe("keyword", "constructor"));
        class_name = current()->getValue();
        newTree->addChild(mustBe("identifier", ""));
    }
    else {
        newTree->addChild(mustBe("keyword", "method"));
        newTree->addChild(mustBe("keyword", ""));
    }

    newTree->addChild(mustBe("identifier", ""));
    newTree->addChild(mustBe("symbol", "("));

    if (mustHave("keyword", "int") || mustHave("keyword", "char") || mustHave("keyword", "boolean") || mustHave("identifier", class_name)) {
        newTree->addChild(compileParameterList());
    }

    newTree->addChild(mustBe("symbol", ")"));

    newTree->addChild(compileSubroutineBody());

    return newTree;
}


ParseTree* CompilerParser::compileParameterList() {
    ParseTree* newTree = new ParseTree("parameterList", "");

    if(mustHave("keyword", "int") || mustHave("keyword", "char") || mustHave("keyword", "boolean")) {
        newTree->addChild(mustBe("keyword", ""));
        newTree->addChild(mustBe("identifier", ""));
    } 
    else {
        newTree->addChild(mustBe("identifier", ""));
        newTree->addChild(mustBe("identifier", ""));
    }

    while (mustHave("symbol", ",")) {
        newTree->addChild(mustBe("symbol", ","));

        if (mustHave("keyword", "int") || mustHave("keyword", "char") || mustHave("keyword", "boolean")) {
            newTree->addChild(mustBe("keyword", ""));
            newTree->addChild(mustBe("identifier", ""));
        }
        else {
            newTree->addChild(mustBe("identifier", ""));
            newTree->addChild(mustBe("identifier", ""));
        }
    }
    return newTree;
}


ParseTree* CompilerParser::compileSubroutineBody() {
    ParseTree* newTree = new ParseTree("subroutineBody", "");
    newTree->addChild(mustBe("symbol", "{"));

    while (mustHave("keyword", "var")) {
        newTree->addChild(compileVarDec());
    }

    if (mustHave("keyword", "let") || mustHave("keyword", "do") || mustHave("keyword", "return") || mustHave("keyword", "if") || mustHave("keyword", "while")) {
        newTree->addChild(compileStatements());
    }

    newTree->addChild(mustBe("symbol", "}"));
    return newTree;
}


ParseTree* CompilerParser::compileVarDec() {
    ParseTree* newTree = new ParseTree("varDec", "");

    newTree->addChild(mustBe("keyword", ""));

    if (mustHave("keyword", "int") || mustHave("keyword", "char") || mustHave("keyword", "boolean")) {
        newTree->addChild(mustBe("keyword", ""));
        newTree->addChild(mustBe("identifier", ""));
    } 
    else {
        newTree->addChild(mustBe("identifier", ""));
        newTree->addChild(mustBe("identifier", ""));
    }

    while (mustHave("symbol", ",")) {
        newTree->addChild(mustBe("symbol", ","));
        if (mustHave("keyword", "int") || mustHave("keyword", "char") || mustHave("keyword", "boolean")) {
            newTree->addChild(mustBe("identifier", ""));
        } 
        else {
            newTree->addChild(mustBe("identifier", ""));
        }
    }
    newTree->addChild(mustBe("symbol", ";"));

    return newTree;
}


ParseTree* CompilerParser::compileStatements() {
    ParseTree* newTree = new ParseTree("statements", "");

    if (mustHave("symbol", "{")) {
        throw ParseException();
    }

    while (!mustHave("symbol", "}")) {
        if (mustHave("keyword", "let")) {
        newTree->addChild(compileLet());
    } 
    else if (mustHave("keyword", "do")) {
        newTree->addChild(compileDo());
    } 
    else if (mustHave("keyword", "return")) {
        newTree->addChild(compileReturn());
    } 
    else if (mustHave("keyword", "if")) {
        newTree->addChild(compileIf());
    } 
    else if (mustHave("keyword", "while")) {
        newTree->addChild(compileWhile());
    } 
    else {
        break;
    }
  }
  return newTree;
}


ParseTree* CompilerParser::compileLet() {
    ParseTree* newTree = new ParseTree("letStatement", "");

    newTree->addChild(mustBe("keyword", "let"));
    newTree->addChild(mustBe("identifier", ""));
    newTree->addChild(mustBe("symbol", "="));
    newTree->addChild(compileExpression());
    newTree->addChild(mustBe("symbol", ";"));

    return newTree;
}


ParseTree* CompilerParser::compileIf() {
  ParseTree* newTree = new ParseTree("ifStatement", "");
    newTree->addChild(mustBe("keyword", "if"));
    newTree->addChild(mustBe("symbol", "("));
    newTree->addChild(compileExpression());
    newTree->addChild(mustBe("symbol", ")"));
    newTree->addChild(mustBe("symbol", "{"));
    newTree->addChild(compileStatements());
    newTree->addChild(mustBe("symbol", "}"));

    if (mustHave("keyword", "else")) {
        newTree->addChild(mustBe("keyword", "else"));
        newTree->addChild(mustBe("symbol", "{"));
        newTree->addChild(compileStatements());
        newTree->addChild(mustBe("symbol", "}"));
    }
  return newTree;
}

ParseTree* CompilerParser::compileWhile() {
    ParseTree* newTree = new ParseTree("whileStatement", "");

    newTree->addChild(mustBe("keyword", "while"));
    newTree->addChild(mustBe("symbol", "("));
    newTree->addChild(compileExpression());
    newTree->addChild(mustBe("symbol", ")"));
    newTree->addChild(mustBe("symbol", "{"));
    newTree->addChild(compileStatements());
    newTree->addChild(mustBe("symbol", "}"));

    return newTree;
}


ParseTree* CompilerParser::compileDo() {
    ParseTree* newTree = new ParseTree("doStatement", "");

    newTree->addChild(mustBe("keyword", "do"));
    newTree->addChild(compileExpression());
    newTree->addChild(mustBe("symbol", ";"));

    return newTree;
}


ParseTree* CompilerParser::compileReturn() {
    ParseTree* newTree = new ParseTree("returnStatement", "");

    newTree->addChild(mustBe("keyword", "return"));
    newTree->addChild(compileExpression());
    newTree->addChild(mustBe("symbol", ";"));

    return newTree;
}


ParseTree* CompilerParser::compileExpression() {
    ParseTree* newTree = new ParseTree("expression", "");

    if (mustHave("keyword", "skip")) {
        newTree->addChild(mustBe("keyword", "skip"));
    } 
    else if (mustHave("symbol", ";")) {
        return newTree;
    } 
    else if (mustHave("integerConstant", "") || mustHave("stringConstant", "") ||
             mustHave("keyword", "true") || mustHave("keyword", "false") ||
             mustHave("keyword", "null") || mustHave("keyword", "this") ||
             mustHave("identifier", "") || !mustHave("symbol", ")")) {
    newTree->addChild(compileTerm());
            while (mustHave("symbol", "+") || mustHave("symbol", "-") ||
                mustHave("symbol", "*") || mustHave("symbol", "/") ||
                mustHave("symbol", "&") || mustHave("symbol", "|") ||
                mustHave("symbol", "<") || mustHave("symbol", ">") ||
                mustHave("symbol", "=")) {
                    newTree->addChild(mustBe("symbol", ""));
                    newTree->addChild(compileTerm());
            }
    }

  return newTree;
}


ParseTree* CompilerParser::compileTerm() {
    ParseTree* newTree = new ParseTree("newTree", "");
    if (mustHave("integerConstant", "")) {
        newTree->addChild(mustBe("integerConstant", ""));
    }
    else if (mustHave("stringConstant", "")) {
        newTree->addChild(mustBe("stringConstant", ""));
    }
    else if (mustHave("identifier", "")) {
        newTree->addChild(mustBe("identifier", ""));
    if (mustHave("symbol", ".")) {
        newTree->addChild(mustBe("symbol", "."));
        newTree->addChild(mustBe("identifier", ""));
        newTree->addChild(mustBe("symbol", "("));
        newTree->addChild(compileExpressionList());
        newTree->addChild(mustBe("symbol", ")"));
    }

    } else if (mustHave("symbol", "(")) {
        newTree->addChild(mustBe("symbol", "("));
        newTree->addChild(compileExpression());
        newTree->addChild(mustBe("symbol", ")"));
    } else if (mustHave("keyword", "true")) {
        newTree->addChild(mustBe("keyword", "true"));
    } else if (mustHave("keyword", "false")) {
        newTree->addChild(mustBe("keyword", "false"));
    } else if (mustHave("keyword", "null")) {
        newTree->addChild(mustBe("keyword", "null"));
    } else if (mustHave("keyword", "this")) {
        newTree->addChild(mustBe("keyword", "this"));
    } else {
        throw ParseException();
    }
  return newTree;
}


ParseTree* CompilerParser::compileExpressionList() {
    ParseTree* newTree = new ParseTree("expressionList", "");
    newTree->addChild(compileExpression());

    while (mustHave("symbol", ",")) {
        newTree->addChild(mustBe("symbol", ","));
        newTree->addChild(compileExpression());
    }
  return newTree;
}

void CompilerParser::next() {
    if (!tokens.empty()) {
        tokens.pop_front();
    }
}


Token* CompilerParser::current(){
    if (!tokens.empty()) {
        return tokens.front();
    }
    return nullptr;
}


bool CompilerParser::have(std::string expectedType, std::string expectedValue) {
    if (!tokens.empty()) {
        Token* currentToken = current();

        if (currentToken->getType() == expectedType &&
            currentToken->getValue() == expectedValue) {
            return true;

        } else if (currentToken->getType() == expectedType) {
            return true;
        }
    }

    return false;
}

bool CompilerParser::mustHave(std::string expectedType, std::string expectedValue) {

     if (!tokens.empty()) {
        Token* currentToken = current();

        if (currentToken->getType() == expectedType && currentToken->getValue() == expectedValue) {
            return true;
        }
    }
  return false;
}

Token* CompilerParser::mustBe(std::string expectedType, std::string expectedValue) {
    if (mustHave(expectedType, expectedValue)) {
        Token* currentToken = current();
        next();
        return currentToken;
    }
  throw ParseException();
}


const char* ParseException::what() const noexcept {
    return "An exception occurred while parsing!";
}