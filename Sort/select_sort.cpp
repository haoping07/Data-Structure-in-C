/*
 * ��ܱƧ�
 *
 * �C�������̥��䪺�������ǭȡA�ñq�Ѿl����������h�̤p���P�ۤv�洫
 *
 * T: O(n^2); S: O(1)
 */

#include <iostream>
using namespace std;

void select_sort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {       // �@�@�i��n-1��
        int min = i;                        // �����̤p������m
        for (int j = i + 1; j < n; j++) {   // �bi~n����̤ܳp����
            if (arr[j] < arr[min]) min = j; // ��s�̤p������m
        }
        swap(arr[i], arr[min]);             // �P��i�Ӧ�m�洫
    }
}

int main()
{
    int arr[5] = {1,5,2,4,3};
    select_sort(arr, 5/*sizeof(int) / sizeof(arr)*/);
    for (int i = 0; i < 5; i++) {
        cout << arr[i] << "\t";
    }
    cout << endl;
    return 0;
}
