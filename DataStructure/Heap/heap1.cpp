//  Max Heap
#include<bits/stdc++.h>
using namespace std;

typedef struct Heap{
    int* arr;
    int count;
    int capacity;
}Heap;

Heap* newHeap(int cap){
    Heap* h = new Heap;   // you may add memory exception ... if (h == NULL)
    h->count=0;
    h->capacity=cap;
    h->arr = new int[h->capacity];  // you may add memory exception ... if (h->arr == NULL)
    return h;
}

int parent(Heap* h,int i){
    if(i<=0 || i>=h->count)
        return -1;
    return (i-1)/2;
}

int leftChild(Heap* h,int i){
    if(i>=h->count)
        return -1;
    return (2*i+1);
}

int rightChild(Heap* h,int i){
    if(i>=h->count)
        return -1;
    return (2*i+2);
}

// for max heap h->arr[0] is the maximum element

int findMax(Heap* h){
    if(h->count==0)
        return -1;
    return h->arr[0];
}

// percolateDown() or heapify() //

int heapify(Heap* h,int i){
    int l = 2*i+1;
    int r = 2*i+2;
    int large=i;

    if(h->arr[l] > h->arr[i] && l < h->count)
        large=l;
    if(h->arr[r] > h->arr[large] && r < h->count)
        large=r;

    if(large!=i){
        int temp = h->arr[i];
        h->arr[i]=h->arr[large];
        h->arr[large]=temp;
        heapify(h,large);
    }

}

// resize()  // latter do it

void resize(Heap* h){
    int *arr_old = h->arr;

    h->arr = new int[h->capacity*2];

    for(int i=0;i<h->capacity;i++)
        h->arr[i]=arr_old[i];
    h->capacity *= 2;
    delete[] arr_old;
}

void destroyHeap(Heap* h){
    if(h==NULL)
        return;
    delete [] h->arr;
    delete h;
    h=NULL;
}

void buildHeap(Heap* h,int input[],int n){
    if(h==NULL)
        return;

    while(n > h->capacity)
        resize(h);

    for(int i=0;i<n;i++)
        h->arr[i] =  input[i];

    h->count=n;

    for(int i=(n-1)/2;i>=0;i--)
        heapify(h,i);

}

void print(Heap* h){
    for(int i=0;i<h->count;i++)
        cout<<h->arr[i]<<" ";
    cout<<endl;

}

int main(){

    int input[] = {18,31,1,2,3,7,8};
    int n=7;
    Heap* h = newHeap(n);

    buildHeap(h,input,n);


    print(h);

    cout<<"Maximum element in the heap " <<findMax(h)<<endl;

    destroyHeap(h);
}
