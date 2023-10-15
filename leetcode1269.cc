// 1269. Number of Ways to Stay in the Same Place After Some Steps
// Leetcode link: https://leetcode.com/problems/number-of-ways-to-stay-in-the-same-place-after-some-steps/description/?envType=daily-question&envId=2023-10-15

//Approach: Apply all the three possible steps on the current step. If idx is greater than steps even if we go all left, we cannot reach 0th index. So the size of
//          dp is like this.
class Solution {
public:
    int dp[501][501];
    int mod=1000000007;
    int help(int steps,int arrLen,int idx)
    {
        if(steps==0)
        {
            if(idx==0){
                return 1;
            }
            else return 0;
        }
        if(idx<0 || idx>=arrLen || idx>steps) return 0;
        if(dp[steps][idx]!=-1)
        {
            return dp[steps][idx];
        }
        int a = help(steps-1,arrLen,idx-1);
        int b = help(steps-1,arrLen,idx);
        int c = help(steps-1,arrLen,idx+1);
        dp[steps][idx]=(((a%mod)+(b%mod))%mod+(c%mod))%mod;
        return dp[steps][idx];
    }
    int numWays(int steps, int arrLen) {
        int idx=0;
        memset(dp,-1,sizeof(dp));
        int ans=help(steps,arrLen,idx);
        return ans;
    }
};