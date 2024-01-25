#include<iostream>
#include<vector>
#include<set>
#include<algorithm>

using namespace std;

/**
 * QUESTION: Given an integer array, identify all unique combinations of 3 items such that their sum is exactly zero and return as a vector of vectors.
*/

// BRUTE SOLUTION: Time Limit Exceeded

/**
 * Approach: Iterates over the entire array using nested loop.
 * Simple simulation of the given problem to find all possible areas.
 * Here we use sets as intermediate container to avoid duplicate solutions.
 * Vectors containing duplicate items are resolved by using the sort function.
*/

class Brute{
public:

    template <typename T>
    void showVectorSet(set<vector<T>> set){
        cout << "{ ";
        for(auto i: set){
            cout << "[ ";
            for(auto j: i){
                cout << j << " ";
            }
            cout << "]";
        }
        cout << " }\n";
    }

    template <typename T>
    void showVectorSet(vector<vector<T>> set){
        cout << "[ ";
        for(auto i: set){
            cout << "[ ";
            for(auto j: i){
                cout << j << " ";
            }
            cout << "]";
        }
        cout << " ]\n";
    }

    vector<vector<int>> threeSum(vector<int>& nums){

        set<vector<int>> triplets;

        for(int i=0; i<nums.size()-2; i++){
            for(int j=i+1; j<nums.size()-1; j++){
                for(int k=j+1; k<nums.size(); k++){

                    if(nums[i] + nums[j] + nums[k] == 0){
                        vector<int> temp = {nums[i], nums[j], nums[k]};
                        sort(temp.begin(), temp.end());
                        triplets.insert(temp);
                    }
                }
            }
        }

        vector<vector<int>> answer;
        for(auto i: triplets){
            answer.push_back(i);
        }

        return answer;
    }
};

int main(){

    Brute S;

    vector<int> nums_1 = {-1, 0, 1, 2, -1, -4};
    vector<int> nums_2 = {0, 1, 1};
    vector<int> nums_3 = {0, 0, 0};

    S.showVectorSet(S.threeSum(nums_1));
    S.showVectorSet(S.threeSum(nums_2));
    S.showVectorSet(S.threeSum(nums_3));

    return 0;
}