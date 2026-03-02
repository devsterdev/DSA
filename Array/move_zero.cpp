#include <iostream>
#include <vector>
using namespace std;

void moveZeroes(vector<int> &nums){
  int zero = 0;
  for (int i = 0; i < nums.size(); i++){
    if (nums[i] != 0){
      int temp = nums[i];
      nums[i] = nums[zero];
      nums[zero] = temp;
      zero++;
    }
  }
}

int main(){
  vector<int> arr;
  int n;
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
  moveZeroes(arr);
  cout << "Array after moving zeros to end: ";
  for (int x : arr){
    cout << x << " ";
  }
  cout << endl;
  return 0;
}