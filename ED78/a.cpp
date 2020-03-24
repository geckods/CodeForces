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

    for(int test=0;test<t;test++){
    	string p;
    	cin>>p;
    	string h;
    	cin>>h;

    	int ps = p.size();
    	int hs = h.size();

    	int pcount[26];
    	int hcount[26];
    	memset(pcount,0,sizeof(pcount));

    	for(int i=0;i<ps;i++){
    		pcount[p[i]-'a']++;
    	}

    	bool works=false;
    	for(int i=0;i<=hs-ps;i++){
    		memset(hcount,0,sizeof(hcount));
    		for(int j=0;j<ps;j++){
    			hcount[h[i+j]-'a']++;
    		}

    		works=true;

    		for(int i=0;i<26;i++){
    			if(hcount[i]!=pcount[i]){
    				works=false;
    				break;
    			}
    		}

    		if(works){
    			break;
    		}
    	}

    	if(works){
    		cout<<"YES"<<endl;
    	}
    	else{
    		cout<<"NO"<<endl;
    	}


    }

}
