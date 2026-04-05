#include<iostream>
#include <vector>
using namespace std;

bool searchMatrix(vector<vector<int>>& matrix, int target) {
  if(matrix.size() == 0){
    return false;
  }
  int n = matrix.size();
  int m = matrix[0].size();
  int low = 0;
  int high = (m*n)-1;
  while (low <= high){
    int mid = low + ((high - low)/2);
    if(matrix[mid/m][mid%m] == target){
      return true;
    }
    else if(matrix[mid/m][mid%m] < target){
      low = mid + 1;
    }
    else{
      high = mid - 1;
    }
  }
  return false;
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

  int target;
  cout << "Enter target: ";
  cin >> target;

  cout << searchMatrix(matrix, target);


  return 0;
}