#include <iostream>
#include <cstdio>

using namespace std;
bool find_matrix(int* matrix,int rows, int columns, int num)
{
    int r_row = 0, l_row = 0;
    int r_column = columns-1, l_column = 0;
    int **matrixl;
    // int matrixl = new int[rows][columns];

    while(r_row <= rows-1 && r_column >= 0)
    {
        if (matrix[rows*r_row+r_column] > num)
        {
            r_column = r_column-1;
        }
        else 
        {
            if(matrix[rows*r_row+r_column]< num)
            {
                r_row = r_row+1;
            }
            else
            {
                return true;
            }

        }
        
    }
    return false;
}
int main()
{
   int rows = 4, columns = 4;
   int matrix[4][4] = {{1,2,8,9},{2,4,9,12},{4,7,10,13},{6,8,11,15}};
   for(int i = 0;i<4; i++)
   {
       for(int j = 0; j<4; j++)
       {
           printf("%d ",matrix[i][j]);
       }
       printf("\n");
   }
   bool re = true;
   re = find_matrix((int*) matrix,rows,columns,7);
   cout<<re<<endl;
   return 0;
}
