// 给定一个二维的矩阵，包含 'X' 和 'O'（字母 O）。

// 找到所有被 'X' 围绕的区域，并将这些区域里所有的 'O' 用 'X' 填充。

// 示例:

// X X X X
// X O O X
// X X O X
// X O X X
// 运行你的函数后，矩阵变为：

// X X X X
// X X X X
// X X X X
// X O X X
// 解释:

// 被围绕的区间不会存在于边界上，换句话说，任何边界上的 'O' 都不会被填充为 'X'。 任何不在边界上，或不与边界上的 'O' 相连的 'O' 最终都会被填充为 'X'。如果两个元素在水平或垂直方向相邻，则称它们是“相连”的。

// 来源：力扣（LeetCode）
// 链接：https://leetcode-cn.com/problems/surrounded-regions
// 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

// 反向操作，找边界点‘O’ 并dfs置换为‘#’，再全局遍历替换'O'->'X', '#'->''O。
class Solution {
public:
    void solve(vector<vector<char>>& board) {
        if (board.empty()) return;
        int m = board.size();
        int n = board[0].size();
        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                bool isEdge = (i==0 || j==0 || i==m-1 || j==n-1);
                if (isEdge && board[i][j] == 'O') {
                    dfs(i, j, board);
                }
            }
        }
        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                if (board[i][j] == '#') {
                    board[i][j] = 'O';
                } else if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
            }
        }
    }
    void dfs(int x, int y, vector<vector<char>>& board) {
        if (x<0 || x>=board.size() || y<0 || y>=board[0].size() || board[x][y] == 'X' || board[x][y] == '#') {
            return;
        }
        board[x][y] = '#';
        dfs(x+1, y, board);
        dfs(x-1, y, board);
        dfs(x, y+1, board);
        dfs(x, y-1, board);
    }
};