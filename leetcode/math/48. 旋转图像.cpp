// 给定一个 n × n 的二维矩阵表示一个图像。

// 将图像顺时针旋转 90 度。

// 说明：

// 你必须在原地旋转图像，这意味着你需要直接修改输入的二维矩阵。请不要使用另一个矩阵来旋转图像。

// 示例 1:

// 给定 matrix = 
// [
//   [1,2,3],
//   [4,5,6],
//   [7,8,9]
// ],

// 原地旋转输入矩阵，使其变为:
// [
//   [7,4,1],
//   [8,5,2],
//   [9,6,3]
// ]

// 来源：力扣（LeetCode）
// 链接：https://leetcode-cn.com/problems/rotate-image
// 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        // 1.上下翻转
        reverse(matrix.begin(), matrix.end());
        // int u = 0;
        // int b = matrix.size()-1;
        // while (u < b) {
        //     swap(matrix[u], matrix[b]);
        //     u++;
        //     b--;
        // }
        
        // 2.主对角线翻转
        for (int i=0; i<matrix.size(); i++) {
            for (int j=i+1; j<matrix.size(); j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
    }
};