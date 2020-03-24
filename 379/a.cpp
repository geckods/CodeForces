#include <bits/stdc++.h>
using namespace std;

int main(){
	
	#ifndef ONLINE_JUDGE
    	freopen("input", "r", stdin);
    	freopen("output", "w", stdout);
	#endif

    int n;
    cin>>n;
 	string s;
 	cin>>s;
 	int a=0;

 	for(int i=0;i<n;i++){
 		if(s[i]=='A') a++;
 	}   

 	if(a>n/2){
 		cout<<"Anton"<<endl;
 	}
 	else if (a<n/2){
 		cout<<"Danik"<<endl;
 	}
 	else{
 		if (n%2==0){
 			cout<<"Friendship"<<endl;
 		}
 		else{
 			cout<<"Danik"<<endl;
 		}
 	}
}
