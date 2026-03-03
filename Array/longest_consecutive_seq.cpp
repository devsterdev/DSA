#include<iostream>
#include<vector>
#include <unordered_set>
using namespace std;

int longestConsecutive(vector<int>& nums) {
    int n = nums.size();
    if(n == 0) return 0;
    int longest = 1;
    unordered_set<int> st;
    for(int i=0; i<n; i++){
      st.insert(nums[i]);
    }

    for(auto it: st){
      if(st.find(it - 1) == st.end()){
        int cnt = 1;
        int x = it;
        while(st.find(x+1) != st.end()){
          x = x + 1;
          cnt = cnt + 1;
        }
        longest = max(longest, cnt);
      }
    }

    return longest;
}

int main(){
  int n;
  cout << "Enter the size of array: ";
  cin >> n;
  cout << endl;
  vector<int> arr;
  cout << "Enter elements: ";
  for (int i = 0; i < n; i++){
    int x;
    cin >> x;
    arr.push_back(x);
  }
  cout << endl;

  cout << longestConsecutive(arr);

  return 0;
}