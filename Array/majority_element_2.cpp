#include<iostream>
#include <vector>
#include <climits>
using namespace std;

vector<int> majorityElement(vector<int>& nums) {
  int count1 = 0;
  int count2 = 0;
  int ele1 = INT_MIN;
  int ele2 = INT_MIN;
  for(int i=0; i<nums.size(); i++){
    if(count1 == 0 && nums[i] != ele2){
      count1 = 1;
      ele1 = nums[i];
    }
    else if(count2 == 0 && nums[i] != ele1){
      count2 = 1;
      ele2 = nums[i];
    }
    else if(ele1 == nums[i]){
      count1++;
    }
    else if(ele2 == nums[i]){
      count2++;
    }
    else{
      count1--;
      count2--;
    }
  }

  count1 = 0;
  count2 = 0;

  for(int num : nums){
      if(num == ele1) count1++;
      else if(num == ele2) count2++;
  }

  int mini = (int)(nums.size()/3)+1;
  vector<int> ans;
  if(count1 >= mini) ans.push_back(ele1);
  if(count2 >= mini) ans.push_back(ele2);
  return ans;
}


int main(){

  int n;
  cout << "Enter the size of array: ";
  cin >> n;

  vector<int> arr;
  cout << "Enter the ele of arr: ";
  for(int i=0; i<n; i++){
    int x;
    cin >> x;
    arr.push_back(x);
  }

  vector<int> ans = majorityElement(arr);

  for(int i=0; i<ans.size(); i++){
    cout << ans[i] << " ";
  }

  
  return 0;
}