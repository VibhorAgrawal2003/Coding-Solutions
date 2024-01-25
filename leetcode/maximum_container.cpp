#include<iostream>
#include<vector>

using namespace std;

/**
 * QUESTION: Given an integer array of heights, identify maximum possible area of a container bounded by the two heights and the distance between them in the array as per their index.
*/


// OPTIMAL SOLUTION: Accepted and beats 79% of C++ Users

/***
 * Approach: Two pointer greedy method
 * 
 * The idea is that we will start with maximum possible reach, assuming our walls at the ends of the vector.
 * Then we slowly shrink the reach and for each new reach, we try to obtain the greediest sub-solution.
 * This greediest sub-solution will always try to increase the wall length over which area is being calculated.
 * The wall which determines the area is always the shorter wall.
 * 
 * As such, make two pointers traverse the array in opposite directions.
 * At every step, shift the pointer looking at smaller wall as we want to keep taller walls in our rectangle.
*/

class Solution{
public:
    int maxArea(vector<int>& height){

        // Base case
        if(height.size() <= 1){ return 0; }

        // Two pointers
        int p = 0;
        int q = height.size() - 1;

        // Result
        int maxarea = 0;

        while(p != q){

            // Update area
            int area = (q-p) * min(height[p], height[q]);
            if(area > maxarea){
                maxarea = area;
            }

            // Move pointers
            if(height[p] <= height[q]){
                p++;
            }
            else{
                q--;
            }
        }

        return maxarea;
    }
};



// SUBOPTIMAL SOLUTION: Accepted but beats only 5% of C++ Users

/**
 * Approach: Find the maximum reach for every item in vector.
 * This reach can be either a left reach or right reach.
 * Run two loops, one that goes before the KEY and one after.
 * Check which side has longer reach for the KEY.
 * Then obtain the best area for the KEY assuming it is the shorter side.
 * 
 * The solution assumes that at every computation, the selected KEY
 * acts as the shorter side of the rectangle/area being formed.
*/

class Subpar{
public:
    int maxArea(vector<int>& height){
        int i, j, maxarea = 0;

        // Selecting a key
        for(i=0; i<height.size(); i++){

            int left_reach = 0;
            int right_reach = 0;

            // Obtain left reach
            for(j=0; j<i; j++){
                if(height[j] >= height[i]){
                    left_reach = i-j;
                    break;
                }
            }

            // Obtain right reach
            for(j=height.size()-1; j>i; j--){
                if(height[j] >= height[i]){
                    right_reach = j-i;
                    break;
                }
            }

            // Obtain area
            int area = ((left_reach >= right_reach)? left_reach : right_reach) * height[i];
            if(area > maxarea){
                maxarea = area;
            }
        }

        return maxarea;
    }
};


// BRUTE FORCE APPROACH: TIME LIMIT EXCEEDED

class Brute{
public:
    int maxArea(vector<int>& height){

        int maxarea = 0;

        for(int i=0; i<height.size(); i++){
            for(int j=i; j<height.size(); j++){

                int smaller = (height[i] < height[j])? height[i] : height[j];
                int area = smaller * (j-i);
                if(area > maxarea){
                    maxarea = area;
                }
            }
        }

        return maxarea;
    }
};

int main(){

    Solution S;

    // Testcases

    vector<int> height_1 = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    vector<int> height_2 = {1, 1};
    vector<int> height_3 = {1, 8, 2};
    vector<int> height_4 = {};
    vector<int> height_5 = {0, 0, 8, 2, 1};
    vector<int> height_6 = {2, 8, 7, 1, 3};
    vector<int> height_7 = {1, 3, 2, 5, 25, 24, 5};

    cout << S.maxArea(height_1) << endl;
    cout << S.maxArea(height_2) << endl;
    cout << S.maxArea(height_3) << endl;
    cout << S.maxArea(height_4) << endl;
    cout << S.maxArea(height_5) << endl;
    cout << S.maxArea(height_6) << endl;
    cout << S.maxArea(height_7) << endl;

    // Testcase Solutions
    // 49, 1, 2, 0, 2, 9, 15

    return 0;
}