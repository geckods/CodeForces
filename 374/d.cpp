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

   	/*
   	cases:
   	count the number of negatives (strictly < 0):
   		if odd, greedily increase the smallest numbers by magnitude
   		if even, see if it can be made odd:
   			if it can, then make it odd as quickly as possible and then increase the smallest numbers by magnitude
   			if it cannot, then greedily decrease magnitude of smallest
	*/

	ll n,k,x;
	cin>>n>>k>>x;

	vector<ll> myVec;
	ll z;
	
	ll minPos=INT_MAX;
	ll minPosind=-1;

	ll maxNeg=INT_MIN;
	ll maxNegind=-1;

	ll negcount=0;

	for(int i=0;i<n;i++){
		cin>>z;
		myVec.push_back(z);

		if(z>=0 && z < minPos){
			minPos = z;
			minPosind=i;
		}

		if(z<0 && z > maxNeg){
			maxNeg = z;
			maxNegind=i;
		}

		if(z<0){
			negcount++;
		}
	}


	if(negcount%2==0){
		//need to convert a neg into a pos or a pos into a neg
		ll noforpos = ceil((double)(minPos+1)/x);
		ll noforneg = ceil((double)((-1*maxNeg)+1)/x);

		// cout<<noforneg<<endl;

		if(min(noforpos,noforneg) > k){
			// cout<<"HI"<<endl;
			//not enough moves to make the product negative
			//minimize absolute value of lowest using priority queue

			if(abs(minPos)<abs(maxNeg)){
				myVec[minPosind]-=(k*x);
				k-=k;
			}
			else{
				myVec[maxNegind]+=(k*x);
				k-=k;
			}

			for(int i=0;i<n;i++){
				cout<<myVec[i]<<" ";
			}
			cout<<endl;

			return 0;
		}
		else{
			if(noforpos<noforneg || (noforneg==noforpos && abs(minPos)<abs(maxNeg))){
				myVec[minPosind]-=(noforpos*x);
				k-=noforpos;
			}
			else{
				myVec[maxNegind]+=(noforneg*x);
				k-=noforneg;
			}
		}
	}

	priority_queue<intpair> myPq;
	for(int i=0;i<n;i++){
		myPq.push(make_pair(-1*abs(myVec[i]), i));
	}

	while(k--){
		intpair mypair = myPq.top();
		myPq.pop();

		if(myVec[mypair.second] >=0){
			myVec[mypair.second]+=x;
		}
		else{
			myVec[mypair.second]-=x;
		}

		mypair.first=-1*abs(myVec[mypair.second]);
		myPq.push(mypair);
	}

	for(int i=0;i<n;i++){
		cout<<myVec[i]<<" ";
	}
	cout<<endl;

	//maximize absolute value of smallest in priority queue
}
