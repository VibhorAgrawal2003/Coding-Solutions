#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

template <typename T>
void showCollection(vector<vector<T>> vec){
    cout << "{ ";
    for(auto x : vec){
        cout << "{ ";
        for(auto y : x){
            cout << y << " ";
        }
        cout << "} ";
    }
    cout << "}\n";
}

// BRUTE SOLUTION: Time Limit Exceeded

/**
 * Approach: Iterates over the entire array using nested loop.
*/

class Brute{
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target){

        vector<vector<int>> quadruplets;

        for(int i=0; i<nums.size()-3; i++){
            for(int j=i+1; j<nums.size()-2; j++){
                for(int k=j+1; k<nums.size()-1; k++){
                    for(int l=k+1; l<nums.size(); l++){
                        if(nums[i] + nums[j] + nums[k] + nums[l] == target){

                            vector<int> four = {nums[i], nums[j], nums[k], nums[l]};
                            auto it = find(quadruplets.begin(), quadruplets.end(), four);
                            if(it == quadruplets.end()){
                                quadruplets.push_back(four);
                            }

                        }
                    }
                }
            }
        }

        return quadruplets;
    }
};

int main(){

    Brute B;

    int t1 = 0;
    int t2 = 8;

    vector<int> v1 = {1, 0, -1, 0, -2, 2};
    vector<int> v2 = {2, 2, 2, 2, 2};

    vector<vector<int>> v3 = {{1, 2, 3}, {4, 5, 6}};
    showCollection<int>(B.fourSum(v1, t1));
    showCollection<int>(B.fourSum(v2, t2));

    return 0;
}