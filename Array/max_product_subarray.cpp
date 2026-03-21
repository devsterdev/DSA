#include<iostream>
#include <vector>
#include <climits>
using namespace std;

int maxProduct(vector<int>& nums) {
  int ans = INT_MIN;
  int pre = 1;
  int suf = 1;
  for(int i=0; i<nums.size(); i++){
    if(pre == 0) pre = 1;
    if(suf == 0) suf = 1;
    pre *= nums[i];
    suf *= nums[nums.size() - i - 1];
    ans = max(ans, max(pre, suf));
  }
  return ans;
}

int main(){

  int n;
  cout << "Enter the size of n: ";
  cin >> n;

  vector<int> arr;
  cout << "Enter the ele: ";
  for(int i=0; i<n; i++){
    int x;
    cin >> x;
    arr.push_back(x);
  }

  cout << maxProduct(arr);

  return 0;
}