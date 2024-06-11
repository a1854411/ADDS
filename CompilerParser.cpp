// #include "CompilerParser.h"

// CompilerParser::CompilerParser(std::list<Token*> tokens) {
//   this->tokens = tokens;
// }


// ParseTree* CompilerParser::compileProgram() {
//     if (!mustHave("keyword", "class")) {
//         throw ParseException();
//     }
//   return compileClass();
// }

// ParseTree* CompilerParser::compileClass() {
//     ParseTree* newTree = new ParseTree("class", "");
//     newTree->addChild(mustBe("keyword", "class"));
//     newTree->addChild(mustBe("identifier", ""));
//     newTree->addChild(mustBe("symbol", "{"));

//     while (mustHave("keyword", "static") || mustHave("keyword", "field")) {
//         newTree->addChild(compileClassVarDec());
//     }

//     while (mustHave("keyword", "constructor") || mustHave("keyword", "function") || mustHave("keyword", "method")) {
//         newTree->addChild(compileSubroutine());

//         while (mustHave("keyword", "static") || mustHave("keyword", "field")) {
//             newTree->addChild(compileClassVarDec());
//         }
//     }

//     newTree->addChild(mustBe("symbol", "}"));

//   return newTree;
// }


// ParseTree* CompilerParser::compileClassVarDec() {
//     ParseTree* newTree = new ParseTree("classVarDec", "");

//     newTree->addChild(mustBe("keyword", ""));
//     newTree->addChild(mustBe("keyword", ""));
//     newTree->addChild(mustBe("identifier", ""));

//     while (mustHave("symbol", ",")) {
//         newTree->addChild(mustBe("symbol", ","));
//         newTree->addChild(mustBe("identifier", ""));
//     }
//     newTree->addChild(mustBe("symbol", ";"));
//     return newTree;
// }


// ParseTree* CompilerParser::compileSubroutine() {
//     std::string class_name;
//     ParseTree* newTree = new ParseTree("subroutine", "");

//     if (mustHave("keyword", "function")) {
//         newTree->addChild(mustBe("keyword", "function"));
//         newTree->addChild(mustBe("keyword", ""));
//     }
//     else if (mustHave("keyword", "constructor")) {
//         newTree->addChild(mustBe("keyword", "constructor"));
//         class_name = current()->getValue();
//         newTree->addChild(mustBe("identifier", ""));
//     }
//     else {
//         newTree->addChild(mustBe("keyword", "method"));
//         newTree->addChild(mustBe("keyword", ""));
//     }

//     newTree->addChild(mustBe("identifier", ""));
//     newTree->addChild(mustBe("symbol", "("));

//     if (mustHave("keyword", "int") || mustHave("keyword", "char") || mustHave("keyword", "boolean") || mustHave("identifier", class_name)) {
//         newTree->addChild(compileParameterList());
//     }

//     newTree->addChild(mustBe("symbol", ")"));

//     newTree->addChild(compileSubroutineBody());

//     return newTree;
// }


// ParseTree* CompilerParser::compileParameterList() {
//     ParseTree* newTree = new ParseTree("parameterList", "");

//     if(mustHave("keyword", "int") || mustHave("keyword", "char") || mustHave("keyword", "boolean")) {
//         newTree->addChild(mustBe("keyword", ""));
//         newTree->addChild(mustBe("identifier", ""));
//     } 
//     else {
//         newTree->addChild(mustBe("identifier", ""));
//         newTree->addChild(mustBe("identifier", ""));
//     }

//     while (mustHave("symbol", ",")) {
//         newTree->addChild(mustBe("symbol", ","));

//         if (mustHave("keyword", "int") || mustHave("keyword", "char") || mustHave("keyword", "boolean")) {
//             newTree->addChild(mustBe("keyword", ""));
//             newTree->addChild(mustBe("identifier", ""));
//         }
//         else {
//             newTree->addChild(mustBe("identifier", ""));
//             newTree->addChild(mustBe("identifier", ""));
//         }
//     }
//     return newTree;
// }


