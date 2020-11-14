#include <iostream>
#include <cstdio>
#include <cstring>
/*

AUTHOR: shi
date 
from offer 5 relative
*/
using namespace std;
void marg(char str1[],char str2[])
{
    int length_str1;
    int length_str2;
    int length;
    length_str1 = strlen(str1);
    length_str2 = strlen(str2);
    length = length_str1+length_str2;
    int c_b = length-1;
    int c_1 = length_str1-1;
    int c_2 = length_str2-1;
    while(c_1 >= 0 && c_2 >= 0)
    {
        if(str2[c_2] >= str1[c_1])
        {
            str1[c_b] = str2[c_2];
            c_2 = c_2-1;
        }
        else
        {
            str1[c_b] = str1[c_1];
            c_1 = c_1-1;            

        }
        c_b = c_b-1;
        
    }
    while(c_1 >= 0 )
    {
        str1[c_b] = str1[c_1];
        c_b = c_b -1;
        c_1 = c_1 - 1;
    }
    while(c_2 >= 0 )
    {
        str1[c_b] = str2[c_2];
        c_2 = c_2-1;
        c_b = c_b-1;
    }
}
int main(){
   char str1[20] = "1458";
   char str2[20] = "11349";
   marg(str1,str2);
   cout<<str1<<endl;
   return 0;
}
