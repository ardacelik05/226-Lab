#include <iostream>

using namespace std;

double power(double base, int exp) {
    double res = 1.0;
    for(int i = 0; i < exp; i++) {
        res *= base;
    }
    return res;
}

double calculate_gn(int n, double r) {
    if (n == 0) {
        return 1.0;
    }
    return power(r, n) + calculate_gn(n - 1, r);
}

int main() {
    double r;
    int n;

    cout << "Enter r: ";
    cin >> r;
    cout << "Enter n: ";
    cin >> n;

    if (n < 0) {
        cout << "Error: n cannot be negative!" << endl;
    } else {
        double result = calculate_gn(n, r);
        cout << "Result: " << result << endl;
    }

    return 0;
}