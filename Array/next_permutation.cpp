#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void nextPermutation(vector<int> &nums){
  int idx = -1;
  for (int i = nums.size() - 2; i >= 0; i--){
    if (nums[i] < nums[i + 1]){
      idx = i;
      cout << "break point = " << nums[idx] << endl;
      break;
    }
  }
  if (idx == -1){
    reverse(nums.begin(), nums.end());
    return;
  }
  for (int i = nums.size() - 1; i > idx; i--){
    if (nums[idx] < nums[i]){
      swap(nums[idx], nums[i]);
      break;
    }
  }

  reverse(nums.begin() + idx + 1, nums.end());
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
  nextPermutation(arr);
  cout << "Next permutation: ";
  for (int i = 0; i < arr.size(); i++){
    cout << arr[i] << " ";
  }
  cout << endl;
  return 0;
}