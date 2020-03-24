#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}
 
/* This function takes last element as pivot, places
   the pivot element at its correct position in sorted
    array, and places all smaller (smaller than pivot)
   to left of pivot and all greater elements to right
   of pivot */
int partition (int arr[], int low, int high,int otherarr[],int otherarr2[])
{
    int pivot = arr[high];    // pivot
    int i = (low - 1);  // Index of smaller element
 
    for (int j = low; j <= high- 1; j++)
    {
        // If current element is smaller than or
        // equal to pivot
        if (arr[j] <= pivot)
        {
            i++;    // increment index of smaller element
            swap(&arr[i], &arr[j]);
            swap(&otherarr[i], &otherarr[j]);
            swap(&otherarr2[i], &otherarr2[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    swap(&otherarr[i + 1], &otherarr[high]);
    swap(&otherarr2[i + 1], &otherarr2[high]);
    return (i + 1);
}
 
/* The main function that implements QuickSort
 arr[] --> Array to be sorted,
  low  --> Starting index,
  high  --> Ending index */
void quickSort(int arr[], int low, int high,int otherarr[],int otherarr2[])
{
    if (low < high)
    {
        /* pi is partitioning index, arr[p] is now
           at right place */
        int pi = partition(arr, low, high,otherarr,otherarr2);
 
        // Separately sort elements before
        // partition and after partition
        quickSort(arr, low, pi - 1,otherarr,otherarr2);
        quickSort(arr, pi + 1, high,otherarr,otherarr2);
    }
}

int main(){
  int n,m;
  cin>>n;
  cin>>m;

  ll verti[n];
  for(int i=0;i<n;i++){
    cin>>verti[i];
  }

  int hori0[m];
  int hori1[m];
  int hori2[m];

  for(int i=0;i<m;i++){
    cin>>hori0[i];
    cin>>hori1[i];
    cin>>hori2[i];
  }

  sort(verti,verti+n);

  ll nextone=1000000000;

  int endpoint,nextone;
  for(int i=n-1;i>=0;i--){
    nextone = 
    endpoint = hori1[i];  
  while(endpoint<nextone)
#    puts "#{i} #{endpoint} #{nextone}"
    nextone = vertiarr[countver]
    horihash[nextone] = i
    countver+=1
  end
  horihash[vertiarr[countver]] = i+1
end

