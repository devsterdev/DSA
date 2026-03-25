#include<iostream>
#include <vector>
using namespace std;

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

vector<int> searchRange(vector<int>& nums, int target) {
  int lb = lowerBound(nums, target);
  if(lb == nums.size() || nums[lb] != target){
    return {-1, -1};
  }
  return {lb, upperBound(nums, target) - 1};
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

  vector<int> ans = searchRange(arr, k);

  for(int i=0; i<ans.size(); i++){
    cout << ans[i] << " ";
  }

  return 0;

  return 0;
}