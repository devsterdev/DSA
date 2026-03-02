#include <iostream>
#include <vector>
using namespace std;

void swap(int &num1, int &num2){
  int temp = num1;
  num1 = num2;
  num2 = temp;
}

void rev(vector<int> &nums, int start, int end){
  while (start < end){
    swap(nums[start], nums[end]);
    start++;
    end--;
  }
}
void rotate(vector<int> &nums, int k){
  k %= nums.size();
  rev(nums, 0, nums.size() - 1);
  rev(nums, 0, k - 1);
  rev(nums, k, nums.size() - 1);
}

int main(){
  vector<int> arr;
  int n, k;
  cout << "Enter number of elements: ";
  cin >> n;
  cout << endl;
  cout << "Enter elements: ";
  for (int i = 0; i < n; i++){
    int x;
    cin >> x;
    arr.push_back(x);
  }
  cout << endl;
  cout << "Enter number of rotations: ";
  cin >> k;
  rotate(arr, k);
  cout << "Rotated array is: ";
  for (int x : arr){
    cout << x << " ";
  }
  cout << endl;
  return 0;
}