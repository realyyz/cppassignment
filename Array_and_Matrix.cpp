#include <iostream>
using namespace std;
int max_size = 8; // This is the maximum size of the matrix.
void matrix_print(double *matrix, int number_of_rows, int number_of_columns)
{
    for (int i = 0; i < number_of_columns; i++)
    {
        for (int j = 0; j < number_of_rows; j++)
            cout << *(matrix + i * (max_size - 1) + j) << "\t";
        cout << endl;
    }
}
void matrix_transpose_f(double *original_matrix, double *matrix_transpose, int number_of_rows, int number_of_columns)
{
    for (int i = 0; i < number_of_columns; i++)
    {
        for (int j = 0; j < number_of_rows; j++)
            *(matrix_transpose + i * (max_size - 1) + j) = *(original_matrix + j * (max_size - 1) + i);
    }
}
void mono_matrix_f(double *original_matrix, double *mono_matrix, int number_of_rows, int number_of_columns)
{
    for (int i = 0; i < number_of_columns; i++)
    {
        for (int j = 0; j < number_of_rows; j++)
            *(mono_matrix + i * number_of_columns + j) = *(original_matrix + i * (max_size - 1) + j);
    }
}
void mono_matrix_print(double *mono_matrix, int number_of_rows, int number_of_columns)
{
    for (int i = 0; i < (number_of_columns * number_of_rows); i++)
    {
        cout << mono_matrix[i] << " ";
    }
}

int main()
{
    int number_of_rows, number_of_columns;
    double original_matrix[max_size - 1][(max_size - 1)], matrix_transpose[(max_size - 1)][(max_size - 1)], mono_matrix[(max_size - 1) * (max_size - 1)];
    cout << "Please specify the number of the rows and columns." << endl;
    cin >> number_of_rows >> number_of_columns;

    // This part is for the input and printing of the matrix.
    printf("The number of rows is %d, the number of columns is %d.", number_of_rows, number_of_columns);
    for (int i = 0; i < number_of_columns; i++)
    {
        printf("Please input the %dth column of the matrix. \n", i + 1);
        for (int j = 0; j < number_of_rows; j++)
            cin >> original_matrix[i][j];
    }
    cout << "The original matrix:" << endl;
    matrix_print(*original_matrix, number_of_rows, number_of_columns);

    // This part is for the printing of the transposed matrix.
    // Pass the address of the original matrix, so we can change the values of the main matrix.
    matrix_transpose_f(*original_matrix, *matrix_transpose, number_of_rows, number_of_columns);
    cout << "The transposed matrix:" << endl;
    matrix_print(*matrix_transpose, number_of_rows, number_of_columns);

    mono_matrix_f(*original_matrix, mono_matrix, number_of_rows, number_of_columns);
    cout << "The mono matrix:" << endl;
    mono_matrix_print(mono_matrix, number_of_rows, number_of_columns);
}