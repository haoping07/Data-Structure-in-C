/*
 * ��Ƨ�
 *
 * T: O(n); S: O(1)
 */

#include <iostream>
using namespace std;

// ���U��s�`�I
void AdjustDown(int arr[], int k, int len) {
    // �ƥ����`�I
    int temp = arr[k];
    for (int i = 2 * k + 1; i < len; i = i * 2 + 1) {
        // ���X���k�l�`�I���j��(�`�N�i��S���k�`�I)
        if (i + 1 < len && arr[i + 1] > arr[i]) i++;
        // �Y���`�I�j��l�`�I�A����
        if (temp >= arr[i]) break;
        else {
            // �Y�p����`�I�A�洫��m
            arr[k] = arr[i];
            // �����洫��m�᪺���`�I��m
            k = i;
        }
    }
    // �N���`�I��J�̫��m
    arr[k] = temp;
}

// ��max heap
void BuildMaxHeap(int arr[], int len) {
    for (int i = len / 2 - 1; i >= 0; i--) {
        AdjustDown(arr, i, len);
    } 
}

// �Ƨ�max heap
void heap_sort(int arr[], int len) {
    // ��max heap
    BuildMaxHeap(arr, len);
    for (int i = len - 1; i >= 0; i--) {
        // ��ڸ`�I(�̤j�I)�P�̥��I�洫
        swap(arr[0], arr[i]);
        // ���s��smax heap�A�`�N�n�����w�ƧǪ���m
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
