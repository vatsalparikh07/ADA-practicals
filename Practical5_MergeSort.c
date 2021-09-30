/* Generate large number of elements randomly and sort all the elements in
ascending order using Merge sort. Analyze the time complexity for best, average
and worst case. */
// -Vatsal Parikh

#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

void Merge(int arr[], int left, int mid, int right) {
    int l = mid - left + 1;
    int r = right - mid;
    int leftArr[l];
    int rightArr[r];
    int i, j, k;

    for (i = 0; i < l; i++) {
        leftArr[i] = arr[left + i];
    }
    for (j = 0; j < r; j++) {
        rightArr[j] = arr[mid + 1 + j];
    }

    i = 0; j = 0; k = left;

    while (i < l && j < r) {
        if (leftArr[i] <= rightArr[j]) {
            arr[k] = leftArr[i];
            i++;
        }
        else {
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }

    while (i < l) {
        arr[k] = leftArr[i];
        i++;
        k++;
    }
    while (j < r) {
        arr[k] = rightArr[j];
        j++;
        k++;
    }
}

void MergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = floor(left + right)/2;
        MergeSort(arr, left, mid);
        MergeSort(arr, mid + 1, right);        
        Merge(arr, left, mid, right);
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
        MergeSort(a, 0, val-1);
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
        MergeSort(a, 0, val-1);

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
        MergeSort(a, 0, val-1);
        gettimeofday(&end, NULL);

        time_taken = (end.tv_sec - start.tv_sec) * 1e6;
        time_taken = (time_taken + (end.tv_usec - 
                                start.tv_usec)) * 1e-6;

        printf("The Worst case for %d elements is %lf milliseconds \n", val, time_taken*1000);
    }
}       
