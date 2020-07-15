/*
 * 堆排序
 *
 * 1. 建max heap
 * 2. 把根結點移到末節點
 * 3. 更新max heap
 * 4. 重複2~4
 *
 * T: O(n); S: O(h)
 */

#include <iostream>
using namespace std;

// 更新max heap
void AdjustDown(int arr[], int k, int len) {
    // 紀錄父節點
    int temp = arr[k];
    for (int i = 2 * k; i < len; i *= 2) {
        // 取出子節點較大者
        if (arr[i] < arr[i + 1]) i++;
        // 若父節點比節點大，結束
        if (temp >= arr[i]) break;
        // 反之，替換
        else {
            arr[k] = arr[i];
            // 更新舊父節點的新位置
            k = i;
        }
    }
    // 將父節點放進最後適合的位置
    arr[k] = temp;
}

// 建max heap
void BuildMaxHeap(int arr[], int len) {
    // 從最後一個父節點開始操作
    for (int i = len / 2; i >= 0; i--) {
        AdjustDown(arr, i, len);
    }
}

// 排序max heap
void heap_sort(int arr[], int len) {
    // 建max heap
    BuildMaxHeap(arr, len);
    // 排列max heap
    for (int i = len - 1; i >= 0; i--) {
        // 把根節點(最大的節點)移到最後一個位置
        swap(arr[i], arr[0]);
        // 重新排列max heap，但每回合都縮減一個尾巴元素(因為尾巴已經排序過了)
        AdjustDown(arr, 0, i - 1);
    }
}

int main()
{
    int arr[10] = {1,10,2,9,3,8,4,7,5,6};
    heap_sort(arr, 10);
    for (int i = 0; i < 10; i++) {
        cout << arr[i] << "\t";
    }
    cout << endl;
    return 0;
}
