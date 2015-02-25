/*
Using names.txt (right click and 'Save Link/Target As...'), a 46K text file containing over five-thousand first names, begin by sorting it into alphabetical order. Then working out the alphabetical value for each name, multiply this value by its alphabetical position in the list to obtain a name score.

For example, when the list is sorted into alphabetical order, COLIN, which is worth 3 + 15 + 12 + 9 + 14 = 53, is the 938th name in the list. So, COLIN would obtain a score of 938 × 53 = 49714.

What is the total of all the name scores in the file?
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
  vector<string> names;
  string temp;
  long long ans=0, word_value=0;
  
  while(getline(cin, temp, ',')){
  	//get the names; file is of the form "ALICE","BOB","CHARLIE",...
  	names.push_back(temp);
  }
  
  sort(names.begin(), names.end());
  
  for(int i=0; i<names.size(); i++){
  	word_value=0;
  	for(int j=1; j<names[i].length()-1; j++){
  	  word_value+=names[i][j]-'A'+1;
  	}
  	ans+=word_value*(i+1);
  }
  
  cout << ans << endl;
}
