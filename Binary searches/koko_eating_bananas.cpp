#include<iostream>
#include <vector>
#include <climits>
#include <cmath>
using namespace std;

int maxEle(vector<int>& arr){
  int maxi = INT_MIN;
  for(int i=0; i<arr.size(); i++){
    maxi = max(maxi, arr[i]);
  }
  return maxi;
}

long long takenHour(vector<int>& arr, int k){
  long long totalHour = 0;
  for(int i=0; i<arr.size(); i++){
    totalHour += (arr[i] + k - 1) / k;
  }
  return totalHour;
}

int minEatingSpeed(vector<int>& piles, int h) {
  int low = 1;
  int high = maxEle(piles);
  int ans = high;
  while(low <= high){
    int mid = low + (high - low) / 2;
    long long k = takenHour(piles, mid);
    if(k <= h){
      ans = mid;
      high = mid - 1;
    }
    else{
      low = mid + 1;
    }
  }
  return ans;
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

  int hour;
  cout << "Enter the target: ";
  cin >> hour;

  cout << minEatingSpeed(arr, hour);


  return 0;
}