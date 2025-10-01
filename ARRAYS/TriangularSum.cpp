class Solution {
public:
    int nCr(int n , int r){
        if(r>n/2) r=n-r;
        int val=1;

        for(int i=0;i<r;i++){
            val*=(n-i);
            val/=(r-i);
        }

        return val;
    }

    int triangularSum(vector<int>& nums) {
        int n = nums.size() , ans = 0 ;
        for(int i=0;i<nums.size();i++){
            ans+=(nCr(n,i))
        }

        return nums[0]%10;
    }
};