#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

//saw editorial to solve

int main(){
	
	#ifndef ONLINE_JUDGE
    	freopen("input", "r", stdin);
    	freopen("output", "w", stdout);
		freopen("error", "w", stderr);
	#endif
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,k;
    cin>>n>>k;

    int p[n];
    int s[n];
    for(int i=0;i<n;i++){
    	cin>>p[i];
    }

    for(int i=0;i<n;i++){
    	cin>>s[i];
    }

    vector<pair<int,pair<int,int> > > myVec;

    for(int i=0;i<n;i++){
    	pair<int,pair<int,int> > asdf;
    	asdf.first=p[i];
    	asdf.second.first=i;
    	asdf.second.second=s[i];
    	myVec.push_back(asdf);
    }

    sort(myVec.begin(),myVec.end());

    for(int i=0;i<n;i++){
    	s[i]=myVec[i].second.second;
    }

    vector<int> asd;

    ll sums=0;
    ll sumt=0;

    for(int i=0;i<n;i++){
    	sums+=myVec[i].first;
    	sumt+=myVec[i].second.second;
    	if(sums==sumt){
    		// cout<<i<<endl;
    		asd.push_back(i);
    		sums=0;
    		sumt=0;
    	}
    }


    if(asd.size() < k){
    	cout<<"NO"<<endl;
    }
    else{
    	cout<<"YES"<<endl;
    	char arr[n];
    	char currchar = 'a';
    	int lispointer=0;
    	for(int i=0;i<n;i++){
    		arr[myVec[i].second.first]=currchar;
    		if(currchar<'z' && i==asd[lispointer]){
    			currchar++;
    			lispointer++;
    		}

    	}
    	for(int i=0;i<n;i++){
    		cout<<arr[i];
    	}
    	cout<<endl;
    }

}

