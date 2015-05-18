#include <iostream>
#include <fstream>
#include "BMI.h"

using namespace std;

int main()
{
    ifstream in("file.in",ios::in);
    ofstream out("file.out",ios::out);

    float height, weight;

    while(in >> height >> weight)
    {
        if(height>0 && weight>0)
        {
            BMI Count_bmi(height, weight);
            out << Count_bmi.BMI_value() << " ";
            out << Count_bmi.BMI_category() << endl;
        }
    }

    in.close();
    out.close();
    return 0;
}


