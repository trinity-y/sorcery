#include <iostream>
#include <string>
#include <vector>
#include "controller.h"
using namespace std;

int main(int argc, char *argv[])
{
    bool testingMode = false;
    string deck1FileName = "default.deck";
    string deck2FileName = "default.deck";
    string initFileName = "";
    for (int i = 0; i < argc; i++)
    {
        if (string(argv[i]) == "-deck1" && i + 1 < argc)
            deck1FileName = argv[i + 1];
        else if (string(argv[i]) == "-deck2" && i + 1 < argc)
            deck2FileName = argv[i + 1];
        else if (string(argv[i]) == "-init" && i + 1 < argc)
            initFileName = argv[i + 1];
        else if (string(argv[i]) == "-testing")
            testingMode = true;
    }
    Controller controller{testingMode, deck1FileName, deck2FileName, initFileName};
    controller.play();
}
