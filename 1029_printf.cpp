#include <bits/stdc++.h> 

using namespace std;

int fib (int a, int *calls_counter) {
    unsigned int num;
    *calls_counter = *calls_counter + 1;
    if (a == 0) num = 0;
    else if (a == 1) num = 1;
    else num = fib(a-2, calls_counter) + fib (a-1, calls_counter);
    return num;
}

int main() {
    int cases, x, calls_c = 0;
    cin >> cases;
    for (int i = 0; i < cases; i++) {
        cin >> x;
        int fibn = fib(x, &calls_c);
        printf("%s%d%s%d%s%d\n", "fib(", x ,") = ", calls_c - 1," calls = ",fibn);
        calls_c = 0;
    }
    return 0;
}