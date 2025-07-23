#ifndef TEXTDISPLAY_H
#define TEXTDISPLAY_H
#include "view.h"
#include <string>
using namespace std;
class TextDisplay : public View {
    public:
        TextDisplay() {};
        void notify(string cmd) override;
};
#endif