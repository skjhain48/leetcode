//746. Min Cost Climbing Stairs
//Leetcode Link: https://leetcode.com/problems/min-cost-climbing-stairs/description/?envType=daily-question&envId=2023-10-13

//Approach: Use recursion to calculate the cost, and store it in array to avoid time limit exceed.
class Solution {
public:
    int dp[1000];
    int help(vector<int>& cost, int start, int end, int path_cost)
    {
        if(start==end) return path_cost;
        if(dp[start]!=0) return dp[start];
        int cost1=cost[start]+help(cost,start+1,end,path_cost);
        int cost2=INT_MAX;
        if(end-start>1) cost2=cost[start]+help(cost,start+2,end,path_cost);
        dp[start]=min(cost1,cost2);
        return min(cost1,cost2);

    }
    int minCostClimbingStairs(vector<int>& cost) {
        int len=cost.size();
        int path_cost=0;
        int cost1=help(cost,0,len,path_cost);
        int cost2=INT_MAX;
        if(len>1) cost2=help(cost,1,len,path_cost);
        return min(cost1,cost2);
    }
};