////整数反转.cpp
//
//#include <iostream>
//#include <algorithm>
//
//int main() 
//{
//	using namespace std;
//	
//	int x = -321;
//	while (x % 10 != 0)
//	{
//		cout << abs(x % 10) << endl;
//		x = x / 10;
//	} 
//	
//	return 0;
//}


//AC代码 
class Solution {
public:
    int reverse(int x) {
        bool flag = true;
        long long reverse_num = 0;   //为了防止溢出，首先返回的数字要使用long long,让其足够大. 
        if (x < 0)
        {
            flag = false;  //记录是否是负数，负数为false，正数为true. 
            x = abs(x);    //提前取绝对值，正数负数按同样的情况处理. 
        }
        while (x / 10 != 0 || x % 10 != 0)  //第一种对应末尾有0，但是取余会提前跳出循环的情况，第二种对应个位数，但是/10会提前跳出的情况. 
        {
            reverse_num = 10 * reverse_num + x % 10;  
            x = x / 10;
        }

        if (flag == false)
            reverse_num = -1 * reverse_num;  //恢复负数 

        if (reverse_num > pow(2, 31) || reverse_num < -pow(2, 31) - 1) //根据题目要求设置. 
            return 0;
        return reverse_num;
    }
};
