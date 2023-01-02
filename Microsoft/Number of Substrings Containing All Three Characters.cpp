class Solution {
public:
    int numberOfSubstrings(string &s) {
        map<char,int> m;
        int n=s.length();
        int j=0;
        int ans=0;
        for(int i=0;i!=n;++i){
            ++m[s[i]];
            while(m['a']&&m['b']&&m['c']){
                --m[s[j]];
                ++j;
            }
            ans+=j;
        }
        return ans;
    }
};
