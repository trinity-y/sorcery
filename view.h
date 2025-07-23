#ifndef VIEW_H
#define VIEW_H
#include <string>

using namespace std;
class View {
    public:
        View() {};
        virtual void notify(string cmd) = 0;
};
#endif