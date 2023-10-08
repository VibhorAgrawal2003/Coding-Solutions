#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
    int T, N;
    cin >> T;

    for(int i=0; i<T; i++){
        cin >> N;

        ll sumA = 0;
        ll sumB = 0;
        ll sa = INT_MAX;
        ll sb = INT_MAX;
        ll x;

        for(int j=0; j<N; j++){
            cin >> x;
            if(x < sa) sa = x;
            sumA += x;
        }

        for(int j=0; j<N; j++){
            cin >> x;
            if(x < sb) sb = x;
            sumB += x;
        }

        sumA += sb*N;
        sumB += sa*N;

        cout << ((sumA < sumB)? sumA : sumB) << "\n";
    }

    return 0;
}