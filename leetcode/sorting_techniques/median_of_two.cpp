#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Subpar{
public:
    void addOverBinarySearch(vector<int>& nums, int x){
        int beg = 0;
        int end = nums.size() - 1;
        while(beg!=end){
            int mid = (beg + end) / 2;
            if(x == nums[mid]){
                nums.insert(nums.begin() + mid, x);
                return;
            }
            else if(x < nums[mid]){
                end = mid - 1;
            }
            else{
                beg = mid + 1;
            }
        }

        if(x <= nums[beg]){
            nums.insert(nums.begin() + beg, x);
        }
        else{
            nums.insert(nums.begin() + beg + 1, x);
        }
    }

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2){
        vector<int>* smaller;
        vector<int>* bigger;

        // Find shorter vector
        if(nums1.size() >= nums2.size()){
            smaller = &nums2;
            bigger = &nums1;
        }
        else{
            smaller = &nums1;
            bigger = &nums2;
        }

        // Build merged vector
        for(auto x : *smaller){
            addOverBinarySearch(*bigger, x);
        }

        // Find median
        int size = (*bigger).size();
        if(size % 2 == 1){
            return (double)(*bigger)[size/2];
        }
        else{
            return 0.5*((double)(*bigger)[size/2] + (double)(*bigger)[size/2 - 1]);
        }
    }
};

int main(){
    Subpar S;

    vector<int> v1 = {1, 3, 5, 7, 9};
    vector<int> v2 = {2, 4, 6, 8};

    vector<int> w1 = {1, 2};
    vector<int> w2 = {3, 4};

    vector<int> u1 = {1, 5, 6, 9, 4, 2, 0, 69, 42, 420};
    vector<int> u2 = {8, 0, 0, 8, 5, 2, 6, 1, 1};

    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());

    sort(w1.begin(), w1.end());
    sort(w2.begin(), w2.end());

    sort(u1.begin(), u1.end());
    sort(u2.begin(), u2.end());

    cout << S.findMedianSortedArrays(v1, v2) << endl;
    cout << S.findMedianSortedArrays(w1, w2) << endl;
    cout << S.findMedianSortedArrays(u1, u2) << endl;

    return 0;
}