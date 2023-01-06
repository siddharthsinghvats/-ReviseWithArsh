#define ll long
class Solution {
public:
    ll rev(ll a){
        string s = to_string(a);
        reverse(s.begin(),s.end());
        return stol(s);
    }
    int countNicePairs(vector<int>& nums) {
        int n = nums.size();

        unordered_map<ll,ll> m;
        ll mod = 1e9+7;
        for(ll x: nums){
            ll y = rev(x);
           m[x-y]++;
        }
        ll ans = 0;
        for(auto it = m.begin();it!=m.end();it++){
            ans = (ans%mod + (it->second)*(it->second-1)/2%mod)%mod;
        }
        ans%=mod;
        return (int)ans;
    }
};
