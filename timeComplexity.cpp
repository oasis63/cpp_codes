#include <bits/stdc++.h>
#include <clang/AST/AST.h>
#include <clang/AST/ASTConsumer.h>
#include <clang/AST/RecursiveASTVisitor.h>
#include <clang/Frontend/FrontendAction.h>
#include <clang/Tooling/Tooling.h>

using namespace clang;
using namespace std;

class ComplexityAnalyzer : public RecursiveASTVisitor<ComplexityAnalyzer> {
  public:
    bool VisitStmt(Stmt *s) {
        if (isa<ForStmt>(s)) {
            std::cout << "Detected a for loop. Estimating O(n) complexity.\n";
        } else if (isa<WhileStmt>(s)) {
            std::cout << "Detected a while loop. Estimating O(n) complexity.\n";
        } else if (isa<IfStmt>(s)) {
            std::cout << "Detected an if statement. Analyzing branches...\n";
        }
        // Add more conditions for function calls, recursion, etc.
        return true;
    }
};

class ComplexityConsumer : public ASTConsumer {
  public:
    void HandleTranslationUnit(ASTContext &context) override {
        ComplexityAnalyzer analyzer;
        analyzer.TraverseDecl(context.getTranslationUnitDecl());
    }
};

class ComplexityAction : public ASTFrontendAction {
  public:
    std::unique_ptr<ASTConsumer> CreateASTConsumer(CompilerInstance &CI,
                                                   StringRef file) override {
        return std::make_unique<ComplexityConsumer>();
    }
};

int main(int argc, const char **argv) {
    cout << "started main method " << endl;
    if (argc > 1) {
        clang::tooling::runToolOnCode(std::make_unique<ComplexityAction>(),
                                      argv[1]);
    } else {
        std::cerr << "Please provide C++ code as input.\n";
    }
    return 0;
}

/*
clang++ -o timeComplexity timeComplexity.cpp $(llvm-config --cxxflags --ldflags
--system-libs --libs all)

*/
