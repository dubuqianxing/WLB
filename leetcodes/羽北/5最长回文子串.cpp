////debug过程用到的代码. 
//
//#include <iostream>
//#include <cstring> 
//
//int main()
//{
//	using namespace std;
//		
//	string s = "babad";
//	int right = s.length() - 1;
//	int left = 0;
//	int right_temp = right;
//	int left_temp = left;
//	int max_length = 0;
//	int flag = true;
//	int final_right = right;
//	int final_left = left;
//	int count = 0; //记录是否碰到了第一个相等的位置 
//	int mem_right = right;
//	int mem_left = left;
//	
//	
//	while (right > left)
//	{
//	    count = 0;
//		while (right_temp >= left_temp)
//	    {
//	        flag = false;
//	        if (s[right_temp] == s[left_temp])
//	        {
//	            right_temp--;
//	            left_temp++;
//	            flag = true;
//	            count++;
//	        if (count == 1)
//	        {
//	        	mem_right = right_temp + 1;
//	        	mem_left = left_temp - 1;
//	        }
//	        }
//	        else
//			{
//				right_temp = mem_right - 1;
//				left_temp = mem_left;
//				mem_right--;
//			}
//	    }
//	    if ((flag == true) && (max_length < mem_right - mem_left + 1))
//	    {
//	        final_left = mem_left;
//	        final_right = mem_right;
//	        max_length =  mem_right - mem_left + 1;
//	    }
//	left++;
//	right_temp = right;
//	left_temp = left;
//	mem_right = right;
//	mem_left = left;
//}
//
//cout <<  s.substr(final_left, final_right-final_left + 1);
//
//return 0;	
//}
//


//AC代码  用时2小时，思路太垃圾了.

class Solution {
public:
    string longestPalindrome(string s) {
        int right = s.length() - 1; //用于判断终止条件.
        int left = 0;               //用于判断终止条件.
        int right_temp = right;     //左边不动，右边逐次做-1的扫描
        int left_temp = left;
        int max_length = 0;         //用于记录最长的字串有多长，以去除不是最长的回文子串
        int flag = true;            //用于判断字符串是否仍然是回文的.
        int final_right = right;    //记录最长的回文子串的起始位置和结束位置.
        int final_left = left;
        int count = 0; //记录是否碰到了第一个相等的位置 
        int mem_right = right;      //用于在中间记录，本次满足回文的子串的起始位置和结束位置.
        int mem_left = left;

        while (right > left)
        {
            count = 0;
            while (right_temp >= left_temp)
            {
                flag = false;
                if (s[right_temp] == s[left_temp])
                {
                    right_temp--;
                    left_temp++;
                    flag = true;
                    count++;
                if (count == 1)  //只记录一次回文的起始位置和结束位置，防止其随着right/left_temp的改变每次都变
                {
                    mem_right = right_temp + 1; //由于上面有right_temp--和left_temp++,因此要做恢复
                    mem_left = left_temp - 1;                    
                }
                }
                else
                {
                    right_temp = mem_right - 1; //如果不是回文子串，那么temp的位置要进行恢复
				    left_temp = mem_left;
				    mem_right--;                //防止死循环，如果上次不是回文子串，那么记录回文子串的位置也要刷新.     
                }
            }
            if ((flag == true) && (max_length < mem_right - mem_left + 1))
            {
                final_left = mem_left;
                final_right = mem_right;
                max_length =  mem_right - mem_left + 1;
            }
        left++;
        right_temp = right; //恢复right_temp，left_temp，mem_right，mem_left的位置.
        left_temp = left;
        mem_right = right;
        mem_left = left;
        }

        return s.substr(final_left, final_right-final_left + 1);

    }
}; 
