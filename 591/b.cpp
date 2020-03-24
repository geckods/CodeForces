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

    int q;
    cin>>q;

    for(int quer=0;quer<q;quer++){
    	string s,t;
    	cin>>s;
    	cin>>t;

    	bool shas[26];
    	bool thas[26];

    	for(int i=0;i<26;i++){
    		shas[i]=thas[i]=false;
    	}

    	for(int i=0;i<s.length();i++){
    		shas[s[i]-'a']=true;
    		thas[t[i]-'a']=true;
    	}

    	bool done=false;
    	for(int i=0;i<26;i++){
    		if(shas[i]&&thas[i]){
    			cout<<"YES"<<endl;
    			done=true;
    			break;
    		}
    	}

    	if(!done){
    		cout<<"NO"<<endl;
    	}
    }
}