#include <iostream>
#include "latihan.h"
using namespace std;

int main() {
    Stack s;
    initStack(s);
    push(s, 10);
    push(s, 20);
    push(s, 30);
    cout << peek(s) << endl;   // 30
    pop(s);
    cout << peek(s) << endl;   // 20
    pop(s);
    cout << peek(s) << endl;   // 10
    pop(s);
    pop(s);                    // Stack Kosong
    return 0;
}
