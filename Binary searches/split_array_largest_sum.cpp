#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

int countSum(vector<int> nums, int pages){
  int n = nums.size();
  int k = 1;
  long long cnt = 0;
  for(int i=0; i<n; i++){
    if(cnt + nums[i] <= pages){
      cnt += nums[i];
    }
    else{
      k++;
      cnt = nums[i];
    }
  }
  return k;
}

int splitArray(vector<int> &nums, int k)  {
  int n = nums.size();
  if(k > n) return -1;
  int low = *max_element(nums.begin(), nums.end());
  int high = accumulate(nums.begin(), nums.end(), 0);
  while(low <= high){
    int mid = low + ((high - low)/ 2);
    int student = countSum(nums, mid);
    if(student > k){
      low = mid + 1;
    }
    else{
      high = mid - 1;
    }
  }
  return low;
}

int main() {

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

  int m;
  cout << "Enter num of student: ";
  cin >> m;

  cout << splitArray(arr, m) << endl;

 return 0;
}