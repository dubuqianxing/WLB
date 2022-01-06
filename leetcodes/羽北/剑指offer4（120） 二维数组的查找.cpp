////查看二维vector的大小
//
//#include <iostream>
//#include <vector>
//
//int main() 
//{
//	using namespace std;
//	
//	vector <vector <int> > nums;
//	nums[0].push_back(1);
//	nums[0].push_back(2);
//	nums[1].push_back(3);
//	nums[1].push_back(4);
//	
//	cout << nums[0].size() << endl;
//	
//	return 0;
//}


//自己的解答 
class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
    //感觉开始最naive的思路就是在行和列上都进行二分，可以先试试.
    //试了一下，发现二分好像只能在一个方向去做，并且只能排除切出来的四个小格子里面的一个. //看了题解，需要使用标志位分四种情况排除
    //或者使用暴力解法，看问题的规模最高也就是1million，可以暴力两层for循环.
    //或者是不是可以使用树的方式去查找.
    //最终题解的方法是用线性查找，但是初始点的选取很有讲究，应该选左下角或者右上角.下面以右上角为例进行求解.除此之外还有广搜，暴力法两种解法. 
    bool is_have = false;
    int up = 0;
    int down = matrix.size(); //得到有多少行. 
    if (down == 0)
    {
        return is_have;
    }
    int left = 0;
    int right = matrix[0].size(); //得到有多少列，这里开始的时候没有-1是防止数组直接越界.
    int i = 0;

    right = right - 1; 
    while (right >= 0 && up < down) //这里的判断条件是防止在数组的行列的任一方向越界.
    {
        if (matrix[up][right] > target)  //千万注意up和right不要写反，这个bug修了一上午！！！
            right--;
        else if (matrix[up][right] < target)
            up++;
        else
        {
            is_have = true;
            break;
        }
    }
    return is_have;
    }
};
