#include<iostream>
#include<vector>

using namespace std;

void longest_common_subsequence(string& a, string& b){

    // Initialization

    int n = a.length();
    int m = b.length();

    char direction_array[n][m];
    int size_array[n+1][m+1];

    for(int i=0; i<n+1; i++){
        size_array[i][0] = 0;
    }

    for(int j=0; j<m+1; j++){
        size_array[0][j] = 0;
    }

    // Updating other entries
    for(int i=1; i<n+1; i++){
        for(int j=1; j<m+1; j++){

            if(a[i-1] == b[j-1]){
                size_array[i][j] = size_array[i-1][j-1] + 1;
                direction_array[i-1][j-1] = 'd';
            }
            else if(size_array[i-1][j] >= size_array[i][j-1]){
                size_array[i][j] = size_array[i-1][j];
                direction_array[i-1][j-1] = 'u';
            }
            else{
                size_array[i][j] = size_array[i][j-1];
                direction_array[i-1][j-1] = 'l';
            }
        }
    }

    // Finding longest subsequence
    string subseq = "";
    int i = n-1;
    int j = m-1;
    while(i>=0 && j>=0){
        if(direction_array[i][j] == 'd'){
            subseq = a[i] + subseq;
            i--; j--;
        }

        else if(direction_array[i][j] == 'u'){
            i--;
        }

        else{
            j--;
        }
    }

    // Output

    cout << "String 1: " << a << endl;
    cout << "String 2: " << b << endl;

    cout << "\nCost Table\n" << endl;

    for(int i=0; i<n+1; i++){
        for(int j=0; j<m+1; j++){
            cout << size_array[i][j] << " ";
        }
        cout << endl;
    }

    cout << "\nDirection Table\n" << endl;

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cout << direction_array[i][j] << " ";
        }
        cout << endl;
    }

    cout << "\n\n";
    cout << "Length of Common Subsequence: " << subseq.length() << endl;
    cout << "Common Subsequence: " << subseq << endl;
    cout << "\n\n";
}


int main(){

    cout << "\n--- Test Case 1 ---" << endl;
    string s1 = "ABCBDAB";
    string s2 = "BDCABA";
    longest_common_subsequence(s1, s2);

    cout << "\n--- Test Case 2 ---" << endl;
    s1 = "ABAABA";
    s2 = "BABBAB";
    longest_common_subsequence(s1, s2);
    return 0;
}

