#include <iostream>
using namespace std;

void input_arr(int *arr, int n) {
   cout << "Enter elements: ";
  for(int i = 0; i < n; i++) {
    cin >> arr[i];
  }
}

void print_arr(int arr[], int n) {
  for(int i = 0; i < n; i++) {
    cout << arr[i] << " ";
  }
  cout << endl;
}


void merge(int *arr, int left, int mid, int right) {
  int len_left = mid - left + 1;
  int len_right = right - mid;
  int l[len_left], r[len_right];

  for(int i = 0; i < len_left; i++) {
    l[i] = arr[left+ i];
  }

  for(int i = 0; i < len_right; i++) {
    r[i] = arr[mid + i + 1];
  }

  int i = 0, j = 0, k = left;

  while(i < len_left && j < len_right) {
    if(l[i] < r[j]) {
      arr[k++] = l[i++];
    } else {
      arr[k++] = r[j++];
    }
  }

  while(i < len_left) arr[k++] = l[i++];
  while(j < len_right) arr[k++] = r[j++];
}

void merge_sort(int *arr, int left, int right) {
  int mid = (left + right)/2;
  if(left < right) {
    merge_sort(arr, left, mid);
    merge_sort(arr, mid+1, right);
    merge(arr, left, mid, right);
  }
}

int main()
{
  int n;
  cout << "Enter n: ";
  cin >> n;
  int a[n];
  input_arr(a, n);

  cout << "Initial Array: ";
  print_arr(a, n);
  cout << "Merge-Sorted: ";
  merge_sort(a, 0, n-1);
  print_arr(a, n);
}
