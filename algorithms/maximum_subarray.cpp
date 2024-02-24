#include<iostream>
#include<vector>

using namespace std;

int kadanes_max_subarray(vector<int>& nums){

    int low{};
    int high{};

    int current_sum = 0;
    int max_sum = INT_MIN;

    for(int i=0; i<nums.size(); i++){
        current_sum += nums[i];

        if(max_sum < current_sum){
            max_sum = current_sum;
            high = i;
        }

        if(current_sum < 0){
            current_sum = 0;
            low = i+1;
        }
    }

    cout << "Sum of maximum subarray: " << "A[" << low + 1 << "," << high + 1 << "] is " << max_sum << endl;
    cout << "Maximum subarray: [ ";
    for(int i=low; i<=high; i++){
        cout << nums[i] << " ";
    }
    cout << "]";

    return max_sum;
}

int main(){
    
    cout << "\n\n--- Test Case 1 ---" << endl;
    vector<int> A = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    kadanes_max_subarray(A);

    cout << "\n\n--- Test Case 2 ---" << endl;
    vector<int> B = {13, -3, -25, 20, -3, -25, 20, -3, -16, -23, 18, 20, -7, 12, -5, -22, 15, -4, 7};
    kadanes_max_subarray(B);

    return 0;
}