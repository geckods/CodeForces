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


    int k;
    cin>>k;
    string s,t;
    cin>>s;
    cin>>t;

    int sarr[k];
    int tarr[k];

    for(int i=k-1;i>=0;i--){
    	sarr[i]=s[i]-'a';
    	tarr[i]=t[i]-'a';
    }

    int sumarr[k+1];

    int carry=0;
    for(int i=k-1;i>=0;i--){
    	sumarr[i+1]=(sarr[i]+tarr[i]+carry)%26;
    	if(sarr[i]+tarr[i]+carry >= 26){
    		carry=1;
    	}
    	else{
    		carry=0;
    	}
    }
    sumarr[0]=carry;

    for(int i=0;i<=k;i++){
    	if(sumarr[i]%2==1){
    		sumarr[i+1]+=26;
    	}
    	sumarr[i]/=2;
    }

    for(int i=1;i<=k;i++){
    	cout<<(char)(sumarr[i]+'a');
    }
    cout<<endl;
}