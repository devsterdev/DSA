#include <iostream>
#include <vector>
using namespace std;

bool check(vector<int> &nums){
  int count = 0;
  for (int i = 0; i < nums.size() - 1; i++){
    if (nums[i] > nums[i + 1]){
      count++;
    }
  }
  if (nums[nums.size() - 1] > nums[0]){
    count++;
  }
  if (count > 1){
    return false;
  }
  return true;
}

int main(){

  vector<int> arr;
  int n;

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

  bool isSorted = check(arr);

  if (isSorted){
    cout << "Array is sorted." << endl;
  }
  else{
    cout << "Array is not sorted." << endl;
  }

  return 0;
}