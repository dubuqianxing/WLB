//三数之和的AC代码.这个题的主要思路在于排序，左右指针以及去重，利用左右指针和排序，可以把时间复杂度从O(n^3)降低到O(n^2).另外，本题中特别需要注意的点在于
//i,左右三个数字的去重问题。由于题目要求返回不重复的三元组，因此，当上一个三元组出现后，首先要满足i不能和上次重复，之后，还需要保证，在当前i的情况下，左右指针
//指向的数字也不能重复，在这里，左指针右移的时候，右指针必须左移，这是因为nums[left]+nums[right] = -nums[i].只移动一边，不会改变输出的三元组. 


class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        if (nums.size() < 3)
            return {};
        vector<vector<int>> ans;
        int right = nums.size() - 1;
        int left = 0;

        for (int i = 0; i < nums.size()-2; i++)
        {
            if (i > 0 && nums[i] == nums[i-1]) //i也需要去重, 另外，这个判断条件要仔细思考。
                continue;  
            left = i + 1;
            right = nums.size() - 1;
            while (left < right)
            {
                if (nums[i] + nums[left] + nums[right] > 0)
                    right--;
                else if (nums[i] + nums[left] + nums[right] < 0)
                    left++;
                else 
                    {
                        ans.push_back({nums[i], nums[left], nums[right]});
                        while (left < right && nums[left] == nums[left+1]) left++; //左端去重
                        while (left < right && nums[right] == nums[right-1]) right--; //右端去重
                        left++;
                        right--;
                    }
            }
        }

        return ans;
    }
};
