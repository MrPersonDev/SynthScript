#include <iostream>

#include "Tokens.h"
#include "Reader.h"
#include "Lexer.h"
#include "Parser.h"
#include "Visitor/PrintVisitor.h"

void run() {
    printf("program would run\n");
}

void buildAndRun(const std::string &path) {
    std::string code = Reader::readFile(path);
    std::vector<Token> tokens = Lexer::parseTokens(code);
//    for (auto t : tokens) {
//        printf("%s\trow:%d\tcol:%d\n", tokenNames[t.tokenType].c_str(), t.lineNumber, t.columnNumber);
//    }

    ProgramNode *program = Parser::parseProgram(tokens);
    auto *visitor = new SemanticAnalysisVisitor();
    program->analyze(visitor, nullptr);

    Error::printBuildStatus();
    if (Error::shouldQuit()) {
        exit(1);
    } else {
        run();
    }
}

void printUsage() {
    std::printf("Usage: sscript <path>\n");
}

int main(int argc, char *argv[]) {
    if (argc == 2 && Reader::fileExists(argv[1])) {
        buildAndRun(argv[1]);
    } else {
        printUsage();
    }
}
