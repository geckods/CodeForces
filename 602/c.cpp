#include <bits/stdc++.h>
using namespace std;

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
    	int n,k;
    	cin>>n>>k;

    	string s;
    	cin>>s;

    	//if k==n/2, then every alternate position would be good - 1,3,5
    	//let's make it such that the first k odd positions are good and the last one is good

    	string final;
    	for(int i=0;i<n;i++){
    		if(i<=2*(k-2)+1){
    			if(i%2==0){
    				final.push_back('(');
    			}
    			else{
    				final.push_back(')');    				
    			}
    		}
    		else{
    			if(i<=2*(k-2)+1 + (n-(2*(k-2)+1))/2){
    				final.push_back('(');
    			}
    			else{
    				final.push_back(')');    				
    			}
    		}
    	}

    	vector<pair<int,int> > ansVec;

    	char copy[n];

    	for(int i=0;i<n;i++){
    		if(s[i]!=final[i]){
    			int j=i+1;
    			while(s[j]!=final[i])j++;
    			ansVec.push_back(make_pair(i+1,j+1));

    			// cout<<s<<endl;

    			for(int k=i;k<=j;k++){
    				copy[k-i]=s[k];
    			}

    			for(int k=i;k<=j;k++){
    				s[k]=copy[j-k];
    			}

    			// cout<<s<<endl;


    		}
    	}

    	cout<<ansVec.size()<<endl;
    	for(int i=0;i<ansVec.size();i++){
    		cout<<ansVec[i].first<<" "<<ansVec[i].second<<endl;
    	}

    }
}