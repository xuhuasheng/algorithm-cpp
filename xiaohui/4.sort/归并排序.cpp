# include <iostream>
# include <vector>
using namespace std;
void merge(vector<int> &arr, int left, int mid, int right);


// # 归并排序：稳定的 
// # 时间复杂度：o(nlogn)
// # 空间复杂度：o(n)
void sort_merge_recursive(vector<int> &arr, int left, int right)
  {
    // 思想：
    // 归并排序这里不再是直接在原始序列上进行操作;
    // 归并排序利用的是分而治之的思想,将序列分成两个子序列,将两个子序列排好序后合并为有序的序列;
    // 而对两个子序列进行排序同样用分而治之,如此递归下去;
    // 归并分为三步：分,治,合;治是关键,而治又是最简单的,将序列分为只有一个元素的两个子序列后自然变得有序;
    // 所以归并可以分为两步：将序列一直分成只有一个元素的子序列,然后将这些有序的子序列合并.
 
    if(left < right)
    {
      // 将序列一分为二并获取中间位置.
      int mid = (left + right)/2;
      // 递归处理两个子序列使之有序.
      sort_merge_recursive(arr, left, mid);
      sort_merge_recursive(arr, mid + 1, right);
      // 合并两个有序子序列后结束归并排序.
      merge(arr, left, mid, right);
    }
  }
 
void merge(vector<int> &arr, int left, int mid, int right)
{
    // 将有序的两个子序列合并.
    // 获取两个子序列的第一个元素.
    int i = left;
    int j = mid + 1;
    // 创建临时容器来保存合并结果,同时指定容器大小.
    vector<int> temp(right - left + 1);
    // 开始合并.
    int k = 0;
    while ((i <= mid) && (j <= right)) {
        if (arr[i] <= arr[j])
            temp[k++] = arr[i++];
        else
            temp[k++] = arr[j++];
    }
    // 到此为止肯定有一个子序列已经完全放到临时容器里,现在将另子序列的元素放入临时容器.
    while (i <= mid)
        temp[k++] = arr[i++];

    while (j <= right)
        temp[k++] = arr[j++];
    // 最后将临时容器里的元素复制到原容器完成合并.
    // 切记这里不能直接使用赋值：arr = temp;
    // 因为这是递归操作,如果这样赋值,那么arr的长度会变成2(思考一下为什么是2),
    // 那么后续操作中会导致"std::out_of_range"错误.
    for(int i=0, n=0; n < k; n++)
    {
        arr[left++] = temp[n];
    }
}

void printArr(vector<int> &arr) {
    for (int i=0; i<arr.size(); i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    vector<int> arr = {4,4,6,5,3,2,8,1};
    printArr(arr);
    sort_merge_recursive(arr, 0, arr.size()-1);
    printArr(arr);
}
 