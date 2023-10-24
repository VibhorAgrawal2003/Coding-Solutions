#include<iostream>
using namespace std;

int main(){
    int T;
    cin >> T;
    for(int i=0; i<T; i++){
        string x;
        cin >> x;
        if(x[0] == '1') cout << 13 << "\n";
        else if(x[0] == '2') cout << 23 << "\n";
        else if(x[0] == '3') cout << 31 << "\n";
        else if(x[0] == '4') cout << 41 << "\n";
        else if(x[0] == '5') cout << 53 << "\n";
        else if(x[0] == '6') cout << 61 << "\n";
        else if(x[0] == '7') cout << 71 << "\n";
        else if(x[0] == '8') cout << 83 << "\n";
        else if(x[0] == '9') cout << 97 << "\n";
    }
    return 0;
}