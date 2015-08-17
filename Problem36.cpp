/*
The decimal number, 585 = 10010010012 (binary), is palindromic in both bases.

Find the sum of all numbers, less than one million, which are palindromic in base 10 and base 2.

(Please note that the palindromic number, in either base, may not include leading zeros.)
*/

#include <bits/stdc++.h>
using namespace std;

bool is_palin_base_10(int n){
  // Determines if n is a palindrome in base 10 by reversing the digits and comparing
  int copy=n, rev=0;
  
  while(copy>0){
  	rev=10*rev+copy%10;
  	copy=copy/10;
  }
  
  return n==rev;
}

bool is_palin_base_2(int n){
  // Determines in n is a palindrome in binary by checking digits
  int size=(int)(log(n)/log(2))+1;
  int point1=0, point2=size-1;
  
  while(point1<point2){
    if((n&(1<<point1))==0){ //digit at point1 is 0
      if((n&(1<<point2))>0){ //digit at point2 is 1
      	return false;
      }
    }
    if((n&(1<<point2))==0){ //digit at point2 is 0
      if((n&(1<<point1))>0){ //digit at point1 is 1
      	return false;
      }
    }
    point1++;
    point2--;
  }
  
  return true;
}

int main() {
  int sum=0;
  
  for(int i=1; i<1000000; i++){
  	if(is_palin_base_10(i) && is_palin_base_2(i)){
  	  sum+=i;
  	}
  }
  
  cout << sum << endl;
}
