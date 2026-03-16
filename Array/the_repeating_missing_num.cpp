#include<iostream>
#include <vector>
using namespace std;

vector<int> findMissingRepeatingNumbers(vector<int> nums) {
  long long n = nums.size();
  long long SN = (n * (n+1))/2;
  long long S2N = (n * (n+1) * (2*n+1)) / 6;
  long long S = 0, S2 = 0;
  for(int i=0; i<n; i++){
    S += nums[i];
    S2 += (long long)nums[i] * (long long)nums[i];
  }
  long long val1 = S - SN;
  long long val2 = S2 - S2N;
  val2 = val2 / val1;
  long long x = (val1 + val2)/2;
  long long y = x - val1;
  return {(int)x, (int)y};
}

int main(){

  int n;
  cout << "Enter the size of arr: ";
  cin >> n;

  vector<int> arr;
  cout << "Enter the ele of arr: ";
  for(int i=0; i<n; i++){
    int x;
    cin >> x;
    arr.push_back(x);
  }

  vector<int> ans = findMissingRepeatingNumbers(arr);

  for(int i=0; i<ans.size(); i++){
    cout << ans[i] << " ";
  }


  return 0;
}