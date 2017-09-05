#include <iostream>
using namespace std;

void print(int arr[], int n) {
  cout << "Array: ";
  for(int i = 0; i < n; i++) {
    cout << arr[i] << " ";
  }
  cout << endl;
}

void insertion_sort(int *arr, int n) {
  //assuming first is rightly placed
  for(int i = 1; i < n; i++) {
    int key = arr[i]; //key to be rightly inserted
    int j = i-1;
    while(j >= 0 && arr[j] > key) {
      arr[j+1] = arr[j];
      j--;
    }
    arr[j+1] = key;
  }
}

int main()
{
  int n;
  cout << "Enter n: ";
  cin >> n;
  int a[n];
  cout << "Enter elements: ";
  for(int i = 0; i < n; i++) {
    cin >> a[i];
  }

  insertion_sort(a, n);
  print(a, n);
}
