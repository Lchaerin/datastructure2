#include "heap.h"
#include <iostream>
#include <string>

using namespace std;

MinHeap::MinHeap() {
  heap_size = 0;
  heap_arr = new int[100]; // Default array of size 100
}

string MinHeap::printHeap() {
  string answer;
  for (int i = 0; i < heap_size; i++)
    answer += to_string(heap_arr[i]) + " ";
  return answer;
}

void MinHeap::insertKey(int k) {
  /////////////////////////////////////////////////////////
  //////////  TODO: Implement From Here      //////////////
  heap_arr[heap_size]=k;
  int temp=0;
  int idx=heap_size;
    while (idx)
    {
      if(heap_arr[idx]<heap_arr[(idx+1)/2-1]){
      temp=heap_arr[idx];
      heap_arr[idx]=heap_arr[(idx+1)/2-1];
      heap_arr[(idx+1)/2-1]=temp;
    }
      idx=(idx+1)/2-1;
    }
  heap_size++;
  ///////////      End of Implementation      /////////////
  /////////////////////////////////////////////////////////
}


void MinHeap::deleteMin() {
  /////////////////////////////////////////////////////////
  //////////  TODO: Implement From Here      //////////////
  //cout<<"deleteMin 동작 시작"<<endl;
  heap_arr[0]=heap_arr[heap_size-1];
  heap_size--;
  minHeapProp(0);
  ///////////      End of Implementation      /////////////
  /////////////////////////////////////////////////////////
}

void MinHeap::minHeapProp(int i) {
  /////////////////////////////////////////////////////////
  //////////  TODO: Implement From Here      //////////////
  //cout<<"minHeapProp 동작 시작"<<endl;
  if(((i+1)*2-1<heap_size)&&(heap_arr[i]>heap_arr[(i+1)*2-1])){
    int temp=heap_arr[i];
    if(((i+1)*2<heap_size)&&(heap_arr[(i+1)*2-1]>heap_arr[(i+1)*2])){
      heap_arr[i]=heap_arr[(i+1)*2];
      heap_arr[(i+1)*2]=temp;
      minHeapProp((i+1)*2);
    }
    else{
    heap_arr[i]=heap_arr[(i+1)*2-1];
    heap_arr[(i+1)*2-1]=temp;
    minHeapProp((i+1)*2-1);
    }
  }
  if(((i+1)*2<heap_size)&&(heap_arr[i]>heap_arr[(i+1)*2])){
    int temp=heap_arr[i];
    heap_arr[i]=heap_arr[(i+1)*2];
    heap_arr[(i+1)*2]=temp;
    minHeapProp((i+1)*2);
  }
  //cout<<"minHeapProp 동작 끝"<<endl;
  ///////////      End of Implementation      /////////////
  /////////////////////////////////////////////////////////
}

void MinHeap::deleteElement(int i) {
  /////////////////////////////////////////////////////////
  //////////  TODO: Implement From Here      //////////////
  //cout<<"deleteElement 동작 시작"<<endl;
  heap_arr[i]=heap_arr[heap_size-1];
  heap_size--;
  minHeapProp(i);
  ///////////      End of Implementation      /////////////
  /////////////////////////////////////////////////////////
}