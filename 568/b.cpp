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

    int n;
    cin>>n;

    for(int test=0;test<n;test++){
    	string s,t;
    	cin>>s;
    	cin>>t;

    	int slen=s.length();
    	int tlen=t.length();


    	int slast=0;
    	int tlast=0;
    	int spointer=0;
    	int tpointer=0;

    	bool done=false;

    	while(slast<slen && tlast<tlen){
    		spointer=slast;
    		tpointer=tlast;
	    	if(s[slast]!=t[tlast]){
	    		// cout<<"NO"<<endl;
	    		done=true;
	    		break;
	    	}


	    	while(spointer<slen && s[spointer]==s[slast]){
   		 		spointer++;
    		}
    		spointer--;

    		while(tpointer<tlen && t[tpointer]==t[tlast]){
    			tpointer++;
    		}
    		tpointer--;

    		if(spointer-slast > tpointer-tlast){
    			// cout<<"NO"<<endl;
    			done=true;
    			break;
    		}

    		slast=spointer+1;
    		tlast=tpointer+1;
    	}

    	if(slast<slen || tlast<tlen||done){
    		cout<<"NO"<<endl;
    	}
    	else{
    		cout<<"YES"<<endl;
    	}
    }
}