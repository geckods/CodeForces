#include <bits/stdc++.h>
using namespace std;

void printthing(int n,char one,char two,char three){
	for(int i=0;i<n;i++){
		if(i%3==0){
			cout<<one;
		}
		if(i%3==1){
			cout<<two;
		}
		if(i%3==2){
			cout<<three;
		}
	}
	cout<<endl;
}

int main(){
	#ifndef ONLINE_JUDGE
    	freopen("input", "r", stdin);
    	freopen("output", "w", stdout);
	#endif

	int n;
	cin>>n;
	string s;
	cin>>s;

	int rgb=0,brg=0,gbr=0,rbg=0,grb=0,bgr=0;

	for(int i=0;i<n;i++){
//		cout<<i<<" "<<s[i]<<endl;
		if(i%3==0){
			if(s[i]!='R'){
				rgb++;
				rbg++;
			}
			if(s[i]!='G'){
				grb++;
				gbr++;
			}
			if(s[i]!='B'){
				brg++;
				bgr++;
			}
		}
		if(i%3==1){
			if(s[i]!='R'){
				grb++;
				brg++;
			}
			if(s[i]!='G'){
				rgb++;
				bgr++;
			}
			if(s[i]!='B'){
				rbg++;
				gbr++;
			}
		}
		if(i%3==2){
			if(s[i]!='R'){
				gbr++;
				bgr++;
			}
			if(s[i]!='G'){
				rbg++;
				brg++;
			}
			if(s[i]!='B'){
				rgb++;
				grb++;
			}
		}
	}

	int arr[6];
	arr[0]=rgb;
	arr[1]=rbg;
	arr[2]=grb;
	arr[3]=gbr;
	arr[4]=bgr;
	arr[5]=brg;

	int min=1000000;
	int ind=-1;
	for(int i=0;i<6;i++){
		if(arr[i]<min){
			min=arr[i];
			ind = i;
		}
	}

	cout<<min<<endl;

	if(ind==0){
		printthing(n,'R','G','B');
	}
	else if(ind==1){
		printthing(n,'R','B','G');
	}
	else if(ind==2){
		printthing(n,'G','R','B');
	}
	else if(ind==3){
		printthing(n,'G','B','R');
	}
	else if(ind==4){
		printthing(n,'B','G','R');
	}
	else if(ind==5){
		printthing(n,'B','R','G');
	}
}
