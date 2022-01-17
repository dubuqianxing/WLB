//���Թ��̣� 
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
//    int temp = 0; //���ڼ�¼��ӽ���ֵ.
//    int left = 0;
//    int right = nums.size()-1;
//    int window = 0;
//    int ans = 0; 
//    temp = target - nums[0] - nums[left+1] - nums[right];   //��һ�����
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



//AC ���� 
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        //�о������15����֮����ȣ��ѵ�������target���������������ĺͲ����ڶ�Ӧ��ϵ����������˲�ȷ����.����Ӧ��Ҳ����sort+����ָ��ȥ��.
        sort(nums.begin(), nums.end());
        int temp = 0; //���ڼ�¼��ӽ���ֵ.
        int left = 0;
        int right = nums.size()-1;
        temp = abs(target - nums[0] - nums[left+1] - nums[right]);   //��һ�����
        int ans = 0;
        for (int i = 0; i < nums.size()-2; i++)
        {
            left = i + 1;
            right = nums.size()-1;
            while (left < right)
            {
                if (abs(temp) >= abs(target - nums[i]- nums[left] - nums[right]))   //����һ��Ҫȡ�Ⱥţ���ֹ��һ�ξ�û�н��룬�����һ��û�н��룬��ôans��ֻ���ǳ�ʼֵ. 
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

