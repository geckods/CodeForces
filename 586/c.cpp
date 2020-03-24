#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){

	#ifndef ONLINE_JUDGE
    	freopen("input", "r", stdin);
    	freopen("output", "w", stdout);
	#endif
	ios_base::sync_with_stdio(false);
   	cin.tie(NULL);

   	string s;
   	cin>>s;

   	char smallest = 'z'+1;

   	for(int i=0;i<s.length();i++){
   		if(smallest<s[i]){
   			cout<<"Ann"<<endl;
   		}
   		else{
   			smallest=s[i];
   			cout<<"Mike"<<endl;
   		}
   	}
}