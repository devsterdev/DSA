#include<iostream>
using namespace std;

double multiply(double number, int n){
  double ans = 1.0;
  for(int i=0; i<n; i++){
    ans = ans*number;
  }
  return ans;
}

int NthRoot(int N, int M) {
  double low = 1;
  double high = M;
  double eps = 1e-6;

  while (high - low > eps){
    double mid = (low + high) / 2.0;
    if(multiply(mid, N) < M){
      low = mid;
    }
    else{
      high = mid;
    }
  }
  return low;
}


int main(){

  int n, m;
  cout << "Enter n and m";
  cin >> n >> m;

  cout << NthRoot(n, m);
  
  return 0;
}