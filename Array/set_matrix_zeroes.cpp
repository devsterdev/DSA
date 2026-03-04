#include<iostream>
#include <vector>
using namespace std;

void makeZeroI(vector<vector<int>>& matrix, int zeroI, int n){
  for(int i=0; i<n; i++){
    matrix[zeroI][i] = 0;
  }
}

void makeZeroJ(vector<vector<int>>& matrix, int zeroJ, int m){
  for(int i=0; i<m; i++){
    matrix[i][zeroJ] = 0;
  }
}

void setZeroes(vector<vector<int>>& matrix) {
  int m = matrix.size();
  int n= matrix[0].size();
  vector<vector<int>> zero;
  for(int i=0; i<m; i++){
    for(int j=0; j<n; j++){
      if(matrix[i][j] == 0){
        zero.push_back({i, j});
      }
    }
  }

  for(int i=0; i<zero.size(); i++){
    makeZeroI(matrix, zero[i][0], n);
    makeZeroJ(matrix, zero[i][1], m);
  }
}

int main(){

  int m, n;
  cout << "Enter the size of array m: ";
  cin >> m;
  cout << endl;
  cout << "Enter the size of ele of array n: ";
  cin >> n;
  cout << endl;
  vector<vector<int>> arr(m, vector<int>(n));

  cout << "Ele of 2d array: ";
  for(int i=0; i<m; i++){
    for(int j=0; j<n; j++){
      cin >> arr[i][j];
    }
  }

  setZeroes(arr);

  for(int i=0; i<m; i++){
    for(int j=0; j<n; j++){
      cout << arr[i][j] << " ";
    }
    cout << endl;
  }

  

  return 0;
}