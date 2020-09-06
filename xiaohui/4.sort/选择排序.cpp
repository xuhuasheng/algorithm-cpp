# include <iostream>
# include <vector>
using namespace std;

// # 选择排序 - 非稳定 原地
// # 时间复杂度：o(n2)
// # 空间复杂度：o(1)
void selectSort(vector<int> &arr) {
    for (int i=0; i<arr.size()-1; i++) {
        for (int j=i+1; j<arr.size(); j++) {
            if (arr[i] > arr[j]) {
                swap(arr[i], arr[j]);
            }
        }
    }
}

void printArr(vector<int> &arr) {
    for (int i=0; i<arr.size(); i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    vector<int> arr = {3, 4, 2, 1, 5, 6, 7, 8};
    printArr(arr);
    selectSort(arr);
    printArr(arr);
}