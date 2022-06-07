#include "heap.h"

HeapBucket* createHeap(size_t capacity) {
    HeapBucket* ret = (HeapBucket *)calloc(sizeof(HeapBucket), 1);
    if (!ret) return NULL;
    ret->capacity = capacity;
    ret->pHeapArray = (HeapNode *)calloc(sizeof(HeapNode), capacity);
    if (!ret->pHeapArray) {
        free(ret);
        return NULL;
    }
    return (ret);
};

// bool addMaxHeapElement(HeapBucket *pHeap, int data) {
//     if (isHeapFull(pHeap) == true)
//         if (!reallocHeapArray(pHeap)) return false;
//     pHeap->size++;
//     pHeap->pHeapArray[pHeap->size].data = data;
//     int i = pHeap->size;
//     while ((i != 1) && (pHeap->pHeapArray[i].data > pHeap->pHeapArray[i / 2].data)) {
//         int tmp = pHeap->pHeapArray[i / 2].data;
//         pHeap->pHeapArray[i / 2].data = pHeap->pHeapArray[i].data;
//         pHeap->pHeapArray[i].data = tmp;
//         i = i / 2;
//     }
//     pHeap->pHeapArray[i].data = data;
//     return true;
// };

bool addMinHeapElement(HeapBucket *pHeap, HeapNode element) {
    if (isHeapFull(pHeap) == true)
        if (!reallocHeapArray(pHeap)) return false;
    pHeap->size++;
    pHeap->pHeapArray[pHeap->size] = element;
    int i = pHeap->size;
    HeapNode tmp;
    while ((i != 1) && (pHeap->pHeapArray[i].data < pHeap->pHeapArray[i / 2].data)) {
        tmp = pHeap->pHeapArray[i / 2];
        pHeap->pHeapArray[i / 2] = pHeap->pHeapArray[i];
        pHeap->pHeapArray[i] = tmp;
        i = i / 2;
    }
    pHeap->pHeapArray[i] = element;
    return true;
};

// int deleteMaxHeapElement(HeapBucket* pHeap) {
//     int ret = pHeap->pHeapArray[1].data;
//     pHeap->pHeapArray[1].data = 0;

//     size_t i = pHeap->size;
//     int tmp = pHeap->pHeapArray[i].data;
//     pHeap->size--;

//     size_t parent = 1;
//     size_t child = 2;
//     while (child <= pHeap->size) {
//         if ((child < pHeap->size)
//             && (pHeap->pHeapArray[child].data < pHeap->pHeapArray[child + 1].data))
//             child = child + 1;
//         if (tmp >= pHeap->pHeapArray[child].data)
//             break ;
//         pHeap->pHeapArray[parent].data = pHeap->pHeapArray[child].data;
//         parent = child;
//         child = child * 2;
//     }
//     pHeap->pHeapArray[pHeap->size + 1].data = 0;
//     pHeap->pHeapArray[parent].data = tmp;
//     return ret;
// };

HeapNode *deleteMinHeapElement(HeapBucket* pHeap) {
    HeapNode *ret = calloc(1, sizeof(HeapNode));
     *ret = pHeap->pHeapArray[1];

    size_t i = pHeap->size;
    HeapNode *tmp = &(pHeap->pHeapArray[i]);
    pHeap->size--;

    size_t parent = 1;
    size_t child = 2;
    while (child <= pHeap->size) {
        if ((child < pHeap->size)
            && (pHeap->pHeapArray[child].data > pHeap->pHeapArray[child + 1].data))
            child = child + 1;
        if (tmp->data <= pHeap->pHeapArray[child].data)
            break ;
        pHeap->pHeapArray[parent] = pHeap->pHeapArray[child];
        parent = child;
        child = child * 2;
    }
    pHeap->pHeapArray[parent] = *tmp;
    return ret;
};

bool reallocHeapArray(HeapBucket* pHeap) {
    size_t newBucketSize = pHeap->capacity == 0 ? 1 : pHeap->capacity * 2;
    HeapNode *newArr = (HeapNode *)calloc(sizeof(HeapNode), newBucketSize);
    if (!newArr) return false;
    for (size_t i = 1; i <= pHeap->size + 1; i++) {
        newArr[i].data = pHeap->pHeapArray[i].data;
        newArr[i].visited = pHeap->pHeapArray[i].visited;
        newArr[i].tovertexID = pHeap->pHeapArray[i].tovertexID;
        newArr[i].fromvertexID = pHeap->pHeapArray[i].fromvertexID;
    }
    free(pHeap->pHeapArray);
    pHeap->pHeapArray = newArr;
    pHeap->capacity = newBucketSize;
    return true;
};

void deleteHeap(HeapBucket* pHeap) {
    free(pHeap->pHeapArray);
    free(pHeap);
    pHeap = NULL;
};

size_t getSizeHeap(HeapBucket* pHeap) {
    return pHeap->size;
};

bool isHeapEmpty(HeapBucket* pHeap) {
    return (pHeap->size == 0);
};

bool isHeapFull(HeapBucket* pHeap) {
    return (pHeap->capacity - 1 <= pHeap->size);
};

void printHeapArray(HeapBucket *pHeap) {
    for (size_t i = 0; i < pHeap->size; i++) {
        printf("fromvertexID %d, tovertexID %d, weight %d\n", pHeap->pHeapArray[i].fromvertexID, pHeap->pHeapArray[i].tovertexID, pHeap->pHeapArray[i].data);
    }
    printf("size : %zu capacity : %zu\n", pHeap->size, pHeap->capacity);
}