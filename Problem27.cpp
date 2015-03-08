/*
Euler discovered the remarkable quadratic formula:

n² + n + 41

It turns out that the formula will produce 40 primes for the consecutive values n = 0 to 39. However, when n = 40, 402 + 40 + 41 = 40(40 + 1) + 41 is divisible by 41, and certainly when n = 41, 41² + 41 + 41 is clearly divisible by 41.

The incredible formula  n² − 79n + 1601 was discovered, which produces 80 primes for the consecutive values n = 0 to 79. The product of the coefficients, −79 and 1601, is −126479.

Considering quadratics of the form:

n² + an + b, where |a| < 1000 and |b| < 1000

where |n| is the modulus/absolute value of n
e.g. |11| = 11 and |−4| = 4
Find the product of the coefficients, a and b, for the quadratic expression that produces the maximum number of primes for consecutive values of n, starting with n = 0.
*/

#include <bits/stdc++.h>
using namespace std;

/* Let f(n)=n^2+an+b
 * f(0)=b is prime, so b is prime and b>=2
 * f(1)=a+b+1 is prime, so a+b>0
 * Therefore f(b)=b^2+ab+b=b(b+a+1) is not prime, as b+a+1>=2 and b>=2
 * Hence only need to check n=0, 1, ..., b-1; max value is thus 999^2+1000*999+1000
 */
 
const int MAXN=1000*1000+999*999+1;
 
bool isnotprime[MAXN];
int p=2; //denotes a prime

void sieve(){
  if(p==1414){
  	return;
  }
  if(!isnotprime[p]){
  	for(int i=2*p; i<MAXN; i+=p){
  	  isnotprime[i]=true;
  	}
  }
  p++;
  sieve();
}

int main() {
  sieve();
  int n=0, bestn=0, bestprod;
  
  for(int b=2; b<1000; b++){ //b must be prime
  	for(int a=-b; a<=1000; a++){ // f(1)=a+b+1 must be positive if it's prime
  	  n=0;
  	  while(n*n+a*n+b>0 && !isnotprime[n*n+a*n+b]){
  	  	n++;
  	  }
  	  if(n>bestn){
  	  	bestn=n;
  	  	bestprod=a*b;
  	  }
  	}
  }
  
  cout << bestprod << endl;
}
