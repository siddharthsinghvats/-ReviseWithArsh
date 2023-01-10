class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>&p , vector<int>& c) {
        vector<pair<long long,long long> > v;
        for(int i =0;i<p.size();i++){
            v.push_back({c[i],p[i]});
        }
        sort(v.begin(), v.end());
        int i = 0;
        int n = p.size();
        long long x = w;
        priority_queue<long long>  pq;
        while(i<n&&k){
            int pre =i;
            while(i<n&&x>=v[i].first){
                pq.push(v[i].second);
                i++;
            }
            while(pq.size()&&k&&x<v[i].first){
                x+=pq.top();
                pq.pop();
                k--;
            }
            i+=(pre==i);
        }
        while(pq.size()&&k--){
            x+=pq.top();
            pq.pop();
        }
        w = x;
        return w;
    }
};
