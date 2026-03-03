#include<iostream>
#include<vector>
#include <climits>
#include <algorithm>
using namespace std;

vector<int> leaders(vector<int>& nums) {
  vector<int> ans;
  int largest = INT_MIN;
  for(int i=nums.size()-1; i >=0; i--){
    if(nums[i] > largest){
      ans.push_back(nums[i]);
      largest = nums[i];
    }
  }

  reverse(ans.begin(), ans.end());
  return ans;
}

int main(){
  int n;
  cout << "Enter the size of array: ";
  cin >> n;
  cout << endl;
  vector<int> arr;
  cout << "Enter elements: ";
  for (int i = 0; i < n; i++){
    int x;
    cin >> x;
    arr.push_back(x);
  }
  cout << endl;

  vector<int> ans = leaders(arr);
  for(int i=0; i<ans.size(); i++){
    cout << ans[i] << " ";
  }

  return 0;
}