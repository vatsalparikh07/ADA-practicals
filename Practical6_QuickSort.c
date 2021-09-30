/* Generate large number of elements randomly and sort all the elements in
ascending order using Quick sort. Analyze the time complexity for best, average
and worst case. */
// -Vatsal Parikh

#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

int Quick(int arr[], int start, int end) { 
    int pivot = arr[end];  
    int i = (start - 1); 
    for (int j = start; j <= end - 1; j++) 
    { 
        if (arr[j] < pivot) 
        { 
            i++;
            swap(&arr[i], &arr[j]); 
        } 
    } 
    swap(&arr[i + 1], &arr[end]); 
    return (i + 1); 
} 

void QuickSort(int arr[], int start, int end) {
    if (start < end) {
        int p = Quick(arr, start, end);

        QuickSort(arr, start, p - 1);
        QuickSort(arr, p + 1, end);
    }
}

int main(void) {

    int inputNum[] = {1024, 2048, 4096, 8192, 16384, 32768};

    for (int t = 0; t < 6 ; t++) {
        int val = inputNum[t];
        int a[val];

        /* Best Case */
        for (int i = 0; i < val; i++){
            a[i] = i;     
        }

        struct timeval start, end;
        gettimeofday(&start, NULL);
        QuickSort(a, 0, val-1);
        gettimeofday(&end, NULL);

        double time_taken;
        time_taken = (end.tv_sec - start.tv_sec) * 1e6;
        time_taken = (time_taken + (end.tv_usec - start.tv_usec)) * 1e-6;

        printf("The Best case for %d elements is %lf milliseconds \n", val, time_taken*1000);

        /* Average Case */
        for (int i = 0; i < val; i++){
            a[i] = rand()%val;     
        }

        gettimeofday(&start, NULL);
        QuickSort(a, 0, val-1);

        gettimeofday(&end, NULL);

        time_taken = (end.tv_sec - start.tv_sec) * 1e6;
        time_taken = (time_taken + (end.tv_usec - 
                                start.tv_usec)) * 1e-6;

        printf("The Average case for %d elements is %lf milliseconds \n", val, time_taken*1000);
    
        //Worst Case
        for (int i = 0; i < val; i++){
            a[i] = val-i;     
        }

        gettimeofday(&start, NULL);
        QuickSort(a, 0, val-1);
        gettimeofday(&end, NULL);

        time_taken = (end.tv_sec - start.tv_sec) * 1e6;
        time_taken = (time_taken + (end.tv_usec - 
                                start.tv_usec)) * 1e-6;

        printf("The Worst case for %d elements is %lf milliseconds \n", val, time_taken*1000);
    }
}       

