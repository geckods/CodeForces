#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<double, ll> pi;

/*I was on the right track for this problem, just couldn't make it airtight in time*/
//https://codeforces.com/contest/1132/problem/D

int notposs=0;
//Idea - use a priority queue of pairs, iterate through the timesteps. If at any point you reach a negative charge then break
int evalthe(ll* a, ll *b, ll n,ll k,ll charge){
		priority_queue<pi, vector<pi>, greater<pi> > pq;

		ll c[n];
		for(int i=0;i<n;i++){
			c[i]=0;
		}

		for(int i=0;i<n;i++){
			pq.push(make_pair((double)a[i]/b[i],i));
		}

		int done=1;

		pi top;
		pi newpair;

//		cout<<pq.top().first<<endl;
//		pq.pop();
//		cout<<pq.top().first<<endl;
//		return 0;
		for(int i=1;i<k;i++){
			top = pq.top();
			pq.pop();
//			cout<<i*b[top.second]<<"  "<<top.first - i*b[top.second] + charge<<endl;
			if(a[top.second] + charge*c[top.second] - i*b[top.second] + charge < 0){
				done=0;
				break;
			}
			c[top.second]++;

			pq.push(make_pair((double)(a[top.second])/b[top.second],top.second));
//			cout<<pq.top().first<<endl;
		}
/*
	cout<<charge<<" "<<pq.size()<<endl;
	while(!pq.empty()){
		cout<<pq.top().first<<" "<<pq.top().second<<endl;
		pq.pop();
	}
	cout<<endl;
*/


//	if(pq.top().first - (k-1)*b[pq.top().second]<0){
//		done=0;
//	}

	return done;
}

int main(){
	
	#ifndef ONLINE_JUDGE
    	freopen("input", "r", stdin);
    	freopen("output", "w", stdout);
	#endif

	ll n,k;
	cin>>n>>k;
	ll a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}

	ll b[n];
	for(int i=0;i<n;i++){
		cin>>b[i];
	}

	ll mincharge=0;
	ll maxcharge=1000000000000000;
	ll prevcharge=-1;
	ll midcharge=(mincharge+maxcharge)/2;
	int done;

	while(midcharge!=prevcharge){
		done = evalthe(a, b, n, k, midcharge);

//		cout<<midcharge<<" "<<done<<endl;

		if(done){
			maxcharge=midcharge;
		}
		else{
			mincharge=midcharge+1;
		}
		prevcharge=midcharge;
		midcharge=(mincharge+maxcharge)/2;
	}

	if(midcharge!=999999999999999 && !notposs){
		if(evalthe(a, b, n, k, midcharge))
			cout<<midcharge<<endl;
		else{
			cout<<midcharge+1<<endl;
		}
	}

	if(notposs){
		cout<<-1<<endl;
	}

}