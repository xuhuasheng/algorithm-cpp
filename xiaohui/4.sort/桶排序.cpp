# include <iostream>
# include <vector>
# include <algorithm>
using namespace std;

// # 桶排序：稳定 非原地
// 类似于计数排序，用“桶”区间，是线性时间复杂度的排序方法
// # 时间复杂度：o(n)
// # 空间复杂度：o(n)
void bucketSort(vector<double> &arr) {
    // 1.遍历原始数组o(n)，求最大值和最小值，计算差值
    int max = arr[0];
    int min = arr[0];
    for(int i = 1; i < arr.size(); i++) {
      if(arr[i] > max)
        max = arr[i];
      if(arr[i] < min)
        min = arr[i];
    }
    int d = max - min;
    // 2.创建桶o(n) 桶的数量=元素的数量
    int bucketsNum = arr.size();
    vector<vector<double>> buckets(bucketsNum);

    // # 3.遍历原始数组o(n)，将每个元素放入桶中
    // # 除最后一个桶只包含max外，前面的各个桶的区间=(max-min)/(桶的数量-1)
    for(int i=0; i<arr.size(); i++) {
        int idx = (arr[i]-min)/d * (bucketsNum-1);
        buckets[idx].push_back(arr[i]);
    }
      

    // 4.对每个桶内部进行排序 所以桶的时间复杂度之和为o(n)
    for (int i=0; i<bucketsNum; i++) {
      sort(buckets[i].begin(), buckets[i].end());
    }

    // 5.输出全部元素 o(n)
    vector<double> sortedArr(arr.size());
    int k = 0;
    for (int i=0; i<bucketsNum; i++) {
      for(int j=0; j<buckets[i].size(); j++)
        sortedArr[k++] = (buckets[i][j]);
    } 
    arr = sortedArr;
}



void printArr(vector<double> &arr) {
    for (int i=0; i<arr.size(); i++) {
        printf("%f ", arr[i]);
    }
    printf("\n");
}

int main() {
    vector<double> arr = {4.12,6.421,0.0023,3.0,2.123,8.123,4.12,10.09};
    printArr(arr);
    bucketSort(arr);
    printArr(arr);
}