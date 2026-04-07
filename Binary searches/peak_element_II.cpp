#include<iostream>
#include <vector>
using namespace std;

int maxEle(vector<vector<int>>& mat, int n, int m, int col){
  int maxValue = -1;
  int idx = -1;
  for(int i=0; i<n; i++){
    if(mat[i][col] > maxValue){
      maxValue = mat[i][col];
      idx = i;
    }
  }
  return idx;
}

vector<int> findPeakGrid(vector<vector<int>>& mat) {
  int n = mat.size();
  int m = mat[0].size();
  int low = 0;
  int high = m - 1;
  while(low <= high){
    int mid = low + ((high - low) / 2);
    int row = maxEle(mat, n, m, mid);
    int left = mid - 1 >= 0 ? mat[row][mid-1] : -1;
    int right = mid + 1 < m ? mat[row][mid+1] : -1;
    if(mat[row][mid] > left && mat[row][mid] > right){
      return {row, mid};
    }
    else if(mat[row][mid] < left){
      high = mid - 1;
    }
    else{
      low = mid + 1;
    }
  }
  return {-1, -1};
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

  vector<int> ans = findPeakGrid(matrix);

  for(int i=0; i<ans.size(); i++){
    cout << ans[i] << " ";
  }

  return 0;
}