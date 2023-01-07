class Solution {
public:
    vector<string> invalidTransactions(vector<string>& t) {
        map<string,vector<pair<int,pair<int,string> > > >m;
        set<pair<string,int> > s;
        int i=-1;
        for(auto x:t){
            i++;
            string cur = "";
            string name,city;
            int amount,time;
            bool f=1,ff=0,fff=0;
            for(int i = 0;i<x.length();i++){
                if(x[i]==','){
                    if(f){
                        name = cur;
                        f=0;
                        ff=1;
                    }else if(ff){
                        time = stoi(cur);
                        ff=0;
                        fff=1;
                    }else if(fff){
                        amount = stoi(cur);
                        fff=0;
                    }
                    cur="";
                }else{
                    cur+=x[i];
                }

            }
            city = cur;
            
            m[name].push_back(make_pair(time,make_pair(amount,city)));
        }
        for(auto it = m.begin();it!=m.end();it++){
            auto v= it->second;
            int n = v.size();
            for(int i =0;i<n;i++){
                if(v[i].second.first>=1000){
                     s.insert({it->first+","+to_string(v[i].first)+","+to_string(v[i].second.first)+","+v[i].second.second,i});
                }
                for(int j = i+1;j<n;j++){
                    if(abs(v[j].first-v[i].first)<=60&& v[i].second.second!=v[j].second.second){
                        s.insert({it->first+","+to_string(v[i].first)+","+to_string(v[i].second.first)+","+v[i].second.second,i});
                        s.insert({it->first+","+to_string(v[j].first)+","+to_string(v[j].second.first)+","+v[j].second.second,j});
                    }
                }
            }
        }
        vector<string> ans;
        for(auto x:s) ans.push_back(x.first);
        return ans;
        
    }
};
