#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;


void solve(vector<string>& ans, string& temp, int idx, string& digits, unordered_map<char, string>& mp){
  if(idx >= digits.size()){
    ans.push_back(temp);
    return;
  }
  char ch = digits[idx];
  string str = mp[ch];
  for(int i=0; i<str.length(); i++){
    temp.push_back(str[i]);
    solve(ans, temp, idx+1, digits, mp);
    temp.pop_back();
  }
}

vector<string> letterCombinations(string digits) {
  if(digits.length() == 0){
    return {};
  }
  vector<string> ans;
  unordered_map<char, string> mp;
  mp['2'] = "abc";
  mp['3'] = "def";
  mp['4'] = "ghi";
  mp['5'] = "jkl";
  mp['6'] = "mno";
  mp['7'] = "pqrs";
  mp['8'] = "tuv";
  mp['9'] = "wxyz";
  string temp = "";
  solve(ans, temp, 0, digits, mp);
  return ans;
}


int main() {
  // Test case 1
  string digits1 = "23";
  vector<string> result1 = letterCombinations(digits1);
  cout << "Input: " << digits1 << "\nOutput: ";
  for(auto& s : result1) cout << s << " ";
  cout << "\n\n";

  // Test case 2
  string digits2 = "";
  vector<string> result2 = letterCombinations(digits2);
  cout << "Input: \"\" \nOutput: ";
  for(auto& s : result2) cout << s << " ";
  cout << "(empty)\n\n";

  // Test case 3
  string digits3 = "234";
  vector<string> result3 = letterCombinations(digits3);
  cout << "Input: " << digits3 << "\nOutput: ";
  for(auto& s : result3) cout << s << " ";
  cout << "\n\n";

  // Test case 4
  string digits4 = "2";
  vector<string> result4 = letterCombinations(digits4);
  cout << "Input: " << digits4 << "\nOutput: ";
  for(auto& s : result4) cout << s << " ";
  cout << "\n";

 return 0;
}