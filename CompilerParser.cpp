#include "CompilerParser.h"

CompilerParser::CompilerParser(std::list<Token*> tokens) : tokens(tokens) {
    it = this->tokens.begin();
}

ParseTree* CompilerParser::compileProgram() {
//     //check if program doesn't begin with class
//     if(current()->getValue() != "class"){
//         throw ParseException();

//     }else{

//     //get class
//     ParseTree* newTree = new ParseTree("class", "");
//     if (have("keyword", "class")) {
//         newTree->addChild(new ParseTree(current()->getType(), current()->getValue()));
//         next();
//     } else {
//         throw ParseException();
//     }

//     //get identifier
//     if (have("identifier", "")) {
//         newTree->addChild(new ParseTree(current()->getType(), current()->getValue()));
//         next();
//     } else {
//         throw ParseException();
//     }

//     //get symbols
//     if (have("symbol", "{")) {
//         newTree->addChild(new ParseTree(current()->getType(), current()->getValue()));
//         next();
//     } else {
//         throw ParseException();
//     }

//     if (have("symbol", "}")) {
//         newTree->addChild(new ParseTree(current()->getType(), current()->getValue()));
//         next();
//     } else {
//         throw ParseException();
//     }

//     return newTree;
//     }
}


ParseTree* CompilerParser::compileClass() {
//     //get class
//     ParseTree* newTree = new ParseTree("class", "");
//     if (have("keyword", "class")) {
//         newTree->addChild(new ParseTree(current()->getType(), current()->getValue()));
//         next();
//     } else {
//         throw ParseException();
//     }

//     //get identifier
//     if (have("identifier", "MyClass")) {
//         newTree->addChild(new ParseTree(current()->getType(), current()->getValue()));
//         next();
//     } else {
//         throw ParseException();
//     }

//     //get symbol {
//     if (have("symbol", "{")) {
//         newTree->addChild(new ParseTree(current()->getType(), current()->getValue()));
//         next();
//     } else {
//         throw ParseException();
//     }

//     //get static
//     if (have("keyword", "static") || have("keyword", "field")) {
//         newTree->addChild(new ParseTree(current()->getType(), current()->getValue()));
//         next();
//     } else {
//         throw ParseException();
//     }

//     compileClassVarDec();

//     //get symbol }
//     if (have("symbol", "}")) {
//         newTree->addChild(new ParseTree(current()->getType(), current()->getValue()));
//         next();
//     } else {
//         throw ParseException();
//     }

//     return newTree;
// }

        ParseTree *newTree = new ParseTree("class","");
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


ParseTree* CompilerParser::compileSubroutine() {
    return NULL;
}


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


ParseTree* CompilerParser::compileStatements() {
    return NULL;
}


ParseTree* CompilerParser::compileLet() {
    return NULL;
}


ParseTree* CompilerParser::compileIf() {
    return NULL;
}


ParseTree* CompilerParser::compileWhile() {
    return NULL;
}


ParseTree* CompilerParser::compileDo() {
    return NULL;
}


ParseTree* CompilerParser::compileReturn() {
    return NULL;
}


ParseTree* CompilerParser::compileExpression() {
    ParseTree* newTree = new ParseTree("expression", "");

    if(current()->getValue() != "term"){

        //get keyword skip
        if (have("keyword", "skip")) {
            newTree->addChild(new ParseTree(current()->getType(), current()->getValue()));
            next();
        } else {
        throw ParseException();
        }

    }else{



    return newTree;
    }
}


ParseTree* CompilerParser::compileTerm() {
    ParseTree* newTree = new ParseTree("term", "");

    if(current()->getValue() != "symbol"){

        //get integerConstant 1
        if (have("integerConstant", "1")) {
        newTree->addChild(new ParseTree(current()->getType(), current()->getValue()));
        next();
        } else {
            throw ParseException();
        }  

    } else {

        //get symbol (
        if (have("symbol", "(")) {
            newTree->addChild(new ParseTree(current()->getType(), current()->getValue()));
            next();
        } else {
            throw ParseException();
        }

        //get identifier a
        if (have("identifier", "")) {
            newTree->addChild(new ParseTree(current()->getType(), current()->getValue()));
            next();
        } else {
            throw ParseException();
        }

        //get symbol -
        if (have("symbol", "-")) {
            newTree->addChild(new ParseTree(current()->getType(), current()->getValue()));
            next();
        } else {
            throw ParseException();
        }

        //get identifier b
        if (have("identifier", "")) {
            newTree->addChild(new ParseTree(current()->getType(), current()->getValue()));
            next();
        } else {
            throw ParseException();
        }

        //get symbol )
        if (have("symbol", ")")) {
            newTree->addChild(new ParseTree(current()->getType(), current()->getValue()));
            next();
        } else {
            throw ParseException();
        }


    return newTree;
}
}


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

