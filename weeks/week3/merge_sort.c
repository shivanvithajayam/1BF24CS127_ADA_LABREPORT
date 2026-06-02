#include<stdio.h>
#include<time.h>
#include<stdlib.h>
void merge(int beg,int mid,int end,int a[]){
    int n1=mid-beg+1;
    int n2=end-mid;
    int a1[n1],a2[n2];
    for(int i=0;i<n1;i++){
        a1[i]=a[beg+i];
    }
    for(int j=0;j<n2;j++){
        a2[j]=a[mid+1+j];
    }
    int i=0;
    int j=0;
    int k=beg;
    while(i<n1 && j<n2){
        if(a1[i]<=a2[j]){
            a[k]=a1[i];
            i++;
        }
        else{
            a[k]=a2[j];
            j++;
        }
        k++;
    }
    while(i<n1){
        a[k]=a1[i];
        i++;
        k++;
    }
    while(j<n2){
        a[k]=a2[j];
        j++;
        k++;
    }

}
void merge_sort(int beg,int end,int a[]){
    if(beg<end){
        int mid=(beg+end)/2;
        merge_sort(beg,mid,a);
        merge_sort(mid+1,end,a);
        merge(beg,mid,end,a);
    }  
}
int main(){
    int a[25000];
    srand(time(0));

    for (int i = 0; i < 25000; i++) {
        a[i] = rand()%25000;  
    }
    clock_t start=clock();
    merge_sort(0,24999,a);
    clock_t end=clock();
    printf("time taken  to execute in ms is %f\n ",(double)(end-start)*1000.0/CLOCKS_PER_SEC);
    for(int i=0;i<10;i++){
        printf("%d\t",a[i]);
    }

}
