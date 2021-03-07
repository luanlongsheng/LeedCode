/*************************************************************************
	> File Name: Leetcode53.cpp
	> Author:lls 
	> Mail:luanlongshengv@163.com 
	> Created Time: 2021年03月07日 星期日 08时19分27秒
 ************************************************************************/
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans = INT_MIN, now = 0;
        for (int i = 0; i < nums.size(); i++) {
            now = max(now + nums[i], nums[i]);
            ans = max(ans, now);
        }
        return ans;
    }
};
