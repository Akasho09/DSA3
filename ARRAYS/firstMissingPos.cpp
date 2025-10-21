#include <iostream>
using namespace std;

int firstPosMisssing (vector<int>nums) {
    int n = nums.size();
    for(int i=0;i<n;i++){
        if(nums[i]>0 && nums[i]<n && nums[nums[i]-1]!=nums[i]){
            swap(nums[i],nums[nums[i]-1]);
        }
    }

    for(int i=0;i<n;i++){
        if(nums[i]!=i+1) return i;
    }
    return n+1;
}

int main () {

}