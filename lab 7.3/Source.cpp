#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

void Create(int** a, const int rowCount, const int colCount, const int Low, const int High);
void Print(int** a, const int rowCount, const int colCount);
void PrintModify(int* f, const int j);
bool Part1_Count(int** a, const int rowCount, const int colCount, int& count);
void Part2_Number(int** a, int* f, const int rowCount, const int colCount, int& Number);

int main()
{
    srand((unsigned)time(NULL));

    int Low = 0;
    int High = 15;
    int rowCount, colCount;

    cout << "rowCount = "; cin >> rowCount;
    cout << "colCount = "; cin >> colCount;

    int* f = new int[colCount];

    int** a = new int* [rowCount];
    for (int i = 0; i < rowCount; i++)
        a[i] = new int[colCount];
    int k = colCount;

    Create(a, rowCount, colCount, Low, High);
    Print(a, rowCount, colCount);

    int count_rows = 0;
    cout << "Count of rows with at least one 0" << endl;
    if (Part1_Count(a, rowCount, colCount, count_rows))
    {
        cout << endl;
        cout << "count = " << count_rows << endl;
        cout << endl;
    }
    else
    {
        cout << "there are no zero elements" << endl;
        cout << endl;
    }

    int Number;
    Part2_Number(a, f, rowCount, colCount, Number);

    cout << "Index of column with biggest seriest" << endl;
    cout << endl;
    cout << "Number = " << Number << endl;
    cout << endl;

    for (int i = 0; i < rowCount; i++)
        delete[] a[i];
    delete[] a;

    delete[] f;

    system("pause");
    return 0;
}

void Create(int** a, const int rowCount, const int colCount, const int Low,
    const int High)
{
    for (int i = 0; i < rowCount; i++)
        for (int j = 0; j < colCount; j++)
            a[i][j] = Low + rand() % (High - Low + 1);
}

void Print(int** a, const int rowCount, const int colCount)
{
    cout << endl;
    for (int i = 0; i < rowCount; i++)
    {
        for (int j = 0; j < colCount; j++)
            cout << setw(4) << a[i][j];
        cout << endl;
    }
    cout << endl;
}

void PrintModify(int* f, const int j)
{
    for (int i = 0; i < j; i++)
        cout << setw(4) << f[i];
    cout << endl;
}

bool Part1_Count(int** a, const int rowCount, const int colCount, int& count_rows)
{
    bool result = false;
    count_rows = 0;
    for (int i = 0; i < rowCount; i++)
    {
        for (int j = 0; j < colCount; j++)
            if (a[i][j] == 0)
            {
                result = true;
                count_rows++;
                break;
            }
    }
    return result;
}

void Part2_Number(int** a, int* f, const int rowCount, const int colNo, int& Number)
{
    int maxC = 0;
    int maxSJ = 0;
    Number = 0;
    int count = 1;
    int j;
    for (j = 0; j < colNo; j++)
    {
        for (int r = 1; r < rowCount; r++)
        {
            if (a[r - 1][j] == a[r][j])
            {
                count++;
                if (maxC < count)
                {
                    maxC = count;
                }
            }
            else
                count = 1;
        }
        f[j] = maxC;
        maxC = 0;
    }
    cout << "Max seriest of each column: " << endl;
    PrintModify(f, j);
    cout << endl;

    for (int i = 0; i < j; i++)
    {
        if (maxSJ < f[i])
        {
            maxSJ = f[i];
            Number = i;
        }
    }
}