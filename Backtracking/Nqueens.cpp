#include <iostream>
#include <vector>
using namespace std;

bool isSafe(vector<string>& board, int row, int col, int n) {
  for (int j = 0; j < n; j++){
    if(board[row][j] == 'Q'){
      return false;
    }
  }
  for(int i = 0; i < n; i++){
    if(board[i][col] == 'Q'){
      return false;
    }
  }
  for(int i = row, j = col; i>=0 && j>=0; i--, j--){
    if(board[i][j] == 'Q'){
      return false;
    }
  }
  for(int i = row, j = col; i >= 0 && j < n; i--, j++){
    if(board[i][j] == 'Q'){
      return false;
    }
  }
  return true;
}

void nQueen(vector<string>& board, int row, int n, vector<vector<string>>& ans){
  if(row == n){
  ans.push_back(board);
  return;
  }
  for(int j = 0; j<n; j++){
    if (isSafe(board, row, j, n)){
      board[row][j] = 'Q';
      nQueen(board, row + 1, n, ans);
      board[row][j] = '.';
    }
  }
}

vector<vector<string>> solveNQueens(int n) {
  vector<string> board(n, string(n, '.'));
  vector<vector<string>> ans;
  nQueen(board, 0, n, ans);
  return ans;
}

int main() {

  // Test case 1: 4 Queens
  int n1 = 4;

  vector<vector<string>> result1 = solveNQueens(n1);

  cout << "N-Queens for n = " << n1 << ":\n";
  cout << "Number of solutions: " << result1.size() << "\n";

  for (auto& solution : result1) {
    for (auto& row : solution) {
      cout << row << "\n";
    }
    cout << "\n";
  }

  // Test case 2: 8 Queens
  int n2 = 8;

  vector<vector<string>> result2 = solveNQueens(n2);

  cout << "N-Queens for n = " << n2 << ":\n";
  cout << "Number of solutions: " << result2.size() << "\n\n";

  // Test case 3: 1 Queen
  int n3 = 1;

  vector<vector<string>> result3 = solveNQueens(n3);

  cout << "N-Queens for n = " << n3 << ":\n";
  cout << "Number of solutions: " << result3.size() << "\n";

  for (auto& solution : result3) {
    for (auto& row : solution) {
      cout << row << "\n";
    }
    cout << "\n";
  }

  return 0;
}
