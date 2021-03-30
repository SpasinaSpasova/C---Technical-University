/*1. A two-dimensional array A [n] [m] is given. Enter the values ??of the elements of the array and find the sum of the positive elements of the array. Perform the task by using functions.
2. A two-dimensional array A [n] [m] is given. Enter the values ??of the elements of the array and find and display the value of the minimum element from each row of the array in which it lies. Perform the task by using functions.
3. A two-dimensional array A [n] [m] is given. Enter the values ??of the elements of the array and find and display the number of even elements from each column of the array. Perform the task by using functions.
4. A two-dimensional array A [n] [m] is given. Enter the values ??of the elements of the array and find and display the index of each row in which all elements are positive. Realize the task by using functions.
5. Write a program that checks if a two-dimensional array a [n] [n] is a magic square.
6. Write a program that enters the elements of a two-dimensional array A [N] [M] and prints the line number in which the elements of it form an ascending row.*/


//1
#include<stdio.h>
int sumMasiv(int r,int c,int M[][c]){
    int sum=0;
    for(int i=0;i<r;i++)
        for(int j=0;j<c;j++){
            if(M[i][j]>0)
            sum+=M[i][j];
        }
    return sum;
}
void inputMasiv(int r,int c,int M[][c]){
    for(int i=0;i<r;i++)
        for(int j=0;j<c;j++)
            scanf("%d",&M[i][j]);
}
void outputMasiv(int r,int c,int M[][c]){
    for(int i=0;i<r;i++)
        for(int j=0;j<c;j++)
            printf("M[%d][%d]=%d",i,j,M[i][j]);
}
int main(){
    int r,c;
    do{
        scanf("%d",&r);
    }while(r<1||r>5);
    do{
        scanf("%d",&c);
    }while(c<1||c>5);
    int M[r][c];
    inputMasiv(r,c,M);
    printf("Sum of possitive elements in M=%d",sumMasiv(r,c,M));    
}

//2
#include<stdio.h>
#define max_size 100
void inputMasiv(int r,int c,int M[max_size][max_size]){
    for(int i=0;i<r;i++)
        for(int j=0;j<c;j++)
            scanf("%d",&M[i][j]);
}
void outputMasiv(int r,int c,int M[max_size][max_size]){
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++)
            printf("%d \t",M[i][j]);
        printf("\n");
    }
}
void MinOnR(int r,int c, int M[max_size][max_size]){
        int i=0;
    while(i<r){
        int min=M[i][0];
        for(int j=0;j<c;j++){
            if(min>M[i][j])
                min=M[i][j];
        }
        printf("min on row %d= %d \n",i,min);
         i++;}
}
int main(){
    int r,c,i=0;
    scanf("%d",&r);
    scanf("%d",&c);
    int M[r][c];
    inputMasiv(r,c,M);
    MinOnR(r,c,M);
    outputMasiv(r,c,M);
    return 0;
}

//3
#include <stdio.h>
#define max_size100
void inputMasiv(int r,int c,int M[][c]){
    for(int i=0;i<r;i++)
        for(int j=0;j<c;j++)
            scanf("%d",&M[i][j]);
}
void outputMasiv(int r,int c,int M[][c]){
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++)
            printf("%d \t",M[i][j]);
            printf("\n");}
}
int EvenInCol(int current_col,int r,int c,int M[][c]){
       int count_even=0; int i=0;
       while(i<r){
            if(M[i][current_col]%2==0){
            count_even=count_even+1;
            printf("%d \t",M[i][current_col]);
            }
            i++;
        }
    return count_even;
        
    }

int main()
{
    int r,c;
    scanf("%d",&r);
    scanf("%d",&c);
    int M[r][c];
    inputMasiv(r,c,M);
    for(int current_column=0;current_column<c;current_column++){
    printf("Even in column %d = %d",current_column,EvenInCol(current_column,r,c,M));
    printf("\n");}
    outputMasiv(r,c,M);
    return 0;
}

//4

