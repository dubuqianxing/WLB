////debug�����õ��Ĵ���. 
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
//	int count = 0; //��¼�Ƿ������˵�һ����ȵ�λ�� 
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


//AC����  ��ʱ2Сʱ��˼·̫������.

class Solution {
public:
    string longestPalindrome(string s) {
        int right = s.length() - 1; //�����ж���ֹ����.
        int left = 0;               //�����ж���ֹ����.
        int right_temp = right;     //��߲������ұ������-1��ɨ��
        int left_temp = left;
        int max_length = 0;         //���ڼ�¼����ִ��ж೤����ȥ��������Ļ����Ӵ�
        int flag = true;            //�����ж��ַ����Ƿ���Ȼ�ǻ��ĵ�.
        int final_right = right;    //��¼��Ļ����Ӵ�����ʼλ�úͽ���λ��.
        int final_left = left;
        int count = 0; //��¼�Ƿ������˵�һ����ȵ�λ�� 
        int mem_right = right;      //�������м��¼������������ĵ��Ӵ�����ʼλ�úͽ���λ��.
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
                if (count == 1)  //ֻ��¼һ�λ��ĵ���ʼλ�úͽ���λ�ã���ֹ������right/left_temp�ĸı�ÿ�ζ���
                {
                    mem_right = right_temp + 1; //����������right_temp--��left_temp++,���Ҫ���ָ�
                    mem_left = left_temp - 1;                    
                }
                }
                else
                {
                    right_temp = mem_right - 1; //������ǻ����Ӵ�����ôtemp��λ��Ҫ���лָ�
				    left_temp = mem_left;
				    mem_right--;                //��ֹ��ѭ��������ϴβ��ǻ����Ӵ�����ô��¼�����Ӵ���λ��ҲҪˢ��.     
                }
            }
            if ((flag == true) && (max_length < mem_right - mem_left + 1))
            {
                final_left = mem_left;
                final_right = mem_right;
                max_length =  mem_right - mem_left + 1;
            }
        left++;
        right_temp = right; //�ָ�right_temp��left_temp��mem_right��mem_left��λ��.
        left_temp = left;
        mem_right = right;
        mem_left = left;
        }

        return s.substr(final_left, final_right-final_left + 1);

    }
}; 
