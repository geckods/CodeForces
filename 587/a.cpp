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

   	int ans=0;
   	for(int i=0;i<n;i+=2){
   		if((s[i]=='a'&&s[i+1]=='b') || (s[i+1]=='a'&&s[i]=='b')){

   		}
   		else{
   			ans++;
   		}
   	}
   	cout<<ans<<endl;
   	for(int i=0;i<n;i+=2){
   		if((s[i]=='a'&&s[i+1]=='b') || (s[i+1]=='a'&&s[i]=='b')){
   			cout<<s[i]<<s[i+1];
   		}
   		else{
   			cout<<"ab";
   		}
   	}
   	cout<<endl;

}
