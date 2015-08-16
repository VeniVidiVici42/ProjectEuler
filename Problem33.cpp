/*
The fraction 49/98 is a curious fraction, as an inexperienced mathematician in attempting to simplify it may incorrectly believe that 49/98 = 4/8, which is correct, is obtained by cancelling the 9s.

We shall consider fractions like, 30/50 = 3/5, to be trivial examples.

There are exactly four non-trivial examples of this type of fraction, less than one in value, and containing two digits in the numerator and denominator.

If the product of these four fractions is given in its lowest common terms, find the value of the denominator.
*/

#include <bits/stdc++.h>
using namespace std;

int gcd(int x, int y){
  // Calculates the greatest common divisor of x,y recursively using Euclidean algorithm
  if(x<y){
  	swap(x,y);
  }
  
  if(y==0){
    return x;
  }
  
  return gcd(x%y,y);
}

int main(){
  /* We want (ab)/(bc)=a/c where (ab),(bc) denote two-digit numbers
   * i.e. (ab)*c=(bc)*a
   * If x=(ab), y=(bc), this can be rewritten as x*(y%10)=y*(x/10), subject to (x%10)=y/10
   */
   
  int num=1, denom=1;
   
  for(int x=10; x<100; x++){
    for(int y=x+1; y<100; y++){
      if((x%10)==y/10 && x*(y%10)==y*(x/10)){
      	//cout << x << " " << y << endl;
        num*=x, denom*=y;
      }
    }
  }
  
  cout << denom/gcd(num,denom) << endl;
}
