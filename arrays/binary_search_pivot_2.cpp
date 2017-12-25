// Search element in a sorted and rotated array (Approach 2) ... in a single iteration of Binary Search O(log n)a
#include<iostream>
#include<algorithm>
using namespace std;

int search(int arr[], int left, int right, int key) {
  if (left > right) return -1;
  int mid = (left + right)/2;
  if(arr[mid] == key) return mid;
  if(arr[left] <= arr[mid]) {  //sorted left-half
    if (key >= arr[left] && key  <= arr[mid])
      return search(arr, left, mid-1, key);
    else
      return search(arr, mid+1, right, key);
  }

  // right-half is sorted
  if(key >= arr[mid] && key <= arr[right])
    return search(arr, mid+1, right, key);
  return search(arr, left,mid-1,key);
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

  int result = search(arr,0,n-1,x);
  (result == -1) ? cout << "Element not found" : cout << "Element found at index " << result+1;
  cout << endl;

}
