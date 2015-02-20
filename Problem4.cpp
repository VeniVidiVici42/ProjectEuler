/*
A palindromic number reads the same both ways. The largest palindrome made from the product of two 2-digit numbers is 9009 = 91 × 99.

Find the largest palindrome made from the product of two 3-digit numbers.
*/

#include <bits/stdc++.h>
using namespace std;

bool is_palin(int n){
  int anchor=n, rev=0;
  
  while(n>0){
  	rev=rev*10+(n%10);
  	n=n/10;
  }
  
  return rev==anchor;
}
  

int main() {
  int ans=0;
  
  for(int i=100; i<1000; i++){
    for(int j=i+1; j<1000; j++){
      if(is_palin(i*j)){
      	ans=max(ans, i*j);
      }
    }
  }
  
  cout << ans << endl;
}
