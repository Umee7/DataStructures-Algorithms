#include <bits/stdc++.h>
using namespace std;

void reverseArray(int nums[], int l, int r) {
    if(l >= r) return;
    swap(nums[l], nums[r]);
    reverseArray(nums, l+1, r-1);
}

int main() {
	int nums[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
	int l = 0, r = 9;
	reverseArray(nums, l, r);
	for(int num : nums) {
	    cout<<num<<" ";
	}
}

// Time Complexity: O(n)
// Space Complexity: O(n)