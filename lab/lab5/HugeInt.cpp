#include "HugeInt.h"

HugeInt tmp;
/*
HugeInt::HugeInt()
{
    size1 = 1;
    ptr = new int;
}
*/

HugeInt::HugeInt(string str)
{
    char *str_num = (char*)str.c_str();
    size1 = strlen(str_num);
    //cout << "size1: " << size1 << endl;
    ptr = new int[size1];
    int i = size1-1;
    int j = 0;
    while(i>=0 && j<size1)
    {
        ptr[j] = str_num[i]-'0';
        i--;
        j++;
    }
}

HugeInt::HugeInt(int num)
{
    int count1 = num/10;
    int count_num = 1;
    while(count1 !=0)
    {
        count1 = count1/10;
        count_num++;
    }
    //cout << "count: " << count_num << endl;
    size1 = count_num;
    ptr = new int[size1];
    if(size1 > 1)
    {
        for(int i=0; i<size1; i++)
        {
            ptr[i] = num%10;
            num = num/10;
        }
    }
}


istream & operator >> (istream &in, HugeInt &x)
{
    char arr[100];
    in >> arr;

    int arr_size = 0;
    while(arr[arr_size] != 0)
    {
        arr_size++;
    }
    //cout << "arr: " << arr_size << endl;
    if(arr_size > x.size1)
    {
        delete [] x.ptr;
        x.size1 = arr_size;
        x.ptr = new int[x.size1];
    }

    int i = arr_size-1;
    int j = 0;
    for(; i>=0; i--, j++)
    {
        x.ptr[j] = arr[i]-'0';
    }
    //cout << "in = " << x.ptr[0] << " " << x.ptr[1] << " " << x.ptr[2] << endl;

    return in;
}

ostream & operator << (ostream &out, const HugeInt &x)
{
    //out << x.size1 << endl;
    //system("pause");
    for(int i=x.size1-1; i>=0; i--)
    {
        out << x.ptr[i];
    }
    //out << endl;

    return out;
}

const HugeInt &HugeInt::operator+ (const HugeInt &x)
{
    if(size1 > x.size1)
        tmp = *this;
    else
        tmp = x;

    int tmp_size;
    if(size1 > x.size1)
        tmp_size = x.size1;
    else
        tmp_size = size1;
    for(int i=0; i<tmp_size; i++)
    {
        tmp.ptr[i] = ptr[i]+x.ptr[i];
        if(tmp.ptr[i] > 9)
        {
            tmp.ptr[i] = tmp.ptr[i]%10;
            tmp.ptr[i+1]++;
            if(tmp.ptr[i+1] >= 10)
            {
                tmp.ptr[i+1] = tmp.ptr[i+1]%10;
                tmp.ptr[i+2]++;
            }

        }
    }

    //cout << tmp.ptr[2] << " " << tmp.ptr[1] << " " << tmp.ptr[0] << endl;

    return tmp;
}

const HugeInt &HugeInt::operator- (const HugeInt &x)
{
    if(size1 > x.size1)
        tmp = *this;
    else
        tmp = x;

    for(int i=x.size1-1; i>=0; i--)
    {
        if(ptr[i] >= x.ptr[i])
            tmp.ptr[i] = ptr[i]-x.ptr[i];
        else
        {
            if(tmp.ptr[i+1] > 0)
                tmp.ptr[i+1]--;
            else if(tmp.ptr[i+1] == 0)
            {
                tmp.ptr[i+2]--;
                tmp.ptr[i+1] = 9;
            }
            tmp.ptr[i] = ptr[i]+10-x.ptr[i];
        }
    }
    //system("pause");

    return tmp;
}

const HugeInt &HugeInt::operator= (const HugeInt &x)
{
    if(&x != this)
    {
        if(size1 != x.size1)
        {
            //cout << "this.size1: " << size1 << endl;
            //cout << "x.size1: " << x.size1 << endl;
            delete [] ptr;
            size1 = x.size1;
            ptr = new int[size1];
        }
        for(int i=0; i<size1; i++)
            ptr[i] = x.ptr[i];
    }
    return *this;
}

HugeInt::~HugeInt()
{
    delete [] ptr;
    //delete [] ptr_str;
}