// ParseTree* CompilerParser::compileSubroutineBody() {
//     ParseTree* newTree = new ParseTree("subroutineBody", "");
//     newTree->addChild(mustBe("symbol", "{"));

//     while (mustHave("keyword", "var")) {
//         newTree->addChild(compileVarDec());
//     }

//     if (mustHave("keyword", "let") || mustHave("keyword", "do") || mustHave("keyword", "return") || mustHave("keyword", "if") || mustHave("keyword", "while")) {
//         newTree->addChild(compileStatements());
//     }

//     newTree->addChild(mustBe("symbol", "}"));
//     return newTree;
// }


// ParseTree* CompilerParser::compileVarDec() {
//     ParseTree* newTree = new ParseTree("varDec", "");

//     newTree->addChild(mustBe("keyword", ""));

//     if (mustHave("keyword", "int") || mustHave("keyword", "char") || mustHave("keyword", "boolean")) {
//         newTree->addChild(mustBe("keyword", ""));
//         newTree->addChild(mustBe("identifier", ""));
//     } 
//     else {
//         newTree->addChild(mustBe("identifier", ""));
//         newTree->addChild(mustBe("identifier", ""));
//     }

//     while (mustHave("symbol", ",")) {
//         newTree->addChild(mustBe("symbol", ","));
//         if (mustHave("keyword", "int") || mustHave("keyword", "char") || mustHave("keyword", "boolean")) {
//             newTree->addChild(mustBe("identifier", ""));
//         } 
//         else {
//             newTree->addChild(mustBe("identifier", ""));
//         }
//     }
//     newTree->addChild(mustBe("symbol", ";"));

//     return newTree;
// }


// ParseTree* CompilerParser::compileStatements() {
//     ParseTree* newTree = new ParseTree("statements", "");

//     if (mustHave("symbol", "{")) {
//         throw ParseException();
//     }

//     while (!mustHave("symbol", "}")) {
//         if (mustHave("keyword", "let")) {
//         newTree->addChild(compileLet());
//     } 
//     else if (mustHave("keyword", "do")) {
//         newTree->addChild(compileDo());
//     } 
//     else if (mustHave("keyword", "return")) {
//         newTree->addChild(compileReturn());
//     } 
//     else if (mustHave("keyword", "if")) {
//         newTree->addChild(compileIf());
//     } 
//     else if (mustHave("keyword", "while")) {
//         newTree->addChild(compileWhile());
//     } 
//     else {
//         break;
//     }
//   }
//   return newTree;
// }


// ParseTree* CompilerParser::compileLet() {
//     ParseTree* newTree = new ParseTree("letStatement", "");

//     newTree->addChild(mustBe("keyword", "let"));
//     newTree->addChild(mustBe("identifier", ""));
//     newTree->addChild(mustBe("symbol", "="));
//     newTree->addChild(compileExpression());
//     newTree->addChild(mustBe("symbol", ";"));

//     return newTree;
// }


// ParseTree* CompilerParser::compileIf() {
//   ParseTree* newTree = new ParseTree("ifStatement", "");
//     newTree->addChild(mustBe("keyword", "if"));
//     newTree->addChild(mustBe("symbol", "("));
//     newTree->addChild(compileExpression());
//     newTree->addChild(mustBe("symbol", ")"));
//     newTree->addChild(mustBe("symbol", "{"));
//     newTree->addChild(compileStatements());
//     newTree->addChild(mustBe("symbol", "}"));

//     if (mustHave("keyword", "else")) {
//         newTree->addChild(mustBe("keyword", "else"));
//         newTree->addChild(mustBe("symbol", "{"));
//         newTree->addChild(compileStatements());
//         newTree->addChild(mustBe("symbol", "}"));
//     }
//   return newTree;
// }

// ParseTree* CompilerParser::compileWhile() {
//     ParseTree* newTree = new ParseTree("whileStatement", "");

