#include<iostream>
#include <vector>
using namespace std;

int lowerBound(vector<int> &nums, int x){
  int low = 0;
  int high = nums.size() - 1;
  int ans = nums.size();
  while (low <= high){
    int mid = (low + high) / 2;
    if(nums[mid] >= x){
      ans = mid;
      high = mid - 1;
    }
    else{
      low = mid + 1;
    }
  }
  return ans;
}

int rowWithMax1s(vector<vector<int>> & mat) {
  int cnt_max = 0;
  int idx = -1;
  for(int i=0; i<mat.size(); i++){
    int cnt_one = mat[i].size() - lowerBound(mat[i], 1);
    if(cnt_one > cnt_max){
      cnt_max = cnt_one;
      idx = i;
    }
  }
  return idx;
}

int main(){

  int rows, cols;

  cout << "Enter number of rows: ";
  cin >> rows;

  cout << "Enter number of columns: ";
  cin >> cols;

  vector<vector<int>> matrix;
  cout << "Enter elements: ";
  for (int i = 0; i < rows; i++) {
      vector<int> row;
      for (int j = 0; j < cols; j++) {
          int x;
          cin >> x;
          row.push_back(x);
      }
      matrix.push_back(row);
  }

  cout << rowWithMax1s(matrix);

  return 0;
}