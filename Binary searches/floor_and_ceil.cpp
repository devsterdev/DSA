#include<iostream>
#include <vector>
using namespace std;

vector<int> getFloorAndCeil(vector<int> nums, int x) {
  int low = 0;
  int high = nums.size() - 1;
  int floorVal = -1;
  int ceilVal = -1;
  while (low <= high){
    int mid = (low + high) / 2;
    if(nums[mid] == x){
      return {nums[mid], nums[mid]};
    }
    else if(nums[mid] <= x){
      floorVal = nums[mid];
      low = mid + 1;
    }
    else if(nums[mid] > x){
      ceilVal = nums[mid]; 
      high = mid - 1;
    }
  }
  return {floorVal, ceilVal};
}

int main(){

  int n;
  cout << "Enter the size of arr: ";
  cin >> n;

  vector<int> arr;
  cout << "Enter the ele of arr: ";
  for(int i=0; i<n; i++){
    int x;
    cin >> x;
    arr.push_back(x);
  }

  int k;
  cout << "Enter the size of arr: ";
  cin >> k;

  vector<int> ans = getFloorAndCeil(arr, k);

  for(int i=0; i<ans.size(); i++){
    cout << ans[i] << " ";
  }

  return 0;
}