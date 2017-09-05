#include <iostream>
using namespace std;

class MyArray {
  int arr[100];
  int size;

  public:

    MyArray(int arr[], int size) {
      arr = arr;
      this->size = size;
    }

    void input() {
      cout << "Enter elements: ";
      for(int i = 0; i < size; i++) {
        cin >> arr[i];
      }
    }

    void print() {
      cout << "Array: ";
      for(int i = 0; i < size; i++) {
        cout << arr[i] << " ";
      }
      cout << endl;
    }

    void insertion_sort() {
      for(int i = 1; i < size; i++) {
        int key = arr[i];
        int j = i-1;

        while(j >= 0 & arr[j] > key) {
          arr[j+1] = arr[j];
          j--;
        }
        arr[j+1] = key;
      }
    }
};


int main()
{
  int n;
  cout << "Enter n: ";
  cin >> n;
  int arr[n];
  MyArray obj = MyArray(arr, n);
  obj.input();
  obj.print();
  obj.insertion_sort();
  obj.print();
}