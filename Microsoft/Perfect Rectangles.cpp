long long min(long long a,long long b){
    return a<b?a:b;
}
long long max(long long a,long long b){
    return a<b?b:a;
}


class Solution {
public:
    map<pair<int,int> ,int> m;
    bool overlap(int x, int y , int typ){
        if(!m.count({x,y})){
            m[{x,y}] = typ;
            return false;
        }
        int prev_typ = m[{x,y}];
        if(prev_typ&typ) return true;
        m[{x,y}] = (typ|prev_typ);
        return false;
    }
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        long bx,by,tx,ty;
        bx = by = INT_MAX;
        tx = ty = INT_MIN;
        long area=0;
        for(auto x: rectangles){
            bx = min(x[0],bx);
            by = min(x[1],by);
            tx = max(x[2],tx);
            ty = max(x[3],ty);
            area += 1LL*(x[2]-x[0])*(x[3]-x[1]);
            if(overlap(x[0],x[1],1)) return false;
            if(overlap(x[0],x[3],2)) return false;
            if(overlap(x[2],x[3],4)) return false;
            if(overlap(x[2],x[1],8)) return false;
        }
         int cnt =0;
        for(auto it : m){
           
            auto itt = it.second;
            if(itt ==1||itt ==2||itt ==4||itt==8) cnt++;
           
        }
         return (cnt==4 && area==(tx-bx)*(ty-by)) ;
    }
};
