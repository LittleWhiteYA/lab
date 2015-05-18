#ifndef HUGEINT_H_INCLUDED
#define HUGEINT_H_INCLUDED
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

using namespace std;

class HugeInt {
    friend istream &operator>> (istream &, HugeInt &);
    friend ostream &operator<< (ostream &, const HugeInt &);
public:
    //HugeInt();
    HugeInt(string str_num);
    HugeInt(int = 9);
    ~HugeInt();
    const HugeInt &operator+ (const HugeInt &);
    const HugeInt &operator- (const HugeInt &);
    const HugeInt &operator= (const HugeInt &);
private:
    int *ptr;
    int size1;
    //char *ptr_str;

};


#endif // HUGEINT_H_INCLUDED

