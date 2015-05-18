#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    ifstream in("file.in", ios::in);
    int cow_num;
    in >> cow_num;

    int in_weight;
    vector<int> weight;
    int size=0;
    while(in >> in_weight)
    {
        weight.push_back(in_weight);
        //cout << weight[size] << endl;
        size++;
    }

    sort(weight.begin(), weight.end());

    int i=0;
    int total=0;
    for(i=weight.size(); i>weight.size()-5; i--)
    {
        total += weight[i-1];
    }
    cout << total << endl;

    in.close();
    return 0;
}

