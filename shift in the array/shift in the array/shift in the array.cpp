#include <iostream>
using namespace std;

const int ROWS = 5;
const int COLS = 5;

void fillArray(int array[ROWS][COLS]) 
{
    srand(time(nullptr)); // инициализация генератора случайных чисел
    for (int i = 0; i < ROWS; ++i) 
    {
        for (int j = 0; j < COLS; ++j) 
        {
            array[i][j] = rand() % 100; // заполняем случайными числами от 0 до 99
        }
    }
}

void printArray(int array[ROWS][COLS]) 
{
    for (int i = 0; i < ROWS; ++i) 
    {
        for (int j = 0; j < COLS; ++j) 
        {
            cout << array[i][j] << " ";
        }
        cout << endl;
    }
}

void shiftArray(int array[ROWS][COLS], int shift, char direction) 
{
    int temp[ROWS][COLS]; // временный массив для сохранения сдвинутых значений

    // выполняем циклический сдвиг по заданному направлению
    for (int k = 0; k < shift; ++k)
    {
        for (int i = 0; i < ROWS; ++i)
        {
            for (int j = 0; j < COLS; ++j)
            {
                switch (direction) 
                {
                case 'l': // влево
                    temp[i][j] = array[i][(j + 1) % COLS];
                    break;

                case 'r': // вправо
                    temp[i][j] = array[i][(j + COLS - 1) % COLS];
                    break;

                case 'u': // вверх
                    temp[i][j] = array[(i + 1) % ROWS][j];
                    break;

                case 'd': // вниз
                    temp[i][j] = array[(i + ROWS - 1) % ROWS][j];
                    break;

                default:
                    break;
                }
            }
        }

        // копируем сдвинутые значения из временного массива обратно в исходный массив
        for (int i = 0; i < ROWS; ++i) 
        {
            for (int j = 0; j < COLS; ++j) 
            {
                array[i][j] = temp[i][j];
            }
        }
    }
}

int main() 
{
    setlocale(LC_ALL, "ru");
    int array[ROWS][COLS];

    fillArray(array);
    cout << "Исходный массив:" << endl;
    printArray(array);

    int shift;
    char direction;
    cout << "Введите количество сдвигов: ";
    cin >> shift;

    cout << "Введите направление сдвига (l - влево, r - вправо, u - вверх, d - вниз): ";
    cin >> direction;

    shiftArray(array, shift, direction);
    cout << "Результат сдвига:" << endl;
    printArray(array);

    return 0;
}