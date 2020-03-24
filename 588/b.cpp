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
   	int k;
   	cin>>n>>k;

   	string s;
   	cin>>s;

   	int conv=0;

   	int i=0;
   	while(conv<k && i<n){
   		if(i==0){
   			if(n==1){
   				s[i]='0';
   				break;
   			}
   			if(s[i]!='1'){
   				s[i]='1';
   				conv++;
   			}
   			i++;
   		}
   		else{
   			if(s[i]!='0'){
   				s[i]='0';
   				conv++;
   			}
   			i++;   			
   		}
   	}

   	cout<<s<<endl;
}