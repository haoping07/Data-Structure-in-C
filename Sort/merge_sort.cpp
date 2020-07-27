/*
 * �k�ֱƧ�
 *
 * 1. �N�Ʋձq���I��}�ƭӤl�ƲաA�l�Ʋճ̦h��2�Ӥ���
 * 2. �ϥΥt�@�Ʋ��x�s�C�Ӭ۾F���l�Ʋ�
 * 3. ��Ʋդ�����������J��Ʋ�
 *
 * T: �C���k��O(n)�A�@��logn��A���GO(nlogn); S: O(n)
 * */


#include <iostream>
#include <vector>
using namespace std;

void merge(int arr[], int low, int mid, int high) {
    // �]�@�Ʋըӱ���Ʋ�
    vector<int> b;
    // ���ӼƲսƻs���B�~�Ŷ� (�ƻs��ӼƲդ~����Ƕi�Ӫ�mid)
    for (int i = 0; i <= high; i++) b.push_back(arr[i]);
    // ��e�����l��ըö�J��Ʋ�
    int i = low, j = mid + 1, k = low;
    for (; i <= mid && j <= high; k++) {
        if (b[i] <= b[j]) arr[k] = b[i++];
        else arr[k] = b[j++];
    }
    // �Y���@�Ʋթ|�������A�N�䴡�J��Ʋ�
    while (i <= mid) arr[k++] = b[i++];
    while (j <= high) arr[k++] = b[j++];
}

void merge_sort(int arr[], int low, int high) {
    // �Y�Ʋզܤ֦�2�Ӥ���
    if (low < high) {
        // ���o���I
        int m = low + (high - low) / 2;
        // ����k�l�Ʋ�
        merge_sort(arr, low, m);
        merge_sort(arr, m + 1, high);
        // �X�ֱƦC���k�l�Ʋ�
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
