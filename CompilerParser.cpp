#include "CompilerParser.h"

CompilerParser::CompilerParser(std::list<Token*> tokens) : tokens(tokens) {
    it = this->tokens.begin();
}

ParseTree* CompilerParser::compileProgram() {
    return compileClass();
}

ParseTree* CompilerParser::compileClass() {
    ParseTree* newTree = new ParseTree("class", "");
    newTree->addChild(new ParseTree("keyword", mustBe("keyword", "class")->getValue()));
    newTree->addChild(new ParseTree("identifier", mustBe("identifier", "")->getValue()));
    newTree->addChild(new ParseTree("symbol", mustBe("symbol", "{")->getValue()));

    while (have("keyword", "static") || have("keyword", "field")) {
        newTree->addChild(compileClassVarDec());
    }

    while (have("keyword", "constructor") || have("keyword", "function") || have("keyword", "method")) {
        newTree->addChild(compileSubroutine());
    }

    newTree->addChild(new ParseTree("symbol", mustBe("symbol", "}")->getValue()));
    return newTree;
}

ParseTree* CompilerParser::compileClassVarDec() {
    ParseTree* newTree = new ParseTree("classVarDec", "");
    newTree->addChild(new ParseTree("keyword", mustBe("keyword", "")->getValue()));
    newTree->addChild(new ParseTree("keyword", mustBe("keyword", "")->getValue()));
    newTree->addChild(new ParseTree("identifier", mustBe("identifier", "")->getValue()));

    while (have("symbol", ",")) {
        newTree->addChild(new ParseTree("symbol", mustBe("symbol", ",")->getValue()));
        newTree->addChild(new ParseTree("identifier", mustBe("identifier", "")->getValue()));
    }

    newTree->addChild(new ParseTree("symbol", mustBe("symbol", ";")->getValue()));
    return newTree;
}

ParseTree* CompilerParser::compileSubroutine() {
    ParseTree* newTree = new ParseTree("subroutineDec", "");

    newTree->addChild(new ParseTree("keyword", mustBe("keyword", "")->getValue()));

    if (have("keyword", "void")) {
        newTree->addChild(new ParseTree("keyword", mustBe("keyword", "void")->getValue()));
    } else {
        newTree->addChild(new ParseTree("keyword", mustBe("keyword", "")->getValue()));
    }

    newTree->addChild(new ParseTree("identifier", mustBe("identifier", "")->getValue()));
    newTree->addChild(new ParseTree("symbol", mustBe("symbol", "(")->getValue()));
    newTree->addChild(compileParameterList());
    newTree->addChild(new ParseTree("symbol", mustBe("symbol", ")")->getValue()));
    newTree->addChild(compileSubroutineBody());

    return newTree;
}

ParseTree* CompilerParser::compileParameterList() {
    ParseTree* newTree = new ParseTree("parameterList", "");

    if (!have("symbol", ")")) {
        newTree->addChild(new ParseTree("keyword", mustBe("keyword", "")->getValue()));
        newTree->addChild(new ParseTree("identifier", mustBe("identifier", "")->getValue()));

        while (have("symbol", ",")) {
            newTree->addChild(new ParseTree("symbol", mustBe("symbol", ",")->getValue()));
            newTree->addChild(new ParseTree("keyword", mustBe("keyword", "")->getValue()));
            newTree->addChild(new ParseTree("identifier", mustBe("identifier", "")->getValue()));
        }
    }

    return newTree;
}

ParseTree* CompilerParser::compileSubroutineBody() {
    ParseTree* newTree = new ParseTree("subroutineBody", "");
    newTree->addChild(new ParseTree("symbol", mustBe("symbol", "{")->getValue()));

    while (have("keyword", "var")) {
        newTree->addChild(compileVarDec());
    }

    newTree->addChild(compileStatements());
    newTree->addChild(new ParseTree("symbol", mustBe("symbol", "}")->getValue()));
    return newTree;
}

