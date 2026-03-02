#include <iostream>
#include <vector>
using namespace std;

void swap(int &nums1, int &nums2){
  int temp = nums1;
  nums1 = nums2;
  nums2 = temp;
}
void sortColors(vector<int> &nums){
  int low = 0;
  int mid = 0;
  int high = nums.size() - 1;
  while (high >= mid){
    if (nums[mid] == 0){
      swap(nums[low], nums[mid]);
      mid++;
      low++;
    }
    else if (nums[mid] == 1){
      mid++;
    }
    else if (nums[mid] == 2){
      swap(nums[mid], nums[high]);
      high--;
    }
  }
}

int main(){
  vector<int> arr;
  int n;
  cout << "Enter number of elements: ";
  cin >> n;
  cout << endl;
  cout << "Enter elements (0, 1, or 2): ";
  for (int i = 0; i < n; i++){
    int x;
    cin >> x;
    arr.push_back(x);
  }
  sortColors(arr);
  cout << "Sorted colors: ";
  for (int i = 0; i < arr.size(); i++){
    cout << arr[i] << " ";
  }
  cout << endl;
  return 0;
}