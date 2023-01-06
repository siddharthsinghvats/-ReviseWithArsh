class Solution {
public:
    int trailingZeroes(int n) {
        int temp =n;
        int cnt2=0;
        while(temp>=2){
            temp/=2;
            cnt2+=temp;
        }
        int cnt5=0;
        temp=n;
        while(temp>=5){
            temp/=5;
            cnt5+=temp;
        }
        return min(cnt2,cnt5);
    }
};
