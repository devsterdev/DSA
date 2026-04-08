#include<iostream>
#include <vector>
using namespace std;

int findMedian(vector<vector<int>>&matrix) {
  int n = matrix.size();
  int m = matrix[0].size();
  int low = 0;
  int high = (m*n) - 1;
  int mid = low + ((high - low) / 2);
  int midEle = matrix[mid/m][mid%m];
  return midEle;
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

  cout << findMedian(matrix);

  return 0;
}