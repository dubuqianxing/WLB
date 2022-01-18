#include <iostream>
#include <algorithm>
#include <vector>

//int main()
//{
//    using namespace std;	
//	vector <int> nums;
//	
//	nums.push_back(-2);
//	nums.push_back(-1);
//	nums.push_back(-1);
//	nums.push_back(1);
//	nums.push_back(1);
//	nums.push_back(2);
//	nums.push_back(2);
//	int target = 0;
//	
//	sort(nums.begin(), nums.end());
//	for (int k =0; k < nums.size(); k++)
//	{
//		cout << nums[k] << ' ';
//	}
//	cout << endl;
//    int right = nums.size()-1;
//    int left = 2;
////    vector <vector <int>> ans;
//    if (nums.size() < 4)
//        return 0;
//    int i = 0;
//    int j = 1;
//    for (i; i < nums.size()-3; i++)
//    {
//		if (i > 0 && nums[i] == nums[i-1])
//            continue;
//        for (j=i+1; j < nums.size()-2; j++)
//        {
//			cout << i << " " << j << endl;
//			if (j > 1 && j-1 > i && nums[j] == nums[j-1])
//            	continue;
//            left = j + 1;
//            right = nums.size()-1;
////            cout << j << " " << i << endl;
//            while (left < right)
//            {
//				if (nums[i] + nums[j] + nums[left] + nums[right] > target)
//                    right--;
//                else if (nums[i] + nums[j] + nums[left] + nums[right] < target)
//                    left++;
//                else
//                {
//                	
//					cout << nums[i] << ' ' << nums[j] << ' ' << nums[left] << ' ' << nums[right] << endl;
//                    while (left < right && nums[left] == nums[left + 1]) left++;
//                    while (left < right && nums[right] == nums[right-1]) right--;
//                    left++;
//                    right--;
//                }
//            }
//        }
//    }	
//	
//} 


//AC代码 
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int right = nums.size()-1;
        int left = 2;
        vector <vector <int>> ans;
        if (nums.size() < 4)
            return {};
        int i = 0;
        int j = 1;
        for (i; i < nums.size()-3; i++)
        {
            if (i > 0 && nums[i] == nums[i-1])
                continue;
            for (j=i+1; j < nums.size()-2; j++)
            {
                if (j > 1 && j-1 > i && nums[j] == nums[j-1])  //需要尤为注意这里的判断条件，j首先要大于1，不能取等，防止j=1的第一个例子进不来，其次，j-1 > i,防止去重时，因为i=j,而导致第一个解就被去掉。 
                    continue;
                left = j + 1;
                right = nums.size()-1;
                while (left < right)
                {
                    if (static_cast <long>(nums[i]) + static_cast <long>(nums[j]) + static_cast <long>(nums[left]) + static_cast <long>(nums[right]) > target)
                        right--;
                    else if (static_cast <long>(nums[i]) + static_cast <long>(nums[j]) + static_cast <long>(nums[left]) + static_cast <long>(nums[right]) < target)  //这里使用静态类型转换static_cast进行强制类型转换，是为了防止出现溢出错误.因为四个小于int边界的值，加到一起可能超过int的边界。
                        left++;
                    else
                    {
                        ans.push_back({nums[i], nums[j], nums[left], nums[right]});
                        while (left < right && nums[left] == nums[left + 1]) left++;
                        while (left < right && nums[right] == nums[right-1]) right--;
                        left++;
                        right--;
                    }
                }
            }
        }

        return ans;
    }
};




