class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int jumps = 0 , low = 0 , high = 0 ;

        for(int i = 0 ; i<n-1 ; i++ ){
            high = max(high , i+nums[i]);
            if(low==i){
               jumps++; low=high; 
            }
        }

        return jumps;
    }
};