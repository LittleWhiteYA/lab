#include "HugeInt.h"

int main()
{
    HugeInt x;
    HugeInt y(28825252);
    HugeInt z("314159265358979323846");
    HugeInt result;
    cin >> x;
    result = x+y;
    cout << x << " + " << y << " = " << result << endl;
    //cout << z << endl;
    result = z-x;
    cout << "result = " << result << endl;
}


