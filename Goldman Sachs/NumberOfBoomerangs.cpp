class Solution {
public:
    int get(int &x1,int &x2,int &y1,int &y2){
      return (x2-x1)*(x2-x1)+(y2-y1)*(y2-y1);
    }
    int numberOfBoomerangs(vector<vector<int>>& points) {
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
        int n = points.size();
        int ans = 0;
        for(int i =0;i<n;i++){
            map<int,int> m;
            int x1,y1;
            x1 = points[i][0];
            y1 = points[i][1];
            for(int j =0;j<n;j++){
               if(i!=j){
                   int x2,y2;
                   x2 = points[j][0];
                   y2 = points[j][1];
                   m[get(x1,x2,y1,y2)] ++;
               }
            }
            for(auto it = m.begin();it!=m.end();it++){
                ans+=(it->second)*(it->second-1);
            }
        }
        return ans;
    }
};
