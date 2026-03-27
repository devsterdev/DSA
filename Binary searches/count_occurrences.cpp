#include<iostream>
#include <vector>
using namespace std;

int lowerBound(vector<int> &nums, int x){
  int low = 0;
  int high = nums.size() - 1;
  int ans = nums.size();
  while (low <= high){
    int mid = (low + high) / 2;
    if(nums[mid] >= x){
      ans = mid;
      high = mid - 1;
    }
    else{
      low = mid + 1;
    }
  }
  return ans;
}

int upperBound(vector<int> &nums, int x){
  int low = 0;
  int high = nums.size() - 1;
  int ans = nums.size();
  while (low <= high){
    int mid = (low + high) / 2;
    if(nums[mid] > x){
      ans = mid;
      high = mid - 1;
    }
    else{
      low = mid + 1;
    }
  }
  return ans;
}


int countOccurrences(vector<int>& arr, int target) {
  return upperBound(arr, target) - lowerBound(arr, target);
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

  cout << countOccurrences(arr, target);

  return 0;
}