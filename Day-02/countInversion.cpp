#include <bits/stdc++.h>

long long int merge(long long int* arr, long long int* temp, int start, int mid, int end){
    int i=start; int j=mid+1; int k=start; long long int cnt=0;
    //INTUTION: 
    /* arr[i] will be left sorted half and arr[j] will be right sorted half of original array
       our requirement: element from left half should be greater than right half  */

    while(i<=mid && j<=end){
        if(arr[i]<= arr[j]){
            temp[k]=arr[i];
            k++; i++;
        }
        else if(arr[i] > arr[j]){ // our requirement
            temp[k]=arr[j];
            cnt+= (mid+1-i);  // (MOST IMPORTANT STEP)
            
            //EXPLANATION: 
            /* pairs will be: {(all elements from [i,mid]),(arr[j])}
               Let arr[]={5,2,7,4}. After calling mergeSort on {5,2,7} and {4}, we got 2 5 7 4
               Before merging: 2 5 7 4 be array. sorted leftHalf:[0,2], sorted rightHalf:[3,3]. we need to merge these 2 sorted half
               we can say that in original arr {2,5,7} was on left of {4}. [ofc both half was in unsorted manner].
               Now here i=0, j=3. arr[i] <= arr[j] --> case 1 (if), i++; || now i=1, j=3
               arr[i] >arr[j] (5>4) --> case 2 (else if), so we got 2 pairs {5,4}, {7,4}, so cnt+=2  
            */
            k++; j++;
        }
    }
    while(i<=mid){
        temp[k]=arr[i];
        k++; i++;
    }
    while(j<=end){
        temp[k]=arr[j];
        k++; j++;
    }
    for(int i=start; i<=end; i++){
        arr[i]=temp[i];
    }
    return cnt;
}
long long int mergeSort(long long int* arr, long long int* temp, int start, int end){
    if(start>=end){ return 0; }
    int mid=start+(end-start)/2;  long long int cnt=0;

    int a= mergeSort(arr, temp, start, mid);
    int b= mergeSort(arr, temp, mid+1, end);
    int c= merge(arr, temp, start, mid, end);
    cnt=a+b+c;
    return cnt;
}
long long int getInversions(long long *arr, int n){
    long long int* temp=new long long int[n];
    return mergeSort(arr, temp, 0, n-1);
}


