#include <iostream>
using namespace std;

bool rotateString(string s, string goal) {
  string d = s + s;
  int i = 0;
  int j = 0;
  string str = "";
  while(j < d.length()){
    while(str.length() < s.length()){
      str += d[j];
      j++;
    }
    if(str == goal){
      return true;
    }
    else{
      str = str.substr(1);
    }
  }
  return false;
}

int main() {

  string s;
  cout << "Enter the string: ";
  cin >> s;

  string goal;
  cout << "Enter goal string: ";
  cin >> goal;

  cout << rotateString(s, goal);

 return 0;
}