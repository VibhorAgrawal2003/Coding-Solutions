#include<iostream>
using namespace std;

// Weird Algorithm
// In this algorithm, we take a positive integer n
// If n is even, we divide by 2
// If n is odd, we multiply by 3 and add 1
// We continue until the number becomes 1

// Source: Collatz Conjecture
// It states that this algorithm results in 1 for all input values n
// However it is a conjecture because no one has been able to prove it

int main(){

    long long n;
    cin >> n;
    while(true){
        cout << n << " ";
        if(n==1){
            break;
        }
        else if(n%2==0){
            n /= 2;
        }
        else{
            n *= 3;
            n += 1;
        }
    }

    return 0;
}