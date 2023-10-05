#include<iostream>
#include<cctype>
using namespace std;

int main(){
    char x, y;
    cin >> y;
    int count = 1, max = 0;

    while(cin >> x){
        if(y != x){
            if(max < count) max = count;
            count = 1;
            y = x;
        }
        else{
            count++;
        }
    }

    if(max < count) max = count;
    cout << max << "\n";
    return 0;
}