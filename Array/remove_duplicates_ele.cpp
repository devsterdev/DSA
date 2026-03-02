#include <iostream>
#include <vector>
using namespace std;

int removeDuplicates(vector<int> &nums){
  int count = 1;

  for (int i = 1; i < nums.size(); i++){
    if (nums[i] != nums[i - 1]){
      nums[count] = nums[i];
      count++;
    }
  }
  return count;
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
  int uniqueCount = removeDuplicates(arr);
  cout << "Number of unique elements: " << uniqueCount << endl;
  return 0;
}