#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

int countStudent(vector<int> nums, int pages){
  int n = nums.size();
  int students = 1;
  long long pagesStudent = 0;
  for(int i=0; i<n; i++){
    if(pagesStudent + nums[i] <= pages){
      pagesStudent += nums[i];
    }
    else{
      students++;
      pagesStudent = nums[i];
    }
  }
  return students;
}

int findPages(vector<int> &nums, int m)  {
  int n = nums.size();
  if(m > n) return -1;
  int low = *max_element(nums.begin(), nums.end());
  int high = accumulate(nums.begin(), nums.end(), 0);
  while(low <= high){
    int mid = low + ((high - low)/ 2);
    int student = countStudent(nums, mid);
    if(student > m){
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

  cout << findPages(arr, m) << endl;

 return 0;
}