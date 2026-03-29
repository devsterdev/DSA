#include<iostream>
#include <vector>
#include <climits>
using namespace std;

int findKRotation(vector<int>& nums) {
  int mini = 0;
  int low = 0;
  int high = nums.size()-1;
  while(low <= high){
    int mid = (low + high) / 2;
    if(nums[low] <= nums[mid]){
      if(nums[mini] > nums[low]){
        mini = low;
      }
      low = mid + 1;
    }
    else{
      if(nums[mini] > nums[mid]){
        mini = mid;
      }
      high = mid - 1;
    }
  }
  return mini;
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

  cout << findKRotation(arr);

  return 0;
}