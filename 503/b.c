#include <stdio.h>

int main(){
  int n;
  scanf("%d",&n);

  int parr[n];

  for(int i=0;i<n;i++){
    scanf("%d",&parr[i]);
    getchar();
  }

  int bitarr[n];
  int ansarr[n];
  int ind=0;

  for(int i=0;i<n;i++){
    ind = i;
    for(int j=0;j<n;j++){
      bitarr[j] = 0;
    }

    while(1){
 
//      printf("%d---", ind);
      if(!bitarr[ind]){
        bitarr[ind] = 1;
      }
      else{
        ansarr[i] = ind+1;
        break;
      }

      ind = parr[ind]-1;
    }
//    putchar('\n');
  }

  //putchar('\n');
  for(int i=0;i<n;i++){
    printf("%d ",ansarr[i]);
  }
  putchar('\n');
}

    
