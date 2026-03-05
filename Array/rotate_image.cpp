#include<iostream>
#include <vector>
using namespace std;

void swap_num(int &num1, int &num2){
  int temp = num1;
  num1 = num2;
  num2 = temp;
}

void rotate(vector<vector<int>>& matrix) {
  int n = matrix.size();
  for(int i=0; i<n/2; i++){
    for(int j=i; j<n-i-1; j++){
      swap_num(matrix[i][j], matrix[j][n-1-i]);
      swap_num(matrix[i][j], matrix[n-1-i][n-1-j]);
      swap_num(matrix[i][j], matrix[n-1-j][i]);
    }
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

  rotate(arr);

  for(int i=0; i<m; i++){
    for(int j=0; j<n; j++){
      cout << arr[i][j] << " ";
    }
    cout << endl;
  }

  

  return 0;
}