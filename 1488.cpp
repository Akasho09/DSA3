class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        unordered_map<int , int>mapp;
        int n = rains.size();
        vector<int>zeroes;
        vector<int>ans (n , -1);

        for(int i = 0 ; i < n ; i++){
            if(rains[i]==0) zeroes.push_back(i);
            else if(mapp.find(rains[i])==mapp.end()){
                mapp[rains[i]]=i;
            } else {
               int p = zeroes.size()-1;
               if(p==-1) return {};
               if(zeroes[p]<=mapp[rains[i]]) return {};
               while(p>0 && (zeroes[p]>mapp[rains[i]] || zeroes[p]==INT_MIN)) p--;
               while(p<zeroes.size() && (zeroes[p]==INT_MIN || zeroes[p]<mapp[rains[i]])) p++;
               ans[zeroes[p]]=rains[i]; zeroes[p]=INT_MIN;
            }
        }

        int i = 0 ;
        while(i<n){
            if(rains[i]==0) {
                if(ans[i]==-1) ans[i]=1; 
            }
            i++;
        }

        return ans ;
    }
};


class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        unordered_map<int , int>mapp;
        int n = rains.size();
        vector<int>zeroes;
        vector<int>ans (n , -1);

        for(int i = 0 ; i < n ; i++){
            if(rains[i]==0) zeroes.push_back(i);
            else if(mapp.find(rains[i])==mapp.end()){
                mapp[rains[i]]=i;
            } else {
               int p = zeroes.size()-1;
               while(p>0 && (zeroes[p]>mapp[rains[i]] || zeroes[p]==INT_MIN)) p--;
               while(p<zeroes.size() && (zeroes[p]==INT_MIN || zeroes[p]<mapp[rains[i]])) p++;
               if(p<0 || p==zeroes.size() || zeroes[p]<mapp[rains[i]] ) return {};
               ans[zeroes[p]]=rains[i]; zeroes[p]=INT_MIN;
            }
        }

        int i = 0 ;
        while(i<n){
            if(rains[i]==0) {
                if(ans[i]==-1) ans[i]=1; 
            }
            i++;
        }

        return ans ;
    }
};