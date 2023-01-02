class Solution {
public:
    int gcd(int a , int b){
        if(a==0) return b;
        if(b==0) return a;
        if(b==1 || a==1) return 1;
        return gcd(b,a%b);
    }
    int minOperations(vector<int>& nums, vector<int>& nd) {
        int x =0;
        for(auto y:nd) x= gcd(x,y);
        set<int> s;
        for(int i =1;i*i<=x;i++){
            if(x%i==0){
                s.insert(x/i);
                s.insert(i);
            }
        }
        int ans = 0;
        map<int,int> m;
        for(auto y: nums) m[y]++;
        for(auto it = m.begin();it!=m.end();it++){
            if(s.find(it->first)==s.end()){
                ans+=it->second;
            }else{
                break;
            }
        }
        return ans==nums.size()?-1:ans;
    }
};
