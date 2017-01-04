//https://leetcode.com/problems/minimum-size-subarray-sum/
//半开半闭区间
class Solution {
public:
    bool able(int l, vector<int>& nums, int s) {
        if(l == 0)
            return false;
        int sum = 0;
        for(int i = 0; i < l; i++) {
            sum += nums[i];
        }
        if(sum >= s)
            return true;
        for(int i = l; i < nums.size(); i++) {
            sum -= nums[i - l];
            sum += nums[i];
            if(sum >= s)
                return true;
        }
        return false;
    }
    int minSubArrayLen(int s, vector<int>& nums) {
        if(nums.size() == 0)
            return 0;
        int l = 0;
        int r = nums.size();
        int len;
        while(r - l > 1) {
            int mid = (l + r) / 2;
            if(!able(mid, nums, s))
                l = mid;
            else
                r = mid;
        }  
        if(r == nums.size() && !able(r, nums,s))
            return 0;
        return r;
    }
};