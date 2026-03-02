#include <iostream>
#include <vector>
using namespace std;

int findMaxConsecutiveOnes(vector<int> &nums){
  int i = 0, j = 0, best = 0;
  while (j < nums.size()){
    if (nums[j] == 0){
      i = j + 1;
    }
    best = max(best, j - i + 1);
    j++;
  }

  return best;
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
  int maxOnes = findMaxConsecutiveOnes(arr);
  cout << "Maximum number of consecutive ones is: " << maxOnes << endl;
  return 0;
}