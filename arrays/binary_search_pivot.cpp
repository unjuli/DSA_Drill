// Search element in a sorted and rotated array
#include<iostream>
#include<algorithm>
using namespace std;

int binarySearchRecur(int arr[], int l, int r, int k);
int binarySearchPivotRecur(int arr[], int l, int r);

int pivotedBinarySearch(int arr[], int n, int key) {
				int pivot = binarySearchPivotRecur(arr,0,n-1);
				cout << "Pivot: " << pivot;
				if(pivot == -1) {
								return binarySearchRecur(arr,0,n-1,key);
				}

				if(arr[pivot] == key) return pivot;
				if(arr[0] <= key) {
								return binarySearchRecur(arr,0,pivot-1,key);
				}
				return binarySearchRecur(arr,pivot+1,n-1,key);
}

int binarySearchPivotRecur(int arr[], int left, int right) {
				if (left > right) return -1;
				if (left == right) return left;
				int mid = (left + right)/2;
				if(mid > left && arr[mid] < arr[mid-1]) return (mid-1);
				if(mid < right && arr[mid] > arr[mid+1]) return mid;
				if(arr[mid] > arr[left]) {
								return binarySearchPivotRecur(arr, mid+1, right);
				} else {
								return binarySearchPivotRecur(arr, left, mid-1);
				}
}

int binarySearchRecur(int arr[], int left, int right, int key) {
				if (left > right) return -1;
				int mid = (left + right)/2;
				if(arr[mid] == key) return mid;
				if(arr[mid] < key) {
								return binarySearchRecur(arr, mid+1, right, key);
				} else {
								return binarySearchRecur(arr, left, mid-1, key);
				}
				return -1;
}

int main()
{
				int n,x;
				cin >> n;
				int arr[n];
				int min = 0, max = n-1;
				int mid;

				for(int i = 0; i < n; i ++) {
								cin >> arr[i];
				}
				cin >> x;

				int result = pivotedBinarySearch(arr,n,x);
				(result == -1) ? cout << "Element not found" : cout << "Element found at index " << result+1;
				cout << endl;

}
