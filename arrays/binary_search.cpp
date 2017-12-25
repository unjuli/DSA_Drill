// Binary Search 
#include<iostream>
#include<algorithm>
using namespace std;

int binarySearchIter(int arr[], int left, int right, int key) {
  while(left <= right) {
    int mid = (right + left)/2;
    if(arr[mid] == key) return mid;
    if(arr[mid] < key) {
      left = mid+1;
    } else {
      right = mid-1;
    }
  };
  return -1;
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
  cout << "Search Element: ";
  cin >> x;

  int result1 = binarySearchIter(arr,0,n-1,x);
  (result1 == -1) ? cout << "Element not found" : cout << "Element found at index " << result1+1;
  cout << endl;

  int result2 = binarySearchRecur(arr,0,n-1,x);
  (result2 == -1) ? cout << "Element not found" : cout << "Element found at index " << result2+1;
  cout << endl;
}
