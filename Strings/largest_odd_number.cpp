#include <iostream>
using namespace std;

string largestOddNumber(string num) {
  int n = num.length();
  for(int i=n-1; i>=0; i--){
    int curNum = num[i] - '0';
    if(curNum%2 != 0){
      return num.substr(0, i+1);
    }
  }
  return "";
}

int main() {

  string s;
  cout << "enter the string of nums: ";
  cin >> s;

  cout << largestOddNumber(s);

 return 0;
}