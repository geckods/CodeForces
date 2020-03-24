#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

typedef struct node NODE;

struct node{
	int curr;
	NODE* parent;
	NODE* farchild;
    NODE* farparent;
};

NODE* newNode(int x){
	NODE* myNode = (NODE*)malloc(sizeof(NODE));
	myNode->parent = NULL;
	myNode->farchild = myNode;
    myNode->farparent=myNode;
	myNode->curr=x;
	return myNode;
}

NODE* getFarParent(NODE* thisNode){
    if(thisNode->farparent == thisNode){
        return thisNode;
    }

    thisNode->farparent = getFarParent(thisNode->farparent);
    return thisNode->farparent;
}

NODE* getFarChild(NODE* thisNode){
	if(thisNode->farchild == thisNode){
		return thisNode;
	}

	thisNode->farchild = getFarChild(thisNode->farchild);
	return thisNode->farchild;
}

void connect(NODE* B, NODE* A){
//	NODE* Bfarchild = getFarChild(B);
//    cout<<B->curr<<endl;
    A = getFarParent(A);
//    cout<<"HI"<<endl;
	A->parent = getFarChild(B);
    getFarParent(A)->farparent = getFarParent(B);
	getFarChild(B)->farchild = getFarChild(A);
}

int main(){
	#ifndef ONLINE_JUDGE
    	freopen("input", "r", stdin);
    	freopen("output", "w", stdout);
	#endif
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;


    int arr[n-1][2];
    for(int i=0;i<n-1;i++){
    	cin>>arr[i][0]>>arr[i][1];
    }

    NODE* nodearray[n];
    for(int i=0;i<n;i++){
    	nodearray[i]=newNode(i+1);
    }

    for(int i=0;i<n-1;i++){
    	connect(nodearray[arr[i][0]-1],nodearray[arr[i][1]-1]);
    }

    NODE* firstNode = getFarChild(nodearray[0]);

    while(firstNode){
    	cout<<firstNode->curr<<" ";
    	firstNode=firstNode->parent;
    }
}
