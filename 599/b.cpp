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
   		string s,t;
   		cin>>s;
   		cin>>t;

   		bool works=true;
   		int diffcount=0;

   		char fs,ft;

   		
   		for(int i=0;i<n;i++){
   			if(s[i]!=t[i]){
   				diffcount++;

   				if(diffcount==1){
   					works=false;
   					fs=s[i];
   					ft=t[i];
   				}
   				else if (diffcount==2){
   					if(ft==t[i]&&fs==s[i]){
   						works=true;
   					}
   				}
   				else{
   					works=false;
   				}
   			}
   		}

   		if(works){
   			cout<<"Yes"<<endl;
   		}
   		else{
   			cout<<"No"<<endl;
   		}

   	}
}