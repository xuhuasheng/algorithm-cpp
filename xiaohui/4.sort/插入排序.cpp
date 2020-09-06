# include <iostream>
using namespace std;

# define len(a) sizeof(a)/sizeof(a[0])


// # 插入排序法
// # 时间复杂度o(n^2)
// # 空间复杂度o(1)
// 稳定的原地排序
void insertSort(int a[], int n) {
    // 从第二个元素开始 遍历候选区
    for (int i=1; i<n; ++i) {
        int key = a[i]; //当前待插元素
        int j = i-1;    //排序区的游标
        while (j>=0 && a[j] > key)
        {
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = key;
    }
}


void printArr(int a[], int n) {
    for (int i=0; i< n; ++i) {
        cout<<a[i]<<" ";
    }
    cout<<endl;
}
int main() {
    int a[] = {4,4,6,5,3,2,8,1};
    int n = len(a);
    printArr(a, n);
    insertSort(a, n);
    printArr(a, n);
}
