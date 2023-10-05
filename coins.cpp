#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
int main(){
    int T;
    ll n, k;
    cin >> T;

    for(int i=0; i<T; i++){
        cin >> n >> k;
        if(n%2!=0 && k%2==0){
            cout << "NO\n";
        }
        else{
            cout << "YES\n";
        }
    }

    return 0;
}