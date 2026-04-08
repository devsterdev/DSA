#include<iostream>
#include <vector>
#include <numeric>
#include <climits>
using namespace std;

vector<int> findEle(vector<int> arr){
  int maxi = INT_MIN;
  int cnt = 0;
  for(int i=0; i<arr.size(); i++){
    if(arr[i] > maxi){
      maxi = arr[i];
    }
    cnt += arr[i];
  }
  return {maxi, cnt};
}

int calDay(vector<int>& arr, int nums){
  int cnt = 1;
  int cal = 0;
  for(int i = 0; i < arr.size(); i++){
    if(cal + arr[i] > nums){ 
      cnt++;
      cal = arr[i];
    }
    else{
      cal += arr[i];
    }
  }
  return cnt;
}

int shipWithinDays(vector<int>& weights, int days) {
  vector<int> res = findEle(weights);
  int low = res[0];
  int high = res[1];
  int ans = -1;
  while (low <= high){
    int mid = low + ((high - low) / 2);
    int curDay = calDay(weights, mid);

    if(curDay <= days){
      ans = mid;
      high = mid-1;
    }
    else{
      low = mid+1;
    }
  }
  return ans;
}

int main(){

  int n;
  cout << "Enter size of weight arr: ";
  cin >> n;

  vector<int> weight;
  cout << "Enter ele of weigh arr: ";
  for(int i=0; i<n; i++){
    int x;
    cin >> x;
    weight.push_back(x);
  }

  int days;
  cout << "Enter the day: ";
  cin >> days;

  cout << shipWithinDays(weight, days);

  return 0;
}