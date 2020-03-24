#include <bits/stdc++.h>
using namespace std;

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

   	int zc=0;
   	int nc=0;
   	for(int i=0;i<n;i++){
   		if(s[i]=='z')zc++;
   		if(s[i]=='n')nc++;
   	}

   	for(int i=0;i<nc;i++){
   		cout<<1<<" ";
   	}
   	for(int i=0;i<zc;i++){
   		cout<<0<<" ";
   	}
   	cout<<endl;
}
