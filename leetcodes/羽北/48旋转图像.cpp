//��һ�ַ����������·�ת���ٶԽ���ת���ԽǷ�תʱ���Խ���Ϊ���ϵ����µ����ߣ���תʱֻ��Ҫ���������Ǿ��󼴿ɡ� 


class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int i =0;
        int j = 0;
        int temp;
        int n = matrix[0].size();
        //���·�ת
        for (i = 0; i < n / 2; i++)
            for (j = 0; j < n; j++)
            {
                temp = matrix[n-i-1][j];
                matrix[n-i-1][j] = matrix[i][j];
                matrix[i][j] = temp;
            }
        //����������Ϊ�Գ������ת��
        for (i = 0; i < n; i++)
            for (j = i; j < n; j++)
            {
                temp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = temp;
            }
    }
};
