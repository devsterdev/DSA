#include<iostream>
#include <vector>
using namespace std;


vector<vector<int>> generate(int numRows) {
  vector<vector<int>> ans;
  for(int i=0; i<numRows; i++){
    vector<int> temp;
    for(int j=0; j<=i; j++){
      int x = 1;
      if(!(j == 0 || j == i)){
        x = ans[i-1][j-1] + ans[i-1][j];
      }
      temp.push_back(x);
    }
    ans.push_back(temp);
  }
  return ans;
}

int main(){

  int n;
  cout << "Enter number of row: ";
  cin >> n;

  vector<vector<int>> ans = generate(n);

  for(int i = 0; i < ans.size(); i++){
    for(int j = 0; j < ans[i].size(); j++){
      cout << ans[i][j] << " ";
    }
    cout << endl;
  }

  

  return 0;
}