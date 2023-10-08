#include<bits/stdc++.h>
using namespace std;

/**
 * @brief By performing increment/decrement operations, find minimum moves to set product of all input integers as zero
 * @see https://codeforces.com/contest/1866/problem/A
*/

int main(){
    int T;
    cin >> T;

    int least = INT_MAX;
    for(int i=0; i<T; i++){
        int x;
        cin >> x;
        if(least == 0) break;
        if(abs(x) < least) least = abs(x);
    }

    cout << least << "\n";
    return 0;
}