//     newTree->addChild(mustBe("keyword", "while"));
//     newTree->addChild(mustBe("symbol", "("));
//     newTree->addChild(compileExpression());
//     newTree->addChild(mustBe("symbol", ")"));
//     newTree->addChild(mustBe("symbol", "{"));
//     newTree->addChild(compileStatements());
//     newTree->addChild(mustBe("symbol", "}"));

//     return newTree;
// }


// ParseTree* CompilerParser::compileDo() {
//     ParseTree* newTree = new ParseTree("doStatement", "");

//     newTree->addChild(mustBe("keyword", "do"));
//     newTree->addChild(compileExpression());
//     newTree->addChild(mustBe("symbol", ";"));

//     return newTree;
// }


// ParseTree* CompilerParser::compileReturn() {
//     ParseTree* newTree = new ParseTree("returnStatement", "");

//     newTree->addChild(mustBe("keyword", "return"));
//     newTree->addChild(compileExpression());
//     newTree->addChild(mustBe("symbol", ";"));

//     return newTree;
// }


// ParseTree* CompilerParser::compileExpression() {
//     ParseTree* newTree = new ParseTree("expression", "");

//     if (mustHave("keyword", "skip")) {
//         newTree->addChild(mustBe("keyword", "skip"));
//     } 
//     else if (mustHave("symbol", ";")) {
//         return newTree;
//     } 
//     else if (mustHave("integerConstant", "") || mustHave("stringConstant", "") ||
//              mustHave("keyword", "true") || mustHave("keyword", "false") ||
//              mustHave("keyword", "null") || mustHave("keyword", "this") ||
//              mustHave("identifier", "") || !mustHave("symbol", ")")) {
//     newTree->addChild(compileTerm());
//             while (mustHave("symbol", "+") || mustHave("symbol", "-") ||
//                 mustHave("symbol", "*") || mustHave("symbol", "/") ||
//                 mustHave("symbol", "&") || mustHave("symbol", "|") ||
//                 mustHave("symbol", "<") || mustHave("symbol", ">") ||
//                 mustHave("symbol", "=")) {
//                     newTree->addChild(mustBe("symbol", ""));
//                     newTree->addChild(compileTerm());
//             }
//     }

//   return newTree;
// }


// ParseTree* CompilerParser::compileTerm() {
//     ParseTree* newTree = new ParseTree("newTree", "");
//     if (mustHave("integerConstant", "")) {
//         newTree->addChild(mustBe("integerConstant", ""));
//     }
//     else if (mustHave("stringConstant", "")) {
//         newTree->addChild(mustBe("stringConstant", ""));
//     }
//     else if (mustHave("identifier", "")) {
//         newTree->addChild(mustBe("identifier", ""));
//     if (mustHave("symbol", ".")) {
//         newTree->addChild(mustBe("symbol", "."));
//         newTree->addChild(mustBe("identifier", ""));
//         newTree->addChild(mustBe("symbol", "("));
//         newTree->addChild(compileExpressionList());
//         newTree->addChild(mustBe("symbol", ")"));
//     }

//     } else if (mustHave("symbol", "(")) {
//         newTree->addChild(mustBe("symbol", "("));
//         newTree->addChild(compileExpression());
//         newTree->addChild(mustBe("symbol", ")"));
//     } else if (mustHave("keyword", "true")) {
//         newTree->addChild(mustBe("keyword", "true"));
//     } else if (mustHave("keyword", "false")) {
//         newTree->addChild(mustBe("keyword", "false"));
//     } else if (mustHave("keyword", "null")) {
//         newTree->addChild(mustBe("keyword", "null"));
//     } else if (mustHave("keyword", "this")) {
//         newTree->addChild(mustBe("keyword", "this"));
//     } else {
//         throw ParseException();
//     }
//   return newTree;
// }


// ParseTree* CompilerParser::compileExpressionList() {
//     ParseTree* newTree = new ParseTree("expressionList", "");
//     newTree->addChild(compileExpression());

//     while (mustHave("symbol", ",")) {
//         newTree->addChild(mustBe("symbol", ","));
//         newTree->addChild(compileExpression());
//     }
//   return newTree;
// }

// void CompilerParser::next() {
//     if (!tokens.empty()) {
//         tokens.pop_front();
//     }
// }


