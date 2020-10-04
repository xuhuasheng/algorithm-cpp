// 给你一个由 '1'（陆地）和 '0'（水）组成的的二维网格，请你计算网格中岛屿的数量。

// 岛屿总是被水包围，并且每座岛屿只能由水平方向或竖直方向上相邻的陆地连接形成。

// 此外，你可以假设该网格的四条边均被水包围。

//  

// 示例 1:

// 输入:
// [
// ['1','1','1','1','0'],
// ['1','1','0','1','0'],
// ['1','1','0','0','0'],
// ['0','0','0','0','0']
// ]
// 输出: 1
// 示例 2:

// 输入:
// [
// ['1','1','0','0','0'],
// ['1','1','0','0','0'],
// ['0','0','1','0','0'],
// ['0','0','0','1','1']
// ]
// 输出: 3
// 解释: 每座岛屿只能由水平和/或竖直方向上相邻的陆地连接而成。

// 来源：力扣（LeetCode）
// 链接：https://leetcode-cn.com/problems/number-of-islands
// 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

class Solution {
public:
    int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        if (m == 0) return 0;
        int n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        int cnt = 0;
        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                if (!visited[i][j] && grid[i][j] == '1') {
                    cnt += 1;
                    dfs(i, j, grid, visited);
                }
            }
        }
        return cnt;
    }

    void dfs(int x, int y, vector<vector<char>>& grid, vector<vector<bool>>& visited) {
        visited[x][y] = true;
        for (int i=0; i<4; i++) {
            int new_x = x + dir[i][0];
            int new_y = y + dir[i][1];
            if (new_x >= 0 && new_x < grid.size() && new_y >= 0 && new_y < grid[0].size()) {
                if (!visited[new_x][new_y] && grid[new_x][new_y] == '1') {
                    dfs(new_x, new_y, grid, visited);
                }
            }
        }
    }

};