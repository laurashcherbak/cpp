#include<iostream>

using namespace std;

int f(int n, int& nr) {
    nr++;
    int r;
    if (n == 0)
        r = 0;
    else
        r = (1 + f(n & (n - 1), nr)); //рекурсивний виклик функції
    return r;
}

int main() {
    int n; //число, функцію якого необхідно обчислити
    long r, t;
    int n1 = 0, nr = -1;

    cout << "Enter n: "; cin >> n;

    r = f(n, nr);
    cout << "f(n) = " << r << endl;

    while (n) {
        t = n % 2;
        if (t == 1) {
            n1++;
        }
        n = n / 2;
        //nr++;
        //cout << n << " | " << t << endl;
    }
    cout << "Amount of 1 in n : " << n1 << endl;
    cout << "Depth of recursion : " << nr << endl;

    return 0;
}
