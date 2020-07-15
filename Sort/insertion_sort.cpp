/*
 * ���J�Ƨ�
 *
 * 1. �q�Ĥ@�Ӥ����}�l�A�Ӥ����i�H�{���w�g�Q�Ƨ�
 * 2. ���X�U�@�Ӥ����A�b�w�g�ƧǪ������ǦC���q��V�e���y
 * 3. �p�G�Ӥ����]�w�Ƨǡ^�j��s�����A�N�Ӥ�������U�@��m
 * 4. ���ƨB�J3�A������w�ƧǪ������p��Ϊ̵���s��������m
 * 5. �N�s�������J��Ӧ�m��
 * 6. ���ƨB�J2~5
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

        // ��key��J�}��; j�n�[1�ɦ^while�j��̫᪺j--
        arr[j + 1] = key;
    }
}
