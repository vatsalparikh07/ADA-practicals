/* Generate large number of elements randomly and sort all the elements in
ascending order using Selection sort. Analyze the time complexity for best, average
and worst case */
// -Vatsal Parikh

#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

void SelectionSort (int arr[], int size) {
	for (int i = 0; i < size; i++) {
		int minIndex = i;
		for (int j = i+1; j < size; j++) {
			if (arr[minIndex] > arr[j]) {
                minIndex = j;
			}
		}
        int temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
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
        SelectionSort(a, val);
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

        SelectionSort(a, val);

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
        SelectionSort(a, val);
        gettimeofday(&end, NULL);

        time_taken = (end.tv_sec - start.tv_sec) * 1e6;
        time_taken = (time_taken + (end.tv_usec - 
                                start.tv_usec)) * 1e-6;

        printf("The Worst case for %d elements is %lf milliseconds \n", val, time_taken*1000);
    }
}   
