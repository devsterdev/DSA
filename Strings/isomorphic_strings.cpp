#include <iostream>
#include <unordered_map>
using namespace std;

bool isIsomorphic(string s, string t) {
  unordered_map<char, char> mp1;
  unordered_map<char, char> mp2;

  int m = s.length();
  for(int i=0; i<m; i++){
    char ch1 = s[i];
    char ch2 = t[i];

    if(mp1.find(ch1) != mp1.end() && mp1[ch1] != ch2 || mp2.find(ch2) != mp2.end() && mp2[ch2] != ch1){
      return false;
    }
    mp1[ch1] = ch2;
    mp2[ch2] = ch1;
  }
  return true;
}

int main() {

  string s1;
  cout << "Enter string 1: ";
  cin >> s1;

  string s2;
  cout << "Enter string 2: ";
  cin >> s2;

  cout << isIsomorphic(s1, s2);

 return 0;
}