#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        std::sort(nums.begin(), nums.end());
        int freq = 1;
        int total = nums[0];
        int current_length = 1;
        int l = 0;
        int r = 0;

        while(r<nums.size()){
            current_length = r-l+1;
            if((nums[r]*current_length <= total+k)){
                if(r != nums.size()-1){
                    if(freq<r-l+1){
                        freq = r-l+1;
                    }
                    total += nums[r+1];
                    r++;
                }
                else{
                    if(freq<r-l+1){
                        freq = r-l+1;
                    }
                    r++;
                }
            }
            else{
                total -= nums[l];
                l++;
            }
        }
        
        return freq;
    }
};

int main() {
    Solution sol;

    vector<int> nums = {9930,9923,9983,9997,9934,9952,9945,9914,9985,9982,9970,9932,9985,9902,9975,9990,9922,9990,9994,9937,9996,9964,9943,9963,9911,9925,9935,9945,9933,9916,9930,9938,10000,9916,9911,9959,9957,9907,9913,9916,9993,9930,9975,9924,9988,9923,9910,9925,9977,9981,9927,9930,9927,9925,9923,9904,9928,9928,9986,9903,9985,9954,9938,9911,9952,9974,9926,9920,9972,9983,9973,9917,9995,9973,9977,9947,9936,9975,9954,9932,9964,9972,9935,9946,9966};
    int k = 3056;

    vector<int> nums1 = {1,2,4};
    int k1 = 5;

    vector<int> nums2 = {1,4,8,13};
    int k2 = 5;

    vector<int> nums3 = {3,9,6};
    int k3 = 2;

    cout << sol.maxFrequency(nums, k) << endl;
    cout << sol.maxFrequency(nums1, k1) << endl;
    cout << sol.maxFrequency(nums2, k2) << endl;
    cout << sol.maxFrequency(nums3, k3) << endl;

    return 0;
}
