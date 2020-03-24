#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
	
	#ifndef ONLINE_JUDGE
    	freopen("input", "r", stdin);
    	freopen("output", "w", stdout);
    	freopen("error", "w", stderr);
	#endif
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;

    while(t--){
    	string s,t;
    	cin>>s;
    	cin>>t;

    	int ns=s.length();
    	int np=t.length();

    	int arr[ns+1][26];//including this character, nearest next char

    	for(int i=0;i<26;i++){
    		arr[ns][i]=INT_MAX;
    	}

    	for(int i=ns-1;i>=0;i--){
    		for(int j=0;j<26;j++){
    			arr[i][j]=arr[i+1][j];
    		}
    		arr[i][s[i]-'a']=i;
    	}

    	int tp=0;
    	int sp=0;
    	int ans=1;
    	while(tp<np){
    		// cout<<tp<<" "<<sp<<endl;
    		if(arr[0][t[tp]-'a']==INT_MAX){
    			ans=-1;
    			sp=0;
    			break;
    		}
    		if(sp==ns || arr[sp][t[tp]-'a']==INT_MAX){
    			sp=0;
    			ans++;
    		}
    		else{
    			sp=arr[sp][t[tp]-'a']+1;
    			tp++;
    		}
    	}
    	// if(sp==ns)ans++;
    	cout<<ans<<endl;
    }
}