#include <stdio.h>
#include <stdlib.h>
#define MAX 101
#pragma warning (disable : 4996)

typedef struct heap {
	int heap[MAX];
	int size;
}heap;
heap *createHeap() {
	heap *h = (heap *)malloc(sizeof(heap));
	h->size = 0;
	return h;
}
void insertHeap(heap *h, int item) {
	int i = ++h->size;
	while (i != 1 && item < h->heap[i / 2]) {
		h->heap[i] = h->heap[i / 2];
		i /= 2;
	}

	h->heap[i] = item;
}
int deleteHeap(heap *h) {
	int i = 1, item = h->heap[1], tmp;
	h->heap[1] = h->heap[h->size];

	while (h->heap[i] > h->heap[i * 2] || h->heap[i] > h->heap[i * 2 + 1]) {
		if (i * 2 > h->size) break;
		if (i * 2 + 1 > h->size) {
			if (h->heap[i] > h->heap[i * 2]) {
				tmp = h->heap[i * 2];
				h->heap[i * 2] = h->heap[i];
				h->heap[i] = tmp;
			}
			break;
		}

		if (h->heap[i * 2] < h->heap[i * 2 + 1]) {
			tmp = h->heap[i * 2];
			h->heap[i * 2] = h->heap[i];
			h->heap[i] = tmp;
		}
		else {
			tmp = h->heap[i * 2 + 1];
			h->heap[i * 2 + 1] = h->heap[i];
			h->heap[i] = tmp;
		}
		i *= 2;
	}

	h->size--;
	return item;
}

int main() {
	int arr[7] = { 92, 52, 22, 508, 1001, 81, 2 };
	heap *h = createHeap();

	for (int i = 0; i < 7; i++) insertHeap(h, arr[i]);
	for (int i = 0; i < 7; i++) printf("%d ", deleteHeap(h));
	printf("\n");

	free(h);
	return 0;
}