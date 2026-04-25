#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int kthElement(vector<int> &a, vector<int>& b, int k) {
  if(a.size() > b.size()) return kthElement(b, a, k);
  
  int n1 = a.size();
  int n2 = b.size();
  int low = max(0, k - n2);
  int high = min(k, n1);

  while (low <= high){
    int cut1 = low + ((high - low) / 2);
    int cut2 = k - cut1;  

    int l1 = cut1 == 0 ? INT_MIN : a[cut1-1];
    int l2 = cut2 == 0 ? INT_MIN : b[cut2-1];
    int r1 = cut1 == n1 ? INT_MAX : a[cut1];
    int r2 = cut2 == n2 ? INT_MAX : b[cut2];

    if(l1 <= r2 && l2 <= r1){
      return max(l1, l2);
    }
    else if(l1 > r2){
      high = cut1 - 1;
    }
    else{
      low = cut1 + 1;
    }
  }
  return -1;
}

int main() {

  int n1;
  cout << "Enter size of arr 1: ";
  cin >> n1;

  vector<int> arr1;
  cout << "Enter ele of arr 1: " ;
  for(int i=0; i<n1; i++){
    int x;
    cin >> x;
    arr1.push_back(x);
  }

  int n2;
  cout << "Enter size of arr 2: ";
  cin >> n2;

  vector<int> arr2;
  cout << "Enter ele of arr 2: " ;
  for(int i=0; i<n2; i++){
    int x;
    cin >> x;
    arr2.push_back(x);
  }

  int k;
  cout << "Enter value of K: ";
  cin >> k;

  cout << kthElement(arr1, arr2, k);

  return 0;
}