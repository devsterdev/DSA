#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<char, int> P;

string frequencySort(string s) {
  vector<P> arr(123);

  for(char &ch: s){
    int freq = arr[ch].second;
    arr[ch] = {ch, freq+1};
  }

  auto lamda = [&](P &p1, P &p2){
    return p1.second > p2.second;
  };

  sort(begin(arr), end(arr), lamda);

  string ans = "";

  for(int i=0; i<=122; i++){
    if(arr[i].second > 0){
      char ch = arr[i].first;
      int freq = arr[i].second;
      string temp = string(freq, ch);
      ans += temp;
    }
  }
  return ans;
}

int main() {

  string s;
  cout << "Enter the string s: ";
  cin >> s;

  cout << frequencySort(s);

 return 0;
}