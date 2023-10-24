#include<iostream>
using namespace std;

/**
 * @brief Calculate score from target practice board
 * @see https://codeforces.com/contest/1873/problem/C
*/

int main(){
    int T, score;
    char C;
    cin >> T;
    for(int i=0; i<T; i++){
        score = 0;
        for(int j=1; j <= 100; j++){
            cin >> C;
            if(C=='X'){
                if(j<10 || j>90 || (j-1)%10 == 0 || j%10 == 0) score += 1;
                else if(j<20 || j>80 || (j-2)%10 == 0 || (j+1)%10 == 0) score += 2;
                else if(j<30 || j>70 || (j-3)%10 == 0 || (j+2)%10 == 0) score += 3;
                else if(j<40 || j>60 || (j-4)%10 == 0 || (j+3)%10 == 0) score += 4;
                else score += 5;
            }
        }
        cout << score << "\n";
    }

    return 0;
}