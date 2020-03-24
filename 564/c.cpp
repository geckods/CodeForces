#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


// bool check(int n, int hand[], int queue, int mid){
// 	int status[n];//status stores the initial position in queue of numbers
// 	for(int i=0;i<n;i++){
// 		status[i]=-1;//not in queue
// 	}
// 	for(int i=0;i<n;i++){
// 		if(queue[i]!=-1){
// 			status[queue[i]]=i;
// 		}
// 	}

// 	// int* currPointer = queue;
// 	// int stepcount=0;

// 	// for(int i=0;i<mid;i++){
// 		// status[*currPointer]=-1;
// 		// currPointer+=mid;
// 		// stepcount+;
// 	// }


// 	for(int i=0;i<n;i++){
// 		status[i]
// 	}

// }

// int binarySearch(int n, int hand[], int queue[], int queuecount){

// 	int low=0;
// 	int high=queuecount;

// 	while(low<=high){
// 		int mid = (low+high)/2;
// 		if(check(n,hand,queue,mid)){//it can be done by removing mid elements
// 			high = mid;
// 		}
// 		else{
// 			low = mid+1;
// 		}
// 	}
// }

int main(){

	#ifndef ONLINE_JUDGE
    	freopen("input", "r", stdin);
    	freopen("output", "w", stdout);
	#endif
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);



    //gotta be a binary search 
    //on the number of non-zeroes you pop 
    //before you start putting things inside

    int n;
    cin>>n;



    int hand[n];
    for(int i=0;i<n;i++){
    	cin>>hand[i];
    	hand[i]--;
    }

    int queue[n];
    int queuecount=0;
    for(int i=0;i<n;i++){
    	cin>>queue[i];
    	queue[i]--;
    	if(queue[i]>=0) queuecount++;
    }

    int status[n];//status stores the initial position in queue of numbers
 	for(int i=0;i<n;i++){
 		status[i]=-1;//not in queue
	}
	for(int i=0;i<n;i++){
		if(queue[i]!=-1){
			status[queue[i]]=i;
		}
	}



    // if you're going to do it in n+k moves, then all you gotta do is check that you get the ith element in hand in less than i pops i.e 0th element in 0 pops
	// if you're going to do it in less than n moves, check the back, and check that you get elements in 

	int upperans=0;
	for(int i=0;i<n;i++){
		if(queue[i]>=0){
			upperans = max(upperans,i-queue[i]+1);
		}
	}

	// cout<<upperans+n<<endl;
	upperans+=n;//this is worst case
	// now just simulate

	int i=0;
	while(i<n && queue[i]!=0)i++;
	if(i==n){//we are done, upperans
		cout<<upperans<<endl;
		return 0;
	}
	else{
		int j;
		for(j=i;j<n;j++){
			if(!(queue[j]==j-i)){
				//we are done, upperans
				cout<<upperans<<endl;
				return 0;
			}
		}
		int lastalreadyin = queue[n-1];
		int nextone = lastalreadyin+1;
		for(int z=nextone;z<n;z++){
			if(status[z]+1 > z-nextone){
				//we are done,upperans
				cout<<upperans<<endl;
				return 0;
			}
		}
		cout<<n-lastalreadyin-1<<endl;
	}


}