//2742. Painting the walls 
//Leetcode Link: https://leetcode.com/problems/painting-the-walls/description/?envType=daily-question&envId=2023-10-14
//Youtube Link: https://www.youtube.com/watch?v=FkJ2_hr6DRo

//Approach-1 (Recursion + Memo)
//T.C : O(n^2) - we will visit at max n^2 states

class Solution {
public:
    int t[501][501];
    int help(vector<int>& cost, vector<int>& time, int wall_left,int start)
    {
        if(wall_left<=0) return 0;
        if(start>=cost.size()) return 1e9;
        if(t[start][wall_left]!=-1) return t[start][wall_left];
        int a = cost[start]+help(cost,time,wall_left-1-time[start],start+1);
        int b = help(cost,time,wall_left,start+1);
        t[start][wall_left]=min(a,b);
        return min(a,b);
    }
    int paintWalls(vector<int>& cost, vector<int>& time) {
        memset(t,-1,sizeof(t));
        int walls_left=cost.size();
        int ans=help(cost,time,walls_left,0);
        return ans;
    }
};