#include <iostream>
#include <vector>
using namespace std;

int longestSubarray(vector<int> &nums, int k){
  int left = 0, right = 0;
  long long sum = nums[0];
  int maxLen = 0;
  int n = nums.size();
  while (right < n){
    while (left <= right && sum > k){
      sum -= nums[left];
      left++;
    }
    if (sum == k){
      maxLen = max(maxLen, right - left + 1);
    }
    right++;
    if (right < n){
      sum += nums[right];
    }
  }
  return maxLen;
}

int main(){
  vector<int> arr;
  int n, k;
  cout << "Enter number of elements: ";
  cin >> n;
  cout << endl;
  cout << "Enter elements: ";
  for (int i = 0; i < n; i++){
    int x;
    cin >> x;
    arr.push_back(x);
  }
  cout << "Enter target sum: ";
  cin >> k;
  int maxLen = longestSubarray(arr, k);
  cout << "The longest subarray with sum " << k << " is of length: " << maxLen << endl;
  return 0;
}