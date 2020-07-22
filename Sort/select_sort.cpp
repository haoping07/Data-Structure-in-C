/*
 * 選擇排序
 *
 * 每次紀錄最左邊的元素當基準值，並從剩餘的元素中選則最小的與自己交換
 *
 * T: O(n^2); S: O(1)
 */

#include <iostream>
using namespace std;

void select_sort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {       // 一共進行n-1趟
        int min = i;                        // 紀錄最小元素位置
        for (int j = i + 1; j < n; j++) {   // 在i~n中選擇最小元素
            if (arr[j] < arr[min]) min = j; // 更新最小元素位置
        }
        swap(arr[i], arr[min]);             // 與第i個位置交換
    }
}

int main()
{
    int arr[5] = {1,5,2,4,3};
    select_sort(arr, 5);   // sizeof(int) / sizeof(arr)
    for (int i = 0; i < 5; i++) {
        cout << arr[i] << "\t";
    }
    cout << endl;
    return 0;
}
