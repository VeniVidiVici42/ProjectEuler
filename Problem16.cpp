/*
215 = 32768 and the sum of its digits is 3 + 2 + 7 + 6 + 8 = 26.

What is the sum of the digits of the number 21000?
*/

#include <bits/stdc++.h>
using namespace std;

string times2(string s){
	
  for(int i=0; i<s.length(); i++){
  	s[i]=2*(s[i]-'0')+'0';
  }
  
  for(int i=s.length()-1; i>=1; i--){
  	if((s[i]-'0')>9){
  	  s[i]-=10;
  	  s[i-1]++;
  	}
  }
  
  if(s[0]-'0'>9){
  	s[0]-=10;
  	s="1"+s;
  }
  
  return s;
}

int main() {
  string s="1";
  
  for(int i=0; i<1000; i++){
  	s=times2(s);
  }
  
  int ans=0;
  
  for(int i=0; i<s.length(); i++){
  	ans+=s[i]-'0';
  }
  
  cout << ans << endl;
}
