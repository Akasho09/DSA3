class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n = intervals.size(); int i = 0;
        while(i<n && intervals[i][0]<newInterval[0]) i++;
        int low = newInterval[0], high = newInterval[1];
        if(low>intervals[i-1][1]){
            vector<int> temp;
            while(i<n){
            temp = intervals[i];
            intervals[i][0] = newInterval[0];
            intervals[i][1] = newInterval[1];
            newInterval=temp;
            }
            intervals.push_back(temp);
        }else {
            while(i>0 && i<=n){
                if(intervals[i-1][0]<=newInterval[1]){
                low = min(low , intervals[i-1][0]);
                high = max(high , intervals[i-1][1]);
                }
            }
        }





    }
};