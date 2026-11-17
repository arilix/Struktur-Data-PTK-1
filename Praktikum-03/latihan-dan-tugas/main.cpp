#include <iostream>
#include "reverse.h"

using namespace std;

int main() {
    StackArr S;
    createStack(S);

    string kata;
    cout << "Masukkan kata: ";
    cin >> kata;

    for (int i = 0; i < (int)kata.length(); i++) {
        push(S, kata[i]);
    }
    cout << "Kata asli: " << kata << endl << endl;
    cout << "Kata yang masuk ke dalam Stack : ";
    viewStack(S);

    balikStack(S);
    cout << "Kata setelah dibalik : ";
    viewStack(S);

    return 0;
}
