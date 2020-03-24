#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int conv(string s){
	int a = s[0]-'0';
	char b=s[1];

	if(b=='s'){
		return a;
	}
	else if (b=='m'){
		return 20+a;
	}
	else{
		return 40+a;
	}
}

int main(){
	
	#ifndef ONLINE_JUDGE
    	freopen("input", "r", stdin);
    	freopen("output", "w", stdout);
	#endif
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s1,s2,s3;
    cin>>s1>>s2>>s3;

    int a1,a2,a3;

    a1=conv(s1);
    a2=conv(s2);
    a3=conv(s3);

    vector<int> myVec;
    myVec.push_back(a1);
    myVec.push_back(a2);
    myVec.push_back(a3);

    sort(myVec.begin(),myVec.end());

    int b1,b2,b3;
    b1=myVec[0];
    b2=myVec[1];
    b3=myVec[2];


    // cout<<b1<<" "<<b2<<" "<<b3<<endl;

    if((b1==b2&&b2==b3) || (b2==b1+1 && b3==b2+1)){
    	cout<<0<<endl;
    }
    else if (b1==b2||b2==b3||b2==b1+1||b3==b2+1||b2==b1+2||b3==b2+2){
    	cout<<1<<endl;
    }
    else{
    	cout<<2<<endl;
    }
}