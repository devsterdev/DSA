#include <iostream>
using namespace std;

void selection_sort(int arr[], int n){
  for (int i = 0; i < n - 1; i++){
    int min = i;
    for (int j = i + 1; j < n; j++){
      if (arr[min] > arr[j]){
        min = j;
      }
    }
    swap(arr[min], arr[i]);
  }
}

int main(){

  int n;
  cout << "Enter the size of array: " << endl;
  cin >> n;
  int arr[n];
  cout << "Enter the elements of array" << endl;
  for (int i = 0; i < n; i++){
    cin >> arr[i];
  }
  selection_sort(arr, n);

  for (int i = 0; i < n; i++){
    cout << arr[i] << " ";
  }

  return 0;
}