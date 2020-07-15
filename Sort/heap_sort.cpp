/*
 * 堆排序
 *
 * T: O(n); S: O(1)
 */

#include <iostream>
using namespace std;

// 往下更新節點
void AdjustDown(int arr[], int k, int len) {
    // 備份父節點
    int temp = arr[k];
    for (int i = 2 * k + 1; i < len; i = i * 2 + 1) {
        // 取出左右子節點較大者(注意可能沒有右節點)
        if (i + 1 < len && arr[i + 1] > arr[i]) i++;
        // 若父節點大於子節點，結束
        if (temp >= arr[i]) break;
        else {
            // 若小於父節點，交換位置
            arr[k] = arr[i];
            // 紀錄交換位置後的父節點位置
            k = i;
        }
    }
    // 將父節點丟入最後位置
    arr[k] = temp;
}

// 建max heap
void BuildMaxHeap(int arr[], int len) {
    for (int i = len / 2 - 1; i >= 0; i--) {
        AdjustDown(arr, i, len);
    } 
}

// 排序max heap
void heap_sort(int arr[], int len) {
    // 建max heap
    BuildMaxHeap(arr, len);
    for (int i = len - 1; i >= 0; i--) {
        // 把根節點(最大點)與最末點交換
        swap(arr[0], arr[i]);
        // 重新更新max heap，注意要忽略已排序的位置
        AdjustDown(arr, 0, i);
    }
}


int main()
{
    int arr[5] = {2,3,4,5,8};
    heap_sort(arr, 5);
    for (int i = 0; i < 5; i++) {
        cout << arr[i] << "\t";
    }
    cout << endl;
    return 0;
}
