#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


//I faced a fuckload of errors
//Moral: don't delete from a set while iterating through it
//Also I missed a fuckload of corner cases : <=, ones, twos, etc

bool checkprime(int a){
	if(a==1){
		return false;
	}
	if(a==2){
		return true;
	}
	for(int i=2;i<ceil(sqrt(a));i++){
		if(a%i==0){
			return false;
		}
	}
	return true;
}


int main(){
	
	// #ifndef ONLINE_JUDGE
 //    	freopen("input", "r", stdin);
 //    	freopen("output", "w", stdout);
	// #endif
	// ios_base::sync_with_stdio(false);
 //    cin.tie(NULL);

    int n;
    cin>>n;

    int arr[n][2];
    for(int i=0;i<n;i++){
    	cin>>arr[i][0]>>arr[i][1];
    }

    set<int> solutions;

    for(int i=2;i<=ceil(sqrt(arr[0][0]));i++){
    	if(arr[0][0]%i==0){
    		if (checkprime(i)) solutions.insert(i);
    		if (checkprime(arr[0][0]/i)) solutions.insert(arr[0][0]/i);
    	}
    }

    for(int i=2;i<=ceil(sqrt(arr[0][1]));i++){
    	if(arr[0][1]%i==0){
    		if (checkprime(i)) solutions.insert(i);
    		if (checkprime(arr[0][1]/i)) solutions.insert(arr[0][1]/i);
    	}
    }

    if(checkprime(arr[0][0])) solutions.insert(arr[0][0]);
    if(checkprime(arr[0][1])) solutions.insert(arr[0][1]);

    for(int i=1;i<n;i++){
    	if(solutions.empty()) break;
    	set<int> newsolutions;
    	for(auto j = solutions.begin();j!=solutions.end();j++){
    		if((arr[i][0]%(*j)==0 || arr[i][1]%(*j)==0)){
    			newsolutions.insert(*j);
    		}
    	}
    	solutions=newsolutions;
    }

    if(solutions.empty()){
    	cout<<-1<<endl;
    }
    else{
    	cout<<*(solutions.begin())<<endl;
    }
}