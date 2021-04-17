#include "heapClass.h"

int heapClass::leftChildIndex(int parent)
{
    int leftIndex = 2 * parent + 1;
    if (leftIndex < heap.size())
        return leftIndex;
    else
        return -1;
}

int heapClass::rightChildIndex(int parent)
{
    int rightIndex = 2 * parent + 2;
    if (rightIndex < heap.size())
        return rightIndex;
    else
        return -1;
}

int heapClass::parentIndex(int child)
{
    int parent = (child - 1) / 2;
    if (child == 0)
        return -1;
    else
        return parent;
}

//after inserting, we heapifyup from where that new inserted player ended up
//compares current node to parent and swaps the smaller to the top
//recursive function, each swap means we call heapifyup on the next higher level
//where we swapped a value
void heapClass::heapifyup(int index)
{
    //IF index is not the root(top of the tree)
//AND parent index within heap bounds (not negative)
//AND current nodes rank less then parent nodes rank
    if (index >= 0 && parentIndex(index) >= 0 && heap[index].rank < heap[parentIndex(index)].rank) {
        //if so, swap values between current node and parent
        numbersClass temp = heap[index];
        heap[index] = heap[parentIndex(index)];
        heap[parentIndex(index)] = temp;
        //since we swapped, lets run heapifyup again recursively on the parent from here
        heapifyup(parentIndex(index));
    }
}


//down is less efficient to up because we have to compare both children first before moving down
//usually called when destroyed root of tree
//recursive function, keeps calling itself as it swaps down the tree
    void heapClass::heapifydown(int index)
    {
        //get left and right children indexes
        int childL = leftChildIndex(index);
        int childR = rightChildIndex(index);
        //child variable representing path we'll compare down
        int childIndex = childL;
        //IF childL is not -1 AND childR is not -1
        //AND right childs rank is less then lefts
        if (childL >= 0 && childR >= 0 && heap[childR].rank < heap[childL].rank)
        {
            //make right child index the focus instead of left
            childIndex = childR;
        }

        //IF childIndex is not the root node and is not -1
        //AND current nodes bigger then child nodes 
        if (childIndex > 0 && heap[index].rank > heap[childIndex].rank)
        {
            //we should swap current with child, because we want smaller ones closer to the top
            numbersClass temp = heap[index];
            heap[index] = heap[childIndex];
            heap[childIndex] = temp;
            //recurse further down
            heapifydown(childIndex);
        }
    }

    //inserts at the lowest next free spot in the tree (this keeps things balanced :D)
    void heapClass::Insert(numbersClass element)
{
        heap.push_back(element);
        heapifyup(heap.size() - 1);
}

void heapClass::DeleteMin()
{
    //cant delete if heap is empty
    if (heap.size() == 0)
    {
        cout << "Heap empty!" << endl;
        return;
    }
    //copy value in last element into root
    heap[0] = heap[heap.size() - 1];//heap.at(heap.size()-1);
    //delete last element
    heap.pop_back();
    //then heapifydown starting from root (index 0)
    heapifydown(0);
    cout << "Root Player deleted" << endl;
}

numbersClass* heapClass::ExtractMin()
{
    //heap empty, no players to return
    if (heap.size() == 0)
        return NULL;
    else
    {
        //return &(heap.front());
        numbersClass* p = &(heap.front());//get memory address of player at front of array/heap
        return p;
    }
}

void heapClass::showHeap()
{
    cout << "Heap -->";
    for (numbersClass p : heap)
    {
        cout << "[" << p.rank << " " << p.name << "] ";
    }
    cout << endl;
}

int heapClass::Size()
{
    return heap.size();
}
