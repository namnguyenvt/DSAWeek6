#include <iostream>

using namespace std;

int binarySearch(int list[], int last, int target) {
	int first = 0;
//	int last = end;
	int mid = -1;

	while (first <= last) {
		mid = (first + last) / 2; // return an integer

		if (target == list[mid]) // found the item
			return mid;
		else if (target > list[mid])  // look in upper half
			first = mid + 1;
		else if (target < list[mid]) // look in lower half
			last = mid - 1;
	}

	return -1;
}

int main() {
	int list[] = { 4, 7, 8, 10, 14, 21, 22, 36, 62, 77, 81, 91 };
	int end = 11;
	int target = 36;
	int locn = binarySearch(list, end, target);
	if (locn != -1)
		cout << "Found the target at " << locn << endl;
	else
		cout << " Can't find the target." << endl;
	return 0;
}
