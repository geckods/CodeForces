#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> intpair;

int main(){
	
	#ifndef ONLINE_JUDGE
    	freopen("input", "r", stdin);
    	freopen("output", "w", stdout);
	#endif
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;
    cin>>t;

    for(int test=0;test<t;test++){
    	ll n,s;
    	cin>>n>>s;

    	vector<intpair> myVec;
    	intpair myPair;
    	for(int i=0;i<n;i++){
    		cin>>myPair.first;
    		cin>>myPair.second;
    		myVec.push_back(myPair);
    	}

    	sort(myVec.begin(),myVec.end());

    	ll leftcount=n/2;

    	for(int i=0;i<n;i++){
    		s-=myVec[i].first;
    	}


    	int leftpointer = leftcount-1;
		int rightpointer = leftcount;

		set<intpair> minRQ;

		ll nextlim;
		ll currMed=myVec[rightpointer].first;

		bool done=false;

		minRQ.insert(make_pair(myVec[rightpointer].second,rightpointer));

		while(s>=0){
			nextlim=LLONG_MAX;

			while(rightpointer<n-1 && myVec[rightpointer+1].first==currMed){
				rightpointer++;
				minRQ.insert(make_pair(myVec[rightpointer].second,rightpointer));
			}

			nextlim=min(nextlim,(*minRQ.begin()).first);

			if(rightpointer<n-1){
				nextlim=min(nextlim,myVec[rightpointer+1].first);
			}

			// cerr<<leftpointer<<" "<<rightpointer<<" "<<currMed<<" "<<nextlim<<" "<<s<<endl;			
			// cerr<<"HI"<<endl;

			if((nextlim-currMed)*(rightpointer-leftcount+1) <= s){
				s-=(nextlim-currMed)*(rightpointer-leftcount+1);
				currMed=nextlim;
			}
			else{
				currMed+=(s/(rightpointer-leftcount+1));
				done=true;
				break;
			}

			if(nextlim==(*minRQ.begin()).first){
				while(leftpointer>=0 && myVec[leftpointer].second<=nextlim){
					leftpointer--;
				}

				if(leftpointer<0){
					done=true;
					break;
				}
				else{
					s-=(myVec[(*minRQ.begin()).second].first - myVec[leftpointer].first);
					minRQ.erase(minRQ.begin());
					minRQ.insert(make_pair(myVec[leftpointer].second,leftpointer));
					leftpointer--;
				}
			}
		}
		cout<<currMed<<endl;
    }
}