#include<iostream>
#include<vector>

using namespace std;

class Subpar{
public:

    int recursive_rob(vector<int>& vec, int i, int e, int sum){
        int sum_1 = 0, sum_2 = 0;
        sum += vec[i]; // Add current house's loot

        if(i+2 >= e){ // Can't go forward
            return sum;
        }
        else{
            sum_1 = recursive_rob(vec, i+2, e, sum); // Jump over 1 house
        }

        if(i+3 < e){
            sum_2 = recursive_rob(vec, i+3, e, sum); // Jump over 2 houses
        }
     
        return (sum_1 > sum_2)? sum_1 : sum_2;
    }

    int rob(vector<int>& nums){
        if(nums.size() == 0){ return 0; }
        if(nums.size() == 1){ return nums[0]; }

        int sum_1 = recursive_rob(nums, 0, nums.size(), 0);
        int sum_2 = recursive_rob(nums, 1, nums.size(), 0);

        return (sum_1 > sum_2)? sum_1 : sum_2;
    }
};

int main(){

    Subpar S;
    vector<int> v1 = {1, 2, 3, 1};
    vector<int> v2 = {2, 7, 9, 3, 1};
    vector<int> v3 = {2, 1, 1, 2};
    vector<int> v4 = {7, 0, 1, 3, 1, 6, 8};
    vector<int> v5 = {2, 3, 2};
    vector<int> v6 = {2, 3, 2, 1, 9};
    vector<int> v7 = {1, 7, 9, 4};
    vector<int> v8 = {};
    vector<int> v9 = {1};
    vector<int> v10 = {1, 10};
    vector<int> v11 = {12, 2};
    vector<int> v12 = {2, 4, 8, 9, 9, 3};

    
    cout << S.rob(v1) << endl;
    cout << S.rob(v2) << endl;
    cout << S.rob(v3) << endl;
    cout << S.rob(v4) << endl;
    cout << S.rob(v5) << endl;
    cout << S.rob(v6) << endl;
    cout << S.rob(v7) << endl;
    cout << S.rob(v8) << endl;
    cout << S.rob(v9) << endl;
    cout << S.rob(v10) << endl;
    cout << S.rob(v11) << endl;
    cout << S.rob(v12) << endl;

    return 0;
}

