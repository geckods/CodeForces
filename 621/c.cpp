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

    string s;
    cin>>s;

    //most common letter or most common letter pair
    ll letters[26];
    ll letpair[26][26];

    memset(letters,0,sizeof(letters));
    for(int i=0;i<26;i++){
    	for(int j=0;j<26;j++){
    		letpair[i][j]=0;
    	}
    }

    int curr;
    for(int i=0;i<s.length();i++){
    	curr=s[i]-'a';
    	for(int j=0;j<26;j++){
    		letpair[j][curr]+=letters[j];
    	}
    	letters[curr]++;
    }

    ll ans=0;
    for(int i=0;i<26;i++){
    	ans=max(ans,letters[i]);
    	for(int j=0;j<26;j++){
    		ans=max(ans,letpair[i][j]);
    	}
    }
    cout<<ans<<endl;
}