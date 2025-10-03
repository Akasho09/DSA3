class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ans;
        int m = s.size();
        int z = words[0].size();
        int total_len = n * z;

        unordered_map<string,int>mapp;
        int n = words.size();
        for(int i=0;i<n;i++) {
            mapp[words[i]]++;
        }

        unordered_map<string,int>cMapp;
        for(int i=0;i<total_len;i+=z) {
            string curr = s.substr(i, z);
            cMapp[curr]++;
        }






        for(int i=0;i<=m-total_len;i++) {
            int j=i;
        unordered_map<string,int>temp=mapp;
            while(j<i+total_len){
                string curr = s.substr(j, z);
                if(temp.find(curr)==temp.end()) break;
                temp[curr]--;
                if(temp[curr]==0) temp.erase(curr);
                if(temp.empty()) {
                    ans.push_back(i);
                    break;
                }
                j+=z;
            }
        }

        return ans;
    }
};



class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        unordered_map<string,int>mapp;
        vector<int> ans;
        int n = words.size();
        for(int i=0;i<n;i++) {
            mapp[words[i]]++;
        }

        int m = s.size();
        int z = words[0].size();
        int total_len = n * z;
        for(int i=0;i<=m-total_len;i++) {
            int j=i;
        unordered_map<string,int>temp=mapp;
            while(j<i+total_len){
                string curr = s.substr(j, z);
                if(temp.find(curr)==temp.end()) break;
                temp[curr]--;
                if(temp[curr]==0) temp.erase(curr);
                if(temp.empty()) {
                    ans.push_back(i);
                    break;
                }
                j+=z;
            }
        }

        return ans;
    }
};