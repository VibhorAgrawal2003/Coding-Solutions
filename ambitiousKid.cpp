#include<bits/stdc++.h>
using namespace std;

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