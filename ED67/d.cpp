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

    int t;
    cin>>t;

    for(int test=0;test<t;test++){
    	int n;
    	cin>>n;
    	int a[n];
    	int b[n];

    	int acopy[n];
    	int bcopy[n];

    	for(int i=0;i<n;i++){
    		cin>>a[i];
    		acopy[i]=a[i];
    	}

    	for(int i=0;i<n;i++){
    		cin>>b[i];
    		bcopy[i]=b[i];
    	}

    	sort(acopy,acopy+n);
    	sort(bcopy,bcopy+n);
    	bool done=false;

    	for(int i=0;i<n;i++){
    		if(acopy[i]!=bcopy[i]){
    			cout<<"NO"<<endl;
    			done=true;
    			break;
    		}
    	}

    	if(done){
    		continue;
    	}


    	int seen[n+1];

    	for(int i=0;i<=n;i++){
    		seen[i]=0;
    	}

    	int bpointer=0;
    	int apointer=0;

    	bool myseen[n];

    	priority_queue<int,vector<int>,greater<int> > myPQ;

    	while(bpointer<n){
    		// cout<<my
    		cout<<apointer<<" "<<bpointer<<" "<<myPQ.size();
    		if(!myPQ.empty()){
    			cout<<myPQ.top()<<" ";
    		}
    		cout<<endl;
    		if(seen[b[bpointer]]==0){

    			while(a[apointer]!=b[bpointer]){
    				seen[a[apointer]]++;
    				myPQ.push(a[apointer]);
    				apointer++;
    				if(apointer>=n){
    					cout<<"NO"<<endl;
    					done=true;
    					break;
    				}
    			}

    			if(done) break;
    			seen[a[apointer]]++;
    			myPQ.push(a[apointer]);
    			apointer++;
	    		

    			// for(int i=0;i<n;i++){
    			// 	cout<<a[i]<<" ";
    			// }
    			// cout<<endl;

	    		// cout<<bpointer<<" "<<apointer<<endl;

    			// sort(a+bpointer,a+apointer+1);
    			
    			// for(int i=0;i<n;i++){
    			// 	cout<<a[i]<<" ";
    			// }
    			// cout<<endl;

    			if(myPQ.top()!=b[bpointer]){
    				// cout<<myPQ.top()<<" "<<apointer<<" "<<bpointer<<endl;
    				cout<<"NO"<<endl;
    				done=true;
    				break;
    			}
    			myPQ.pop();

    			seen[b[bpointer]]--;
    		}
    		else{
    			if(myPQ.top()!=b[bpointer]){
	    			cout<<"NO"<<endl;
    				done=true;
    				break;    			
    			}
    			myPQ.pop();
    			seen[b[bpointer]]--;
    		}
    		bpointer++;
    		if(bpointer>apointer)apointer=bpointer;
    	}

    	if(done){
    		continue;
    	}
    	cout<<"YES"<<endl;
    }
}