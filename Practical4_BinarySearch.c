    /* Generate large number of elements randomly and search a given number from it
    using sequential search and binary search. Analyze the time complexity for best,
    average and worst case. */
    // -Vatsal Parikh

    #include <stdio.h>
    #include <stdlib.h>
    #include <sys/time.h>

    int BinarySearch(int arr[], int size, int key) {
        int low = 0;
        int high = size - 1;
        
        while (low <= high) {
            int mid = floor((high + low)/2);
            if (key == arr[mid]) {
                return mid;
            }
            else if (key < arr[mid]) {
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }
        return -1;
    }

    int main(void)
    {

        int inputNum[] = {1024, 2048, 4096, 8192, 16384, 32768};

        for (int t = 0; t < 6; t++)
        {
            int aSize = inputNum[t];
            int a[aSize];
            for (int i = 0; i < aSize; i++)
            {
                a[i] = i;
            }

            //Best Case
            int key = a[0];

            struct timeval start, end;
            gettimeofday(&start, NULL);

            BinarySearch(a, aSize, key);

            gettimeofday(&end, NULL);

            double time_taken;
            time_taken = (end.tv_sec - start.tv_sec) * 1e6;
            time_taken = (time_taken + (end.tv_usec -
                                        start.tv_usec)) *
                        1e-6;

            printf("Best Case for %d Elements is %lf Micro Seconds\n", aSize, time_taken);

            //Average Case
            key = a[rand() % aSize];
            gettimeofday(&start, NULL);
            BinarySearch(a, aSize, key);
            gettimeofday(&end, NULL);

            time_taken = (end.tv_sec - start.tv_sec) * 1e6;
            time_taken = (time_taken + (end.tv_usec - start.tv_usec)) * 1e-6;

            printf("Average Case for %d Elements is %lf Micro Seconds\n", aSize, time_taken);

            //Worst Case
            key = aSize + 1;

            gettimeofday(&start, NULL);
            BinarySearch(a, aSize, key);
            gettimeofday(&end, NULL);

            time_taken = (end.tv_sec - start.tv_sec) * 1e6;
            time_taken = (time_taken + (end.tv_usec - start.tv_usec)) * 1e-6;

            printf("Worst Case for %d Elements is %lf Micro Seconds\n", aSize, time_taken);
        }
        return 0;
    }
