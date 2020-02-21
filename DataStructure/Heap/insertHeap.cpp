// Max Heap

#include<bits/stdc++.h>
using namespace std;

typedef struct Heap{
    int *arr;
    int count;
    int capacity;
}Heap;

Heap* newHeap(int cap){
    Heap* h = new Heap;
    h->count=0;
    h->capacity=cap;
    h->arr=new int[h->capacity];
    return h;
}

void heapify(Heap* h,int i){
    int left=2*i+1;
    int right=2*i+2;
    int large=i;

    if(h->arr[left] > h->arr[large] && left < h->count)
        large=left;

    if(h->arr[right] > h->arr[large] && right < h->count)
        large=right;

    if(large!=i){
        int temp = h->arr[i];
        h->arr[i]=h->arr[large];
        h->arr[large] = temp;
        heapify(h,large);
    }
}

void resize(Heap* h){
    int *arr_old = h->arr;

    h->arr = new int[h->capacity*2];

    for(int i=0;i < h->capacity;i++)
        h->arr[i] = arr_old[i];

    h->capacity *=2;

    delete[] arr_old;

}

int findMax(Heap* h){
    if(h==NULL)
        return -1;
    return h->arr[0];
}

void buildHeap(Heap* h,int input[],int n){
    while(h->capacity < n)
        resize(h);
    for(int i=0;i<n;i++)
        h->arr[i] = input[i];
    h->count = n;

    for(int i = (n-1)/2;i>=0;i--)
        heapify(h,i);
}

void print(Heap* h){
    for(int i=0;i<h->count;i++)
        cout<<h->arr[i]<<" ";

    cout<<endl;
}



void destroyHeap(Heap *h){
    if(h==NULL)
        return;
    delete[] h->arr;
    delete h;
}


void insert(Heap* h,int data){
    if(h->capacity == h->count)
        resize(h);

    h->count++;
    int i=h->count-1;

    while(i>0 && data > h->arr[(i-1)/2]){
        h->arr[i] = h->arr[(i-1)/2];
        i=(i-1)/2;
    }

    h->arr[i] = data;
}


int main(){
    int input[] = {18,31,1,2,3,7,8};
    int n=7;
    Heap* h = newHeap(n);

    buildHeap(h,input,n);

    print(h);

    insert(h,43);

    print(h);

    cout<<"Maximum element in the heap " <<findMax(h)<<endl;


    insert(h,-1);

    print(h);


    destroyHeap(h);

}


