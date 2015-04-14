#include "Sudoku.h"
#include <stdlib.h>

using namespace std;

Sudoku::Sudoku():judge(0){
    for(int i=0; i<sudokuSize; ++i)
    map[i] = 0;
}
Sudoku::Sudoku(const int init_map[]){
    for(int i=0; i<sudokuSize; ++i)
        map[i] = init_map[i];
}

void Sudoku::setMap(const int set_map[]){
    for(int i=0; i<sudokuSize; ++i)
        map[i] = set_map[i];
}
int Sudoku::getElement(int index){
    return map[index];
}
void Sudoku::setElement(int index, int value){
    map[index] = value;
}
int Sudoku::getFirstZeroIndex(){
    for(int i=0;i<sudokuSize;++i)
        if(map[i] == 0)
            return i;

    return -1;
}
void Sudoku::ReadIn(){
    //ifstream infile;
    //infile.open("infile4.txt",ios::in);

    int num[sudokuSize];

    int i=0;
    //while(infile >> num[i])
    //    i++;
    for(; i<sudokuSize; i++)
        cin >> num[i];

    setMap(num);

    //:infile.close();

}

bool Sudoku::checkUnity(int arr[]){
    int arr_unity[9]={}; // counters
    /*for(int i=0; i<length; i++)
        cout << arr[i] << " ";
    cout << endl;*/

    //for(int i=0; i<length; ++i)
    //    arr_unity[i] = 0; // initialize
    for(int i=0; i<length; ++i)
    {
        if(arr[i] == -1)
            continue;

        ++arr_unity[arr[i]-1]; // count
        //cout << "arr " << arr[i]-1 << " ";
        //cout << "unity " << arr_unity[arr[i]-1] << endl;
    }

    /*for(int i=0; i<9; i++)
        cout << arr_unity[i] << " ";
    cout << endl;
    system("pause");*/

    for(int i=0; i<9; ++i)
        if(arr_unity[i] != 1) // all element
            return false; // must be 1

    return true;
}
bool Sudoku::isCorrect(int map[]){
    bool check_result;
    int check_arr[length]={};
    int location;

    for(int i=0; i<sudokuSize; i+=length) // check rows
    {
        for(int j=0; j<length; ++j)
            check_arr[j] = map[i+j];


        check_result = checkUnity(check_arr);

        if(check_result == false)
            return false;
    }

    for(int i=0; i<length; ++i) // check columns
    {
        for(int j=0; j<length; ++j)
            check_arr[j] = map[i+length*j];

        check_result = checkUnity(check_arr);
        if(check_result == false)
            return false;
    }

    for(int i=0; i<length; i++)
        check_arr[i] = -1;

    for(int i=0; i<4*4; ++i) // check cells
    {
        for(int j=0; j<3*3; ++j)
        {
            location = 36*(i/4) + 3*(i%4) +length*(j/3) + (j%3);
            check_arr[j] = map[location];
        }

        if(check_arr[0] == -1)
            return true;

        check_result = checkUnity(check_arr);
        if(check_result == false)
            return false;
    }
    return true;
}

bool Sudoku::Check(){

    int i;
    int test = 0;
    int Check_map[sudokuSize];
    for(i=0; i<sudokuSize; i++)
        Check_map[i] = map[i];

    while(test < 5)
    {
        //cout << "1" << endl;
        for(i=0; i<sudokuSize; i++)
        {
            if(Check_map[i] == 0)
            {
                check_row(Check_map, i);
                check_col(Check_map, i);
                check_squa(Check_map, i);
            }
        }
        /*
        for(i=0; i<sudokuSize; i++)
        {
            if(Check_map[i] == 0)
            {
                check_col(Check_map, i);
            }
        }

        for(i=0; i<sudokuSize; i++)
        {
            if(Check_map[i] == 0)
            {
                check_squa(Check_map, i);
            }
        }*/

        if(isCorrect(Check_map))
        {
            for(i=0; i<sudokuSize; i++)
                Correct[i] = Check_map[i];
            return true;
        }
        else
            test++;
    }

    return false;
}
void Sudoku::check_row(int map[], int num){
    int num_lost = 1;
    int count_row[length]={};
    bool num_Same;
    int row = num/length;

    for(int i=row*length; i<(row+1)*length; i++)
    {
        if(map[i] == 0)
        {
            count_row[row]++; //計算 0 在每一列的次數
            if(count_row[row] > 1)
                break;
        }
    }

    if(count_row[row] == 1)
    {
        while(num_lost <= 9)
        {
            for(int i=row*length; i<(row+1)*length; i++)
            {
                num_Same = false;
                if(num_lost == map[i])
                {
                    num_Same = true;
                    num_lost++;
                    break;
                }
            }
            if(num_Same == false)
            {
                map[num] = num_lost;
            }
        }
    }
}
void Sudoku::check_col(int map[], int num){
    int num_lost2 = 1;
    bool num_Same2;
    int col = num%length;
    int count_col[length]={};

    for(int i=col; i<col+length*length; i=i+length)
    {
        if(map[i] == 0)
        {
            count_col[col]++; //計算 0 在每一行的次數
            if(count_col[col] > 1)
                break;
        }
    }

    if(count_col[col] == 1)
    {
        while(num_lost2 <= 9)
        {
            for(int i=col; i<col+length*length; i=i+length)
            {
                num_Same2 = false;
                if(num_lost2 == map[i])
                {
                    num_Same2 = true;
                    num_lost2++;
                    break;
                }
            }
            if(num_Same2 == false)
            {
                map[num] = num_lost2;
            }
        }
    }

}
void Sudoku::check_squa(int map[], int num){
    int num_lost3 = 1;
    int count_squa[length]={};
    bool num_Same3;
    int row = num/length;
    int col = num%length;
    int squa = (row/3)*3*length+(col/3)*3;
    int squa_num = row/3*3+col/3;

    for(int i=squa; i<=squa+2*length; i=i+length) // check cells
    {
        for(int j=i; j<i+3; j++)
        {
            if(map[j] == 0)
            {
                count_squa[squa_num]++;     //計算 0 在每個 3x3 的次數
                if(count_squa[squa_num] > 1)
                    break;
            }

        }
        if(count_squa[squa_num] > 1)
            break;
    }

    if(count_squa[squa_num] == 1)
    {
        while(num_lost3 <= 9)
        {
            for(int i=squa; i<=squa+2*length; i=i+length)
            {
                for(int j=i; j<i+3; j++)
                {
                    num_Same3 = false;
                    if(num_lost3 == map[j])
                    {
                        num_Same3 = true;
                        num_lost3++;
                        break;
                    }
                }
                if(num_Same3 == true)
                    break;
            }
            if(num_Same3 == false)
            {
                map[num] = num_lost3;
            }
        }
    }
}
bool Sudoku::check_num(int Zero, int set_num){
    int num;
    num = set_num;
    int row = Zero/length;
    int col = Zero%length;
    int squa = (row/3)*3*length+(col/3)*3;
    int i,j;

    for(i=row*length; i<(row+1)*length; i++)
        if(num == map[i])
        {
            //cout << "Same1! " << i << endl;
            //count_num[ map[i]-1 ] = 1;
            return false;
            //test = false;
        }

    for(i=col; i<col+length*length; i=i+length)
        if(num == map[i])
        {
            //cout << "Same2! " << i << endl;
            //count_num[ map[i]-1 ] = 1;
            return false;
            //test = false;
        }

    for(i=squa; i<=squa+2*length; i=i+length) // check cells
    {
        for(j=i; j<i+3; j++)
        {
            if(num == map[j])
            {
                //cout << "Same3! " << j << endl;
                //count_num[ map[j]-1 ] = 1;
                return false;
                //test = false;
            }

        }
    }
/*
    for(i=0; i<9; i++)
        if(count_num[i] == 0)
            count_zero++;

    if(count_zero == 1)
        for(i=0; i<9; i++)
            if(count_num[i] == 0)
            {
                cout << Zero << "," << i << endl;
                map[Zero] = i;
            }
*/


    return true;
}

