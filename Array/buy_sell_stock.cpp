#include <iostream>
#include <vector>
using namespace std;

int maxProfit(vector<int> &prices){
  int mini = prices[0];
  int profit = 0;
  for (int i = 1; i < prices.size(); i++){
    int cost = prices[i] - mini;
    profit = max(profit, cost);
    mini = min(mini, prices[i]);
  }
  return profit;
}

int main(){
  vector<int> arr;
  int n;
  cout << "Enter number of elements: ";
  cin >> n;
  cout << endl;
  cout << "Enter elements: ";
  for (int i = 0; i < n; i++){
    int x;
    cin >> x;
    arr.push_back(x);
  }
  int result = maxProfit(arr);
  cout << "The maximum profit is: " << result << endl;
  return 0;
}