#include <iostream>
#include <cstring>
using namespace std;

#include "stack.h"

bool match(int open, char close) {
    return (open == '(' && close == ')') ||
           (open == '[' && close == ']') ||
           (open == '{' && close == '}');
}

int main(int argc, char **argv) {

    cout << "Checking the parentheses in argv arguments\n";

    for (int i = 1; i < argc; i++) {
        cout << "\nArgument: " << argv[i] << endl;

        Stack s;
        bool ok = true;

        for (int j = 0; j < strlen(argv[i]); j++) {
            char c = argv[i][j];


            if (c == '(' || c == '[' || c == '{') {
                s.push((int)c);
            }


            else if (c == ')' || c == ']' || c == '}') {
                int open = s.pop();

                if (open == -1) {
                    ok = false;
                    break;
                }

                if (!match(open, c)) {   // wrong type
                    ok = false;
                    break;
                }
            }
        }

        int leftover = s.pop();
        if (leftover != -1) ok = false;

        if (ok)
            cout << "→ Parentheses OK\n";
        else
            cout << "→ Parentheses NOT OK\n";
    }

    return 0;
}

