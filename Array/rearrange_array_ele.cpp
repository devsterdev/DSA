#include <iostream>
#include <vector>
using namespace std;

vector<int> rearrangeArray(vector<int> &nums){
  int n = nums.size();
  vector<int> ans(n, 0);
  int posIndex = 0, negIndex = 1;
  for (int i = 0; i < n; i++){
    if (nums[i] < 0){
      ans[negIndex] = nums[i];
      negIndex += 2;
    }
    else{
      ans[posIndex] = nums[i];
      posIndex += 2;
    }
  }
  return ans;
}

int main(){
  vector<int> arr;
  int n;
  cout << "Enter number of elements: ";
  cin >> n;
  cout << endl;
  cout << "Enter elements: ";
  for (int i = 0; i < n; i++){
    int x;
    cin >> x;
    arr.push_back(x);
  }
  vector<int> result = rearrangeArray(arr);
  cout << "Rearranged array: ";
  for (int i = 0; i < result.size(); i++){
    cout << result[i] << " ";
  }
  cout << endl;
  return 0;
}