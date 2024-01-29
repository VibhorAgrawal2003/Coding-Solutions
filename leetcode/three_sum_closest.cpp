#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

// OPTIMAL SOLUTION: Accepted and beats 78% of C++ Users

/***
 * Approach: Two pointer method after key selection from sorted array
 * 
 * The first step is to initialize a closest with the sum of first three array elements.
 * Then sort the given array and run a loop that will selecta key, nums[i].
 * For each key, we will run two pointers from opposite ends of the array.
 * The idea is to try and always move the pointer that brings the result closer to desired target.
 * This is a more general version of the 3Sum problem where target is always zero.
*/

class Solution{
public:
    int threeSumClosest(vector<int>&nums, int target){
        int closest = nums[0] + nums[1] + nums[2];
        if(closest == target || nums.size() == 3) return closest;
        sort(nums.begin(), nums.end());

        for(int i=0; i<nums.size(); i++){
            int j=0;
            int k=nums.size()-1;
            while(j!=k){

                // Check skip
                if(i==j){
                    j++;
                    continue;
                }

                if(i==k){
                    k--;
                    continue;
                }

                // Check sum
                int sum = nums[i] + nums[j] + nums[k];
                if(sum == target){
                    return target;
                }
                else if(sum < target){
                    j++;
                }
                else{
                    k--;
                }

                // Check closest
                if(abs(sum - target) < abs(closest - target)){
                    closest = sum;
                }
            }
        }
        return closest;
    }
};

// BRUTE SOLUTION: Accepted but beats only 5% of C++ Users

/**
 * Approach: Iterates over the entire array using nested loop.
 * Simple simulation of the given problem to find all possible sums.
 * Simply check which of the possible triplets gives closest sum to target.
*/

class Brute{
public:
    int threeSumClosest(vector<int>& nums, int target){
        int closest = nums[0] + nums[1] + nums[2];
        for(int i=0; i<nums.size(); i++){
            for(int j=i+1; j<nums.size(); j++){
                for(int k=j+1; k<nums.size(); k++){
                    int sum = nums[i] + nums[j] + nums[k];
                    if(sum == target){
                        return sum;
                    }
                    else if(abs(sum - target) < abs(closest - target)){
                        closest = sum;
                    }
                }
            }
        }
        return closest;
    }
};


int main(){
    Solution S;
    // Subpar S;
    Brute B;

    int tar1 = 1;
    int tar2 = 1;
    int tar3 = 5;
    int tar4 = 4;
    int tar5 = 10;
    int tar6 = 6;
    int tar7 = 0;
    int tar8 = 255;

    vector<int> v1 = {-1, 2, 1, -4};
    vector<int> v2 = {0, 0, 0};
    vector<int> v3 = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    vector<int> v4 = {1, 1, 1, 10, 10, 10};
    vector<int> v5 = {7, 6, 4, 2, -2, -5, 3, 2};
    vector<int> v6 = {-1, -1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 2, -1, -1};
    vector<int> v7 = {100, 200, 300};
    vector<int> v8 = {-43,57,-71,47,3,30,-85,6,60,-59,0,-46,-40,-73,53,68,-82,-54,88,73,20,-89,-22,39,55,-26,95,-87,-57,-86,28,-37,43,-27,-24,-88,-35,82,-3,39,-85,-46,37,45,-24,35,-49,-27,-96,89,87,-62,85,-44,64,78,14,59,-55,-10,0,98,50,-75,11,97,-72,85,-68,-76,44,-12,76,76,8,-75,-64,-57,29,-24,27,-3,-45,-87,48,10,-13,17,94,-85,11,-42,-98,89,97,-66,66,88,-89,90,-68,-62,-21,2,37,-15,-13,-24,-23,3,-58,-9,-71,0,37,-28,22,52,-34,24,-8,-20,29,-98,55,4,36,-3,-9,98,-26,17,82,23,56,54,53,51,-50,0,-15,-50,84,-90,90,72,-46,-96,-56,-76,-32,-8,-69,-32,-41,-56,69,-40,-25,-44,49,-62,36,-55,41,36,-60,90,37,13,87,66,-40,40,-35,-11,31,-45,-62,92,96,8,-4,-50,87,-17,-64,95,-89,68,-51,-40,-85,15,50,-15,0,-67,-55,45,11,-80,-45,-10,-8,90,-23,-41,80,19,29,7};

    cout << S.threeSumClosest(v1, tar1) << endl;
    cout << S.threeSumClosest(v2, tar2) << endl;
    cout << S.threeSumClosest(v3, tar3) << endl;
    cout << S.threeSumClosest(v4, tar4) << endl;
    cout << S.threeSumClosest(v5, tar5) << endl;
    cout << S.threeSumClosest(v6, tar6) << endl;
    cout << S.threeSumClosest(v7, tar7) << endl;
    cout << S.threeSumClosest(v8, tar8) << endl;

    /**
     * Answers
     * 2
     * 0
     * 6
     * 3
     * 10
     * 4
     * 600
     * 255
    */

    return 0;
}