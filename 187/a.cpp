#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// THINGS TO REMEMBER
// ENDL is slow, '\n' is fast
// Clear everything (including graphs) between test cases
// use anti-anti-hash: https://codeforces.com/blog/entry/62393
// pb-ds: https://codeforces.com/blog/entry/11080
// check when to use LLONG_MAX/LLONG_MIN vs INT_MAX or INT_MIN
// You frequently suffer from confirmation bias - you trust your initial solution and miss simple things. 
// When you hit a roadblock, remember to rethink the solution ground up, not just try hacky fixes

int main(){
	
	#ifndef ONLINE_JUDGE
    	freopen("input", "r", stdin);
    	freopen("output", "w", stdout);
    	freopen("error", "w", stderr);
	#endif
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll b,d;
    cin>>b>>d;
    string a,c;
    cin>>a>>c;

    ll alen = a.length();
    ll clen = c.length();

    ll nextChar[alen][26];
    for(int i=0;i<alen;i++){
    	for(int j=0;j<26;j++){
    		nextChar[i][j]=-1;
    	}
    }

    nextChar[alen-1][a[alen-1]-'a']=alen-1;

    for(int i=alen-2;i>=0;i--){
    	for(int j=0;j<26;j++){
    		nextChar[i][j]=nextChar[i+1][j];
    	}
	    nextChar[i][a[i]-'a']=i;
    }

    for(int i=0;i<alen;i++){
    	for(int j=0;j<26;j++){
    		if(nextChar[i][j]==-1){
    			nextChar[i][j]=nextChar[0][j];
    		}
    	}
    }

    ll ap=0;
    ll cp=0;

    ll nap;
    ll oap;

    ll numIterA=0;
    ll numIterC=0;

    ll firstUse = nextChar[0][c[0]-'a'];

    map<intpair,intpair> myMap;

    while(1){
    	nap = nextChar[ap][c[cp]-'a'];

    	if(cp == 0){
    		cerr<<ap<<" "<<nap<<" "<<firstUse<<endl;
    	}
    	// cerr<<ap<<" "<<nap<<" "<<cp<<endl;


    	if(nap==-1){
    		cout<<0<<endl;
    		return 0;
    	}

    	oap = ap;
    	ap = (nap+1)%alen;
    	if(ap<=oap)numIterA++;


    	cp++;
    	if(cp==clen){
    		cp=0;
    		numIterC++;
    	}

    	if(cp == 0 && nextChar[ap][c[0]-'a']==firstUse){
    		if(ap >= nextChar[ap][c[0]-'a'])
	    		numIterA++;
    		break;
    	}
    }

    // cout<<numIterA<<" "<<numIterC<<endl;

    ll ans = ((b/numIterA)*numIterC)/d;
    b%=numIterA;

    if(b==0){
    	cout<<ans<<endl;
    	return 0;
    }

    ap = nap = oap = cp = 0;
    numIterC = numIterA = 0;

    while(1){
    	nap = nextChar[ap][c[cp]-'a'];
    	// cerr<<ap<<" "<<nap<<" "<<cp<<endl;

    	// cerr<<numIterA<<" "<<b<<endl;

    	if(nap==-1){
    		cout<<0<<endl;
    		return 0;
    	}

    	oap = ap;
    	ap = (nap+1)%alen;
    	if(ap<=oap)numIterA++;

    	if(numIterA==b){
    		ans+=numIterC/d;
    		break;
    	}

    	cp++;
    	if(cp==clen){
    		cp=0;
    		numIterC++;
    	}

    }


    // cout<<numIterA<<" "<<numIterC<<endl;

    cout<<ans<<endl;

}
