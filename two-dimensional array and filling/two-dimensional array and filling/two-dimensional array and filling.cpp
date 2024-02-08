#include <iostream>
using namespace std;

int main() 
{
    setlocale(LC_ALL, "ru");
    int n;
    cout << "Введите число: ";
    cin >> n;

    int array[3][3];

    for (int i = 0; i < 3; i++) 
    {
        array[0][i] = n;
        n *= 2;
    }

    for (int i = 1; i < 3; i++) 
    {
        for (int j = 0; j < 3; j++) 
        {
            array[i][j] = array[i - 1][j] * 2;
        }
    }

    for (int i = 0; i < 3; i++) 
    {
        for (int j = 0; j < 3; j++) 
        {
            cout << array[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
