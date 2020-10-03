// 实现 pow(x, n) ，即计算 x 的 n 次幂函数。

// 示例 1:

// 输入: 2.00000, 10
// 输出: 1024.00000
// 示例 2:

// 输入: 2.10000, 3
// 输出: 9.26100
// 示例 3:

// 输入: 2.00000, -2
// 输出: 0.25000
// 解释: 2-2 = 1/22 = 1/4 = 0.25

// 来源：力扣（LeetCode）
// 链接：https://leetcode-cn.com/problems/powx-n
// 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

// 快速幂
// # 时间复杂度：O(logn)，即为对 nn 进行二进制拆分的时间复杂度。
// # 空间复杂度：O(1)。
class Solution {
public:
    double quickMul(double x, long long N) {
        double ans = 1.0;
        while (N) {
            if (N & 1) {
                ans *= x;
            }
            x *= x;
            N >>= 1;
        }
        return ans;
    }

    double myPow(double x, int n) {
        long long N = n;
        return N >= 0 ? quickMul(x, N) : 1.0 / quickMul(x, -N);
    }
};

// 时间复杂度：O(logn)，即为递归的层数。
// # 空间复杂度：O(logn)，即为递归的层数。这是由于递归的函数调用会使用栈空间。
class Solution {
public:
    double quickMul(double x, long long N) {
        if (N == 0) {
            return 1.0;
        }
        double y = quickMul(x, N / 2);
        return N % 2 == 0 ? y * y : y * y * x;
    }

    double myPow(double x, int n) {
        long long N = n;
        return N >= 0 ? quickMul(x, N) : 1.0 / quickMul(x, -N);
    }
};
