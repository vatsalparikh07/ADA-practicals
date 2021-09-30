/* To implement making change problem using Dynamic Programming */
// -Vatsal Parikh

#include<stdio.h>

void main(){
    int d[5];
    int MakingChange(int [5], int, int);
    int n,N;
    printf("\nEnter the number of coins: ");
    scanf("%d", &n);
    printf("\nEnter the value of each coin: ");
    for(int i=1; i<=n; i++){
        scanf("%d", &d[i]);
    }
    printf("\nEnter the number of changes to be made: ");
    scanf("%d", &N);
    printf("\n Minimum no. of coins %d ", MakingChange(d,n,N));
}

int minvalue(int x, int y){
    if(x<y){
        return x;
    }
    else{
        return y;
    }
}

int MakingChange(int d[], int n, int N)
{
    int minvalue(int x, int y);
    int i,j;
    int c[10][10];
    
    for(i=0; i<=n; i++){
        for(j=0; j<=N; j++){
            c[i][j] = 999999;
        }
    }
    
    for(i=0; i<=n; i++){
        c[i][0] = 0;
    }
    
    for(j=1; j<= N; j++){
        c[0][j] = j;
    }
    
    for(j=1; j<=N; j++){
        for(i=1; i<=n; i++){
            if(i==1){
                if(j<d[i]){
                    c[i][j] = 999999;
                }
                else{
                    c[i][j] = 1 + c[1][j - d[i]];
                }
            }
            else if(j < d[i]){
                c[i][j] = c[i-1][j];
            }
            else{
                c[i][j] = minvalue(c[i-1][j], 1 + c[i][j-d[i]]);
            }
        }
    }
    
    printf("\nThe table for making change problem in dynamic programming is:\n");
    for(i=0; i<=n; i++){
        for(j=0; j<=N; j++){
            printf(" %d", c[i][j]);
        }
        printf("\n");
    }
    return c[n][N];
}
