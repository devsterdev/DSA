#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int maxSubArray(vector<int> &nums){
  long long sum = 0;
  long long maxi = LLONG_MIN;
  for (int i = 0; i < nums.size(); i++){
    sum += nums[i];
    if (sum > maxi){
      maxi = sum;
    }
    if (sum < 0){
      sum = 0;
    }
  }
  return maxi;
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
  int result = maxSubArray(arr);
  cout << "The maximum subarray sum is: " << result << endl;
  return 0;
}