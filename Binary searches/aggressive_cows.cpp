#include<iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool canWePlace(vector<int> nums, int dist, int cows){
  int cntCow = 1;
  int last = nums[0];
  for(int i=0; i<nums.size(); i++){
    if(nums[i] - last >= dist){
      cntCow++;
      last = nums[i];
      if(cntCow >= cows){
        return true;
      }
    }
  }
  return false;
}

int aggressiveCows(vector<int> &nums, int k) {
  sort(nums.begin(), nums.end());
  int n = nums.size();
  int low = 0;
  int high = nums[n-1] - nums[0];
  while(low <= high){
    int mid = low + ((high - low) / 2);
    if(canWePlace(nums, mid, k) == true){
      low = mid + 1;
    }
    else{
      high = mid - 1;
    }
  }
  return high;
}

int main(){

  int n;
  cout << "Enter the size of arr: ";
  cin >> n;

  vector<int> arr;
  cout << "Enter ele of arr: ";
  for(int i=0; i<n; i++){
    int x;
    cin >> x;
    arr.push_back(x);
  }

  int k;
  cout << "Enter num of cow: ";
  cin >> k;

  cout << aggressiveCows(arr, k);

  return 0;
}