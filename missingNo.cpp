#include<bits/stdc++.h>
using namespace std;

int main(){

    int n;
    cin >> n;
    bool* arr = (bool*) calloc(n, sizeof(bool));
    for(int i=0; i<n-1; i++){
        int a;
        cin >> a;
        arr[a-1] = true;
    }

    for(int j=0; j<n; j++){
        if(arr[j] == false){
            cout << j+1 << "\n";
            break;
        }
    }

    return 0;
}