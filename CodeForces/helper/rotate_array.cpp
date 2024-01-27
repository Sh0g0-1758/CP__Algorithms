#include <iostream>

using namespace std;

// Function to rotate the array 90 degrees clockwise
void rotateClockwise(int *arr, int rows, int cols)
{
    int temp[cols][rows];
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            temp[j][rows - i - 1] = *(arr + i * cols + j);
        }
    }
    for (int i = 0; i < cols; i++)
    {
        for (int j = 0; j < rows; j++)
        {
            cout << temp[i][j] << " ";
        }
        cout << endl;
    }
}

// Function to rotate the array 90 degrees counterclockwise
void rotateCounterClockwise(int *arr, int rows, int cols)
{
    int temp[cols][rows];
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            temp[cols - j - 1][i] = *(arr + i * cols + j);
        }
    }
    for (int i = 0; i < cols; i++)
    {
        for (int j = 0; j < rows; j++)
        {
            cout << temp[i][j] << " ";
        }
        cout << endl;
    }
}

// Function to rotate the array 180 degrees
void rotate180(int *arr, int rows, int cols)
{
    int temp[rows][cols];
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            temp[rows - i - 1][cols - j - 1] = *(arr + i * cols + j);
        }
    }
    // Copying the rotated array back to the original array
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            *(arr + i * cols + j) = temp[i][j];
        }
    }
}

int main()
{
    const int rows = 3;
    const int cols = 4;
    int arr[rows][cols] = {{1, 2, 3, 4},
                           {5, 6, 7, 8},
                           {9, 10, 11, 12}};

    // Rotate 90 degrees counterclockwise
    rotateCounterClockwise((int *)arr, rows, cols);
    cout << "Rotated 90 degrees counterclockwise:" << endl;

    // Rotate 180 degrees
    rotate180((int *)arr, rows, cols);
    cout << "Rotated 180 degrees:" << endl;

    return 0;
}
