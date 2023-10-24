#include<iostream>
using namespace std;

/**
 * This program performes basic integer multiplication on non-negative integers using iterative addition.
*/

int multiplyTwo(int x, int y){

    int prod = 0, i, j;

    if(x<y){
        i = x; j = y;
    }
    else{
        i = y; j = x;
    }

    while(i > 0){
        prod += j;
        i--;
    }

    return prod;
}

int main(){

    cout << 4 << " * " << 5 << " = " << multiplyTwo(4,5) << "\n";
    cout << 2 << " * " << 7 << " = " << multiplyTwo(2,7) << "\n";
    cout << 11 << " * " << 4 << " = " << multiplyTwo(11,4) << "\n";

    return 0;
}