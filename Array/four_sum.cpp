#include<iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> fourSum(vector<int>& nums, int target){
  vector<vector<int>> ans;
  int n = nums.size();
  if(n < 4) return ans;
  sort(nums.begin(), nums.end());
  for(int i=0; i<n-3; i++){
    if(i>0 && nums[i] == nums[i-1]){
      continue;
    }
    for(int j=i+1; j<n-2; j++){
      if(j>i+1 && nums[j] == nums[j-1]){
        continue;
      }
      int k = j+1;
      int l = n-1;
      while(k<l){
        long long curSum = nums[i];
        curSum += nums[j];
        curSum += nums[k];
        curSum += nums[l];
        if(curSum > target){
          l--;
        }
        else if(curSum < target){
          k++;
        }
        else{
          vector<int> temp = {nums[i], nums[j], nums[k], nums[l]};
          ans.push_back(temp);
          k++;
          l--;
          while(k < l && nums[l] == nums[l+1]) l--;
          while(k < l && nums[k] == nums[k-1]) k++;
        }
      }
    }
  }
  return ans;
}

int main(){

  int n;
  cout << "Enter size of array: ";
  cin >> n;

  vector<int> arr;
  cout << "Enter ele of array: ";
  for(int i=0; i<n; i++){
    int x;
    cin >> x;
    arr.push_back(x);
  }

  int target;
  cout << "Enter the target: ";
  cin >> target;

  vector<vector<int>> ans = fourSum(arr, target);

  for(int i=0; i<ans.size(); i++){
    for(int j=0; j<ans[i].size(); j++){
      cout << ans[i][j] << " ";
    }
    cout << endl;
  }

  return 0;
}