#include <iostream> 
using namespace std;
 
int main() {
    double a, b;
    char s;
    cout << "Enter equation: " << endl;
    cin >> a >> s >> b;

    switch (s) {
    case '-': {
        cout << "a - b = " << a - b << endl;
        break;
    }
    case '+': {
        cout << "a + b = " << a + b << endl;
        break;
    }
    case '*': {
        cout << "a * b = " << a * b << endl;
        break;
    }
    case '/': {
        if (b == 0) {
            cout << "Error" << endl;
            break;
        }
        else {
            cout << "a / b = " <<  a / b << endl;
            break;
        }
    }
    default: {
        cout << "Error" << endl;
        break;
        }
    }
}