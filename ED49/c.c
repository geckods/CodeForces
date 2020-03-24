#include <stdio.h>
#include <vector>
#include <float.h>
using namespace std;

int main(){

  int t;
  scanf("%d",&t);

  int n;
  
  int arr[n];
  int countarr[10001];
  vector<int> newarr;
  int doublecount=0;
  int doneflag = 0;
  int ind=0;

  double min = DBL_MAX;
  int minind=0;
  double ratio;

  auto begn = newarr.begin();

  for(int q=0;q<t;q++){

    ind = 0;
    doublecount = doneflag = 0;
    scanf("%d",&n);
    getchar();
    newarr.clear();

    for(int i=0;i<10001;i++){
      countarr[i]=0;
    }

    for(int i=0;i<n;i++){
      scanf("%d",&arr[i]);
      getchar();
 
      if(doneflag) continue;

      countarr[arr[i]]++;

      if (countarr[arr[i]]==2){
        for(int j=0;j<doublecount;j++){
          if (newarr[j]<arr[i]){
            ind = j;
            break;
          }
        }
        newarr.insert(begn+ind,arr[i]);
        doublecount++;
      }
      else if (countarr[arr[i]]==4){
        doneflag = arr[i];
      }     
    }

    if (doneflag){
      printf("%d %d %d %d",doneflag,doneflag,doneflag,doneflag);
      continue;
    }

    min = DBL_MAX;
    minind=0;

    for(int i=0;i<doublecount-1;i++){ 
      ratio = (newarr[i]/newarr[i+1])-1;
      if (ratio<min){
        min = ratio;
        minind = i;
      }
    }

    printf("%d %d %d %d",newarr[minind],newarr[minind],newarr[minind+1],newarr[minind+1]);
  }
}
