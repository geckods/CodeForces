#include <bits/stdc++.h>
using namespace std;

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
    	string s,t,p;
    	cin>>s;
    	cin>>t;
    	cin>>p;

    	int scount[26]={0};
    	int tcount[26]={0};
		int pcount[26]={0};

		for(int i=0;i<s.length();i++){
			scount[s[i]-'a']++;
		}

		for(int i=0;i<t.length();i++){
			tcount[t[i]-'a']++;
		}

		for(int i=0;i<p.length();i++){
			pcount[p[i]-'a']++;
		}

		bool done=false;
		for(int i=0;i<26;i++){
			if(pcount[i]+scount[i]<tcount[i]){
				cout<<"NO"<<endl;
				done=true;
				break;
			}
		}	

		if(done) continue;

		int spoint=0;
		int tpoint=0;

		while(tpoint<t.length()){
			if(s[spoint]==t[tpoint]){
				spoint++;
			}
			tpoint++;
		}

		if(spoint<s.length()){
			cout<<"NO"<<endl;
		}
		else{
			cout<<"YES"<<endl;
		}

    }
}