# include <iostream>
using namespace std;
# define len(x) sizeof(x)/sizeof(x[0])

int partition(int arr[], int start, int end);
int partition2(int arr[], int start, int end);


// # 快排 - 不稳定的原地排序
// # 时间复杂度：o(nlogn)：logn轮递归，每一次都是n
// # 空间复杂度：o(logn)：快速排序每次递归都会返回一个中间值的位置，必须使用栈。所以空间复杂度就是栈用的空间
void quickSort(int arr[], int start, int end) {
    if (start >= end) {
        return;
    }
    int pivotIndex = partition(arr, start, end);
    quickSort(arr, start, pivotIndex-1);
    quickSort(arr, pivotIndex+1, end);
}

int partition(int arr[], int start, int end) {
    int pivot = arr[start];
    int mark = start;
    for (int i=start+1; i<=end; ++i) {
        if (arr[i] < pivot) {
            mark ++;
            swap(arr[i], arr[mark]);
        }
    }
    swap(arr[start], arr[mark]);
    return mark;
}

int partition2(int arr[], int start, int end) {
    int pivot = arr[start];
    int left = start;
    int right = end;
    while (left != right)
    {
        while (left < right && arr[right]>=pivot) {
            right--;
        }
        while (left<right && arr[left] <= pivot) {
            left ++;
        }
        if (left < right) {
            swap(arr[left], arr[right]);
        }
    }
    swap(arr[start], arr[left]);
    return left;  
}

void printArr(int arr[], int n) {
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {4,4,6,5,3,2,8,1};
    int length = sizeof(arr)/sizeof(arr[0]);
    printArr(arr, length);
    quickSort(arr, 0, length-1);
    printArr(arr, length);
}

