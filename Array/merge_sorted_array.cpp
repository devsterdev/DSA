#include<iostream>
#include <vector>
#include <algorithm>
using namespace std;

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
  for(int i=0; i<n; i++){
    nums1[m+i] = nums2[i];
  }
  sort(nums1.begin(), nums1.end());
}


int main(){

  int m;
  int n;

  cout << "Enter the size of num1: ";
  cin >> m;
  cout << "Enter the size of num2: ";
  cin >> n;


  vector<int> num1(m+n, 0);
  vector<int> num2;

  cout << "Enter the ele of num1: ";
  for(int i=0; i<m; i++){
    int x;
    cin >> x;
    num1[i] = x;
  }
  
  cout << "Enter the ele of num2: ";
  for(int i=0; i<n; i++){
    int x;
    cin >> x;
    num2.push_back(x);
  }

  merge(num1, m, num2, n);

  for(int i=0; i<num1.size(); i++){
    cout << num1[i] << " ";
  }
  

  return 0;
}