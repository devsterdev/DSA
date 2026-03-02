#include <iostream>
#include <vector>
using namespace std;

int secondLargestElement(vector<int> &nums){

  int largest = INT8_MIN;
  int secondLargest = INT8_MIN;

  for (int x : nums){
    if (x > largest){
      secondLargest = largest;
      largest = x;
    }
    else if (x < largest && x > secondLargest){
      secondLargest = x;
    }
  }

  if (secondLargest == INT8_MIN)
    return -1;
  return secondLargest;
}

int main(){

  vector<int> arr;
  int n, k;

  cout << "Enter number of elements: ";
  cin >> n;
  cout << endl;

  cout << "Enter elements: ";
  for (int i = 0; i < n; i++){
    int x;
    cin >> x;
    arr.push_back(x);
  }
  cout << endl;

  int sec_max = secondLargestElement(arr);

  cout << "Second largest element is: " << sec_max << endl;

  return 0;
}