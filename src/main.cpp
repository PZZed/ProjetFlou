#include <iostream>
#include "core/ValueModel.h"
using namespace core;
using namespace std;
int main() {
    ValueModel<int> i(15);
    cout << endl << i.evaluate();
    ValueModel<string> s("ProjetFlou");
    cout << endl << s.evaluate();
    return 0;
}