#include<iostream>
#include <vector>
#include <climits>
#include <cmath>
using namespace std;

int curThresHold(vector<int>& nums, int mid){
  int cnt = 0;
  for(int i=0; i<nums.size(); i++){
    cnt += (nums[i] + mid - 1) / mid;
  }
  return cnt;
}

int smallestDivisor(vector<int>& nums, int threshold) {
  int low = 1;
  int high = INT_MIN;
  for(int i=0; i<nums.size(); i++){
    high = max(high, nums[i]);
  }
  int ans = high;
  while(low <= high){
    int mid = low + ((high - low) / 2);
    int curr = curThresHold(nums, mid);
    if(curr <= threshold){
      ans = mid ;
      high = mid - 1;
    }
    else{
      low = mid + 1;
    }
  }
  return ans;
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

  int threshold;
  cout << "Enter the threshold: ";
  cin >> threshold;

  cout << smallestDivisor(arr, threshold);

  return 0;
}