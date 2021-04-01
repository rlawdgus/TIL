#include <stdio.h>
#include <stdlib.h>
#pragma warning (disable : 4996)

typedef struct heap {
	long long heap[10001];
	int size;
}heap;
heap *createHeap() {
	heap *h = (heap *)malloc(sizeof(heap));
	h->size = 0;
	return h;
}
void insertHeap(heap *h, long long item) {
	long long i;
	h->size = h->size + 1;
	i = h->size;
	while (i != 1 && item < h->heap[i / 2]) {
		h->heap[i] = h->heap[i / 2];
		i /= 2;
	}
	h->heap[i] = item;
}
long long returnHeap(heap *h) {
	long long parent, child;
	long long item, tmp;
	item = h->heap[1];
	tmp = h->heap[h->size];
	h->size = h->size - 1;
	parent = 1;
	child = 2;
	while (child <= h->size) {
		if (child < h->size && h->heap[child] > h->heap[child + 1]) child++;
		if (tmp <= h->heap[child]) break;
		else {
			h->heap[parent] = h->heap[child];
			parent = child;
			child = child * 2;
		}
	}
	h->heap[parent] = tmp;
	return item;
}

int main() {
	FILE *inp = fopen("add.inp", "rt");
	FILE *out = fopen("add.out", "wt");

	long long N, num, tmp, res = 0;
	heap *h = createHeap();

	while (1) {
		fscanf(inp, "%lld", &N);
		if (N == 0) break;

		for (int i = 0; i < N; i++) { fscanf(inp, "%lld", &num); insertHeap(h, num); }

		while (1) {
			tmp = 0;
			for (int i = 0; i < 2; i++) tmp += returnHeap(h);
			if (h->size == 0) { res += tmp; break; }
			insertHeap(h, tmp);

			res += tmp;
		}

		fprintf(out, "%lld\n", res);
		res = 0;
	}


	fclose(inp);
	fclose(out);
	return 0;
}