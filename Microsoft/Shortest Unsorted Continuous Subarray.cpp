class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int> v = nums;
        sort(v.begin(),v.end());
        int s=-1,e=-1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=v[i]&&s ==-1) s = i;
            if(nums[i]!=v[i]) e =i;
        }
        
        return (s==-1?0:e-s+1);
    }
};
