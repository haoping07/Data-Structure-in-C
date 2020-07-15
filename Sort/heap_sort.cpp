/*
 * ��Ƨ�
 *
 * 1. ��max heap
 * 2. ��ڵ��I���쥽�`�I
 * 3. ��smax heap
 * 4. ����2~4
 *
 * T: O(n); S: O(h)
 */

#include <iostream>
using namespace std;

// ��smax heap
void AdjustDown(int arr[], int k, int len) {
    // �������`�I
    int temp = arr[k];
    for (int i = 2 * k; i < len; i *= 2) {
        // ���X�l�`�I���j��
        if (arr[i] < arr[i + 1]) i++;
        // �Y���`�I��`�I�j�A����
        if (temp >= arr[i]) break;
        // �Ϥ��A����
        else {
            arr[k] = arr[i];
            // ��s�¤��`�I���s��m
            k = i;
        }
    }
    // �N���`�I��i�̫�A�X����m
    arr[k] = temp;
}

// ��max heap
void BuildMaxHeap(int arr[], int len) {
    // �q�̫�@�Ӥ��`�I�}�l�ާ@
    for (int i = len / 2; i >= 0; i--) {
        AdjustDown(arr, i, len);
    }
}

// �Ƨ�max heap
void heap_sort(int arr[], int len) {
    // ��max heap
    BuildMaxHeap(arr, len);
    // �ƦCmax heap
    for (int i = len - 1; i >= 0; i--) {
        // ��ڸ`�I(�̤j���`�I)����̫�@�Ӧ�m
        swap(arr[i], arr[0]);
        // ���s�ƦCmax heap�A���C�^�X���Y��@�ӧ��ڤ���(�]�����ڤw�g�ƧǹL�F)
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
