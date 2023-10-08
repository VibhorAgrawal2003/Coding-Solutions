#include<bits/stdc++.h>
using namespace std;

/**
 * @brief Identify if an amount n can be represented exactly by 2 unit and k unit notes
 * @see https://codeforces.com/contest/1814/problem/A
*/

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