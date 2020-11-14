#include <iostream>
#include <cstdio>
#include <cstring>

/*

AUTHOR: shi
date 
from: offer 5 replacespace
*/
using namespace std;
char* new_space(char text[],char str[])
{
    int length;
    int str_length;
    int count = 0;
    if(!strcmp(text,""))
    {
        char *str_n = new char[3];
        str_n = "no";
        return str_n;
    }
    length = strlen(text);
    str_length = strlen(str);
    for(int i= 0;i< length;i++)
    {
        if(text[i] == ' ' )
        {
            count = count+1;
        }
    }
    int text_c = length-1;
    char* str_n = new char [length-count+str_length*count+1];
    str_n[length-count+str_length*count] = '\0';
    int i = length-count+str_length*count-1;
    while(i >= 0)
    {
        if(text[text_c] != ' ')
        {
            str_n[i] = text[text_c];
            text_c = text_c-1;
            i--;
        }
        else
        {

            for(int j = str_length-1; j >= 0; j--)
            {
                str_n[i] = str[j];            
                i--; 
            }
            text_c = text_c-1;
        }
        
    }
    return str_n;
}

int main(){
   char text[23] = "test   for do";
   char str[23] = "%20";
   char *str_n;
   str_n = new_space(text,str);
   printf("%s\n",str_n);
   delete [] str_n;
   return 0;
}
