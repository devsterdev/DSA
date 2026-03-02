#include <iostream>
#include <vector>
using namespace std;

int singleNumber(vector<int> &nums){
  int XOR = 0;
  for (int i = 0; i < nums.size(); i++){
    XOR = XOR ^ nums[i];
  }
  return XOR;
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
  int singleNum = singleNumber(arr);
  cout << "The single number is: " << singleNum << endl;
  return 0;
}