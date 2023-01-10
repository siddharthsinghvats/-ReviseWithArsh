class Solution {
public:
    bool isPossible(vector<int>& nums) {
        map<int,int> avail, want;
       for(auto x: nums)
       {
           avail[x]++;
       }

       for(auto x : nums){
           if(avail[x]<=0) continue;
           if(want[x]>0){
               avail[x]--;
               want[x]--;
               want[x+1]++;
           }else{
               if(avail[x+1]>0&&avail[x+2]>0){
                   avail[x]--;
                   avail[x+1]--;
                   avail[x+2]--;
                   want[x+3]++;
               }else{
                   return false;
               }
           }
       }
       return true;
    }
};
