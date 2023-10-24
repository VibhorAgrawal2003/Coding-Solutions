#include<bits/stdc++.h>
using namespace std;

int main(){
    int T, x;
    cin >> T;

    for(int i=0; i<T; i++){
        cin >> x;

        if(x<7 || x == 9){
            cout << "NO\n";
            continue;
        }

        cout << "YES\n";
        if(x%3!=0){
            cout << 1 << " " << 2 << " " << x-3 << "\n";
        }
        else cout << 1 << " " << 4 << " " << x-5 << "\n";
    }

    return 0;
}