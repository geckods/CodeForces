#include <bits/stdc++.h>
using namespace std;

int main(){
	
	#ifndef ONLINE_JUDGE
    	freopen("input", "r", stdin);
    	freopen("output", "w", stdout);
	#endif

    int n,k;
    int d,m;
    cin>>n>>k;
    int initk = k;
    int arr[n];
    for(int i=0;i<n;i++){
    	cin>>arr[i];
    }

    int testno=0;
    int time=0;

    set<int> finishingtimes;
    set<int> goodsols;

    while(testno<n || k<initk){

    	if(finishingtimes.find(time)!=finishingtimes.end()){
    		k++;
    	}

    	if(k>0 && testno<n){
    		k--;
    		finishingtimes.insert(time+arr[testno++]);
    	}

    	m=testno-(initk-k);
    	d=floor(100*((double)m/n)+0.5);

    	if(d>=m && d<testno){
    		goodsols.insert(d);
    	}

//    	cout<<d<<endl;
    	time++;
    }
    cout<<goodsols.size()<<endl;
}