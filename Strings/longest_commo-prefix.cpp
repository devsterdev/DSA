#include <iostream>
#include <vector>
using namespace std;

string longestCommonPrefix(vector<string>& strs) {
  if (strs.empty()) return "";
  string prefix = strs[0];
  for(int i=0; i<strs.size(); i++){
    string curStr = strs[i];
    int j = 0;
    int n = min(prefix.length(), curStr.length());
    while (j < n && prefix[j] == curStr[j]) {
      j++;
    }
    prefix = prefix.substr(0, j);
    if (prefix.empty()) return "";
  }
  return prefix;
}

int main() {

  int n;
  cout << "Enter size of str arr: ";
  cin >> n;

  vector<string> arr;
  cout << "Enter strings in vector: ";
  for(int i=0; i<n; i++){
    string str;
    cin >> str;
    arr.push_back(str);
  }

  cout << longestCommonPrefix(arr);

 return 0;
}