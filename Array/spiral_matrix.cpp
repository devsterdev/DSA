#include <iostream>
#include <vector>
using namespace std;

vector<int> spiralOrder(vector<vector<int>> &matrix){
  int m = matrix.size();
  int n = matrix[0].size();

  int up = 0;
  int down = m - 1;
  int left = 0;
  int right = n - 1;

  bool rightS = true; 
  int downS = false; 
  int leftS = false;
  int upS = false;

  int i = 0;
  int j = 0;
  vector<int> ans;

  for (int k = 0; k < m * n; k++){
    ans.push_back(matrix[i][j]);
    if (rightS){
      if (j < right)
        j++;
      else{
        rightS = false;
        downS = true;
        up++;
        i++;
      }
    }
    else if (downS){
      if (i < down)
        i++;
      else{
        downS = false;
        leftS = true;
        right--;
        j--;
      }
    }

    else if (leftS){
      if (j > left)
        j--;
      else{
        leftS = false;
        upS = true;
        down--;
        i--;
      }
    }

    else if (upS){
      if (i > up)
        i--;
      else{
        upS = false;
        rightS = true;
        left++;
        j++;
      }
    }
  }

  return ans;
}

int main(){
  int m, n;
  cout << "Enter rows: ";
  cin >> m;
  cout << "Enter columns: ";
  cin >> n;

  vector<vector<int>> arr(m, vector<int>(n));

  cout << "Enter elements:\n";
  for (int i = 0; i < m; i++){
    for (int j = 0; j < n; j++){
      cin >> arr[i][j];
    }
  }

  vector<int> ans = spiralOrder(arr);

  for(int i=0; i<ans.size(); i++){
    cout << ans[i] << " ";
  }

  return 0;
}