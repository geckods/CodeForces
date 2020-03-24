#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define MOD 1000000007

int main(){
	
	#ifndef ONLINE_JUDGE
    	freopen("input", "r", stdin);
    	freopen("output", "w", stdout);
	#endif
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll fib[100001];
    fib[0]=1;
    fib[1]=1;
    for(int i=2;i<=100000;i++){
    	fib[i]=(fib[i-1]+fib[i-2])%MOD;
    	fib[i]%=MOD;
    }

    string s;
    cin>>s;

    int n=s.length();

    int i=0,j=0;

    ll ans=1;

    while(i<n){
    	j=i;
    	if(s[i]=='u'||s[i]=='n'){
    		while(j<n && s[j]==s[i])j++;
    		ans*=fib[j-i];
    		ans%=MOD;
    		i=j;
    	}
    	else{
    		if(s[i]=='m'||s[i]=='w'){
    			ans=0;
    			break;
    		}
    		i++;
    	}
    }

    cout<<ans<<endl;
}
