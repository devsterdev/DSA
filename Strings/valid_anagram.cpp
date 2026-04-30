#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

bool isAnagram(string s, string t) {
  if (s.length() != t.length()) return false;
  vector<int> count(26, 0);
  for(char &ch : s){
    count[ch-'a']++;
  }
  for(char &ch : t){
    count[ch-'a']--;
  }

  bool allZero = all_of(begin(count), end(count), [](int element){
    return element == 0;
  });

  return allZero;
}

int main() {

  string s;
  cout << "Enter string s: ";
  cin >> s;

  string t;
  cout << "Enter string t: ";
  cin >> t;

  cout << isAnagram(s, t);

 return 0;
}