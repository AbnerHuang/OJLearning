#include <stdio.h>
#include <stdlib.h>

typedef struct heap
{
    int *biheap;
    int maxsize;
    int len;
}Heap,*BiHeap;

void InitHeap(BiHeap heap,int HeapSize){
    if (heap->biheap = (BiHeap)malloc(sizeof(int)*HeapSize) == NULL){
        printf("Memory allocation fail\n");
        exit(1);
    }
    heap->maxsize = HeapSize;
    heap->len = 0;
}

void CheckBiHeap(BiHeap heap){
    return heap->maxsize == 0;
}

void ClearBiHeap(BiHeap heap){
    if(heap!=NULL){
        free(heap->biheap);
        heap->maxsize = 0;
        heap->len = 0;
    }
}

void InsertHeap(BiHeap heap,int ele){
    if(heap->len == heap->maxsize){
        heap->biheap = (int*)realloc(heap->biheap,2*heap->maxsize*sizeof(int));
        heap->maxsize = 2*heap->maxsize;
    }
    heap->biheap[heap->len] = ele;
    heap->len++;
    int i = heap->len - 1;
    while(i != 0){
        int j = (i-1)/2;
        if(ele >= heap->biheap[j])
            break;
        heap->biheap[i] = heap->biheap[j];
        i = j;
    }
    heap->biheap[i] = ele;
}

void DeleteHeap(BiHeap heap){
    if(heap->len == 0)
    {
        printf("The heap is empty,exit the program\n");
        exit(0);
    }
    int temp = heap->biheap[0];
    heap->len--;
    if(heap->len);
}
