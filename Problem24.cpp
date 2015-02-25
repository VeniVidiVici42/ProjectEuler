/*
A permutation is an ordered arrangement of objects. For example, 3124 is one possible permutation of the digits 1, 2, 3 and 4. If all of the permutations are listed numerically or alphabetically, we call it lexicographic order. The lexicographic permutations of 0, 1 and 2 are:

012   021   102   120   201   210

What is the millionth lexicographic permutation of the digits 0, 1, 2, 3, 4, 5, 6, 7, 8 and 9?
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> digits;
int factorials[10];

int main() {
  long long ans=0;
  
  for(int i=0; i<=9; i++){
  	digits.push_back(i);
  }
  
  factorials[0]=1;
  
  for(int i=1; i<10; i++){
  	factorials[i]=i*factorials[i-1];
  }
  
  //count 0123456789 as 0th permutation
  int n=1000000-1;
  
  while(digits.size()>0){
  	int k=n/factorials[digits.size()-1];
  	//digits[k] will be next digit as otherwise there are too many permutations less than it
  	n=n%factorials[digits.size()-1];
  	ans=10*ans+digits[k];
  	//don't use digits[k] again
  	digits.erase(digits.begin()+k);
  }
  
  cout << ans << endl;
}
