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


   	int zerocount=0;
   	int onecount=0;
   	for(int i=0;i<n;i++){
   		if(s[i]=='1'){
   			onecount++;
   		}
   		else{
   			zerocount++;
   		}
   	}

   	if(zerocount==onecount){
   		cout<<2<<endl;
   		cout<<s[0]<<" ";
   		for(int i=1;i<n;i++){
   			cout<<s[i];
   		}
   		cout<<endl;
   	}
   	else{
   		cout<<1<<endl;
   		cout<<s<<endl;
   	}

}
