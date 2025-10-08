// (✅ O(n log n) time, O(1) space),
class Solution {
  public:
    int mostFreqEle(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        int mCount = 0 , ans = arr[0];
        int count = 1;
        for(int i=1;i<arr.size();i++){
            if(arr[i]==arr[i-1]) count++;
            else count=1;
            if(count>=mCount) { ans = arr[i]; mCount = count; }
        }
        
        return ans ;
    }
};


// unordered_map (O(n) time)   , O(n) = space 
class Solution {
  public:
    int mostFreqEle(vector<int>& arr) {
        unordered_map<int,int>mapp ;
        int ans , mCount = 0 ;
        for(int i : arr){
            mapp[i]++;
            if(mapp[i]==mCount){ 
                ans = max(i,ans) ;
            }else if(mapp[i]>mCount){
                ans = i; 
                mCount = mapp[i];
            }
        }
        
        return ans ;
    }
};