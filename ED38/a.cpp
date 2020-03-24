#include <bits/stdc++.h>
using namespace std;

bool isVowel(char a){
	if(a=='a'||a=='e'||a=='i'||a=='o'||a=='u'||a=='y'){
		return true;
	}
	return false;
}

int main(){

	#ifndef ONLINE_JUDGE
    	freopen("input", "r", stdin);
    	freopen("output", "w", stdout);
	#endif
	ios_base::sync_with_stdio(false);
   	cin.tie(NULL);

   	int n;
   	cin>>n;

   	string s;
   	cin>>s;

   	vector<char> myVec;

   	int i=0;
   	while(i<n){
   		myVec.push_back(s[i]);
   		if(!isVowel(s[i])){
   			i++;
   		}
   		else{
   			i++;
   			while(i<n && isVowel(s[i])) i++;
   		}
   	}

   	for(int j=0;j<myVec.size();j++){
   		cout<<myVec[j];
   	}
   	cout<<endl;

}
