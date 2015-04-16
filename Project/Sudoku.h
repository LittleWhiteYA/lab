#include <iostream>
#include <fstream>

#include <time.h>

class Sudoku {
public:
    Sudoku();
    Sudoku(const int init_map[]);
    void setMap(const int set_map[]);
    int getElement(int index);
    bool isCorrect(int map[]);
    static const int sudokuSize = 144;

    bool Solve_main();
    bool Check();
    void ReadIn();
    int getFirstZeroIndex();
    void setElement(int index, int value);
    int judge;
    void Solve();   //main
    void GiveQuestion();

private:
    bool checkUnity(int arr[]);
    int map[sudokuSize];

    int Correct[sudokuSize];
    static const int length = 12;
    void check_row(int map[], int num);
    void check_col(int map[], int num);
    void check_squa(int map[], int num);
    bool check_num(int Zero, int set_num);
    static int Check_time;
    bool Check_Dark(int Check_map[]);

};

