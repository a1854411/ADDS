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

