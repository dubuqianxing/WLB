//����֮�͵�AC����.��������Ҫ˼·������������ָ���Լ�ȥ�أ���������ָ������򣬿��԰�ʱ�临�Ӷȴ�O(n^3)���͵�O(n^2).���⣬�������ر���Ҫע��ĵ�����
//i,�����������ֵ�ȥ�����⡣������ĿҪ�󷵻ز��ظ�����Ԫ�飬��ˣ�����һ����Ԫ����ֺ�����Ҫ����i���ܺ��ϴ��ظ���֮�󣬻���Ҫ��֤���ڵ�ǰi������£�����ָ��
//ָ�������Ҳ�����ظ����������ָ�����Ƶ�ʱ����ָ��������ƣ�������Ϊnums[left]+nums[right] = -nums[i].ֻ�ƶ�һ�ߣ�����ı��������Ԫ��. 


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
            if (i > 0 && nums[i] == nums[i-1]) //iҲ��Ҫȥ��, ���⣬����ж�����Ҫ��ϸ˼����
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
                        while (left < right && nums[left] == nums[left+1]) left++; //���ȥ��
                        while (left < right && nums[right] == nums[right-1]) right--; //�Ҷ�ȥ��
                        left++;
                        right--;
                    }
            }
        }

        return ans;
    }
};
