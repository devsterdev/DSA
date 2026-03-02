#include <iostream>
#include <vector>
using namespace std;

vector<int> twoSum(vector<int> &nums, int target){
  vector<int> ans;
  for (int i = 0; i < nums.size(); i++){
    for (int j = i + 1; j < nums.size(); j++){
      if (nums.at(i) + nums.at(j) == target){
        ans.push_back(i);
        ans.push_back(j);
      }
    }
  }
  return ans;
}

int main(){
  vector<int> arr;
  int n, target;
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
  cin >> target;
  vector<int> result = twoSum(arr, target);
  if (result.size() == 2){
    cout << "Indices of the two numbers that add up to " << target << " are: "
         << result[0] << " and " << result[1] << endl;
  }
  else{
    cout << "No two numbers add up to the target." << endl;
  }
  return 0;
}