# include <iostream>
# include <vector>
using namespace std;

 // 计数排序：基于数组下标和频数统计（线性时间复杂度）- 稳定的
 // 原始数组规模为n，极值差为m
 // 时间复杂度：o(3n+m) => o(n+m)
 // 空间复杂度：o(m+1) => o(m)
 // 局限性：1.不适合极值差m过大的
 //        2.待排序列是存在小数的，无法建立统计数组
void countSort(vector<int> &arr)
  {
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
    // 2.建立统计数组o(m+1)，遍历原始数组o(n)，统计元素频数
    vector<int> count_arr(d+1);
    for(int i = 0; i < arr.size(); i++)
        count_arr[arr[i] - min] ++;

    // 3.对统计数组做变形，从第二个元素开始遍历o(m)，累加前面的频数
    for(int i=1; i<count_arr.size(); i++)
        count_arr[i] += count_arr[i-1];

    // 4.倒序遍历原始数组o(n)，从变形后的统计数组中找到排位，填入结果数组(索引=排位-1), 统计数组对应的频数自减一
    vector<int> sorted_arr(arr.size());
    for(int i = arr.size()-1; i >= 0; i--)
    {
      sorted_arr[count_arr[arr[i] - min] - 1] = arr[i];
      // 随后更新统计容器的元素值,这和倒序遍历是实现稳定排序的关键.
      count_arr[arr[i]-min] -= 1;
    }
    // 5.最后将已排序容器赋给原始序列,排序结束.
    arr = sorted_arr;
  }



void printArr(vector<int> &arr) {
    for (int i=0; i<arr.size(); i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    vector<int> arr = {95,84,91,98,99,90,99,93,91,92};
    printArr(arr);
    countSort(arr);
    printArr(arr);
}