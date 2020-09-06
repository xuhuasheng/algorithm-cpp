# include <iostream>
# include <vector>
using namespace std;

void cocktailSort(vector<int> &arr) {
    int n = arr.size();
    bool isSorted = true;
    for(int i=0; i<n/2; i++) {
        isSorted = true;
        for (int j=i; j<n-1-i; j++) {
            if (arr[j] > arr[j+1]) {
                swap(arr[j], arr[j+1]);
                isSorted = false;
            }
        }
        if (isSorted) break;

        isSorted = true;
        for (int j=n-1-i; j>i; j--) {
            if (arr[j] < arr[j-1]) {
                swap(arr[j], arr[j-1]);
                isSorted = false;
            }
        }
        if (isSorted) break;
    }
}

void printArr(vector<int> &arr) {
    for (int i=0; i<arr.size(); i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    vector<int> arr = {2, 3, 4, 5, 6, 7, 8, 1};
    printArr(arr);
    cocktailSort(arr);
    printArr(arr);
}