// Token* CompilerParser::current(){
//     if (!tokens.empty()) {
//         return tokens.front();
//     }
//     return nullptr;
// }


// bool CompilerParser::have(std::string expectedType, std::string expectedValue) {
//     if (!tokens.empty()) {
//         Token* currentToken = current();

//         if (currentToken->getType() == expectedType &&
//             currentToken->getValue() == expectedValue) {
//             return true;

//         } else if (currentToken->getType() == expectedType) {
//             return true;
//         }
//     }

//     return false;
// }

// bool CompilerParser::mustHave(std::string expectedType, std::string expectedValue) {

//      if (!tokens.empty()) {
//         Token* currentToken = current();

//         if (currentToken->getType() == expectedType && currentToken->getValue() == expectedValue) {
//             return true;
//         }
//     }
//   return false;
// }

// Token* CompilerParser::mustBe(std::string expectedType, std::string expectedValue) {
//     if (mustHave(expectedType, expectedValue)) {
//         Token* currentToken = current();
//         next();
//         return currentToken;
//     }
//   throw ParseException();
// }


// const char* ParseException::what() const noexcept {
//     return "An exception occurred while parsing!";
// }

#include "CompilerParser.h"

/**
 * Constructor for the CompilerParser
 * @param tokens A linked list of tokens to be parsed
 */
CompilerParser::CompilerParser(std::list<Token*> tokens) {
  this->tokens = tokens;
}

/**
 * Generates a parse tree for a single program
 * @return a ParseTree
 */
ParseTree* CompilerParser::compileProgram() {
  // the program doesn't begin with a class
  if (!mustHave("keyword", "class")) {
    throw ParseException();
  }
  // the program begin with a class
  return compileClass();
}

/**
 * Generates a parse tree for a single class
 * @return a ParseTree
 */
ParseTree* CompilerParser::compileClass() {
  ParseTree* classNode = new ParseTree("class", "");
  classNode->addChild(mustBe("keyword", "class"));
  classNode->addChild(mustBe("identifier", ""));
  classNode->addChild(mustBe("symbol", "{"));

  while (mustHave("keyword", "static") || mustHave("keyword", "field")) {
    classNode->addChild(compileClassVarDec());
  }

  while (mustHave("keyword", "constructor") ||
         mustHave("keyword", "function") || mustHave("keyword", "method")) {
    classNode->addChild(compileSubroutine());

    while (mustHave("keyword", "static") || mustHave("keyword", "field")) {
      classNode->addChild(compileClassVarDec());
    }
  }

  classNode->addChild(mustBe("symbol", "}"));

  return classNode;
}

/**
 * Generates a parse tree for a static variable declaration or field declaration
 * @return a ParseTree
 */
ParseTree* CompilerParser::compileClassVarDec() {
  ParseTree* varDecNode = new ParseTree("classVarDec", "");
  varDecNode->addChild(mustBe("keyword", ""));
  varDecNode->addChild(mustBe("keyword", ""));
  varDecNode->addChild(mustBe("identifier", ""));
  while (mustHave("symbol", ",")) {
    varDecNode->addChild(mustBe("symbol", ","));
    varDecNode->addChild(mustBe("identifier", ""));
  }
  varDecNode->addChild(mustBe("symbol", ";"));
  return varDecNode;
}

/**
 * Generates a parse tree for a method, function, or constructor
 * @return a ParseTree
 */
ParseTree* CompilerParser::compileSubroutine() {
  std::string className;
  ParseTree* subroutine = new ParseTree("subroutine", "");
  if (mustHave("keyword", "function")) {
    subroutine->addChild(mustBe("keyword", "function"));
    subroutine->addChild(mustBe("keyword", ""));
  } else if (mustHave("keyword", "constructor")) {
    subroutine->addChild(mustBe("keyword", "constructor"));
    className = current()->getValue();
    subroutine->addChild(mustBe("identifier", ""));
  } else {
    subroutine->addChild(mustBe("keyword", "method"));
    subroutine->addChild(mustBe("keyword", ""));
  }
  subroutine->addChild(mustBe("identifier", ""));
  subroutine->addChild(mustBe("symbol", "("));
  if (mustHave("keyword", "int") || mustHave("keyword", "char") ||
      mustHave("keyword", "boolean") || mustHave("identifier", className)) {
    subroutine->addChild(compileParameterList());
  }
  subroutine->addChild(mustBe("symbol", ")"));

  subroutine->addChild(compileSubroutineBody());

  return subroutine;
}

