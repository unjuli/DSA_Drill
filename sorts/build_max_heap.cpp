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

void max_heapify(int *arr, int i, int n) {
  int left = 2*i + 1;
  int right = 2*(i+1);
  int largest = i;

  if(left < n && arr[left] > arr[largest]) {
    largest = left;
  }

  if(right < n && arr[right] > arr[largest]) {
    largest = right;
  }

  if(largest != i) {
    int temp = arr[i];
    arr[i] = arr[largest];
    arr[largest] = temp;

    max_heapify(arr, largest, n);
  }

}

void build_max_heap(int *arr, int n) {
  for(int i = n/2; i >= 0; i--) {
    max_heapify(arr,i,n);
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
  cout << "Max-Heap: ";
  build_max_heap(a,n);
  print_arr(a, n);
}