#include <stdio.h>
void inputMasiv(int r,int c,int M[5][5])
{
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            printf("Insert M[%d][%d]",i,j);
            scanf("%d",&M[i][j]);
        }
    }
}
void outputMasiv(int r,int c,int M[5][5])
{
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            printf("M[%d][%d]=%d\n",i,j,M[i][j]);
        }
    }
}
int IndexOfMasiv(int *M,int size)
{
    int value=M[0];
    int IndexOfMasiv=0;
    for(int i=0;i<size;i++)
    {
        if(value>M[i])
        {
            value=M[i];
            IndexOfMasiv=i;
        }
    }
    if(value>0)
    {
        return 1;
    }
    else return 0;
}
int main()
{
    int myM[5][5],r,c,num;
    do{
        printf("Enter r:");
        scanf("%d",&r);
    }while(r<0||r>5);
    do{
        printf("Enter c:");
        scanf("%d",&c);
    }while(c<0||c>5); 
    inputMasiv(myM,r,c);
    for(int i=0;i<r;i++)
    {
        num=IndexOfMasiv(myM[i],r);
        if(num==1)
        {
            printf("message:%d\n",i);
        }
    }
    outputMasiv(myM,r,c);
    return 0;
}

//5

int AreUniqueItems(int N, int M[][N]){
    int check_M[N*N],k=0;
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++){
            check_M[k]=M[i][j];
            k+=1;
        }
    for(int i=0;i<N*N;i++){
        for(int j=0;j<i-1;j++)
        if(check_M[i]==check_M[j])
        return 0;
    }
    return 1;
}
int IsMagicSquare(int N,int mat[][N]) 
{  
    // calculate the sum of  
    // diagonals
    int sum = 0,sum2=0;  
    for (int i = 0; i < N; i++) {
        sum = sum + mat[i][i]; 
        sum2 = sum2 + mat[i][N-1-i]; 
    }
    //Check if diagonals are equal
    if(sum!=sum2)  
        return 0; 
  
    // For sums of Rows  
    for (int i = 0; i < N; i++) {
        int RowSum = 0;      
        for (int j = 0; j < N; j++) 
            RowSum += mat[i][j]; 
          
        // check if every row sum is 
        // equal to prime diagonal sum 
        if (RowSum != sum) 
            return 0; 
    } 
  
    // For sums of Columns 
    for (int i = 0; i < N; i++) { 
          
        int ColSum = 0;      
        for (int j = 0; j < N; j++) 
            ColSum += mat[j][i]; 
  
        // check if every column sum is  
        // equal to prime diagonal sum 
        if (sum != ColSum)  
        return 0; 
    } 
  
    return 1; 
} 
void inputMasiv(int N,int M[][N]){
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            scanf("%d",&M[i][j]);
}
void outputMasiv(int N,int M[][N]){
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            printf("M[%d][%d]=%d",i,j,M[i][j]);
}
int main(){
    int N;
    scanf("%d",&N);
    int M[N][N];
    inputMasiv(N,M);
    if(IsMagicSquare(N,M)+AreUniqueItems(N,M)==2)
    printf("It's a magic square,with magic number=%d",N*((N*N+1)/2));
    else printf("NO");  
}

//6

#include<stdio.h>
#define max_size 100
void inputMasiv(int r,int c,int M[max_size][max_size]){
    for(int i=0;i<r;i++)
        for(int j=0;j<c;j++)
            scanf("%d",&M[i][j]);
}
void outputMasiv(int r,int c,int M[max_size][max_size]){
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++)
            printf("%d \t",M[i][j]);
        printf("\n");
    }
}
int GrowingR(int current_row,int c, int M[max_size][max_size]){
        for(int j=0;j<c-1;j++){
            if(M[current_row][j]>M[current_row][j+1])
            return 0;
        }
        return 1;
}
int main(){
    int r,c,i=0;
    scanf("%d",&r);
    scanf("%d",&c);
    int M[r][c];
    inputMasiv(r,c,M);
    for(int i=0;i<r;i++)
    if(GrowingR(i,c,M)==1)
    printf("Growing row on line %d \n",i);
    outputMasiv(r,c,M);
    return 0;
}


