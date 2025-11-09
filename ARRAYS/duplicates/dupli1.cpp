// Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive.
// There is only one repeated number in nums, return this repeated number.
// You must solve the problem without modifying the array nums and using only constant extra space.
// Function to find the duplicate number (start of the cycle)

// ## Floyd’s Cycle Algorithm on Array

int findDuplicate(vector<int>& nums) {
    int slow = nums[0];
    int fast = nums[0];

    // Phase 1: Detect intersection
    do {
        slow = nums[slow];
        fast = nums[nums[fast]];
    } while (slow != fast);

    // Phase 2: Find entrance to cycle (duplicate number)
    slow = nums[0];
    while (slow != fast) {
        slow = nums[slow];
        fast = nums[fast];
    }
    return slow;
}

/*
Given an integer array nums of length n where all the integers of nums are in the range [1, n] and each integer appears at most twice, 
return an array of all the integers that appears twice.

You must write an algorithm that runs in O(n) time and uses only constant auxiliary space, excluding the space needed to store the output
*/

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<bool>v(nums.size(),false);
        int i = 0;
        for(int num : nums){
            if(v[num]) nums[i++]=num;
            v[num]=true;
        }
        return vector<int>(nums.begin(),nums.begin()+i);
    }
};


/*
Given an integer array nums, return true if any value appears at least twice in the array, and return false if every element is distinct.
*/

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int>s;
        for(int num : nums){
            if(s.find(num)!=s.end()) return true;
            s.insert(num);
        }
        return false;
    }
};

/*
Given a fixed-length integer array arr, duplicate each occurrence of zero, shifting the remaining elements to the right.

Note that elements beyond the length of the original array are not written. Do the above modifications to the input array in place and do not return anything.
*/

class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        int n = arr.size();
        int zeros = 0;

        for (int i = 0; i < n; i++) {
            if (arr[i] == 0) zeros++;
        }

        for (int i = n - 1; i >= 0; i--) {
            if (i + zeros < n) arr[i + zeros] = arr[i];

            if (arr[i] == 0) {
                zeros--;
                if (i + zeros < n) arr[i + zeros] = 0;
            }
        }
    }
};