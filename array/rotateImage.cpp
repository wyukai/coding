//
// Created by wk on 2021/7/30.
//
/*
 * 48 Rotate Image
 * 给定一个 n × n 的矩阵，求它顺时针旋转 90 度的结果，且必须在原矩阵上修改（in-place）。
怎样能够尽量不创建额外储存空间呢？
输入和输出都是一个二维整数矩阵。
 Input:
[[1,2,3],
[4,5,6],
[7,8,9]]
Output:
[[7,4,1],
[8,5,2],
[9,6,3]]

 */

#include <iostream>
#include <vector>

using namespace std;

void rotateImage(vector<vector<int>>& matrix){
    int temp = 0, n = matrix.size() - 1;
    for (int i = 0; i <= n/2; ++i) {
        for (int j = i; j < n - i ; ++j) {
            temp = matrix[j][n-i];
            matrix[j][n-i] = matrix[i][j];
            matrix[i][j] = matrix[n-j][i];
            matrix[n-j][i] = matrix[n-i][n-j];
            matrix[n-i][n-j] = temp;
        }
    }
}

int main(){
    vector<vector<int>> matrix = {{1,2},
                                  {3,4}};
    rotateImage(matrix);
    return 0;
}