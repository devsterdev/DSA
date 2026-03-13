#include<iostream>
#include <vector>
#include <map>
using namespace std;

int subarraysWithXorK(vector<int> &nums, int k) {
  int xr = 0;
  map<int, int> mpp;
  mpp[xr]++;
  int count = 0;
  for(int i=0; i<nums.size(); i++){
    xr = xr ^ nums[i];
    int x = xr ^ k;
    count += mpp[x];
    mpp[xr]++;
  }
  return count;
}


int main(){

  int n;
  cout << "Enter size of array: ";
  cin >> n;

  vector<int> arr;
  cout << "Enter ele of arr: ";
  for(int i=0; i<n; i++){
    int x;
    cin >> x;
    arr.push_back(x);
  }

  int k;
  cout << "enter target: ";
  cin >> k;

  cout << subarraysWithXorK(arr, k);

  return 0;
}