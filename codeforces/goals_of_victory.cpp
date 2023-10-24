#include<bits/stdc++.h>
using namespace std;

/**
 * @brief Given the efficiency of all but one teams in a round-robin tournament, identify the missing efficiency
 * @see https://codeforces.com/contest/1877/problem/A
*/

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