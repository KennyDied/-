#include <iostream>
#include <cmath>
using namespace std;


double formulae() 
{
    double n = 1;
    double number = 0;
    while (1 / (2 * n * (2 * n - 1) * (2 * n + 1)) > pow(10, -6)) {
        number = number + (1 / ((2 * n - 1) * 2 * n * (2 * n + 1)));
        n++;
    }
    return number;
}

int main()
{   
    cout << log(2) - 0.5 << endl;
    cout << formulae() << endl;   
}