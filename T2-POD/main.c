#include <stdio.h>
#include <stdlib.h>
#include "functions.c"
#include <time.h>
#include <sys/time.h>

int main(){
    srand(time(NULL));
    struct timeval stop, start;

    FILE *arqM, *arqH, *arqC, *arqR;

    int *vetA10, *vetA50, *vetA100, *vetB10,*vetB50, *vetB100, *vetC10, *vetC50, *vetC100, i, j;
    int sizeA10 = 10000;
    int sizeA50 = 50000;
    int sizeA100 = 100000;
    int sizeB10 = 10000;
    int sizeB50 = 50000;
    int sizeB100 = 100000;
    int sizeC10 = 10000;
    int sizeC50 = 50000;
    int sizeC100 = 100000;
    arqM = fopen("outM.txt", "w+");
    
    //CRIACAO DOS VETORES
    vetA10 = malloc(sizeA10 * sizeof(int));
    vetA50 = malloc(sizeA50 * sizeof(int));
    vetA100 = malloc(sizeA100 * sizeof(int));
    vetB10 = malloc(sizeB10 * sizeof(int));
    vetB50 = malloc(sizeB50 * sizeof(int));
    vetB100 = malloc(sizeB100 * sizeof(int));
    vetC10 = malloc(sizeB10 * sizeof(int));
    vetC50 = malloc(sizeB50 * sizeof(int));
    vetC100 = malloc(sizeB100 * sizeof(int));
    for(i = 0; i < sizeA10; i ++){
        vetA10[i] = i;
    }
    for(i = sizeB10; i >= 0; i--){
        vetB10[sizeB10 - i] = i;
    }
    for( i = 0; i < sizeC10; i++){
        vetC10[i] = rand() % sizeC10;
    }

    for(i = 0; i < sizeA50; i ++){
        vetA50[i] = i;
    }
    for(i = sizeB50; i >= 0; i--){
        vetB50[sizeB50 - i] = i;
    }
    for( i = 0; i < sizeC50; i++){
        vetC50[i] = rand() % sizeC50;
    }

    for(i = 0; i < sizeA100; i ++){
        vetA100[i] = i;
    }
    for(i = sizeB100; i >= 0; i--){
        vetB100[sizeB100 - i] = i;
    }
    for( i = 0; i < sizeC100; i++){
        vetC100[i] = rand() % sizeC100;
    }
    
    //VETORES COM 10K - MERGESORT

    gettimeofday(&start, NULL);
    merge(vetA10, 0, sizeA10 - 1);
    gettimeofday(&stop, NULL);
	printf("Tempo para ordenar o vetor A-10k com mergeSort: %f\n", (double)(stop.tv_usec - start.tv_usec) / 1000000 + (double)(stop.tv_sec - start.tv_sec)); 
    gettimeofday(&start, NULL);
    merge(vetB10, 0, sizeB10 - 1);
    gettimeofday(&stop, NULL);
	printf("Tempo para ordenar o vetor B-10k com mergeSort: %f\n", (double)(stop.tv_usec - start.tv_usec) / 1000000 + (double)(stop.tv_sec - start.tv_sec));
	gettimeofday(&start, NULL);
    merge(vetC10, 0, sizeC10 - 1);
    gettimeofday(&stop, NULL);
	printf("Tempo para ordenar o vetor C-10k com mergeSort: %f\n", (double)(stop.tv_usec - start.tv_usec) / 1000000 + (double)(stop.tv_sec - start.tv_sec));
    fprintf(arqM, "VETOR A - 10k: \n\n\n");
    for(int k = 0; k < sizeA10; k++){
        fprintf(arqM, "%d\n", vetA10[k]);
    }
    fprintf(arqM, "VETOR B - 10k: \n\n\n");
    for(int k = 0; k < sizeB10; k++){
        fprintf(arqM, "%d\n", vetB10[k]);
    }
    fprintf(arqM, "VETOR C - 10k: \n\n\n");
    for(int k = 0; k < sizeC10; k++){
        fprintf(arqM, "%d\n", vetC10[k]);
    }

    //VETORES COM 50K - MERGESORT

	gettimeofday(&start, NULL);
    merge(vetA50, 0, sizeA50 - 1);
    gettimeofday(&stop, NULL);
	printf("Tempo para ordenar o vetor A-50k com mergeSort: %f\n", (double)(stop.tv_usec - start.tv_usec) / 1000000 + (double)(stop.tv_sec - start.tv_sec)); 
    gettimeofday(&start, NULL);
    merge(vetB50, 0, sizeB50 - 1);
    gettimeofday(&stop, NULL);
	printf("Tempo para ordenar o vetor B-50k com mergeSort: %f\n", (double)(stop.tv_usec - start.tv_usec) / 1000000 + (double)(stop.tv_sec - start.tv_sec));
	gettimeofday(&start, NULL);
    merge(vetC50, 0, sizeC50 - 1);
    gettimeofday(&stop, NULL);
	printf("Tempo para ordenar o vetor C-50k com mergeSort: %f\n", (double)(stop.tv_usec - start.tv_usec) / 1000000 + (double)(stop.tv_sec - start.tv_sec));
    fprintf(arqM, "VETOR A - 10k: \n\n\n");
    for(int k = 0; k < sizeA50; k++){
        fprintf(arqM, "%d\n", vetA50[k]);
    }
    fprintf(arqM, "VETOR B - 50k: \n\n\n");
    for(int k = 0; k < sizeB50; k++){
        fprintf(arqM, "%d\n", vetB50[k]);
    }
    fprintf(arqM, "VETOR C - 50k: \n\n\n");
    for(int k = 0; k < sizeC50; k++){
        fprintf(arqM, "%d\n", vetC50[k]);
    }

    //VETORES COM 100K - MERGESORT

    gettimeofday(&start, NULL);
    merge(vetA100, 0, sizeA100 - 1);
    gettimeofday(&stop, NULL);
	printf("Tempo para ordenar o vetor A-100k com mergeSort: %f\n", (double)(stop.tv_usec - start.tv_usec) / 1000000 + (double)(stop.tv_sec - start.tv_sec)); 
    gettimeofday(&start, NULL);
    merge(vetB100, 0, sizeB100 - 1);
    gettimeofday(&stop, NULL);
	printf("Tempo para ordenar o vetor B-100k com mergeSort: %f\n", (double)(stop.tv_usec - start.tv_usec) / 1000000 + (double)(stop.tv_sec - start.tv_sec));
	gettimeofday(&start, NULL);
    merge(vetC100, 0, sizeC100 - 1);
    gettimeofday(&stop, NULL);
	printf("Tempo para ordenar o vetor C-100k com mergeSort: %f\n", (double)(stop.tv_usec - start.tv_usec) / 1000000 + (double)(stop.tv_sec - start.tv_sec));
    fprintf(arqM, "VETOR A - 10k: \n\n\n");
    for(int k = 0; k < sizeA100; k++){
        fprintf(arqM, "%d\n", vetA100[k]);
    }
    fprintf(arqM, "VETOR B - 100k: \n\n\n");
    for(int k = 0; k < sizeB100; k++){
        fprintf(arqM, "%d\n", vetB100[k]);
    }
    fprintf(arqM, "VETOR C - 100k: \n\n\n");
    for(int k = 0; k < sizeC100; k++){
        fprintf(arqM, "%d\n", vetC100[k]);
    }

    //VETORES HEAP 10K

    arqH = fopen("outH.txt", "w+");
    gettimeofday(&start, NULL);
    heapSort(vetA10, sizeA10);
    gettimeofday(&stop, NULL);
    printf("Tempo para ordenar o vetor A-10k com heapSort: %f\n", (double)(stop.tv_usec - start.tv_usec) / 1000000 + (double)(stop.tv_sec - start.tv_sec));
    gettimeofday(&start, NULL);
    heapSort(vetB10, sizeB10);
    gettimeofday(&stop, NULL);
    printf("Tempo para ordenar o vetor B-10k com heapSort: %f\n", (double)(stop.tv_usec - start.tv_usec) / 1000000 + (double)(stop.tv_sec - start.tv_sec));
	gettimeofday(&start, NULL);
    heapSort(vetC10, sizeC10);
    gettimeofday(&stop, NULL);
    printf("Tempo para ordenar o vetor C-10k com heapSort: %f\n", (double)(stop.tv_usec - start.tv_usec) / 1000000 + (double)(stop.tv_sec - start.tv_sec));
    fprintf(arqH, "VETOR A - 10K \n\n\n");
	for(int k = 0; k < sizeA10; k++){
        fprintf(arqH, "%d\n", vetA10[k]);
    }
    fprintf(arqH, "VETOR B - 10K: \n\n\n");
    for(int k = 0; k < sizeB10; k++){
        fprintf(arqH, "%d\n", vetB10[k]);
    }
    fprintf(arqH, "VETOR C - 10K: \n\n\n");
    for(int k = 0; k < sizeC10; k++){
        fprintf(arqH, "%d\n", vetC10[k]);
    }

    //vetores 50k - heapSort

    gettimeofday(&start, NULL);
    heapSort(vetA50, sizeA50);
    gettimeofday(&stop, NULL);
    printf("Tempo para ordenar o vetor A-50k com heapSort: %f\n", (double)(stop.tv_usec - start.tv_usec) / 1000000 + (double)(stop.tv_sec - start.tv_sec));
    gettimeofday(&start, NULL);
    heapSort(vetB50, sizeB50);
    gettimeofday(&stop, NULL);
    printf("Tempo para ordenar o vetor B-50k com heapSort: %f\n", (double)(stop.tv_usec - start.tv_usec) / 1000000 + (double)(stop.tv_sec - start.tv_sec));
	gettimeofday(&start, NULL);
    heapSort(vetC50, sizeC50);
    gettimeofday(&stop, NULL);
    printf("Tempo para ordenar o vetor C-50k com heapSort: %f\n", (double)(stop.tv_usec - start.tv_usec) / 1000000 + (double)(stop.tv_sec - start.tv_sec));
    fprintf(arqH, "VETOR A - 5OK: \n\n\n");
    for(int k = 0; k < sizeA50; k++){
        fprintf(arqH, "%d\n", vetA50[k]);
    }
    fprintf(arqH, "VETOR B - 50K: \n\n\n");
    for(int k = 0; k < sizeB50; k++){
        fprintf(arqH, "%d\n", vetB50[k]);
    }
    fprintf(arqH, "VETOR C - 50K: \n\n\n");
    for(int k = 0; k < sizeC50; k++){
        fprintf(arqH, "%d\n", vetC50[k]);
    }

    // Heap sort - 100k

    gettimeofday(&start, NULL);
    heapSort(vetA100, sizeA100);
    gettimeofday(&stop, NULL);
    printf("Tempo para ordenar o vetor A-100k com heapSort: %f\n", (double)(stop.tv_usec - start.tv_usec) / 1000000 + (double)(stop.tv_sec - start.tv_sec));
    gettimeofday(&start, NULL);
    heapSort(vetB100, sizeB100);
    gettimeofday(&stop, NULL);
    printf("Tempo para ordenar o vetor B-100k com heapSort: %f\n", (double)(stop.tv_usec - start.tv_usec) / 1000000 + (double)(stop.tv_sec - start.tv_sec));
	gettimeofday(&start, NULL);
    heapSort(vetC100, sizeC100);
    gettimeofday(&stop, NULL);
    printf("Tempo para ordenar o vetor C-100k com heapSort: %f\n", (double)(stop.tv_usec - start.tv_usec) / 1000000 + (double)(stop.tv_sec - start.tv_sec));
    fprintf(arqH, "VETOR A - 10OK: \n\n\n");
    for(int k = 0; k < sizeA100; k++){
        fprintf(arqH, "%d\n", vetA100[k]);
    }
    fprintf(arqH, "VETOR B - 100K: \n\n\n");
    for(int k = 0; k < sizeB100; k++){
        fprintf(arqH, "%d\n", vetB100[k]);
    }
    fprintf(arqH, "VETOR C - 100K \n\n\n");
    for(int k = 0; k < sizeC100; k++){
        fprintf(arqH, "%d\n", vetC100[k]);
    }

    //CoutingSort 10K

    arqC = fopen("outC.txt", "w+");
    gettimeofday(&start, NULL);
    countingSort(vetA10, sizeA10);
    gettimeofday(&stop, NULL);
    printf("Tempo para ordenar o vetor A-10k com countingSort: %f\n", (double)(stop.tv_usec - start.tv_usec) / 1000000 + (double)(stop.tv_sec - start.tv_sec));
    gettimeofday(&start, NULL);
    countingSort(vetB10, sizeB10);
    gettimeofday(&stop, NULL);
    printf("Tempo para ordenar o vetor B-10k com countingSort: %f\n", (double)(stop.tv_usec - start.tv_usec) / 1000000 + (double)(stop.tv_sec - start.tv_sec));
	gettimeofday(&start, NULL);
    countingSort(vetC10, sizeC10);
    gettimeofday(&stop, NULL);
    printf("Tempo para ordenar o vetor C-10k com countingSort: %f\n", (double)(stop.tv_usec - start.tv_usec) / 1000000 + (double)(stop.tv_sec - start.tv_sec));
    fprintf(arqC, "VETOR A 10k: \n\n\n");
    for(int k = 0; k < sizeA10; k++){
        fprintf(arqC, "%d\n", vetA10[k]);
    }
    fprintf(arqC, "VETOR B 10k: \n\n\n");
    for(int k = 0; k < sizeB10; k++){
        fprintf(arqC, "%d\n", vetB10[k]);
    }
    fprintf(arqC, "VETOR C 10k: \n\n\n");
    for(int k = 0; k < sizeC10; k++){
        fprintf(arqC, "%d\n", vetC10[k]);
    }

    // CountingSort 50k

    gettimeofday(&start, NULL);
    countingSort(vetA50, sizeA50);
    gettimeofday(&stop, NULL);
    printf("Tempo para ordenar o vetor A-50k com countingSort: %f\n", (double)(stop.tv_usec - start.tv_usec) / 1000000 + (double)(stop.tv_sec - start.tv_sec));
    gettimeofday(&start, NULL);
    countingSort(vetB50, sizeB50);
    gettimeofday(&stop, NULL);
    printf("Tempo para ordenar o vetor B-50k com countingSort: %f\n", (double)(stop.tv_usec - start.tv_usec) / 1000000 + (double)(stop.tv_sec - start.tv_sec));
	gettimeofday(&start, NULL);
    countingSort(vetC50, sizeC50);
    gettimeofday(&stop, NULL);
    printf("Tempo para ordenar o vetor C-50k com countingSort: %f\n", (double)(stop.tv_usec - start.tv_usec) / 1000000 + (double)(stop.tv_sec - start.tv_sec));
    fprintf(arqC, "VETOR A 50k: \n\n\n");
    for(int k = 0; k < sizeA50; k++){
        fprintf(arqC, "%d\n", vetA50[k]);
    }
    fprintf(arqC, "VETOR B 50k: \n\n\n");
    for(int k = 0; k < sizeB50; k++){
        fprintf(arqC, "%d\n", vetB50[k]);
    }
    fprintf(arqC, "VETOR C 50k: \n\n\n");
    for(int k = 0; k < sizeC50; k++){
        fprintf(arqC, "%d\n", vetC50[k]);
    }
    
    //CountingSort 100k

    gettimeofday(&start, NULL);
    countingSort(vetA100, sizeA100);
    gettimeofday(&stop, NULL);
    printf("Tempo para ordenar o vetor A-100k com countingSort: %f\n", (double)(stop.tv_usec - start.tv_usec) / 1000000 + (double)(stop.tv_sec - start.tv_sec));
    gettimeofday(&start, NULL);
    countingSort(vetB100, sizeB100);
    gettimeofday(&stop, NULL);
    printf("Tempo para ordenar o vetor B-100k com countingSort: %f\n", (double)(stop.tv_usec - start.tv_usec) / 1000000 + (double)(stop.tv_sec - start.tv_sec));
	gettimeofday(&start, NULL);
    countingSort(vetC100, sizeC100);
    gettimeofday(&stop, NULL);
    printf("Tempo para ordenar o vetor C-100k com countingSort: %f\n", (double)(stop.tv_usec - start.tv_usec) / 1000000 + (double)(stop.tv_sec - start.tv_sec));
    fprintf(arqC, "VETOR A 100k: \n\n\n");
    for(int k = 0; k < sizeA100; k++){
        fprintf(arqC, "%d\n", vetA100[k]);
    }
    fprintf(arqC, "VETOR B 100k: \n\n\n");
    for(int k = 0; k < sizeB100; k++){
        fprintf(arqC, "%d\n", vetB100[k]);
    }
    fprintf(arqC, "VETOR C 100k: \n\n\n");
    for(int k = 0; k < sizeC100; k++){
        fprintf(arqC, "%d\n", vetC100[k]);
    }
	
	//Radix Sort 10k
	
	arqR = fopen("outR.txt", "w+");
	gettimeofday(&start, NULL);
    radixSort(sizeA10, vetA10);
    gettimeofday(&stop, NULL);
    printf("Tempo para ordenar o vetor A-10k com radixSort: %f\n", (double)(stop.tv_usec - start.tv_usec) / 1000000 + (double)(stop.tv_sec - start.tv_sec));
    gettimeofday(&start, NULL);
    radixSort(sizeB10, vetB10);
    gettimeofday(&stop, NULL);
    printf("Tempo para ordenar o vetor B-10k com radixSort: %f\n", (double)(stop.tv_usec - start.tv_usec) / 1000000 + (double)(stop.tv_sec - start.tv_sec));
	gettimeofday(&start, NULL);
    radixSort(sizeC10, vetC10);
    gettimeofday(&stop, NULL);
    printf("Tempo para ordenar o vetor C-10k com radixSort: %f\n", (double)(stop.tv_usec - start.tv_usec) / 1000000 + (double)(stop.tv_sec - start.tv_sec));
    fprintf(arqR, "VETOR A 10k: \n\n\n");
    for(int k = 0; k < sizeA10; k++){
        fprintf(arqR, "%d\n", vetA10[k]);
    }
    fprintf(arqR, "VETOR B 10k: \n\n\n");
    for(int k = 0; k < sizeB10; k++){
        fprintf(arqR, "%d\n", vetB10[k]);
    }
    fprintf(arqR, "VETOR C 10k: \n\n\n");
    for(int k = 0; k < sizeC10; k++){
        fprintf(arqR, "%d\n", vetC10[k]);
    }

	//Radix Sort 50k

	gettimeofday(&start, NULL);
    radixSort(sizeA50, vetA50);
    gettimeofday(&stop, NULL);
    printf("Tempo para ordenar o vetor A-50k com radixSort: %f\n", (double)(stop.tv_usec - start.tv_usec) / 1000000 + (double)(stop.tv_sec - start.tv_sec));
    gettimeofday(&start, NULL);
    radixSort(sizeB50, vetB50);
    gettimeofday(&stop, NULL);
    printf("Tempo para ordenar o vetor B-50k com radixSort: %f\n", (double)(stop.tv_usec - start.tv_usec) / 1000000 + (double)(stop.tv_sec - start.tv_sec));
	gettimeofday(&start, NULL);
    radixSort(sizeC50, vetC50);
    gettimeofday(&stop, NULL);
    printf("Tempo para ordenar o vetor C-50k com radixSort: %f\n", (double)(stop.tv_usec - start.tv_usec) / 1000000 + (double)(stop.tv_sec - start.tv_sec));
    fprintf(arqR, "VETOR A 50k: \n\n\n");
    for(int k = 0; k < sizeA50; k++){
        fprintf(arqR, "%d\n", vetA50[k]);
    }
    fprintf(arqR, "VETOR B 50k: \n\n\n");
    for(int k = 0; k < sizeB50; k++){
        fprintf(arqR, "%d\n", vetB50[k]);
    }
    fprintf(arqR, "VETOR C 50k: \n\n\n");
    for(int k = 0; k < sizeC50; k++){
        fprintf(arqR, "%d\n", vetC50[k]);
    }
	
	//Radix Sort - 100k
	
	gettimeofday(&start, NULL);
    radixSort(sizeA100, vetA100);
    gettimeofday(&stop, NULL);
    printf("Tempo para ordenar o vetor A-100k com radixSort: %f\n", (double)(stop.tv_usec - start.tv_usec) / 1000000 + (double)(stop.tv_sec - start.tv_sec));
    gettimeofday(&start, NULL);
    radixSort(sizeB100, vetB100);
    gettimeofday(&stop, NULL);
    printf("Tempo para ordenar o vetor B-100k com radixSort: %f\n", (double)(stop.tv_usec - start.tv_usec) / 1000000 + (double)(stop.tv_sec - start.tv_sec));
	gettimeofday(&start, NULL);
    radixSort(sizeC100, vetC100);
    gettimeofday(&stop, NULL);
    printf("Tempo para ordenar o vetor C-100k com radixSort: %f\n", (double)(stop.tv_usec - start.tv_usec) / 1000000 + (double)(stop.tv_sec - start.tv_sec));
    fprintf(arqR, "VETOR A 100k: \n\n\n");
    for(int k = 0; k < sizeA100; k++){
        fprintf(arqR, "%d\n", vetA100[k]);
    }
    fprintf(arqR, "VETOR B 100k: \n\n\n");
    for(int k = 0; k < sizeB100; k++){
        fprintf(arqR, "%d\n", vetB100[k]);
    }
    fprintf(arqR, "VETOR C 100k: \n\n\n");
    for(int k = 0; k < sizeC100; k++){
        fprintf(arqR, "%d\n", vetC100[k]);
    }

}
