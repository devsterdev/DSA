#include<iostream>
#include <vector>
using namespace std;

int cnt = 0;

void merge(vector<int> &arr, int low, int mid, int high){
  vector<int> temp;
  int left = low;
  int right = mid + 1;
  while (left <= mid && right <= high){
    if (arr[left] <= arr[right]){
      temp.push_back(arr[left]);
      left++;
    }
    else{
      temp.push_back(arr[right]);
      cnt += (mid - left +1);
      right++;
    }
  }
  while (left <= mid){
    temp.push_back(arr[left]);
    left++;
  }
  while (right <= high){
    temp.push_back(arr[right]);
    right++;
  }

  for (int i = low; i <= high; i++){
    arr[i] = temp[i - low];
  }
}

void mS(vector<int> &arr, int low, int high){
  if (low >= high)
    return;
  int mid = (low + high) / 2;
  mS(arr, low, mid);
  mS(arr, mid + 1, high);
  merge(arr, low, mid, high);
}

void mergeSort(vector<int> &arr, int n){
  mS(arr, 0, n - 1);
}

long long int numberOfInversions(vector<int> nums) {
  int n = nums.size();
  mS(nums, 0,  n-1);
  return cnt;
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

  cout << numberOfInversions(arr);

  return 0;
}