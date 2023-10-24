#include<iostream>
using namespace std;

/**
 * This program utilizes a reverseSign function to perform multiplication of any two integers.
*/

int reverseSign(int x){
    return 0 - x;
}

int multiplyTwo(int x, int y){

    int prod = 0, i, j;
    if(x < y){
        i = x; j = y;
    }
    else{
        i = y; j = x;
    }

    if(i<0) i = reverseSign(i);
    if(j<0) j = reverseSign(j);

    while(i > 0){
        prod += j;
        i--;
    }

    if((x<0 && y>0) || (x>0 && y<0)) prod = reverseSign(prod);
    return prod;
}

int main(){

    cout << 5 << " reversed is " << reverseSign(5) << "\n";
    cout << 7 << " reversed is " << reverseSign(7) << "\n";
    cout << 5 << " * " << 7 << " = " << multiplyTwo(5, 7) << "\n";
    cout << -5 << " * " << 7 << " = " << multiplyTwo(-5, 7) << "\n";
    cout << 5 << " * " << -7 << " = " << multiplyTwo(5, -7) << "\n";
    cout << -5 << " * " << -7 << " = " << multiplyTwo(-5, -7) << "\n";
    return 0;
}