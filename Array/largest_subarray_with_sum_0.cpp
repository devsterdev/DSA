#include<iostream>
#include<vector>
#include <unordered_map>
using namespace std;

int maxLen(vector<int>& arr) {
  unordered_map<int, int> mpp;
  int maxi = 0;
  int sum = 0;
  for(int i=0; i<arr.size(); i++){
    sum += arr[i];
    if(sum == 0){
      maxi = i+1;
    }
    else{
      if(mpp.find(sum) != mpp.end()){
        maxi = max(maxi, i-mpp[sum]);
      }
      else{
        mpp[sum] = i;
      }
    }
  }
  return maxi;
}

int main(){

  int n;
  cout << "Enter the size of arr: ";
  cin >> n;

  vector<int> arr;
  cout << "Enter ele of arr: ";
  for(int i=0; i<n; i++){
    int x;
    cin >> x;
    arr.push_back(x);
  }

  cout << "max length of string with sum 0: " << maxLen(arr);

  return 0;
}