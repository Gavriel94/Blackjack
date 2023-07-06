#include "include/TestingSuite.h"
#include "include/RunGame.h"

int main(int argc, char* argv[]) {
    if (argc > 1 && std::string(argv[1]) == "test") {
        TestingSuite testingSuite = TestingSuite();
        testingSuite.testHost();
    }
    else {
        RunGame game = RunGame();
        game.initialiseGame();
    }
    return 0;
}