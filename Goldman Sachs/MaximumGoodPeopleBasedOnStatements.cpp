class Solution {
public:
    vector<string> all;
    void generate(int i, int &n ,string &s){
        if(i==n){
            all.push_back(s);
            return;
        }
        s+='0';
        generate(i+1,n,s);
        s.pop_back();
        s+='1';
        generate(i+1,n,s);
        s.pop_back();
    }
    
    bool isPossible(vector<vector<int> >& v,string& s){
        
        int n = v.size();
        vector<int> m(n,-1);
        for(int i =0;i<n;++i){
            if(s[i]=='1'){
                for(int j = 0;j<n;++j){
                    if(i!=j&&v[i][j]!=2&&m[j]!=-1&&m[j]!=v[i][j]){
                        return false;
                    }
                    if(v[i][j]!=2)
                        m[j] = v[i][j];
                }
            }
        }
    for(int i =0;i<n;++i){
        if(m[i]!=-1&&m[i]+'0'!=s[i]) return false;
    }
        return true;
    }
    int maximumGood(vector<vector<int>>& statements) {
        string s="";
        int n = statements.size();
        generate(0,n,s);
        int ans= 0;
        for(auto s:all){
            if(isPossible(statements,s)) ans= max(ans,(int)count(s.begin(),s.end(),'1'));
        }
        return ans;
    }
};
