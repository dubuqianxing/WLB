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


//AC���� 
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
                if (j > 1 && j-1 > i && nums[j] == nums[j-1])  //��Ҫ��Ϊע��������ж�������j����Ҫ����1������ȡ�ȣ���ֹj=1�ĵ�һ�����ӽ���������Σ�j-1 > i,��ֹȥ��ʱ����Ϊi=j,�����µ�һ����ͱ�ȥ���� 
                    continue;
                left = j + 1;
                right = nums.size()-1;
                while (left < right)
                {
                    if (static_cast <long>(nums[i]) + static_cast <long>(nums[j]) + static_cast <long>(nums[left]) + static_cast <long>(nums[right]) > target)
                        right--;
                    else if (static_cast <long>(nums[i]) + static_cast <long>(nums[j]) + static_cast <long>(nums[left]) + static_cast <long>(nums[right]) < target)  //����ʹ�þ�̬����ת��static_cast����ǿ������ת������Ϊ�˷�ֹ�����������.��Ϊ�ĸ�С��int�߽��ֵ���ӵ�һ����ܳ���int�ı߽硣
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




