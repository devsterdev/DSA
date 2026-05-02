#include <iostream>
using namespace std;

int maxDepth(string s) {
  int ans = 0;
  int cnt = 0;
  for(int i=0; i<s.length(); i++){
    char ch = s[i];
    if(ch == '('){
      cnt++;
      ans = max(ans, cnt);
    }
    else if(ch == ')'){
      cnt--;
    }
  }
  return ans;
}

int main() {

  string s;
  cout << "Enter string s: ";
  cin >> s;

  cout << maxDepth(s);

 return 0;
}