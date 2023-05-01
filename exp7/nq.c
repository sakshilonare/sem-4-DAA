#include <stdio.h>
#include <stdbool.h>

int N;
int c=0;
void printBoard(int b[N][N]){
     for(int i=0;i<N;i++)
     {
          for(int j=0;j<N;j++)
          {
               printf("%d\t",b[i][j]);
          }
          printf("\n");
}
}

bool ifSafe(int b[N][N],int row,int col)
{
     int i,j;
      for (i = 0; i < col; i++)//to check row on left side of col
        if (b[row][i])
            return false;

    for (i = row, j = col; i >= 0 && j >= 0; i--, j--)//to check upper diagonal
        if (b[i][j])
            return false;

    for (i = row, j = col; j >= 0 && i < N; i++, j--)//to check lower diagonal
        if (b[i][j])
            return false;

      return true;
}

/*bool solvNQ(int b[N][N],int col)//prints one solution
{
     if(col>=N)//if all queens are placed
     {
         c++;
        printf("Solution %d:\n", c);
        printBoard(b);
          return true;
     }

     for(int i=0;i<N;i++)
     {
          if(ifSafe(b,i,col))
          {
               b[i][col]=1;//place the queen

          if (solvNQ(b, col + 1))//recur to place all the queens
               return true;

          b[i][col]=0; //BACKTRACK i.e if queen cant be placed , no solution
      }
      }
      return false; //no solution for the queens to be placed
}*/

void solvNQ(int b[N][N], int col, int* sols[][N])//to print all the solutions
{
    if (col >= N) {
        int (*sol)[N] = malloc(N * sizeof(*sol));
        memcpy(sol, b, N * sizeof(*sol));
        sols[c][0] = sol;
        c++;
        return;
    }
    for (int i = 0; i < N; i++) {
        if (ifSafe(b, i, col)) {
            b[i][col] = 1;
            solvNQ(b, col + 1, sols);
            b[i][col] = 0;
        }
    }
}

bool checkB()
{
    int i;
    printf("Enter the value of N:");
    scanf("%d", &N);
    int b[N][N];
    int* sols[100][N];
    for (i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            b[i][j] = 0;
        }
    }
    solvNQ(b, 0, sols);
    if (c == 0) {
        printf("Solution does not exist");
        return false;
    }
    printf("Number of solutions found: %d\n",c);
    printf("Solutions:\n");
    for (int k = 0; k < c; k++) {
        printf("Solution %d:\n", k + 1);
        int (*sol)[N] = sols[k][0];
        for (i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                printf("%d ", sol[i][j]);
            }
            printf("\n");
        }
        printf("\n");
    }
    return true;
}
int main(){
checkB();
return 0;
}
