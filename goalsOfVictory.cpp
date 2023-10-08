#include<bits/stdc++.h>
using namespace std;

int main(){
    int T, N, sum, x;
    cin >> T;

    for(int i=0; i<T; i++){
        cin >> N;
        sum = 0;
        for(int j=0; j<N-1; j++){
            cin >> x;
            sum += x;
        }

        cout << -sum << "\n";
    }
    return 0;
}