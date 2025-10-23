class Solution {
public:
    int maxRepeating(string a, string b) {
        string s = b + "#" + a;
        int n = s.size(), nb = b.size();
        
        vector<int> lps(n, 0);
        int i = 1, j = 0;
        while(i < n){
            if(s[i] == s[j]) {
                lps[i++]=++j;
            } else if(j > 0) {
                j=lps[j-1];
            } else i++;
        }
        int ans = 0;
        for(int i = 0; i < n; i++){
            if(lps[i]==nb){
                int j = i+nb , temp=1; 
                while(j<n && lps[j]==nb) temp++ , i=j , j+=nb; 
                ans = max(ans,temp);
            }
        }
        return ans;
    }
};