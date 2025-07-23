#include "textdisplay.h"
#include <string>
#include <iostream>
using namespace std;
void TextDisplay::notify(string cmd) {
    if (cmd == "help") {
        cout << "help stuff" << endl;
    }
    cout << "text display notified with command " << cmd << endl;
}
