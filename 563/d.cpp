#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){

    // #ifndef ONLINE_JUDGE
    //     freopen("input", "r", stdin);
    //     freopen("output", "w", stdout);
    // #endif
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);

    int n;
    int x;
    // cin>>n>>x;

    n = 18;
    x = 10;

    set<int> cannot;
    queue<int> ans;

    cannot.insert(0);
    cannot.insert(x);

    int max = pow(2,n);

    int currcum=0;

	bool done = false;
	int currlim=1;
    while(!done){
    	done = true;
	    for(int i=currlim;i<max;i++){
    		int newcum = currcum^i;
    		if(cannot.find(newcum)==cannot.end()){
    			ans.push(i);
    			cannot.insert(newcum);
    			cannot.insert(newcum^x);
    			currcum=newcum;
    			done = false;
    		}
    		currlim=i;
    	}

    	if(done){
    		currlim=1;
	    	for(int i=currlim;i<max;i++){
    			int newcum = currcum^i;
    			if(cannot.find(newcum)==cannot.end()){
    				done = false;
    				break;
    			}
    		}
    	}

    }

    cout<<ans.size()<<endl;

    while(ans.size()>0){
    	cout<<ans.front()<<" ";
    	ans.pop();
    }
    cout<<endl;
}