/**
 * Generates a parse tree for a subroutine's parameters
 * @return a ParseTree
 */
ParseTree* CompilerParser::compileParameterList() {
  ParseTree* parameterList = new ParseTree("parameterList", "");
  if (mustHave("keyword", "int") || mustHave("keyword", "char") ||
      mustHave("keyword", "boolean")) {
    parameterList->addChild(mustBe("keyword", ""));
    parameterList->addChild(mustBe("identifier", ""));
  } else {
    parameterList->addChild(mustBe("identifier", ""));
    parameterList->addChild(mustBe("identifier", ""));
  }

  while (mustHave("symbol", ",")) {
    parameterList->addChild(mustBe("symbol", ","));
    if (mustHave("keyword", "int") || mustHave("keyword", "char") ||
        mustHave("keyword", "boolean")) {
      parameterList->addChild(mustBe("keyword", ""));
      parameterList->addChild(mustBe("identifier", ""));
    } else {
      parameterList->addChild(mustBe("identifier", ""));
      parameterList->addChild(mustBe("identifier", ""));
    }
  }
  return parameterList;
}

/**
 * Generates a parse tree for a subroutine's body
 * @return a ParseTree
 */
ParseTree* CompilerParser::compileSubroutineBody() {
  ParseTree* subroutineBody = new ParseTree("subroutineBody", "");
  subroutineBody->addChild(mustBe("symbol", "{"));
  while (mustHave("keyword", "var")) {
    subroutineBody->addChild(compileVarDec());
  }
  if (mustHave("keyword", "let") || mustHave("keyword", "do") ||
      mustHave("keyword", "return") || mustHave("keyword", "if") ||
      mustHave("keyword", "while")) {
    subroutineBody->addChild(compileStatements());
  }

  subroutineBody->addChild(mustBe("symbol", "}"));
  return subroutineBody;
}

/**
 * Generates a parse tree for a subroutine variable declaration
 * @return a ParseTree
 */
ParseTree* CompilerParser::compileVarDec() {
  ParseTree* varDecNode = new ParseTree("varDec", "");
  varDecNode->addChild(mustBe("keyword", ""));
  if (mustHave("keyword", "int") || mustHave("keyword", "char") ||
      mustHave("keyword", "boolean")) {
    varDecNode->addChild(mustBe("keyword", ""));
    varDecNode->addChild(mustBe("identifier", ""));
  } else {
    varDecNode->addChild(mustBe("identifier", ""));
    varDecNode->addChild(mustBe("identifier", ""));
  }
  while (mustHave("symbol", ",")) {
    varDecNode->addChild(mustBe("symbol", ","));
    if (mustHave("keyword", "int") || mustHave("keyword", "char") ||
        mustHave("keyword", "boolean")) {
      varDecNode->addChild(mustBe("identifier", ""));
    } else {
      varDecNode->addChild(mustBe("identifier", ""));
    }
  }
  varDecNode->addChild(mustBe("symbol", ";"));
  return varDecNode;
}

/**
 * Generates a parse tree for a series of statements
 * @return a ParseTree
 */
ParseTree* CompilerParser::compileStatements() {
  ParseTree* statements = new ParseTree("statements", "");
  if (mustHave("symbol", "{")) {
    throw ParseException();
  }
  while (!mustHave("symbol", "}")) {
    if (mustHave("keyword", "let")) {
      statements->addChild(compileLet());
    } else if (mustHave("keyword", "do")) {
      statements->addChild(compileDo());
    } else if (mustHave("keyword", "return")) {
      statements->addChild(compileReturn());
    } else if (mustHave("keyword", "if")) {
      statements->addChild(compileIf());
    } else if (mustHave("keyword", "while")) {
      statements->addChild(compileWhile());
    } else {
      break;
    }
  }
  return statements;
}

