#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
class CMyString
{
    public:
        CMyString(char* pdata = nullptr);
        CMyString(const CMyString& str);
        ~CMyString(void);
        CMyString& operator =(const CMyString& str);
        void Print();
    private:
        char* m_pData;
};
CMyString::CMyString(char *pdata)
{
    if(pdata == nullptr)
    {
        m_pData = new char[1];
        m_pData[0] = '\0';
    }
    else
    {
        m_pData = new char[strlen(pdata)+1];
        strcpy(m_pData,pdata);
    }
    
}

CMyString::CMyString(const CMyString& str)
{
    int len = strlen(str.m_pData);
    m_pData = new char[len+1];
    m_pData = str.m_pData;
}
CMyString::~CMyString(void)
{
    delete []m_pData;
}
CMyString& CMyString::operator =(const CMyString& str)
{
    if (this == &str)
    {
        return *this;
    }
    delete []m_pData;
    int len = strlen(str.m_pData);
    m_pData = new char[len+1];
    m_pData = str.m_pData;
    return *this;
}
void CMyString:: Print(void)
{
    cout<<m_pData<<endl;
}
int main(void)
{
    char text[] = "hello wor";
    CMyString x(text);
    //cout<<"the original one:\n"<<x<<endl;
    cout<<"the original one:"<<endl;
    x.Print();
    CMyString b;
    b = x;
    cout<<"new one:"<<endl;
    b.Print();
    CMyString a;
    a = b;
    a.Print();
    //cout<<"new one:/n"<<b<<endl;
    return 0;
}