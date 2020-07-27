/*
 * 歸併排序
 *
 * 1. 將數組從中點拆開數個子數組，子數組最多有2個元素
 * 2. 使用另一數組儲存每個相鄰的子數組
 * 3. 兩數組互比較元素後填入原數組
 *
 * T: 每趟歸併O(n)，共需logn趟，結果O(nlogn); S: O(n)
 * */


#include <iostream>
#include <vector>
using namespace std;

void merge(int arr[], int low, int mid, int high) {
    // 設一數組來接原數組
    vector<int> b;
    // 把整個數組複製到額外空間 (複製整個數組才能對到傳進來的mid)
    for (int i = 0; i <= high; i++) b.push_back(arr[i]);
    // 交叉比較兩子樹組並填入原數組
    int i = low, j = mid + 1, k = low;
    for (; i <= mid && j <= high; k++) {
        if (b[i] <= b[j]) arr[k] = b[i++];
        else arr[k] = b[j++];
    }
    // 若任一數組尚有元素，將其插入原數組
    while (i <= mid) arr[k++] = b[i++];
    while (j <= high) arr[k++] = b[j++];
}

void merge_sort(int arr[], int low, int high) {
    // 若數組至少有2個元素
    if (low < high) {
        // 取得中點
        int m = low + (high - low) / 2;
        // 拆成左右子數組
        merge_sort(arr, low, m);
        merge_sort(arr, m + 1, high);
        // 合併排列左右子數組
        merge(arr, low, m, high);
    }
}

int main()
{
    int arr[10] = { 1,10,2,9,3,8,4,7,5,6 };
    merge_sort(arr, 0, 9);
    for (int i = 0; i < 10; i++) {
        cout << arr[i] << "\t";
    }
    cout << endl;
    return 0;
}
