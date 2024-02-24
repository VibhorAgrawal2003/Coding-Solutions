#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

typedef long long ll;

ll karatsuba(ll x, ll y) {
    if (x < 10 || y < 10) {
        return x * y; // Base case: simple multiplication
    }

    // Calculate the number of digits in both x and y
    int size = max(log10(x) + 1, log10(y) + 1) / 2;

    // Splitting x and y into two halves
    ll high1 = x / pow(10, size);
    ll low1 = x % (ll)pow(10, size);
    ll high2 = y / pow(10, size);
    ll low2 = y % (ll)pow(10, size);

    // Recursive steps
    ll z0 = karatsuba(low1, low2);
    cout << "The product of " << low1 << " x " << low2 << " is: " << z0 << endl; 

    ll z1 = karatsuba((low1 + high1), (low2 + high2));
    cout << "The product of " << low1 + high1 << " x " << low2 + high2 << " is: " << z1 << endl; 

    ll z2 = karatsuba(high1, high2);
    cout << "The product of " << high1 << " x " << high2 << " is: " << z2 << endl; 

    // Combine the results to get the final product
    return (z2 * (ll)pow(10, 2 * size)) + ((z1 - z2 - z0) * (ll)pow(10, size)) + z0;
}

int main() {
    cout << "\n--- Test Case 1 ---" << endl;
    ll x = 2412;
    ll y = 3231;

    ll result = karatsuba(x, y);
    cout << "\nResult of multiplication: " << x << " x " << y << " is: " << result << endl;

    cout << "\n--- Test Case 2 ---" << endl;
    x = 1234;
    y = 8765;

    result = karatsuba(x, y);
    cout << "\nResult of multiplication: " << x << " x " << y << " is: " << result << endl;

    return 0;
}

