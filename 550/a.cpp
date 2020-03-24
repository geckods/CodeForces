#include <bits/stdc++.h>
using namespace std;

int main(){
	
	#ifndef ONLINE_JUDGE
    	freopen("input", "r", stdin);
    	freopen("output", "w", stdout);
	#endif
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;

    string s;

    int min,max;

    int count[256];
    bool recur;

    for(int i=0;i<n;i++){
    	recur=false;
    	for(int j=0;j<256;j++){
    		count[j]=0;
    	}

    	cin>>s;
    	min = 'z'+1;
    	max = 'a'-1;

 		for(int j=0;j<s.length();j++){
 			if(s[j]>max)max=s[j];
 			if(s[j]<min)min=s[j];
 			count[s[j]]++;
 		}

 		for(int j=0;j<256;j++){
 			if(count[j]>1){
 				recur=true;
 				break;
 			}
 		}

 		if(!recur && max-min+1 == s.length()){
 			cout<<"Yes"<<endl;
 		}
 		else{
 			cout<<"No"<<endl;
 		}
    }
}