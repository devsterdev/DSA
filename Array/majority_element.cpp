#include <iostream>
#include <vector>
using namespace std;

int majorityElement(vector<int> &nums){
  int count = 1;
  int elem = nums[0];
  for (int i = 1; i < nums.size(); i++){
    if (nums[i] == elem){
      count++;
    }
    else{
      count--;
    }
    if (count < 0){
      count = 1;
      elem = nums[i];
    }
  }
  return elem;
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
  int result = majorityElement(arr);
  cout << "The majority element is: " << result << endl;
  return 0;
}