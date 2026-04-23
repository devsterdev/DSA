#include <iostream>
using namespace std;

string trim(string s){
  if(s.length() <= 2) return "";
  return s.substr(1, s.length() - 2);
}

string removeOuterParentheses(string s) {
  string ans = "";
  int cnt = 0;
  string cur = "";
  for(int i=0; i<s.length(); i++){
    if(s[i] == '('){
      cnt++;
    }
    if(s[i] == ')'){
      cnt--;
    }
    cur += s[i];
    if(cnt == 0){
      ans += trim(cur);
      cur = "";
    }
  }
  return ans;
}

int main() {

  string s;
  cout << "Enter string s: ";
  cin >> s;

  cout << removeOuterParentheses(s);

 return 0;
}