int Sudoku::Check_time = 0;
bool Sudoku::Solve_main(){

    //fstream out;
    //out.open("out.txt",ios::out|ios::app);

    if(Check_time == 0)
    {
        Check_time++;
        Check();
    }

    int FirstZero;
    FirstZero = getFirstZeroIndex();

    if(FirstZero == -1)
    {
        //out << "Zero=" << FirstZero << endl;
        if(isCorrect(map))
        {
            //out << "Correct!" << endl;
            return true;
        }
        else
        {
            //out << "Final wrong!" << endl;
            return false;
        }

    }
    else
    {
        int set_num;
        for(set_num=1; set_num<=9; set_num++)
        {
            //out << "set_num = " << set_num << ", Zero = " << FirstZero << endl;
            /*if(set_num == 9 && FirstZero == 18)
            {
                for(int i=0; i<sudokuSize; i++)
                {
                    cout << getElement(i) << " ";
                    if(i%9==8)
                        cout << endl;
                }
                cout << "----------------------" << endl;
            }*/

            if(check_num(FirstZero, set_num))
            {
                //out << "num = " << set_num << ", Zero = " << FirstZero << endl;
                setElement(FirstZero, set_num);
                if(Check())
                {
                    //out << "Check Correct!" << endl;
                    judge++;
                    //setElement(FirstZero, set_num+1);
                    //Solve_main();
                    continue;
                    return true;
                }
                else
                {
                    //out << "Check Wrong!" << endl;
                    bool tmp = Solve_main();
                    if(tmp == false && set_num == 9)
                    {
                        //out << "set1 0, Zero " << FirstZero << endl;
                        setElement(FirstZero, 0);
                        Check();
                    }

                }
            }
            else if(set_num == 9)
            {
                //out << "set 0, Zero " << FirstZero << endl;
                setElement(FirstZero, 0);
            }
        }
    }

    return false;
}
void Sudoku::Solve(){

    clock_t start, finish;
    start = clock();

    int i;
    for(i=0; i<sudokuSize; i++)
    {
        cout << getElement(i) << " ";
        if(i%length==length-1)
            cout << endl;
    }

    cout << "----------------------" << endl;
    if(!Check_Dark(map))
    {
        cout << "Dark place is wrong!" << endl;
        exit(0);
    }

    Solve_main();
    cout << judge << endl;
    if(judge == 1)
    {
        for(i=0; i<sudokuSize; i++)
        {
            cout << Correct[i] << " ";
            if(i%length==length-1)
                cout << endl;
        }
    }


    finish = clock();
    double duration = finish-start;
    cout << "start time = " << start << endl;
    cout << "finish time = " << finish << endl;
    cout << "duration = " << duration << endl;

}

bool Sudoku::Check_Dark(int Check_map[]){

    int num=0;
    for(int k=0; k<sudokuSize; k=k+3)
    {
        if(Check_map[k] == -1)
        {
            num++;
            int row = k/length;
            int col = k%length;
            int squa = (row/3)*3*length+(col/3)*3;
            for(int i=squa; i<=squa+2*length; i=i+length) // check cells
            {
                for(int j=i; j<i+3; j++)
                {
                    if(Check_map[j] != -1)
                    {
                        cout << " -1 wrong place" << endl;
                        return false;
                    }

                }
            }
            k = k+24;
        }
    }
    cout << "num=" << num << endl;
    if(num != 4)
        return false;

    return true;
}

