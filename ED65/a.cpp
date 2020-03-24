#include <bits/stdc++.h>
using namespace std;

int main(){

	#ifndef ONLINE_JUDGE
    	freopen("input", "r", stdin);
    	freopen("output", "w", stdout);
	#endif
	ios_base::sync_with_stdio(false);
   	cin.tie(NULL);

   	int t;
   	cin>>t;
   	for(int test=0;test<t;test++){
   		int n;
   		cin>>n;
   		string s;
   		cin>>s;
   		bool done=false;
   		for(int i=0;i<n-10;i++){
   			if(s[i]=='8'){
   				cout<<"YES"<<endl;
   				done=true;
   				break;
   			}
   		}

   		if(!done)cout<<"NO"<<endl;
   	}

}
