#include<iostream>
using namespace std;

/**
 * @brief This algorithm is defined by the Collatz Conjecture.
 * @see Task: https://cses.fi/problemset/task/1068
*/

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