#include<iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> threeSum(vector<int>& nums) {
  vector<vector<int>> ans;
  sort(nums.begin(), nums.end());
  for(int i=0; i<nums.size(); i++){
    if(i>0 && nums[i] == nums[i-1]){
      continue;
    }
    int j = i+1;
    int k = nums.size()-1;
    while(j<k){
      int sum = nums[i] + nums[j] + nums[k];
      if(sum < 0){
        j++;
      }
      else if(sum > 0){
        k--;
      }
      else{
        vector<int> temp = {nums[i], nums[j], nums[k]};
        ans.push_back(temp);
        j++;
        k--;
        while(j <k && nums[j] == nums[j-1]) j++;
        while(j < k && nums[k] == nums[k+1]) k--;
      }
    }
  }

  return ans;
}


int main(){

  int n;
  cout << "Enter size of arr: ";
  cin >> n;

  vector<int> arr;
  cout << "Enter ele of arr: ";
  for(int i=0; i<n; i++){
    int x;
    cin >> x;
    arr.push_back(x);
  }

  vector<vector<int>> ans = threeSum(arr);

  for(int i=0; i<ans.size(); i++){
    for(int j=0; j<ans[i].size();j++){
      cout << ans[i][j] << " ";
    }
    cout << endl;
  }

  return 0;
}