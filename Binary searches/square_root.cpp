  #include<iostream>
  using namespace std;

  int floorSqrt(int n)  {
    int low = 0;
    int high = n;
    int ans = 1;
    while(low <= high){
      int mid = (low + high) / 2;
      if(mid * mid == n){
        return mid;
      }
      else if(mid*mid < n){
        ans = mid;
        low = mid+1;
      }
      else{
        high = mid-1;
      }
    }
    return ans;
  }


  int main(){

    int n;
    cout << "Enter n: ";
    cin >> n;
    cout << floorSqrt(n);

    return 0;
  }