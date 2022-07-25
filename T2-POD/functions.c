#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

void swap(int *vet, int a, int b){ 
  int tmp = vet[b]; 
  vet[b] = vet[a]; 
  vet[a] = tmp; 
 }

void mergeSort(int *vet, int first, int middle, int last) {
  int *aux = malloc((last - first + 1) * sizeof(int));

  int i = first;
  int j = middle + 1;
  int k = 0;

  while (i <= middle && j <= last) {
    if (vet[i] <= vet[j]) {
      aux[k] = vet[i];
      i++;
    } else {
      aux[k] = vet[j];
      j++;
    }

    k++;
  }

  while (i <= middle) {
    aux[k] = vet[i];
    i++;
    k++;
  }

  while (j <= last) {
    aux[k] = vet[j];
    j++;
    k++;
  }

  for (int i = first; i <= last; i++) {
    vet[i] = aux[i - first];
  }

  free(aux);
}

void merge(int *vet, int first, int last) {
  int middle;

  if (first < last) {
    middle = (first + last) / 2;

    merge(vet, first, middle);
    merge(vet, middle + 1, last);
    mergeSort(vet, first, middle, last);
  }
}

void heap(int *vet, int i, int n) {
  int top = i;
  int left = 2 * i + 1;
  int right = 2 * i + 2;

  if (left < n && vet[left] > vet[top])
    top = left;

  if (right < n && vet[right] > vet[top])
    top = right;

  if (top != i){
    swap(vet, i, top);
    heap(vet, top, n);
  }
}

void heapSort(int *vet, int n){
  for (int k = n / 2 - 1; k >= 0; k--)
    heap(vet, k, n);

  for (int k = n-1; k >= 1; k--) {
    swap(vet, 0, k);
    heap(vet, 0, k);
  }
}

void countingSort(int *vet, int n) {
	
  int k = vet[0];
  for (int i = 1; i < n; i++) {
    if (vet[i] > k)
      k = vet[i];
  }
  
  int *a = (int*)calloc(k + 1, sizeof(int));

  for (int i = 0; i < n; i++){
	  a[vet[i]]++;
  }
  for (int i = 0; i < k + 1; i++) {
    for (int j = 0; j < a[i]; j++) {
      //printf("%d ", i);
    }
  }
}

void countSort(int n, int exp, int *vet) {
  int *a = malloc(n*sizeof(int));
  int count[10] = { 0 };

  for (int i = 0; i < n; i++)
    count[(vet[i] / exp) % 10]++;

  for (int i = 1; i < 10; i++)
    count[i] += count[i - 1];

  for (int i = n - 1; i >= 0; i--) {
    count[(vet[i] / exp) % 10]--;
    a[count[(vet[i] / exp) % 10]] = vet[i];
  }

  for (int i = 0; i < n; i++)
    vet[i] = a[i];
}

void radixSort(int n, int *vet) {
  int max = vet[0];

  for (int i = 1; i < n; i++)
    if (vet[i] > max) max = vet[i];

  for (int exp = 1; max / exp > 0; exp *= 10)
    countSort(n, exp, vet);
}
