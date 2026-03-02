#include <iostream>
#include <vector>
using namespace std;

void swap(int &num1, int &num2){
  int temp = num1;
  num1 = num2;
  num2 = temp;
}

int partition(vector<int> &arr, int low, int high){
  int pivot = arr[low];
  int i = low;
  int j = high;

  while (i < j){
    while (i <= high - 1 && arr[i] <= pivot)
      i++;

    while (j >= low + 1 && arr[j] > pivot)
      j--;

    if (i < j)
      swap(arr[i], arr[j]);
  }

  swap(arr[low], arr[j]);
  return j;
}

void qs(vector<int> &arr, int low, int high){
  if (low < high){
    int pIndex = partition(arr, low, high);
    qs(arr, low, pIndex - 1);
    qs(arr, pIndex + 1, high);
  }
}

vector<int> quick_sort(vector<int> arr){
  qs(arr, 0, arr.size() - 1);
  return arr;
}

int main(){
  vector<int> arr;
  vector<int> sol;
  int n;

  cout << "Enter number of elements: ";
  cin >> n;

  cout << "Enter elements: ";
  for (int i = 0; i < n; i++){
    int x;
    cin >> x;
    arr.push_back(x);
  }

  sol = quick_sort(arr);

  cout << "Sorted array: ";
  for (int i = 0; i < n; i++){
    cout << sol[i] << " ";
  }
  return 0;
}