#include <iostream>
#include <cstring>

using namespace std;

int mc[50][50];

int matrix_chain_multiply(int* c, int i, int j){
    if(i == j){
        return 0;
    }

    if(mc[i][j] != -1){
        return mc[i][j];
    }

    mc[i][j] = INT_MAX;
    for(int k=i; k<j; k++){
        mc[i][j] = min(mc[i][j], matrix_chain_multiply(c, i, k) + matrix_chain_multiply(c, k+1, j) + c[i-1] * c[k] * c[j]);
    }
    return mc[i][j];
}

int matrix_multiplications(int* c, int n){
    int i = 1; 
    int j = n - 1;
    return matrix_chain_multiply(c, i, j);
}

int main(){

    cout << "\n\n--- Test Case 1 ---" << endl;
    int A1[] = {4, 10, 3, 12, 20, 7};
    int n1 = sizeof(A1) / sizeof(int);
    memset(mc, -1, sizeof(mc));
    cout << "Minimum number of multiplications is: " << matrix_multiplications(A1, n1);

    cout << "\n\n--- Test Case 2 ---" << endl;
    int A2[] = {30, 35, 15, 5, 10, 20, 25};
    int n2 = sizeof(A2) / sizeof(int);
    memset(mc, -1, sizeof(mc));
    cout << "Minimum number of multiplications is: " << matrix_multiplications(A2, n2);

    cout << "\n\n";
    return 0;
}

