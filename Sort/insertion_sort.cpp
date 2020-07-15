/*
 * 插入排序
 *
 * 1. 從第一個元素開始，該元素可以認為已經被排序
 * 2. 取出下一個元素，在已經排序的元素序列中從後向前掃描
 * 3. 如果該元素（已排序）大於新元素，將該元素移到下一位置
 * 4. 重複步驟3，直到找到已排序的元素小於或者等於新元素的位置
 * 5. 將新元素插入到該位置後
 * 6. 重複步驟2~5
 *
 * T: O(n^2), S: O(1)
*/

void insertion_sort(int arr[], int len) {
    int key, j;
    for (int i = 1; i < len; i++) {
        key = arr[i];
        j = i - 1;
        while ((j >= 0) && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }

        // 把key填入洞中; j要加1補回while迴圈最後的j--
        arr[j + 1] = key;
    }
}
