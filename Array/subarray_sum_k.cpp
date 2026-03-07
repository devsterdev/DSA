#include<iostream>
#include <vector>
#include <map>
using namespace std;

int subarraySum_mysol(vector<int>& nums, int k) {
    int left = 0, right = 0;
    int count = 0;
    int curSum = 0;

    while (right < nums.size()) {
        curSum += nums[right];

        while (curSum > k && left <= right) {
            curSum -= nums[left];
            left++;
        }

        if (curSum == k) {
            count++;
        }

        right++;
    }

    return count;
}

int subarraySum(vector<int>& nums, int k) {
  map<int, int> mpp;
  mpp[0] = 1;
  int preSum = 0;
  int cnt = 0;
  for(int i=0; i<nums.size(); i++){
    preSum += nums[i];
    int remove = preSum - k;
    cnt += mpp[remove];
    mpp[preSum] += 1;
    
  }

  return cnt;
}

int main(){

  vector<int> arr;
  int n;
  cout << "Enter the size of array: ";
  cin >> n;

  cout << "Enter ele of arr: ";

  for (int i = 0; i < n; i++){
    int x;
    cin >> x;
    arr.push_back(x);
  }

  int k;
  cout << "Enter k: ";
  cin >> k;

  int count = subarraySum(arr, k);

  cout << "Count : " << count;
  

  return 0;
}