#define ll long long
class Solution {
public:
    bool checkPerp(ll x1, ll y1 , ll x2 , ll y2 , ll x3 , ll y3){
        if(x1==x2&&y2 == y3||x2==x3&&y1==y2) return true;
        // cout<< (y2-y3)/(x2-x3)<<endl;
        // cout<<-((x2-x1)/(y2-y1))<<endl;
        if(x1==x2 || x2 == x3 || y2==y1) return false;
        int y = y2-y3;
        int x = x2-x3;
        int p = y2-y1;
        int q = x2-x1;
        int xy = abs(__gcd(x,y));
        int pq = abs(__gcd(p,q));
        y/=xy;
        x/=xy;
        p/=pq;
        q/=pq;
        cout<<x<<" "<<y<<" "<<q<<" "<<p<<endl;
        return y*p==-q*x;
    }
    ll dis(ll x1 , ll y1 , ll x2 , ll y2){
        return (x2-x1)*(x2-x1)+(y2-y1)*(y2-y1);
    }

    bool check(int x1 , int y1 , int x2, int y2 , int x3 , int y3 , int x4,int y4){
        bool f1 = checkPerp(x4,y4,x1,y1,x2,y2)&&checkPerp(x1,y1,x4,y4,x3,y3);
        bool f2 = checkPerp(x4,y4,x3,y3,x2,y2)&&checkPerp(x1,y1,x2,y2,x3,y3);
        bool perp = f1&&f2;
        ll x = dis(x1,y1,x2,y2);
        ll y = dis(x1,y1,x4,y4);
        ll z = dis(x4,y4,x3,y3);
        ll w = dis(x3,y3,x2,y2);
        cout<<f1<<" "<<f2<<" "<<x<<" "<<y<<" "<<z<<" "<<w<<endl;
        bool eq = (x&&x==y&&y==z&&z==w);
        return eq&&perp;
    }

    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        vector<vector<int> > v ={p1,p2,p3,p4};
        sort(v.begin(), v.end());
        int cnt=0;
        do{
            cnt++;
            if(check(v[0][0],v[0][1],v[1][0],v[1][1],v[2][0],v[2][1],v[3][0],v[3][1]))
            return true;
        }while(next_permutation(v.begin(), v.end()));
        cout<<cnt;
        return false;
    }
};
