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

    int n,k;
    cin>>n>>k;

    string s;
    cin>>s;

    set<char> ks;

    // string kst;
    // cin>>kst;
    // for(int i=0;i<kst.size();i++){
    	// 
    // }

    char c;

    for(int i=0;i<k;i++){
    	cin>>c;
    	ks.insert(c);
    	// cout<<c<<endl;
    }

    ll ans=0;

    ll i=0,j;
    while(i<n){
    	while(i<n && ks.find(s[i])==ks.end()){
    		i++;
    	}
    	if(i==n)break;
    	// cout<<i<<" "<<j<<" "<<s[i]<<endl;

    	// cout<<i<<" "<<j<<" "<<s[i]<<endl;


    	j=i+1;
    	while(j<n && ks.find(s[j])!=ks.end()){
    		j++;
    	}

    	ans+=((j-i)*(j-i+1))/2;
    	// cout<<i<<" "<<j<<" "<<s[i]<<endl;
    	i=j;
    }
    cout<<ans<<endl;

}