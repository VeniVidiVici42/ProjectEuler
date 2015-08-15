/*
Surprisingly there are only three numbers that can be written as the sum of fourth powers of their digits:

1634 = 14 + 64 + 34 + 44
8208 = 84 + 24 + 04 + 84
9474 = 94 + 44 + 74 + 44
As 1 = 14 is not a sum it is not included.

The sum of these numbers is 1634 + 8208 + 9474 = 19316.

Find the sum of all the numbers that can be written as the sum of fifth powers of their digits.
*/

#include <bits/stdc++.h>
using namespace std;

/* Suppose n has k digits; define f(n) to be the sum of the fifth powers of the digits
 * Then n>=10^(k-1) and f(n)<9^5*k; as n=f(n) we have 10^(k-1)<9^5*k, implying k<=6
 * Hence, suffices to check all k-digit numbers with 2<=k<=6
 */
 
int dig_fifth_power(int n){
  //Calculates the sum of the fifth powers of the digits of n
  int ret=0;
  
  while(n>0){
    ret+=(n%10)*(n%10)*(n%10)*(n%10)*(n%10);
    n=n/10;
  }
  
  return ret;
}

int main() {
	
  int sum=0;
  
  for(int n=10; n<=999999; n++){
    if(n==dig_fifth_power(n)){
      sum+=n;
    }
  }
  
  cout << sum << endl;
}
