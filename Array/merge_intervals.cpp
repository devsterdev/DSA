#include<iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<vector<int>> merge(vector<vector<int>>& intervals) {
  vector<vector<int>> ans;
  sort(intervals.begin(), intervals.end());
  for(int i=0; i<intervals.size(); i++){
    int start = intervals[i][0];
    int end = intervals[i][1];
    if(ans.empty() || start > ans.back()[1]){
      ans.push_back(intervals[i]);
    }
    else{
      ans.back()[1] = max(ans.back()[1], intervals[i][1]);
    }
  }
  return ans;
}

int main(){

  int k;
  cout << "Enter number of intervals: ";
  cin >> k;

  vector<vector<int>> arr;
  cout << "Enter intervals: ";

  for(int i = 0; i < k; i++) {
      vector<int> temp(2);
      cin >> temp[0] >> temp[1];
      arr.push_back(temp);
  }

  vector<vector<int>> ans = merge(arr);

  for(int i=0; i<ans.size(); i++){
    for(int j=0; j<ans[i].size(); j++){
      cout << ans[i][j] << " ";
    }
    cout << endl;
  }

  return 0;
}