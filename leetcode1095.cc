// Leetcode question 1095: Find in Mountain array
// Leetcode Link: https://leetcode.com/problems/find-in-mountain-array/description/?envType=daily-question&envId=2023-10-12


//First approach
class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int len = mountainArr.length();
        int min_index=-1;
        for(int i=0;i<len;i++)
        {
            if(target==mountainArr.get(i))
            {
                min_index=i;
                break;
            }
        }
        return min_index;
    }
};



//Second Approach
//optimised
class Solution {
public:
    void help(int target, MountainArray &mountainArr, int start, int end,int& ans)
    {
        if(start>end) return;
        int len=end-start+1;
        int mid;
        if(len%2==0) mid = start + len/2;
        else mid = start +(len-1)/2;
        int first=mountainArr.get(mid);
        if(first==target)
        {
            help(target,mountainArr,start,mid-1,ans);
            if(ans!=-1) ans=min(ans,mid);
            else ans=mid;
        }
        else
        {
            int second=0;
            if(mid!=0) second=mountainArr.get(mid-1);
            int third=0;
            if(mid!=mountainArr.length()-1) third=mountainArr.get(mid+1);
            if(first>target)
            {
                if(first>second && first>third)
                {
                    help(target,mountainArr,start,mid-1,ans);
                    if(ans==-1) help(target,mountainArr,mid+1,end,ans);
                }
                help(target,mountainArr,start,mid-1,ans);
                if(ans==-1) help(target,mountainArr,mid+1,end,ans);
                else return;
                return;
            }
            else if(first<target)
            {
                if(first>second && first>third) return;
                if(first<second) help(target,mountainArr,start,mid-1,ans);
                else if(first<third) help(target,mountainArr,mid+1,end,ans);
                else return;
                return;
            }
            else return;
            return;
        }
        return;

    }
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int len=mountainArr.length();
        int ans=-1;
        help(target,mountainArr,0,len-1,ans);
        return ans;
    }
};

//Third approach: First find peak then find minimum using binary search in either increasing array or decreasing array
class Solution {
public:
    int peak(MountainArray& mountainArr,int start,int end)
    {
        if(start>end) return -1;
        int len=end-start+1;
        int mid;
        int ans;
        if(len%2==0) mid = start+len/2;
        else mid=start+(len-1)/2;
        int first=-1;
        if(mid!=0) first=mountainArr.get(mid-1);
        int second=mountainArr.get(mid);
        int third=-1;
        if(mid!=mountainArr.length()-1) third=mountainArr.get(mid+1);
        if(second>first && second>third) return mid;
        if(second<first) ans=peak(mountainArr,start,mid-1);
        else ans=peak(mountainArr,mid+1,end);
        return ans;
    }
    void helpd(int target,MountainArray& mountainArr,int start,int end,int& ans)
    {
        if(start>end) return;
        int len=end-start+1;
        int mid;
        if(len%2==0) mid = start+len/2;
        else mid=start+(len-1)/2;
        int num=mountainArr.get(mid);
        if(num==target)
        {
            ans=mid;
            return;
        }
        else if(num>target) helpd(target,mountainArr,mid+1,end,ans);
        else helpd(target,mountainArr,start,mid-1,ans);
        return;

    }
    void helpi(int target,MountainArray& mountainArr,int start,int end,int& ans)
    {
        if(start>end) return;
        int len=end-start+1;
        int mid;
        if(len%2==0) mid = start+len/2;
        else mid=start+(len-1)/2;
        int num=mountainArr.get(mid);
        if(num==target)
        {
            ans=mid;
            return;
        }
        else if(num>target) helpi(target,mountainArr,start,mid-1,ans);
        else helpi(target,mountainArr,mid+1,end,ans);
        return;

    }
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int len=mountainArr.length();
        int ans=-1;
        int tip=peak(mountainArr,0,len-1);
        if(mountainArr.get(tip)==target) return tip;
        if(mountainArr.get(tip)<target) return ans;
        helpi(target,mountainArr,0,tip-1,ans);
        if(ans==-1) helpd(target,mountainArr,tip+1,len-1,ans);
        return ans;

    }
};