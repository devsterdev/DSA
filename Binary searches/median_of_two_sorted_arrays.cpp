#include <iostream>
#include <vector>
#include <climits>
using namespace std;

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
  if(nums2.size() < nums1.size()) return findMedianSortedArrays(nums2, nums1);

  int n1 = nums1.size();
  int n2 = nums2.size();
  int low = 0;
  int high = n1;

  while(low <= high){
    int cut1 = low + ((high - low) / 2);
    int cut2 = (n1 + n2 + 1) / 2 - cut1;

    int l1 = cut1 == 0 ? INT_MIN : nums1[cut1-1];
    int l2 = cut2 == 0 ? INT_MIN : nums2[cut2-1];
    int r1 = cut1 == n1 ? INT_MAX : nums1[cut1];
    int r2 = cut2 == n2 ? INT_MAX : nums2[cut2];

    if(l1 <= r2 && l2 <= r1){
      if((n1 + n2)%2 == 0){
        return (max(l1, l2) + min(r1, r2)) / 2.0;
      }
      else{
        return max(l1, l2);
      }
    }
    else if(l1 > r2){
      high = cut1 - 1;
    }
    else{
      low = cut1 + 1;
    }
  }
  return 0.0;
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

  cout << findMedianSortedArrays(arr1, arr2);

 return 0;
}