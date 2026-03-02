#include <iostream>
#include <vector>
using namespace std;

int largestElement(vector<int> &nums){
  int max = nums[0];
  for (int i = 1; i < nums.size(); i++){
    if (nums[i] > max)
      max = nums[i];
  }
  return max;
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

  int max = largestElement(arr);

  cout << "Largest element is: " << max << endl;

  return 0;
}