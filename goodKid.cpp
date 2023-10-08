#include<bits/stdc++.h>
using namespace std;

/**
 * @brief Maximise the product of an array of integers by incrementing any one element
 * @see https://codeforces.com/contest/1873/problem/B
*/

int main(){

    int T, N, S, P, Z, x;
    cin >> T;
    for(int i=0; i<T; i++){
        cin >> N;
        S = INT_MAX; P = 1; Z = 0;
        for(int j=0; j<N; j++){
            cin >> x;
            (x != 0)? P *= x : Z++;
            if(x < S) S = x;
        }

        if(Z == 0) cout << P/S * (S+1) << "\n";
        else if(Z == 1) cout << P << "\n";
        else cout << 0 << "\n";
    }

    return 0;
}