#include<iostream>
#include <vector>
#include <climits>
using namespace std;

bool possible(vector<int>& arr, int day, int m, int k){
  int cnt = 0;
  int noOfB = 0;
  for(int i=0; i<arr.size(); i++){
    if(arr[i] <= day){
      cnt++;
    }
    else{
      noOfB += (cnt/k);
      cnt = 0;
    }
  }
  noOfB += (cnt/k);
  return noOfB >= m;
}

int minDays(vector<int>& bloomDay, int m, int k) {
  long long var = m * 1LL * k * 1LL;
  if(var > bloomDay.size()) return -1;
  int mini = INT_MAX;
  int maxi = INT_MIN;
  for(int i=0; i<bloomDay.size(); i++){
    mini = min(mini, bloomDay[i]);
    maxi = max(maxi, bloomDay[i]);
  }
  int low = mini;
  int high = maxi;
  while(low <= high){
    int mid = low + ((high - low) / 2);
    if(possible(bloomDay, mid, m, k)){
      high = mid - 1;
    }
    else{
      low = mid + 1;
    }
  }
  return low;
}


int main(){

  int n;
  cout << "Enter the size of sorted arr: ";
  cin >> n;

  vector<int> arr;
  cout << "Enter the ele of sorted arr: ";
  for(int i=0; i<n; i++){
    int x;
    cin >> x;
    arr.push_back(x);
  }

  int m;
  cout << "Enter m: ";
  cin >> m;

  int k;
  cout << "Enter k: ";
  cin >> k;

  cout << minDays(arr, m, k);


  return 0;
}