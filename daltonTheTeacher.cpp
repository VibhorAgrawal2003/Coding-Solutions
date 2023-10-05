#include<iostream>
using namespace std;

int main(){

    int T, N, U, x;
    cin >> T;

    for(int i=0; i<T; i++){
        cin >> N;
        U = 0;
        for(int j=1; j<=N; j++){
            cin >> x;
            if(x == j) U++;
        }

        cout << ( (U%2==0)? U/2 : (1 + (U-1)/2) ) << "\n";
    }

    return 0;
}