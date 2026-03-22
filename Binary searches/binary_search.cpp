#include<iostream>
#include <vector>
using namespace std;

int search(vector<int>& nums, int target) {
  int low = 0;
  int high = nums.size() - 1;
  while (low <= high){
    int mid = (low + high) / 2;
    if(nums[mid] == target){
      return mid;
    }
    else if(nums[mid] < target){
      low = mid + 1;
    }
    else if(nums[mid] > target){
      high = mid - 1;
    }
  }
  return -1;
}

int main(){

  int n;
  cout << "Enter the size of sorted arr: ";
  cin >> n;

  vector<int> arr;
  cout << "Enter the ele of sorted arr: ";
  for(int i=0; i<n; i++){
    int x;
    cin >> x;
    arr.push_back(x);
  }

  int target;
  cout << "Enter the target: ";
  cin >> target;

  cout << search(arr, target);

  return 0;
}