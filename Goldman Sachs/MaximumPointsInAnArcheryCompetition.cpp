class Solution {
public:
    
    vector<int> maximumBobPoints(int numArrows, vector<int>& a) {
        vector<int>b(12,0);
        int dp[numArrows+1][12];
        memset(dp,-1,sizeof(dp));
        for(int i =0;i<=numArrows;i++) dp[i][0] = 0;
        for(int i = 0;i<12;i++) dp[0][i] = 0;
        for(int i =0;i<=numArrows;i++){
            for(int j = 1;j<12;j++){
                if(i>a[j]){
                     int x= max(j+dp[i-a[j]-1][j-1],dp[i][j-1]);
                     dp[i][j] = max(x,dp[i][j]);
                }else{
                    dp[i][j] = max(dp[i][j],dp[i][j-1]);
                }
            }
        }
        int i = numArrows, j = 11;
        while(i>=0&&j>=1){
            if(i>a[j]&&dp[i][j] ==j+ dp[i-a[j]-1][j-1]){
                b[j] = a[j]+1;
                
                i-=a[j]+1;
                numArrows-=a[j]+1;
                j--;
            }else j--;
        }
        b[0] = numArrows;
        return b;
    }
};
