#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define MAXN 200000
ll seenarr[26][MAXN];

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

    int m;
    cin>>m;

    int occurcount[26];
    memset(occurcount,0,sizeof(occurcount));

    for(int i=0;i<n;i++){
    	seenarr[s[i]-'a'][++occurcount[s[i]-'a']]=i+1;
    }

    for(int i=0;i<m;i++){
    	ll ans=0;
    	string t;
    	cin>>t;
	    int thiscount[26];    	
	    memset(thiscount,0,sizeof(thiscount));

	    for(int j=0;j<t.size();j++){
	    	thiscount[t[j]-'a']++;
	    }

	    for(int i=0;i<26;i++){
	    	if(thiscount[i]>0){ 
			    // cerr<<(char)(i+'a')<<thiscount[i]<<endl;
		    	ans=max(ans,seenarr[i][thiscount[i]]);
	    	}
	    }

	    cout<<ans<<endl;
    }
}