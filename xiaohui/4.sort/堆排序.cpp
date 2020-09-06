# include <iostream>
# include <vector>
using namespace std;

// # 堆排序-不稳定 原地排序
// # 空间复杂度o(1)
// # 时间复杂度o(nLogn)
    // # 升序-构造最大堆
    // # 降序-构造最小堆
void downAdjust(vector<int> &arr, int parentIdx, int length) {
    int temp = arr[parentIdx];  // 父节点
    int childIdx = 2*parentIdx+1;//左子节点
    while (childIdx < length)
    {
        //如果右子节点存在，且右子节点比左子节点大，则切换到右子节点
        if (childIdx+1 < length && arr[childIdx+1] > arr[childIdx]) 
            childIdx += 1;
        // 父节点比子节点都大，不用下沉
        if (temp >= arr[childIdx])
            break;
        arr[parentIdx] = arr[childIdx];
        parentIdx = childIdx;
        childIdx = 2*parentIdx + 1;
    }
    arr[parentIdx] = temp;
}

void heapSort(vector<int> &arr) {
    // 1.把无序数字构建最大堆：从最后一个非叶子节点开始，依次做下沉
    for (int i=(arr.size()-1-1)/2; i>=0; i--) {
        downAdjust(arr, i, arr.size());
    }
    // 倒序遍历 n-1轮
    for (int i=arr.size()-1; i>0; i--) {
        // 2.最大堆首尾互换：换至末端的是最大元素-保留
        swap(arr[i], arr[0]);
        // 3.换至顶端的元素做下沉调整
        downAdjust(arr, 0, i);
    }
}

void printArr(vector<int> &arr) {
    for (int i=0; i<arr.size(); i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    vector<int> arr = {1,3,2,6,5,7,8,9,10,0};
    printArr(arr);
    heapSort(arr);
    printArr(arr);
}