#include<iostream>
#include <vector>
using namespace std;

int singleNonDuplicate(vector<int>& nums) {
    int low = 0;
    int high = nums.size() - 1;

    while (low < high) {
      int mid = (low + high) / 2;
      if (mid % 2 == 1) mid--;
      if (nums[mid] == nums[mid + 1]) {
        low = mid + 2;
      } else {
        high = mid;
      }
    }

    return nums[low];
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

  cout << singleNonDuplicate(arr);


  return 0;
}