ParseTree* CompilerParser::compileVarDec() {
    ParseTree* newTree = new ParseTree("varDec", "");
    newTree->addChild(new ParseTree("keyword", mustBe("keyword", "var")->getValue()));
    newTree->addChild(new ParseTree("keyword", mustBe("keyword", "")->getValue()));
    newTree->addChild(new ParseTree("identifier", mustBe("identifier", "")->getValue()));

    while (have("symbol", ",")) {
        newTree->addChild(new ParseTree("symbol", mustBe("symbol", ",")->getValue()));
        newTree->addChild(new ParseTree("identifier", mustBe("identifier", "")->getValue()));
    }

    newTree->addChild(new ParseTree("symbol", mustBe("symbol", ";")->getValue()));
    return newTree;
}

ParseTree* CompilerParser::compileStatements() {
    ParseTree* newTree = new ParseTree("statements", "");

    while (have("keyword", "let") || have("keyword", "if") || have("keyword", "while") || have("keyword", "do") || have("keyword", "return")) {
        if (have("keyword", "let")) {
            newTree->addChild(compileLet());
        } else if (have("keyword", "if")) {
            newTree->addChild(compileIf());
        } else if (have("keyword", "while")) {
            newTree->addChild(compileWhile());
        } else if (have("keyword", "do")) {
            newTree->addChild(compileDo());
        } else if (have("keyword", "return")) {
            newTree->addChild(compileReturn());
        }
    }

    return newTree;
}

ParseTree* CompilerParser::compileLet() {
    ParseTree* newTree = new ParseTree("letStatement", "");
    newTree->addChild(new ParseTree("keyword", mustBe("keyword", "let")->getValue()));
    newTree->addChild(new ParseTree("identifier", mustBe("identifier", "")->getValue()));

    if (have("symbol", "[")) {
        newTree->addChild(new ParseTree("symbol", mustBe("symbol", "[")->getValue()));
        newTree->addChild(compileExpression());
        newTree->addChild(new ParseTree("symbol", mustBe("symbol", "]")->getValue()));
    }

    newTree->addChild(new ParseTree("symbol", mustBe("symbol", "=")->getValue()));
    newTree->addChild(compileExpression());
    newTree->addChild(new ParseTree("symbol", mustBe("symbol", ";")->getValue()));
    return newTree;
}

ParseTree* CompilerParser::compileIf() {
    ParseTree* newTree = new ParseTree("ifStatement", "");
    newTree->addChild(new ParseTree("keyword", mustBe("keyword", "if")->getValue()));
    newTree->addChild(new ParseTree("symbol", mustBe("symbol", "(")->getValue()));
    newTree->addChild(compileExpression());
    newTree->addChild(new ParseTree("symbol", mustBe("symbol", ")")->getValue()));
    newTree->addChild(new ParseTree("symbol", mustBe("symbol", "{")->getValue()));
    newTree->addChild(compileStatements());
    newTree->addChild(new ParseTree("symbol", mustBe("symbol", "}")->getValue()));

    if (have("keyword", "else")) {
        newTree->addChild(new ParseTree("keyword", mustBe("keyword", "else")->getValue()));
        newTree->addChild(new ParseTree("symbol", mustBe("symbol", "{")->getValue()));
        newTree->addChild(compileStatements());
        newTree->addChild(new ParseTree("symbol", mustBe("symbol", "}")->getValue()));
    }

    return newTree;
}

ParseTree* CompilerParser::compileWhile() {
    ParseTree* newTree = new ParseTree("whileStatement", "");
    newTree->addChild(new ParseTree("keyword", mustBe("keyword", "while")->getValue()));
    newTree->addChild(new ParseTree("symbol", mustBe("symbol", "(")->getValue()));
    newTree->addChild(compileExpression());
    newTree->addChild(new ParseTree("symbol", mustBe("symbol", ")")->getValue()));
    newTree->addChild(new ParseTree("symbol", mustBe("symbol", "{")->getValue()));
    newTree->addChild(compileStatements());
    newTree->addChild(new ParseTree("symbol", mustBe("symbol", "}")->getValue()));
    return newTree;
}

ParseTree* CompilerParser::compileDo() {
    ParseTree* newTree = new ParseTree("doStatement", "");
    newTree->addChild(new ParseTree("keyword", mustBe("keyword", "do")->getValue()));
    newTree->addChild(compileExpression());
    newTree->addChild(new ParseTree("symbol", mustBe("symbol", ";")->getValue()));
    return newTree;
}

