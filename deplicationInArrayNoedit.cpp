#include <iostream>
#include <cstdio>

using namespace std;
int Duplication(const int* numbers, int length);
int countrange(const int* numbers, int length,int start,int middle);
int Duplication(const int* numbers,int length)
{
    if(numbers == nullptr || length <= 0)
    {
        return -1;
    }
    int start = 1;
    int end = length-1;
    int middle = 0;
    int count_first = 0;
    int couont_sec = 0;
    while(end >= start)
    {
        middle = (end+start)/2;
        count_first = countrange(numbers,length,start,middle);
        if(start == end)
        {
            if(count_first >= 1)
                return start;
            else
            {
                break;
            }
            
        }
        if(count_first >= middle-start+1)
        {
            end = middle;
        }
        else
        {
            start = middle+1;
        }
        

    }    
    return -1;
}
int countrange(const int* numbers, int length, int start, int end)
{
    int count = 0;
    for(int i = 0;i<=length;i++)
    {
        if(numbers[i]>= start && numbers[i]<= end)
        {
            count++;
        }
    }
    return count;
}
int main(){
   int length = 8;
   int numbers[8] = {1 ,3,5,4,3,2,6,7};
   int rx;
   rx = Duplication(numbers,length);
   printf("%d\n",rx);
   return 0;
}
