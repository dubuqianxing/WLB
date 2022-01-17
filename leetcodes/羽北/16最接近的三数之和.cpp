//调试过程： 
//#include <iostream>
//#include <algorithm> 
//#include <vector>
//int main()
//{
//	using namespace std;
//	vector <int> nums;
//	nums.push_back(-1);
//	nums.push_back(2);
//	nums.push_back(1);
//	nums.push_back(-4);
//	int target = 1;
//	
//    sort(nums.begin(), nums.end());
//    int temp = 0; //用于记录最接近的值.
//    int left = 0;
//    int right = nums.size()-1;
//    int window = 0;
//    int ans = 0; 
//    temp = target - nums[0] - nums[left+1] - nums[right];   //第一个组合
//    for (int i = 0; i < nums.size()-2; i++)
//    {
//        left = i + 1;
//        right = nums.size()-1;
//         while (left < right)
//         {
//             window = abs(target - nums[i]- nums[left] - nums[right]);
//			 if (abs(temp) >= abs(target - nums[i]- nums[left] - nums[right]))
//            {
//            	temp = (target - nums[i]- nums[left] - nums[right]);
//            	ans = nums[i] + nums[left] + nums[right];
//            }
//				
//             if (nums[i] + nums[left] + nums[right] > target)
//                right--;
//             else if (nums[i] + nums[left] + nums[right] < target)
//                left++;
//            else
//            {
//                temp = (target - nums[i]- nums[left] - nums[right]);
//                ans = nums[i] + nums[left] + nums[right];
//                break;
//            }
//         }
//    }
//
//}



//AC 代码 
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        //感觉此题和15三数之和相比，难点在于其target和数组中三个数的和不存在对应关系，因此引入了不确定性.但是应该也得用sort+左右指针去做.
        sort(nums.begin(), nums.end());
        int temp = 0; //用于记录最接近的值.
        int left = 0;
        int right = nums.size()-1;
        temp = abs(target - nums[0] - nums[left+1] - nums[right]);   //第一个组合
        int ans = 0;
        for (int i = 0; i < nums.size()-2; i++)
        {
            left = i + 1;
            right = nums.size()-1;
            while (left < right)
            {
                if (abs(temp) >= abs(target - nums[i]- nums[left] - nums[right]))   //这里一定要取等号，防止第一次就没有进入，如果第一次没有进入，那么ans就只会是初始值. 
                {
                    temp = (target - nums[i]- nums[left] - nums[right]);
                    ans = nums[i] + nums[left] + nums[right];
                }    
                if (nums[i] + nums[left] + nums[right] > target)
                    right--;
                else if (nums[i] + nums[left] + nums[right] < target)
                    left++;
                else
                {
                    temp = (target - nums[i]- nums[left] - nums[right]);
                    ans = nums[i] + nums[left] + nums[right];
                    break;
                }
            }
        }

        return ans;

    }
};

