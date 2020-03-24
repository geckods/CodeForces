#include <bits/stdc++.h>
using namespace std;

char getOther(char a,char b){
	if(a==b){
		if(a=='R') return 'G';
		if(a=='G') return 'B';
		if(a=='B') return 'R';
	}


	if((a=='R' && b=='G')|| (a=='G' && b=='R')){
		return 'B';
	}
	if((a=='B' && b=='G') ||(a=='G' && b=='B')){
		return 'R';
	}
	if((a=='R' && b=='B') || (a=='B' && b=='R')){
		return 'G';
	}
}

int main(){
	
	#ifndef ONLINE_JUDGE
    	freopen("input", "r", stdin);
    	freopen("output", "w", stdout);
	#endif

	int n;
	cin>>n;
	string s;
	cin>>s;

	int count=0;
	char prevchar='a',nextchar='a',nextnextchar='a';

	for(int i=1;i<n;i++){
		prevchar=s[i-1];
		if(i<n-1){
			nextchar = s[i+1];
		}

		if(s[i]==prevchar){
			s[i] = getOther(prevchar,nextchar);
//			cout<<prevchar<<" "<<nextchar<<endl;
//			cout<<"HI "<<i<<" "<<s[i]<<endl;
			count++;
		}
	}

	cout<<count<<endl;
	cout<<s<<endl;
}