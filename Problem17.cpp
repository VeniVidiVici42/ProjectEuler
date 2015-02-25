/*
If the numbers 1 to 5 are written out in words: one, two, three, four, five, then there are 3 + 3 + 5 + 4 + 4 = 19 letters used in total.

If all the numbers from 1 to 1000 (one thousand) inclusive were written out in words, how many letters would be used?


NOTE: Do not count spaces or hyphens. For example, 342 (three hundred and forty-two) contains 23 letters and 115 (one hundred and fifteen) contains 20 letters. The use of "and" when writing out numbers is in compliance with British usage.
*/

#include <bits/stdc++.h>
using namespace std;

//(zero), one, two, three, four, five, six, seven, eight, nine
int dig[10]={0,3,3,5,4,4,3,5,5,4};

//ten, eleven, twelve, thirteen, fourteen, fifteen, sixteen, seventeen, eighteen, nineteen
int teen[10]={3,6,6,8,8,7,7,9,8,8};

//ten, twenty, thirty, forty, fifty, sixty, seventy, eighty, ninety
int tens[10]={0,3,6,6,5,5,5,7,6,6};

int calc(int n){
  int ret=0, d=0;
  
  if(n%100==0){
  	return 7+dig[n/100]; //"hundred"
  }
  
  if(10<=n%100 && n%100<=19){
  	ret+=teen[n%100-10];
  	n-=n%100;
  }
  
  while(n>0){
  	d++;
  	if(d==1){
  	  ret+=dig[n%10];
  	}
  	if(d==2){
  	  ret+=tens[n%10];
  	}
  	if(d==3){
  	  ret+=10; //"and", "hundred"
  	  ret+=dig[n%10];
  	}
  	n=n/10;
  }
  
  return ret;
}

int main() {
  int ans=0;
  
  for(int i=1; i<=999; i++){
  	ans+=calc(i);
  }
  
  cout << ans+11 << endl; //count "one thousand" separately
}
