#define ll long long
class Solution {
public:
    ll power(ll a ,ll b, ll m){
        if(b==0) return 1;
        if(b&1) return (a%m*power(a,b-1,m)%m)%m;
        return power((a%m*a%m)%m, b/2,m);
    }
    string longestPrefix(string s) {
        ll p = 128,m = 1e9+7;
        ll x =1,y=1;
        int n = s.length();
    ll l=0,r=0;

        int ans = INT_MIN;
        for(int i=1;i<=n-1;i++){
            l=(l%m+(1LL*(s[i-1]-'a'+1)%m*x%m))%m;
            r= (r*p)%m;
            r+=((s[n-i]-'a'+1))%m;
            if(l==r) ans =i;
            x= x*p%m;
        }
        if(ans ==INT_MIN)return "";
        string cur ="";
        for(int i =0;i<ans;i++) cur+=s[i];
        return cur;
    }
};
