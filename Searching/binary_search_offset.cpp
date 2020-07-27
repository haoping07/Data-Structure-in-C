/*
折半查找反轉數組中的元素位置

往沒有反轉的區段去查找元素

*/

#include <iostream>
#include <vector>
using namespace std;

int Binary_Search(vector<int>& a, int key) {
	int low = 0, high = a.size() - 1;
	while (low <= high) {
		int m = low + (high - low) / 2;
		if (key == a[m]) return m;
		// 如果左區沒有反轉, 先在左區尋找
		if (a[low] <= a[m]) {
			// 如果查找元素大於中點, 向右移動邊界
			if (key > a[m]) low = m + 1;
			// 反之向左
			else {
				if (key >= a[low]) high = m - 1;
				else low = m + 1;
			}
		}
		// 如果右區沒有反轉, 先在右區尋找
		else {
			if (key < a[m]) high = m - 1;
			else {
				if (key > a[high]) high = m - 1;
				else low = m + 1;
			}
		}
	}
	// 沒找到
	return -1;
}

int main()
{
	vector<int> a{ 5,6,7,8,9,1,2,3,4 };
	cout << Binary_Search(a, 5) << endl;
	return 0;
}