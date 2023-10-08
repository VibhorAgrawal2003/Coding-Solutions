#include<bits/stdc++.h>
using namespace std;

int main(){

    int T, n, m, k;
    cin >> T;

    for(int i=0; i<T; i++){
        cin >> n >> m >> k;

        if(k == 1) cout << 1 << "\n";

        else if(k == 2){
            if(m >= n) cout << (n-1) + (m/n) << "\n";
            else cout << m << "\n";
        }

        else if(k == 3){
            if(m >= n) cout << (m/n - 1)*(n-1) + m%n << "\n";
            else cout << 0 << "\n";
        }

        else{
            cout << 0 << "\n";
        }

    }
    return 0;
}