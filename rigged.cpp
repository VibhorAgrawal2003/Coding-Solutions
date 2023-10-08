#include<bits/stdc++.h>
using namespace std;

int main(){
    int T, N;
    cin >> T;

    for(int j=0; j<T; j++){
        cin >> N;

        int sp = 0, ep = 0, s, e, maxs = 0;
        for(int i=0; i<N; i++){
            cin >> s >> e;
            if(i==0){
                sp = s;
                ep = e;
            }
            else{
                if(e >= ep && s > maxs){
                    maxs = s;
                }
            }
        }

        if(maxs + 1 <= sp){
            cout << maxs + 1 << "\n";
        }
        else{
            cout << -1 << "\n";
        }
    }
    return 0;
}