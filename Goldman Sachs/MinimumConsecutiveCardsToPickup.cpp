class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        vector<int> v(1000001,-1);
        int ans  = INT_MAX;
        for(int i = 0;i<cards.size();i++){
            if(v[cards[i]]!=-1){
                ans = min(ans, i-v[cards[i]]+1);
            }
            v[cards[i]] = i;
        }
        return ans == INT_MAX?-1:ans;
    }
};
