#include<bits/stdc++.h>
using namespace std;

/**
 * @brief Modify an array only by incrementing such that each element is bigger than all its predecessors
 * @see https://cses.fi/problemset/task/1094
*/

#define ll long long

int main(){
    int T;
    ll y;
    ll count = 0;
    cin >> T;
    cin >> y;

    for(int i=1; i<T; i++){
        ll x;
        cin >> x;
        if(y > x){
            count += y - x;
        }
        else{
            y = x;
        }
    }

    cout << count << "\n";
    return 0;
}