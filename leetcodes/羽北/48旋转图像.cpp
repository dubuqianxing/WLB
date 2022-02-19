//第一种方法，先上下反转，再对焦反转，对角反转时，对角线为左上到右下的连线，反转时只需要遍历上三角矩阵即可。 


class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int i =0;
        int j = 0;
        int temp;
        int n = matrix[0].size();
        //上下翻转
        for (i = 0; i < n / 2; i++)
            for (j = 0; j < n; j++)
            {
                temp = matrix[n-i-1][j];
                matrix[n-i-1][j] = matrix[i][j];
                matrix[i][j] = temp;
            }
        //以左上右下为对称轴进行转置
        for (i = 0; i < n; i++)
            for (j = i; j < n; j++)
            {
                temp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = temp;
            }
    }
};
