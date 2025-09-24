/*
The frequency of an element is the number of times it occurs in an array.

You are given an integer array nums and an integer k. In one operation, you can choose an index of nums and increment the element at that index by 1.

Return the maximum possible frequency of an element after performing at most k operations.
*/


// TLE
// Find diff and find max len subarray 
class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        int ans = 0;
        int n = nums.size();
        sort(nums.begin() , nums.end());
        for(int i=0;i<n-1;i++){
            nums[i]=nums[i+1]-nums[i];
        }

        for(int i=0;i<n-1;i++){
            int rem = k;
            for(int j=i;j<n-1;j++){
                rem-=(j-i+1)*nums[j];
                if(rem<0){ 
                    break;
                }
                ans = max(ans , j-i+1);
            }
        }

        return ans+1;
    }
};


class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        long long total = 0;
        int l = 0, res = 1;

        for (int r = 0; r < nums.size(); r++) {
            total += nums[r];

            while ((long long)nums[r] * (r - l + 1) - total > k) {
                total -= nums[l];
                l++;
            }

            res = max(res, r - l + 1);
        }
        return res;
    }
};



#include <iostream>
using namespace std;

int main (){



}

