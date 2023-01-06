class Solution {
public:
    int gcd(int a, int b){
        if(b==0) return a;
        return gcd(b,a%b);
    }
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        if(n==1||n==2) return n;
        int ans=2;
        sort(points.begin(), points.end());
        for(int i = 0;i<n-1;i++){
            for(int j = i+1;j<n;j++){
                int num = points[j][1] - points[i][1];
                int den = points[j][0] - points[i][0];
                int gc = gcd(num,den);
                num/=gc; 
                den/=gc;
                int temp=2;
                for(int k =0;k<n;k++){
                    if(k!=i&&k!=j){
                        int num1 = points[k][1]-points[i][1];
                        int den1 = points[k][0]-points[i][0];
                        int gc1 = gcd(num1,den1);
                        num1/=gc1;
                        den1/=gc1;
                        int num2 = points[j][1]-points[k][1];
                        int den2 = points[j][0]-points[k][0];
                        int gc2 = gcd(num2,den2);
                        num2/=gc2;
                        den2/=gc2;
                        if(num1==num2&&den1==den2) temp++;
                    }
                }
                ans = max(ans,temp);

            }
        }
        return ans;
    }
};
