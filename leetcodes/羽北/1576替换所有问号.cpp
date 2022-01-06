//#include <iostream>
////#include <cstring>
//int main()
//{
//	using namespace std;
//	
//	string s = "b?";
//	int n = s.length();
//    if (n == 1)
//    {
//        s[0] = 'a';
//        cout << s;
//    }
//
//    for (int i = 0; i < n; i++)
//    {
//        if (s[i] == '?')
//        {
//            for (char c = 'a'; c < 'z'; c++)
//            {
//                if (i == 0 && c != s[i+1])
//                {
//                    s[i] = c;
//                    break;
//                }
//                else if (i == n-1 && c != s[i-1])
//                {
//                    s[i] = c;
//                    break;
//                }
//                else if (c != s[i+1] && c != s[i-1])
//                {
//                    s[i] = c;
//                    break;
//                }
//            }
//        }
//    }
//    cout << s;
//}


//AC代码 
class Solution {
public:
    string modifyString(string s) {
        int n = s.length();
        //单独讨论字符串长度为1的情况，防止越界。 
        if (n == 1)
        {
            s[0] = 'a';
            return s;
        }

        for (int i = 0; i < n; i++)
        {
            if (s[i] == '?')
            {
                for (char c = 'a'; c < 'z'; c++)
                {
                    //单独讨论问号在开头的情况，防止比较重复字符串时index越界。 
					if (i == 0 && c != s[i+1])
                    {
                        s[i] = c;
                        break;
                    }
                    //单独讨论问号在结尾的情况，防止比较重复字符串时index越界 
                    else if (i == n-1 && c != s[i-1])
                    {
                        s[i] = c;
                        break;
                    }
                    //general case: 
                    else if (c != s[i+1] && c != s[i-1])
                    {
                        s[i] = c;
                        break;
                    }
                }
            }
        }
        return s;
    }
};

//如果不想比较特殊的在开头或者结尾的情况，可以使用加头加尾的方式，防止越界，感觉随便加a-z的任意字符即可，最后再除去，有时间可以写一下。 

