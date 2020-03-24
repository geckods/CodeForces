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

    int q;
    cin>>q;

    for(int quer=0;quer<q;quer++){
    	ll n,k;
    	cin>>n>>k;
    	string s;
    	cin>>s;

    	ll zc=0;
    	for(int i=0;i<n;i++){
    		if(s[i]=='0')zc++;
    	}

    	// if(k==9428683473)cout<<"HI"<<endl;

    	ll i=0,j=0;
    	ll sum=0;

    	ll state=-1;
    	ll excess;

    	while(j<n){
    		while(i<n && s[i]=='1')i++;
    		if(i==n){
    			state=0;
    			break;
    		}
    		if(sum+i-j > k){
    			state=1;
    			excess=k-sum;
    			break;
    		}
    		else{
    			sum+=i-j;
    			i++;
    			j++;
    		}
    	}

    	if(j==n)state=0;

    	if(state==0){
    		for(int z=0;z<zc;z++){
    			cout<<'0';
    		}
    		for(int z=0;z<n-zc;z++){
    			cout<<'1';
    		}
    		cout<<endl;
    	}
    	else if (state==1){
    		int z=0;
    		for(;z<j;z++){
    			cout<<'0';
    		}
    		for(;z<i-excess;z++){
    			cout<<'1';
    		}
    		cout<<'0';
    		z++;
    		for(;z<=i;z++){
    			cout<<'1';
    		}
    		for(;z<n;z++){
    			cout<<s[z];
    		}
    		cout<<endl;
    	}

    }
}