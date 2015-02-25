/*
The Fibonacci sequence is defined by the recurrence relation:

Fn = Fn−1 + Fn−2, where F1 = 1 and F2 = 1.
Hence the first 12 terms will be:

F1 = 1
F2 = 1
F3 = 2
F4 = 3
F5 = 5
F6 = 8
F7 = 13
F8 = 21
F9 = 34
F10 = 55
F11 = 89
F12 = 144
The 12th term, F12, is the first term to contain three digits.

What is the first term in the Fibonacci sequence to contain 1000 digits?
*/

#include <bits/stdc++.h>
using namespace std;

string add(string a, string b){
  //b is necessarily larger string
  string ret="";
  
  for(int i=0; i<b.size(); i++){
  	ret+=" ";
  }
  
  for(int i=a.size(); i<b.size(); i++){
  	a="0"+a;
  }
  
  for(int i=0; i<b.size(); i++){
    ret[i]=(b[i]-'0')+(a[i]-'0')+'0';	
  }
  
  for(int i=ret.size()-1; i>0; i--){
  	if(ret[i]-'0'>9){
  	  ret[i]-=10;
  	  ret[i-1]++;
  	}
  }
  
  if(ret[0]-'0'>9){
  	ret[0]-=10;
  	ret="1"+ret;
  }
  
  return ret;
}

int main() {
  string f1="1";
  string f2="1";
  
  int count=2;
  
  while(f2.size()<1000){
    string temp=f2;
    f2=add(f1,f2);
    f1=temp;
    count++;
  }
  
  cout << count << endl;
}
