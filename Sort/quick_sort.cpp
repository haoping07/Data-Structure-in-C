/*
 * �ֳt�Ƨ�
 *
 * 1. �D���ǭȡG�q�ƦC���D�X�@�Ӥ����A�٬��u��ǡv�]pivot�^
 * 2. ���ΡG���s�ƧǼƦC�A�Ҧ����ǭȤp�������\��b��ǫe���A�Ҧ����ǭȤj��
 *    �����\�b��ǫ᭱�]�P��ǭȬ۵����ƥi�H�����@��^�C�b�o�Ӥ��ε�������A���
 *    �ǭȪ��ƧǴN�w�g����
 * 3. ���j�ƧǤl�ǦC�G���j�a�N�p���ǭȤ������l�ǦC�M�j���ǭȤ������l�ǦC�ƧǡC
 *
 * T: worst O(n^2) when all are sorted; avg. O(nlogn)
 * S: worst O(n) which is depth of recursion; avg. O(logn)
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
