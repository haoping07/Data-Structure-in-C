/*
 * 快速排序
 *
 * 1. 挑選基準值：從數列中挑出一個元素，稱為「基準」（pivot）
 * 2. 分割：重新排序數列，所有比基準值小的元素擺放在基準前面，所有比基準值大的
 *    元素擺在基準後面（與基準值相等的數可以到任何一邊）。在這個分割結束之後，對基
 *    準值的排序就已經完成
 * 3. 遞迴排序子序列：遞迴地將小於基準值元素的子序列和大於基準值元素的子序列排序。
 *
 * T: O(n^2), S: O(n)
 * T最壞發生在已排列數組，O(n^2)，最好發生在每次分區都剛好一半，O(nlogn)
 * S worst O(n) which is depth of recursion; avg. O(logn)
*/

int partition(int arr[], int low, int high) {
    // Get the pivot elem value (most right elem)
    int pval = arr[high];
    // compare and swap
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j] <= pval) {
            i++;
            swap(arr[j], arr[i]);
        }
    }
    // Move the pivot elem to the middle of the section
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quick_sort(int arr[], int low, int high) {
    if (low < high) {
        int pivot = partition(arr, low, high);
        quick_sort(arr, low, pivot - 1);
        quick_sort(arr, pivot + 1, high);
    }
}
