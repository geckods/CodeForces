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

   	int depth[n];

   	int currdepth=0;
   	for(int i=0;i<n;i++){
   		if(s[i]=='('){
   			depth[i]=currdepth++;
   		}
   		else{
   			depth[i]=--currdepth;
   		}
   	}

   	for(int i=0;i<n;i++){
   		if(depth[i]%2==0){
   			cout<<1;
   		}
   		else{
   			cout<<0;
   		}
   	}
   	cout<<endl;
}