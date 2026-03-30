#include<iostream>
#include <vector>
using namespace std;

int findPeakElement(vector<int>& nums) {
  int n = nums.size();
  if(n == 1) return 0;
  if(nums[0] > nums[1]) return 0;
  if(nums[n-1] > nums[n-2]) return n-1;
  int low = 1;
  int high = n-2;
  while (low <= high){
    int mid = (low + high) / 2;
    if(nums[mid] > nums[mid-1] && nums[mid] > nums[mid+1]) return mid;
    else if(nums[mid] > nums[mid-1]){
      low = mid+1;
    }
    else if(nums[mid] > nums[mid+1]){
      high = mid-1;
    }
    else{
      low = mid + 1;
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

  cout << findPeakElement(arr);

  return 0;
  
  return 0;
}