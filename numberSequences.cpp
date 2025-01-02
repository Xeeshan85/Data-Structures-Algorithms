#include <iostream>
using namespace std;

// nth fibonacci number
int fib(int x) {
    if ((x==0) || (x==1)) {
        return x;
    }
    return (fib(x-1) + fib(x-2));
}

int main() {
    int i = 0;
    while (i < 10) {
        cout << fib(i) <<  " ";
        i++;
    }
    return 0;
}