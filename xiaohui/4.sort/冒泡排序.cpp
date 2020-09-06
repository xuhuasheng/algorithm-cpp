# include <iostream>
using namespace std;


// # 冒泡排序 - 稳定 原地
// # 时间复杂度：o(n2)
// # 空间复杂度：o(1)
void bubbleSort(int arr[], int n) {
    for (int i=0; i<n-1; i++)
        for (int j=0; j<n-1-i; j++)
            if (arr[j] > arr[j+1])
                swap(arr[j], arr[j+1]);
}

void bubbleSort_v2(int arr[], int n) {
    for (int i=0; i<n-1; i++) {
        bool isSorted = true;
        for (int j=0; j<n-1-i; j++) {
            if (arr[j] > arr[j+1]) {
                swap(arr[j], arr[j+1]);
                isSorted = false;
            }
        }
        if (isSorted)
            break;
    }
}

void bubbleSort_v3(int arr[], int n) {
    int border = n-1;
    int lastborder = 0;
    for (int i=0; i<n-1; i++) {
        bool isSorted = true;
        for (int j=0; j<border; j++) {
            if (arr[j] > arr[j+1]) {
                swap(arr[j], arr[j+1]);
                isSorted = false;
                lastborder = j;
            }
        }
        border = lastborder;
        if (isSorted)
            break;
    }
}

void printArr(int arr[], int n) {
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {3, 4, 2, 1, 5, 6, 7, 8};
    int n = sizeof(arr)/sizeof(arr[0]);
    printArr(arr, n);
    bubbleSort_v3(arr, n);
    printArr(arr, n);
}