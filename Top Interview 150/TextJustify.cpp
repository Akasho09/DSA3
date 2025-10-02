class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        int n = words.size();
        vector<string>ans ;

        for(int i=0;i<n;){
            int t = 0 ;
            vector<string>v;
            while(t<maxWidth){
                if(t+words[i].size()<maxWidth){
                    v.push_back(words[i]); //
                    t+=words[i++].size()+1;
                } else break;
            }
            int s = v.size();
            int ExtraSpaces = 0 ;
            if(s!=1) ExtraSpaces = (maxWidth-t)/(s-1);
            int rem  = 0 ; 
            if(s!=1) rem = (maxWidth-t)%(s-1);

            string curr = "";
            t=0;
            while(t<s-1){
                curr+=v[t];
                int j=0;
                while(j<=ExtraSpaces) { 
                    curr+=" " ; j++; 
                }
                if(t-s<rem) curr+=" "; 
                t++;
            }
            if(curr.empty()) {
                curr+=v[s-1];
                int p = v[s-1].size();
                while(p<maxWidth){
                    curr+=" "; p++;
                }
            } else {
                curr+=v[s-1];
            }

            ans.push_back(curr);
        }

        return ans;
    }
};


class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> result;
        int n = words.size();
        int index = 0;

        while (index < n) {
            int totalChars = words[index].size();
            int last = index + 1;

            // Try to fit as many words as possible in the current line
            while (last < n) {
                if (totalChars + 1 + words[last].size() > maxWidth) break;
                totalChars += 1 + words[last].size();
                last++;
            }

            string line;
            int numWords = last - index;
            int numSpaces = maxWidth - totalChars + (numWords - 1); 

            // If last line OR only one word: left justify
            if (last == n || numWords == 1) {
                for (int i = index; i < last; i++) {
                    line += words[i];
                    if (i < last - 1) line += " ";
                }
                while (line.size() < maxWidth) line += " ";
            } else {
                // Full justification
                int spaces = (maxWidth - (totalChars - (numWords - 1))) / (numWords - 1);
                int extra = (maxWidth - (totalChars - (numWords - 1))) % (numWords - 1);

                for (int i = index; i < last; i++) {
                    line += words[i];
                    if (i < last - 1) {
                        int spaceCount = spaces + (i - index < extra ? 1 : 0);
                        line.append(spaceCount, ' ');
                    }
                }
            }

            result.push_back(line);
            index = last;
        }

        return result;
    }
};