ParseTree* CompilerParser::compileReturn() {
    ParseTree* newTree = new ParseTree("returnStatement", "");
    newTree->addChild(new ParseTree("keyword", mustBe("keyword", "return")->getValue()));

    if (!have("symbol", ";")) {
        newTree->addChild(compileExpression());
    }

    newTree->addChild(new ParseTree("symbol", mustBe("symbol", ";")->getValue()));
    return newTree;
}

ParseTree* CompilerParser::compileExpression() {
    ParseTree* newTree = new ParseTree("expression", "");
    newTree->addChild(compileTerm());

    while (have("symbol", "+") || have("symbol", "-") || have("symbol", "*") || have("symbol", "/") || have("symbol", "&") || have("symbol", "|") || have("symbol", "<") || have("symbol", ">") || have("symbol", "=")) {
        newTree->addChild(new ParseTree("symbol", mustBe("symbol", "")->getValue()));
        newTree->addChild(compileTerm());
    }

    return newTree;
}

ParseTree* CompilerParser::compileTerm() {
    ParseTree* newTree = new ParseTree("term", "");

    if (have("integerConstant", "")) {
        newTree->addChild(new ParseTree("integerConstant", mustBe("integerConstant", "")->getValue()));
    } else if (have("stringConstant", "")) {
        newTree->addChild(new ParseTree("stringConstant", mustBe("stringConstant", "")->getValue()));
    } else if (have("keyword", "true") || have("keyword", "false") || have("keyword", "null") || have("keyword", "this")) {
        newTree->addChild(new ParseTree("keyword", mustBe("keyword", "")->getValue()));
    } else if (have("identifier", "")) {
        newTree->addChild(new ParseTree("identifier", mustBe("identifier", "")->getValue()));

        if (have("symbol", "[")) {
            newTree->addChild(new ParseTree("symbol", mustBe("symbol", "[")->getValue()));
            newTree->addChild(compileExpression());
            newTree->addChild(new ParseTree("symbol", mustBe("symbol", "]")->getValue()));
        } else if (have("symbol", "(")) {
            newTree->addChild(new ParseTree("symbol", mustBe("symbol", "(")->getValue()));
            newTree->addChild(compileExpressionList());
            newTree->addChild(new ParseTree("symbol", mustBe("symbol", ")")->getValue()));
        } else if (have("symbol", ".")) {
            newTree->addChild(new ParseTree("symbol", mustBe("symbol", ".")->getValue()));
            newTree->addChild(new ParseTree("identifier", mustBe("identifier", "")->getValue()));
            newTree->addChild(new ParseTree("symbol", mustBe("symbol", "(")->getValue()));
            newTree->addChild(compileExpressionList());
            newTree->addChild(new ParseTree("symbol", mustBe("symbol", ")")->getValue()));
        }
    } else if (have("symbol", "(")) {
        newTree->addChild(new ParseTree("symbol", mustBe("symbol", "(")->getValue()));
        newTree->addChild(compileExpression());
        newTree->addChild(new ParseTree("symbol", mustBe("symbol", ")")->getValue()));
    } else if (have("symbol", "-") || have("symbol", "~")) {
        newTree->addChild(new ParseTree("symbol", mustBe("symbol", "")->getValue()));
        newTree->addChild(compileTerm());
    } else {
        throw ParseException();
    }

    return newTree;
}

ParseTree* CompilerParser::compileExpressionList() {
    ParseTree* newTree = new ParseTree("expressionList", "");

    if (!have("symbol", ")")) {
        newTree->addChild(compileExpression());

        while (have("symbol", ",")) {
            newTree->addChild(new ParseTree("symbol", mustBe("symbol", ",")->getValue()));
            newTree->addChild(compileExpression());
        }
    }

    return newTree;
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
        return token->getType() == expectedType && (expectedValue.empty() || token->getValue() == expectedValue);
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



// bool CompilerParser::have(std::string expectedType, std::string expectedValue) {
//     Token* token = current();
//     if (token) {
//         return token->getType() == expectedType && token->getValue() == expectedValue;
//     }
//     return false;
// }

// Token* CompilerParser::mustBe(std::string expectedType, std::string expectedValue) {
//     if (have(expectedType, expectedValue)) {
//         Token* token = current();
//         next();
//         return token;
//     } else {
//         throw ParseException();
//     }
// }
