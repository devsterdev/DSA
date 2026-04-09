#include<iostream>
#include <vector>
using namespace std;

int findKthPositive(vector<int>& arr, int k) {
  int low = 0;
  int high = arr.size() - 1;
  while (low <= high){
    int mid = low + ((high - low) / 2);
    int missing = arr[mid] - (mid + 1);
    if(missing < k){
      low = mid + 1;
    }
    else{
      high = mid - 1;
    }
  }
  return low + k;
}

int main(){

  int n;
  cout << "Enter size of arr: ";
  cin >> n;
  
  vector<int> arr;
  cout << "Enter ele of arr: ";
  for(int i=0; i<n; i++){
    int x;
    cin >> x;
    arr.push_back(x);
  }

  int k;
  cout << "Enter the missing position: ";
  cin >> k;

  cout << findKthPositive(arr, k);

  return 0;
}