#include <cstdio>
#include <iostream>
using namespace std;
int same(int numbers[],int len)
{
    int temp;
    if(numbers == nullptr || len <= 0)
    {
        return -1;
    }
    for(int i = 0;i <len;i++)
    {
        while(numbers[i] != i)
        {
            if(numbers[i] == numbers[numbers[i]])
            {
                return numbers[i];
            }
                temp = numbers[i];
                numbers[i] = numbers[temp];
                numbers[temp] = temp;
        }
    }
    return -1;
}
int main(void)
{   
    int len;
    int i = 0;
    // cout<<"input length"<<endl;
    // cin>>len;
    // cout<<"length:"<<len<<endl;
    // int* numbers = new int[len];
    // for(int i=0;;i++)
    // {
    //     cin>>numbers[i];
    //     if(getchar() == '\n')
    //     {
    //         break;
    //     }
    // }
    // cout<<"input numbers"<<endl;
    // for(int j=0;j <len;j++)
    // {
    //     printf("%d,",numbers[j]);
    // }
    // cout<<endl;
    len = 7;
    int numbers[7] = {2,3,1,0,2,5,3}; 
    int r;
    r = same(numbers,len);
    cout<<r<<endl;
    return 0;
}