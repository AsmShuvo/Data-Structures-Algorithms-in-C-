#include<bits/stdc++.h>
using namespace std;

int partition(int a[], int st, int en){
    // pivot is the last element and idx is initially st-1
    int pivot = a[en], idx = st-1;
    for(int i = st; i<en; i++){ //O(n)
        if(a[i]<=pivot){
            idx++;
            swap(a[idx], a[i]);
        }
    }
    idx++;
    swap(a[idx], a[en]);

    return idx;
}

void quicksort(int a[], int st, int en){
    if(st<en){
        int pv_idx = partition(a, st, en); //logn 
        quicksort(a, st, pv_idx-1);
        quicksort(a, pv_idx+1, en);
    }
}

int main(){
    int a[] = {5,3,5,2,4,2,6,3};
    quicksort(a,0,7);
    for(int i=0; i<7; i++) cout<<a[i]<<" ";

}
/*
Time:
 Avg/best: O(nLogn)
 Worst Case:Already sorted O(n^2)
Space complexity:
 O(1)

Interview Ques (***)
 Priority: if lower space: quick sort
 else if priority is time: merge sort

*/