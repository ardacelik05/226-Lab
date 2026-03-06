#include <iostream>
using namespace std;

int main() {
    int num;

    cout << "Enter a positive integer greater than 9: ";
    cin >> num;

    while (num <= 9) {
        cout << "Invalid input! Please enter a number greater than 9: ";
        cin >> num;
    }

    int steps = 0;
    cout << num;

    while (num >= 10) {
        int temp = num;
        int digit_sum = 0;

        while (temp > 0) {
            digit_sum += temp % 10;
            temp /= 10;
        }

        num = digit_sum;
        steps++;

        cout << " -> " << num;
    }

    cout << endl;
    cout << "Final value: " << num << endl;
    cout << "Total steps: " << steps << endl;

    return 0;
}