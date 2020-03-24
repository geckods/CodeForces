#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool check(int n,int m,int a[],int b[],double fuel){
	double currmass = m+fuel;

	//first take off
	fuel-=(currmass/a[0]);
	currmass = m+fuel;

	for(int i=1;i<n;i++){
		//landing on each planet
		
		if(fuel<=0){
			return false;
		}

		fuel-=(currmass/b[i]);
		currmass=m+fuel;

		if(fuel<=0){
			return false;
		}

		fuel-=(currmass/a[i]);
		currmass=m+fuel;
	}
	if(fuel<=0){
		return false;
	}

	fuel-=(currmass/b[0]);
	currmass=m+fuel;

	if(fuel<=0){
		return false;
	}

	return true;	
}


int main(){
	
	#ifndef ONLINE_JUDGE
    	freopen("input", "r", stdin);
    	freopen("output", "w", stdout);
	#endif
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(17);

    int n,m;
    cin>>n;
    cin>>m;

    int a[n],b[n];
    for(int i=0;i<n;i++){
    	cin>>a[i];
    }

    for(int i=0;i<n;i++){
    	cin>>b[i];
    }

    double min=0;
    double max=pow(10,9)+1;

    double mid=-1;
    double prevmid=-2;

    while(prevmid!=mid){
    	prevmid=mid;
    	mid=(min+max)/2;
    	if(check(n,m,a,b,mid)){
    		max = mid;
    	}
    	else{
    		min = mid;
    	}
    }

    if(mid>pow(10.0,9.0)+0.00001){
    	cout<<-1<<endl;
    }
    else{
		cout<<mid<<endl;
	}
}
