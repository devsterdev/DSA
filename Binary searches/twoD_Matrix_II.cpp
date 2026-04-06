#include<iostream>
#include <vector>
using namespace std;

bool searchMatrix(vector<vector<int>>& matrix, int target) {
  if(matrix.size() == 0){
    return false;
  }
  int n = matrix.size();
  int m = matrix[0].size();
  int first = 0;
  int secound = m-1;
  while (first < n && secound >= 0){
    if(matrix[first][secound] == target){
      return true;
    }
    else if(matrix[first][secound] < target){
      first++;
    }
    else{
      secound--;
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