/**
 * Generates a parse tree for a let statement
 * @return a ParseTree
 */
ParseTree* CompilerParser::compileLet() {
  ParseTree* letStatement = new ParseTree("letStatement", "");
  letStatement->addChild(mustBe("keyword", "let"));
  letStatement->addChild(mustBe("identifier", ""));
  letStatement->addChild(mustBe("symbol", "="));
  letStatement->addChild(compileExpression());
  letStatement->addChild(mustBe("symbol", ";"));
  return letStatement;
}

/**
 * Generates a parse tree for an if statement
 * @return a ParseTree
 */
ParseTree* CompilerParser::compileIf() {
  ParseTree* ifStatement = new ParseTree("ifStatement", "");
  ifStatement->addChild(mustBe("keyword", "if"));
  ifStatement->addChild(mustBe("symbol", "("));
  ifStatement->addChild(compileExpression());
  ifStatement->addChild(mustBe("symbol", ")"));
  ifStatement->addChild(mustBe("symbol", "{"));
  ifStatement->addChild(compileStatements());
  ifStatement->addChild(mustBe("symbol", "}"));
  if (mustHave("keyword", "else")) {
    ifStatement->addChild(mustBe("keyword", "else"));
    ifStatement->addChild(mustBe("symbol", "{"));
    ifStatement->addChild(compileStatements());
    ifStatement->addChild(mustBe("symbol", "}"));
  }

  return ifStatement;
}

/**
 * Generates a parse tree for a while statement
 * @return a ParseTree
 */
ParseTree* CompilerParser::compileWhile() {
  ParseTree* whileStatement = new ParseTree("whileStatement", "");
  whileStatement->addChild(mustBe("keyword", "while"));
  whileStatement->addChild(mustBe("symbol", "("));
  whileStatement->addChild(compileExpression());
  whileStatement->addChild(mustBe("symbol", ")"));
  whileStatement->addChild(mustBe("symbol", "{"));
  whileStatement->addChild(compileStatements());
  whileStatement->addChild(mustBe("symbol", "}"));
  return whileStatement;
  ;
}

/**
 * Generates a parse tree for a do statement
 * @return a ParseTree
 */
ParseTree* CompilerParser::compileDo() {
  ParseTree* doStatement = new ParseTree("doStatement", "");
  doStatement->addChild(mustBe("keyword", "do"));
  doStatement->addChild(compileExpression());
  doStatement->addChild(mustBe("symbol", ";"));
  return doStatement;
}

/**
 * Generates a parse tree for a return statement
 * @return a ParseTree
 */
ParseTree* CompilerParser::compileReturn() {
  ParseTree* returnStatement = new ParseTree("returnStatement", "");
  returnStatement->addChild(mustBe("keyword", "return"));
  returnStatement->addChild(compileExpression());
  returnStatement->addChild(mustBe("symbol", ";"));
  return returnStatement;
}

/**
 * Generates a parse tree for an expression
 * @return a ParseTree
 */
ParseTree* CompilerParser::compileExpression() {
  ParseTree* expression = new ParseTree("expression", "");
  if (mustHave("keyword", "skip")) {
    expression->addChild(mustBe("keyword", "skip"));
  } else if (mustHave("symbol", ";")) {
    return expression;
  } else if (have("integerConstant", "") || have("stringConstant", "") ||
             mustHave("keyword", "true") || mustHave("keyword", "false") ||
             mustHave("keyword", "null") || mustHave("keyword", "this") ||
             have("identifier", "") || !mustHave("symbol", ")")) {
    expression->addChild(compileTerm());
    while (mustHave("symbol", "+") || mustHave("symbol", "-") ||
           mustHave("symbol", "*") || mustHave("symbol", "/") ||
           mustHave("symbol", "&") || mustHave("symbol", "|") ||
           mustHave("symbol", "<") || mustHave("symbol", ">") ||
           mustHave("symbol", "=")) {
      expression->addChild(mustBe("symbol", ""));
      expression->addChild(compileTerm());
    }
  }

  return expression;
}

