#include<iostream>~
using namespace std;

int main(){
    int n, r;
    cin >> n;
    r = n%2;

    if(n==1) cout << "1\n";
    else if(n==2 || n==3) cout << "NO SOLUTION\n";
    else{
        for(int i=(r? n : n-1); i>=1; i-=2){
            cout << i << " ";
        }

        for(int j=(r? n-1 : n); j>=2; j-=2){
            cout << j << " ";
        }
    }

    return 0;
}