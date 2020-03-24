#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll gcd(ll a, ll b) 
{ 
    if (b == 0) 
        return a; 
    return gcd(b, a % b);  
} 

ll bestdepth;
ll bestcount;

void givedepth(vector<ll> myVec, vector<bool> asd, int currdepth){
	int evecount=0;
	int oddcount=0;
	int alreadydeleted=0;
	for(int i=0;i<myVec.size();i++){
		if(asd[i]){
			if(myVec[i]%2==0){
				evecount++;
			}
			else{
				oddcount++;
			}
		}
		else{
			alreadydeleted++;
		}
	}


	if(alreadydeleted==myVec.size())return;

	if(alreadydeleted+evecount<bestcount){
		bestcount=alreadydeleted+evecount;
		bestdepth=currdepth;
	}

	// cout<<evecount<<" "<<oddcount<<" "<<alreadydeleted<<" "<<bestcount<<" "<<bestdepth<<endl;


	vector<ll> newVec;
	for(int i=0;i<myVec.size();i++){
		if(asd[i]){
			if(myVec[i]%2==0){
				myVec[i]/=2;
			}
			else{
				asd[i]=false;
			}
		}
	}

	givedepth(myVec,asd,currdepth+1);
}


int main(){

	#ifndef ONLINE_JUDGE
    	freopen("input", "r", stdin);
    	freopen("output", "w", stdout);
	#endif
	ios_base::sync_with_stdio(false);
   	cin.tie(NULL);

   	bestdepth=-1;
   	bestcount=INT_MAX;

   	ll n;
   	cin>>n;

   	vector<ll> myVec;
   	for(int i=0;i<n;i++){
   		ll x;
   		cin>>x;
   		myVec.push_back(x);
   	}

   	vector<bool> boolVec;
   	for(int i=0;i<n;i++){
   		boolVec.push_back(true);
   	}

   	givedepth(myVec,boolVec,0);

   	ll a=1;
   	for(int i=0;i<bestdepth;i++){
   		a*=2;
   	}

   	int ans=0;
   	vector<ll> ansVec;
   	for(int i=0;i<n;i++){
   		if(myVec[i]%a!=0 || (myVec[i]/a)%2==0){
   			ans++;
   			ansVec.push_back(myVec[i]);
   		}
   	}


   	cout<<ans<<endl;
   	for(int i=0;i<ansVec.size();i++){
   		cout<<ansVec[i]<<" ";
   	}
   	cout<<endl;
}

