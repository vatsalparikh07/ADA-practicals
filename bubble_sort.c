/* Generate large number of elements randomly and sort all the elements in
ascending order using Bubble sort. Analyze the time complexity for best, average
and worst case */
// -Vatsal Parikh

#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

void BubbleSort(int a[], int size) {
	for (int i = 0; i < size; i++) {
		int flag = 0;
		for (int j = 0; j < size; j++) {
			if (a[j] > a[j + 1]) {
				int temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
				flag = 1;
			}
		}
		if (flag == 0) {
			break;
		}
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
        BubbleSort(a, val);
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

        BubbleSort(a, val);

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
        BubbleSort(a, val);
        gettimeofday(&end, NULL);

        time_taken = (end.tv_sec - start.tv_sec) * 1e6;
        time_taken = (time_taken + (end.tv_usec - 
                                start.tv_usec)) * 1e-6;

        printf("The Worst case for %d elements is %lf milliseconds \n", val, time_taken*1000);
    }
}       