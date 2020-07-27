/*
折半查找
*/

#include <iostream>
#include <vector>
using namespace std;

bool Binary_Search(vector<int>& a, int key) {
	int low = 0, high = a.size() - 1;
	while (low <= high) {
		int m = low + (high - low) / 2;
		if (key == a[m]) return true;
		if (key < a[m]) high = m - 1;
		else low = m + 1;
	}
	return false;
}

int main()
{
	vector<int> a{ 1,3,4,6,7,9,10 };
	cout << Binary_Search(a, 7) << endl;
	return 0;
}