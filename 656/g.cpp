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

#define MAXN 200001
ll a[MAXN];
ll b[MAXN];
ll pos[MAXN][2];
bool seenInOne[MAXN];
bool toFlip[MAXN];

int main(){
	
	#ifndef ONLINE_JUDGE
    	freopen("input", "r", stdin);
    	freopen("output", "w", stdout);
    	freopen("error", "w", stderr);
	#endif
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;
    cin>>t;

    while(t--){
    	ll n;
    	cin>>n;

    	for(int i=0;i<n;i++){
			pos[i][0]=pos[i][1]=-1;
			seenInOne[i]=false;
			toFlip[i]=false;
    	}

    	for(int i=0;i<n;i++){
    		cin>>a[i];
    		a[i]--;
    		if(pos[a[i]][0]==-1){
    			pos[a[i]][0]=i;
    		}
    		else{
    			pos[a[i]][1]=i;    			
    		}
    	}

    	for(int i=0;i<n;i++){
    		cin>>b[i];
    		b[i]--;
    		if(pos[b[i]][0]==-1){
    			pos[b[i]][0]=i;
    		}
    		else{
    			pos[b[i]][1]=i;    			
    		}
    	}

    	bool works=true;
    	for(int i=0;i<n;i++){
    		if(pos[i][0]==-1 || pos[i][1]==-1){
    			works=false;
    			break;
    		}
    	}
    	if(!works){
    		cout<<-1<<endl;
    		continue;
    	}


    	ll firstUnseenPointer = 0;
    	while(firstUnseenPointer<n){
    		ll curr = firstUnseenPointer;

    		while(1){
    			seenInOne[curr]=true;
	    		ll currPos = pos[curr][0];
				// cerr<<"HI"<<curr<<" "<<currPos<<endl;
	    		if(a[currPos]==b[currPos]){
	    			break;
	    		}

	    		ll other;

	    		if(a[currPos]==curr){
	    			other = b[currPos];
	    			if(seenInOne[other])break;
	    			curr = other;
	    		}
				else{
	    			other = a[currPos]; 
	    			if(!seenInOne[other]){
	    				toFlip[currPos]=true;
	    				a[currPos]=curr;
	    				b[currPos]=other;
	    				curr = other;
	    			}
	    			else {
	    				currPos = pos[curr][1];
			    		if(a[currPos]==curr){
			    			other = b[currPos];
			    			if(seenInOne[other])break;
			    			curr = other;
			    		}
			    		else{
			    			other = a[currPos];
		    				toFlip[currPos]=true;
		    				a[currPos]=curr;
		    				b[currPos]=other;
		    				curr = other;
			    		}

	    			}
	    		}

    		}

    		while(firstUnseenPointer<n && seenInOne[firstUnseenPointer])firstUnseenPointer++;
    	}

    	ll c = 0;
    	for(int i=0;i<n;i++){
    		if(toFlip[i])c++;
    	}

		// cout<<min(ans.size(),(int)n-ans.size())<<endl;
    	// cout<<"CASE"<<" "<<t<<endl;
		if(c<n-c){
			cout<<c<<endl;
			for(int i=0;i<n;i++){
				if(toFlip[i])
					cout<<i+1<<" ";
			}
			cout<<endl;
		}
		else{
			cout<<n-c<<endl;

			for(int i=0;i<n;i++){
				if(!toFlip[i]){
					cout<<i+1<<" ";
				}
			}
			cout<<endl;

		}

    }
}
