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


void heapSort(int input[],int n){
    Heap* h1 = newHeap(n);

    buildHeap(h1,input,n);  // max Heap

    for(int i=n-1;i>=0;i--){
        int temp=h1->arr[0];// max element
        h1->arr[0] = h1->arr[h1->count-1];
        h1->arr[h1->count-1]=temp;
        h1->count--;
        heapify(h1,0);
    }


    for(int i=0;i<n;i++)
        input[i] = h1->arr[i];


    destroyHeap(h1);
}

int deleteMax(Heap* h){
    if(h==NULL){
        cout<<"Empty Heap "<<endl;
        return -1;
    }

    int data = h->arr[0];  // we are considering the max heap
    h->arr[0] = h->arr[h->count-1];
    h->count--;

    heapify(h,0);

    return data;

}

// delete any element from the heap

int deleteKey(Heap* h ,int data){
     if(h==NULL){
        cout<<"Empty Heap "<<endl;
        return 0;
    }

    int i,get=0;

    for(i=0;i<h->count;i++){
        if(h->arr[i] == data){
            get=1;
            break;
        }
    }

     if(get==0){
        cout<<"Element is not found"<<endl;
        return 0;
    }

    h->arr[i] = h->arr[h->count-1];// swapping with the last key
    h->count--;
    heapify(h,i);
    return 1;
}



int main(){
    int input[] = {18,31,1,2,3,7,8};
    int len=7;
    int m=7+2;
    Heap* h1 = newHeap(m);

     for(int i=0;i<len;i++)
        insert(h1,input[i]);

    int n=3;
    int num[] = { 20,40,60};

    Heap *h2 = newHeap(3);

    for(int i=0;i<n;i++)
        insert(h2,num[i]);


    print(h1);
    print(h2);

    cout<<"\nMerging heap h1 to the Heap h2 " <<endl;

    int fi = h1->count;

    for(int i=0;i<n;i++){
        insert(h1,h2->arr[i]);
    }


    cout<<"\nh2  after merging the h1 to it "<<endl;

    print(h1);

    cout<<"Count of h1 " << h1->count<<endl;
    cout<<"Capacity of h1 " << h1->capacity<<endl;


    if(h1->count == h1->capacity)
        cout<<"H1 is full "<<endl;
    else
        cout<<" h1 is not full " <<endl;



    destroyHeap(h1);
    destroyHeap(h2);

}


