#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> intpair;
#define MOD 998244353

#define endl '\n'
  
ll gcd(ll a, ll b); 
  
ll power(ll x, ll y, ll m); 
  
// Function to find modular inverse of a under modulo m 
// Assumption: m is prime 
ll modInverse(ll a, ll m) 
{ 
    ll g = gcd(a, m); 
    if (g != 1) 
        cout << "Inverse doesn't exist"; 
    else
    { 
        // If a and m are relatively prime, then modulo inverse 
        // is a^(m-2) mode m 
        return power(a, m-2, m); 
    } 
} 
  
// To compute x^y under modulo m 
ll power(ll x, ll y, ll m) 
{ 
    if (y == 0) 
        return 1; 
    ll p = power(x, y/2, m);
    if(p>m)p%=m;
    p = (p * p);
    if(p>m)p%=m;
  
    return (y%2 == 0)? p : (x * p) % m; 
} 
  
// Function to return gcd of a and b 
ll gcd(ll a, ll b) 
{ 
    if (a == 0) 
        return b; 
    return gcd(b%a, a); 
} 


unordered_map<ll,ll> primeFactorsOfFactors(ll n)  
{  
	unordered_map<ll,ll> pfn;
    // cerr<<"HI"<<endl;
    while (n % 2 == 0)  
    {  
    	pfn[2]++;
        n = n/2;  
    }  
  
    for (int i = 3; i*i<=n; i = i + 2)  
    {  
        while (n % i == 0)  
        {  
        	pfn[i]++;
            n = n/i;  
        }  
    }  


    if(n>1)
		pfn[n]++;

	return pfn;
	// for(auto pf:pfn){
	// 	cerr<<pf.first<<" "<<pf.second<<endl;
	// }

	// unordered_map<ll,unordered_map<ll,ll> > wtfMap;
	// wtfMap[1] = unordered_map<ll,ll>();

	// wtfMap[n] = pfn;

	// for(auto pf:pfn){
	// 	// cerr<<pf.first<<" "<<pf.second<<endl;
	// 	ll curr=1;
	// 	unordered_map<ll,unordered_map<ll,ll> > tempMap=wtfMap;
	// 	for(int i=1;i<=pf.second;i++){
	// 		curr*=pf.first;
	// 		//from everything currently in wtfmap, create a new number
	// 		for(auto wtf:tempMap){
	// 			// cerr<<wtf.first<<" "<<curr<<endl;
	// 			wtfMap[wtf.first*curr]=wtfMap[wtf.first];
	// 			wtfMap[wtf.first*curr][pf.first]+=i;
	// 		}
	// 	}
	// }
	// return wtfMap;
}

ll fac[1001];
ll modInvFac[1001];
void preCompFac(){
	fac[0]=fac[1]=1;
	for(int i=2;i<=1000;i++){
		fac[i]=i*fac[i-1];
		fac[i]%=MOD;
	}
}

void preCompModInverse(){
	for(int i=1;i<=1000;i++){
		modInvFac[i]=modInverse(fac[i],MOD);
	}
}

unordered_map<ll,ll> primeFactorize(ll n, vector<ll> factors){
	unordered_map<ll,ll> ans;
	ll facSize=factors.size();
	for(int i=0;i<facSize;i++){
		if(factors[i]==1)continue;
		if(factors[i]>n)break;
		while(n%factors[i]==0){
			n/=factors[i];
			ans[factors[i]]++;
		}
	}
	return ans;
}


int main(){

	#ifndef ONLINE_JUDGE
    	freopen("input", "r", stdin);
    	freopen("output", "w", stdout);
    	freopen("error", "w", stderr);
	#endif
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	ll d;
	cin>>d;

	// cerr<<"HI"<<endl;
    preCompFac();
    preCompModInverse();
	unordered_map<ll,ll> wtfMap=primeFactorsOfFactors(d);
	// for(auto i:wtfMap){
	// 	cerr<<i.first<<endl;
	// 	for(auto j:i.second){
	// 		cerr<<j.first<<" "<<j.second<<endl;
	// 	}
	// }

	vector<ll> factors;
	for(auto i:wtfMap){
		factors.push_back(i.first);
	}

	sort(factors.begin(),factors.end());

	ll q;
	ll u,v;
	cin>>q;

	vector<intpair> myVec;

	while(q--){
		cin>>u>>v;
		myVec.push_back({u,v});
	}

	unordered_map<ll,bool> computedFac;
	unordered_map<ll,unordered_map<ll,ll> > mainFac;
	mainFac[1]=unordered_map<ll,ll>();
	mainFac[d]=wtfMap;
	ll myVecSize=myVec.size();

	for(int i=0;i<myVecSize;i++){

		// ll thegcd=gcd(myVec[i].first,myVec[i].second);
		// myVec[i].first/=thegcd;
		// myVec[i].second/=thegcd;

		if(!computedFac[myVec[i].first]){
			mainFac[myVec[i].first]=primeFactorize(myVec[i].first,factors);
			computedFac[myVec[i].first]=true;
		}

		if(!computedFac[myVec[i].second]){
			mainFac[myVec[i].second]=primeFactorize(myVec[i].second,factors);
			computedFac[myVec[i].second]=true;
		}

	}

	ll ans;
	ll goUpAns;
	ll goDownAns;

	ll lookup1;
	ll lookup2;
	ll upSize,downSize,goUpMult,goDownMult;


	for(int i=0;i<myVecSize;i++){


		u=myVec[i].first;
		v=myVec[i].second;

		// mainFac[u];
		// mainFac[v];

		goUpAns=0;
		goDownAns=0;

		vector<ll> todivideUp;
		vector<ll> todivideDown;

		goUpMult=1;
		goDownMult=1;

		for(auto it:factors){
			lookup1=mainFac[u][it];
			lookup2=mainFac[v][it];

			if(lookup1==lookup2)continue;

			// cerr<<lookup1<<" "<<lookup2<<" "<<it<<endl;

			if(lookup1>lookup2){
				goUpAns+=lookup1-lookup2;
				todivideUp.push_back(lookup1-lookup2);
				goUpMult*=modInvFac[lookup1-lookup2];
				if(goUpMult>MOD)goUpMult%=MOD;
			}
			else if (lookup1<lookup2){
				goDownAns+=lookup2-lookup1;
				todivideDown.push_back(lookup2-lookup1);
				goDownMult*=modInvFac[lookup2-lookup1];
				if(goDownMult>MOD)goDownMult%=MOD;
			}
		}

		goUpAns=fac[goUpAns];
		goDownAns=fac[goDownAns];
		// cerr<<goDownAns<<endl;


		// upSize=todivideUp.size();
		// downSize=todivideDown.size();

		// for(int i=0;i<upSize;i++){
		// 	goUpAns*=modInvFac[todivideUp[i]];
		// 	if(goUpAns>MOD)
		// 		goUpAns%=MOD;
		// }

		// for(int i=0;i<downSize;i++){
		// 	goDownAns*=modInvFac[todivideDown[i]];
		// 	if(goDownAns>MOD)
		// 		goDownAns%=MOD;
		// }

		ans=goUpAns*goDownAns;
		if(ans>MOD)
			ans%=MOD;
		ans*=goUpMult;
		if(ans>MOD)
			ans%=MOD;
		ans*=goDownMult;
		if(ans>MOD)
			ans%=MOD;
		cout<<ans<<endl;
	}

}