/**
 * Generates a parse tree for an expression term
 * @return a ParseTree
 */
ParseTree* CompilerParser::compileTerm() {
  ParseTree* term = new ParseTree("term", "");
  if (have("integerConstant", "")) {
    term->addChild(mustBe("integerConstant", ""));
  } else if (have("stringConstant", "")) {
    term->addChild(mustBe("stringConstant", ""));
  } else if (have("identifier", "")) {
    term->addChild(mustBe("identifier", ""));
    if (mustHave("symbol", ".")) {
      term->addChild(mustBe("symbol", "."));
      term->addChild(mustBe("identifier", ""));
      term->addChild(mustBe("symbol", "("));
      term->addChild(compileExpressionList());
      term->addChild(mustBe("symbol", ")"));
    }

  } else if (mustHave("symbol", "(")) {
    term->addChild(mustBe("symbol", "("));
    term->addChild(compileExpression());
    term->addChild(mustBe("symbol", ")"));
  } else if (mustHave("keyword", "true")) {
    term->addChild(mustBe("keyword", "true"));
  } else if (mustHave("keyword", "false")) {
    term->addChild(mustBe("keyword", "false"));
  } else if (mustHave("keyword", "null")) {
    term->addChild(mustBe("keyword", "null"));
  } else if (mustHave("keyword", "this")) {
    term->addChild(mustBe("keyword", "this"));
  } else {
    throw ParseException();
  }
  return term;
}

/**
 * Generates a parse tree for an expression list
 * @return a ParseTree
 */
ParseTree* CompilerParser::compileExpressionList() {
  ParseTree* expressionList = new ParseTree("expressionList", "");
  expressionList->addChild(compileExpression());
  while (mustHave("symbol", ",")) {
    expressionList->addChild(mustBe("symbol", ","));
    expressionList->addChild(compileExpression());
  }
  return expressionList;
}

/**
 * Advance to the next token
 */
void CompilerParser::next() {
  // check if token list isn't empty
  if (!tokens.empty()) {
    // go to the next element
    tokens.pop_front();
  }
}

/**
 * Return the current token
 * @return the Token
 */
Token* CompilerParser::current() {
  // check if token list isn't empty
  if (!tokens.empty()) {
    // go to the front element
    return tokens.front();
  }
  return nullptr;
}

/**
 * Check if the current token matches the expected type and value.
 * @return true if a match, false otherwise
 */
bool CompilerParser::have(std::string expectedType, std::string expectedValue) {
  // check if token list isn't empty
  if (!tokens.empty()) {
    // go to the current token
    Token* currentToken = current();
    // if current token == type AND value
    if (currentToken->getType() == expectedType &&
        currentToken->getValue() == expectedValue) {
      return true;
      // if current token == type
    } else if (currentToken->getType() == expectedType) {
      return true;
    }
  }
  // if current token != type AND/OR value
  return false;
}

bool CompilerParser::mustHave(std::string expectedType,
                              std::string expectedValue) {
  // check if token list isn't empty
  if (!tokens.empty()) {
    // go to the current token
    Token* currentToken = current();
    // if current token == type AND value
    if (currentToken->getType() == expectedType &&
        currentToken->getValue() == expectedValue) {
      return true;
    }
  }
  // if current token != type AND/OR value
  return false;
}

/**
 * Check if the current token matches the expected type and value.
 * If so, advance to the next token, returning the current token, otherwise
 * throw a ParseException.
 * @return the current token before advancing
 */
Token* CompilerParser::mustBe(std::string expectedType,
                              std::string expectedValue) {
  if (have(expectedType, expectedValue)) {
    Token* currentToken = current();
    next();
    return currentToken;
  }
  throw ParseException();
}

const char* ParseException::what() const noexcept {
    return "An exception occurred while parsing!";
}
