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

 	int n=s.size();

 	if(n%2==1){
 		bool seenone=false;
 		for(int i=1;i<n;i++){
 			if(s[i]=='1'){
 				seenone=true;
 				break;
 			}
 		}
 		if(seenone){
 			cout<<n/2+1<<endl;
 		}
 		else{
 			cout<<n/2<<endl;
 		}
 	}
 	else{
 		cout<<n/2<<endl;
 	}

}
