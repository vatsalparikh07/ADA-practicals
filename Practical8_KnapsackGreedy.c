/* To implement Knapsack problem using Greedy method */
// -Vatsal Parikh

#include<stdio.h>
#include<conio.h>

void knapsack(int n, float m, float w[], float v[]){
    float x[10], U, profit = 0.0, weight = 0.0;
    int i;
    U = m;
    
    for(i=0; i<n; i++){
        x[i] = 0.0;
    }
    
    for(i=0; i<n; i++){
        if(w[i] > U){
            break;
        }
        x[i] = 1.0;
        U = U - w[i];
    }
    
    if(i<n){
        x[i] = U/w[i];
    }
    
    for(i=0; i<n; i++){
        w[i] = w[i] * x[i];
        v[i] = v[i] * x[i];
    }
    
    for(i = 0; i<n; i++){
        profit = profit + v[i];
        weight = weight + w[i];
    }
    
    printf("\nMaximum Profit is: %.2f", profit);
}

void main()
{
    int i,j,n;
    float v[10],w[10], c[10], temp, m;
    printf("Enter the total number of items: ");
    scanf("%d", &n);
    printf("\nEnter the weights: ");
    for(i=0; i<n; i++){
        scanf("%f", &w[i]);
    }
    printf("\nEnter the profits: ");
    for(i = 0; i<n; i++){
        scanf("%f", &v[i]);
    }
    printf("\nEnter the size of the knapsack: ");
    scanf("%f", &m);
    
    for(i = 0; i<n ; i++){
        c[i] = v[i]/w[i];
    }
    
    for(i=0; i<n; i++)
    {
        for(j=0; j<n-1; j++){
            
            if(c[j] < c[j+1])
            {
                temp = c[j];
                c[j] = c[j+1];
                c[j+1] = temp;
                
                temp = w[j];
                w[j] = w[j+1];
                w[j+1] = temp;
                
                temp = v[j];
                v[j] = v[j+1];
                v[j+1] = temp;
            }
            
        }   
    }
    
    knapsack(n,m,w,v);
}
