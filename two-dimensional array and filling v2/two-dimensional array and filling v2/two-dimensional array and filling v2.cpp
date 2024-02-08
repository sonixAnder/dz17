#include <iostream>
using namespace std;

int main() 
{
    setlocale(LC_ALL, "ru");
    int n;

    cout << "Введите число: ";
    cin >> n;

    int arr[3][3];

    for (int i = 0; i < 3; i++) 
    {
        arr[0][i] = n + i;
    }

    for (int i = 1; i < 3; i++) 
    {
        for (int j = 0; j < 3; j++) 
        {
            arr[i][j] = arr[i - 1][j] + 1;
        }
    }

    cout << "Созданный массив:\n";
    for (int i = 0; i < 3; i++) 
    {
        for (int j = 0; j < 3; j++) 
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
