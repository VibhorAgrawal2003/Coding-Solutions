#include<iostream>
#include<vector>
#include<set>
#include<algorithm>

using namespace std;

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


// SUBOPTIMAL SOLUTION: Accepted and beats 40% of C++ Users

/**
 * Approach: Sort the input array and apply two pointer approach
 * We select a key by placing an 'i' pointer first
 * Then we run two pointers 'j' & 'k' from opposite ends
 * Always move the pointer which brings sum closer to zero
 * Keep going until both pointers complete their journey
 * Then change key i.e. pointer 'i' and repeat process
*/

class Subpar{
public:
    vector<vector<int>> threeSum(vector<int>& nums){

        int i{}, j{}, k{};
        set<vector<int>> temp;
        sort(nums.begin(), nums.end());

        // Optimize input vector and find zero triplet
        for(i=0; i<nums.size()-2; i++){

            bool zero_triplet_found = false;
            if(nums[i] == nums[i+1] && nums[i] == nums[i+2]){

                if(nums[i] == 0 && !zero_triplet_found){
                    temp.insert({0, 0, 0});
                    zero_triplet_found = true;
                }

                nums.erase(nums.begin()+i);
                i--;
            }

        }

        // Find remaining possible triplets
        for(i=0; i<nums.size(); i++){
            j = 0;
            k = nums.size() - 1;

            while( (j<nums.size()) && (k>=0) ){

                // Resolve when any two pointers match location
                if(i == j || j == k){
                    j++;
                    continue;
                }

                if(i == k){
                    k--;
                    continue;
                }

                int sum = nums[i] + nums[j] + nums[k];

                // Insertion into set of triplets
                if(sum == 0){
                    vector<int> triplet{{nums[i], nums[j], nums[k]}};
                    sort(triplet.begin(), triplet.end());
                    temp.insert(triplet);
                }

                // Moving the pointers
                if(sum >= 0){
                    k--;
                }
                else{
                    j++;
                }
            }
        }

        // Convert the set back into a vector
        vector<vector<int>> result;
        for(auto i: temp){
            result.push_back(i);
        }

        return result;
    }
};


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

    Subpar S;

    vector<int> nums_1 = {-1, 0, 1, 2, -1, -4};
    vector<int> nums_2 = {0, 1, 1};
    vector<int> nums_3 = {0, 0, 0};
    vector<int> nums_4 = {2, 2, 2, 2, 2, 2, 2, 2, 2};
    vector<int> nums_5 = {-1, -1, -1, -1, -1, -1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1};

    showVectorSet(S.threeSum(nums_1));
    showVectorSet(S.threeSum(nums_2));
    showVectorSet(S.threeSum(nums_3));
    showVectorSet(S.threeSum(nums_4));
    showVectorSet(S.threeSum(nums_5));

    return 0;
}