#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
	
	#ifndef ONLINE_JUDGE
    	freopen("input", "r", stdin);
    	freopen("output", "w", stdout);
    	freopen("error", "w", stderr);
	#endif
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;

    for(int test=0;test<t;test++){
    	int n;
    	cin>>n;

    	int arr[n];
    	for(int i=0;i<n;i++){
    		cin>>arr[i];
    	}

    	int j=(n-2)/2;
    	while(j>=0 && arr[j]==arr[j+1])j--;

    	vector<int> asd;
    	int i=0;

    	while(i<=j){
    		int k=i;
    		while(k<=j && arr[k]==arr[i])k++;
    		asd.push_back(k-i);
    		i=k;
    	}

    	if(asd.size()<3){
    		cout<<0<<" "<<0<<" "<<0<<endl;
    		continue;
    	}

    	int g=asd[0];
    	
    	i=1;
    	int s=0;
    	while(i<=j && s<=g){
    		s+=asd[i++];
    	}

    	int b = (j+1-g-s);
    	if(g>=b || g>=s){
    		cout<<0<<" "<<0<<" "<<0<<endl;
    	}
    	else{
    		cout<<g<<" "<<s<<" "<<b<<endl;
    	}
    }

}
