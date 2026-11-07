// heap.cpp
// Diba Mirza

#include "heap.h"
#include <iostream>
using std::cout;

// Builds a heap from the range [start, end) using the heapify algorithm
// Should run in O(n) time
Heap::Heap(std::vector<int>::iterator start, std::vector<int>::iterator end){
	vdata.assign(start, end);
	int n = static_cast<int>(vdata.size());

	for(int i = n/2 -1; i >= 0; i--){
		bubbleDown(i);
	}
}

// Pushes a value into the heap, then ensures
// the heap is correctly arranged
void Heap::push(int value){
	vdata.push_back(value);
	bubbleUp(static_cast<int>(vdata.size())-1);
}

// Pops the minimum value off the heap
// (but does not return it), then ensures
// the heap is correctly arranged
void Heap::pop(){
	if(vdata.empty()){
		return;
	}
	vdata[0] = vdata.back();
	vdata.pop_back();
	if(!vdata.empty()){
		bubbleDown(0);
	}
}

void Heap::bubbleDown(int i){
	int n = static_cast<int>(vdata.size());
	while(1){
		int left = 2*i+1;
		int right = 2*i+2;
		int least = i;

		if(left < n && vdata[left] < vdata[least]){
			least = left;
		}
		if(right < n && vdata[right] < vdata[least]){
			least = right;
		}
		if(least == i){
			break;
		}
		int curr = vdata[i];
		vdata[i] = vdata[least];
		vdata[least] = curr;
		i = least;
	}
}

void Heap::bubbleUp(int i){
	while(i>0){
		int p = (i-1)/2;
		if(vdata[i] < vdata[p]){
			int p_value = vdata[p];
			vdata[p] = vdata[i];
			vdata[i] = p_value;
			i = p;
		}
		else{
			break;
		}
	}
}

// Returns the minimum element in the heap
int Heap::top(){
  if(empty()){
	  return 0;
  }
  return vdata[0];
}

// Returns true if the heap is empty, false otherwise
bool Heap::empty(){
  return vdata.empty();
}
    
