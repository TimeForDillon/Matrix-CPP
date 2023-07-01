#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

/*******************************************************************************
* MATRIX CLASS
*_______________________________________________________________________________
* This program defines the functions and constructors for the Matrix Class.
*_______________________________________________________________________________
* INPUT:
*  "Matrix.h": The function and constructor
*	declarations for the Matrix class
*
* OUTPUT:
*  None
*******************************************************************************/

const int MAXROWS = 2;      // Matrix max row size
const int MAXCOLS = 3;      // Matrix max column size


template <typename T>
class Matrix
{
public:
/*******************************************************************************
* CONSTRUCTOR MATRIX
*_______________________________________________________________________________
* This constructor constructs an empty Matrix object.
*******************************************************************************/
    Matrix();
/*******************************************************************************
* FUNCTION PRINTMATRIX
*_______________________________________________________________________________
* This function prints out the contents of the Matrix object.
*******************************************************************************/
    void printMatrix() const;
/*******************************************************************************
* FUNCTION OPERATOR<<
*_______________________________________________________________________________
* This function overloads the << operator for the Matrix class.
*******************************************************************************/
    friend ostream& operator<<(ostream& out,        // IN - ostream variable
                               const Matrix m)      // IN - matrix object
    {
        // PROCESSING - traversing 2D array
        for (int i = 0; i < m.rows; i++)
        {
            for (int j = 0; j < m.cols; j++)
            {
                out << m.array[i][j] << "  ";
            }
            out << endl;
        }
        return out;
    }
/*******************************************************************************
* FUNCTION SETELEMENT
*_______________________________________________________________________________
* This function sets the passed/indicated element of the matrix to the passed
* in value.
*******************************************************************************/
    void setElement(int row,                        // IN - number of row
                    int col,                        // IN - number of column
                    T value);                       // IN - value to be stored
/*******************************************************************************
* FUNCTION SETMATRIX
*_______________________________________________________________________________
* This function sets the matrix to the 1D array that is passed in.
*******************************************************************************/
    void setMatrix(const T m[]);                    // IN - 1D array
/*******************************************************************************
* FUNCTION SETMATRIX
*_______________________________________________________________________________
* This function sets the matrix to the passed in 2D array.
*******************************************************************************/
    void setMatrix(const T m[][MAXCOLS]);           // IN - 2D array
/*******************************************************************************
* FUNCTION OPERATOR+
*_______________________________________________________________________________
* This function overloads the + operator for the Matrix class.
*******************************************************************************/
    const Matrix operator+(const Matrix &m) const;  // IN - matrix object
private:
    T array[MAXROWS][MAXCOLS];      // CALC & OUT - 2D array storing matrix
    int rows;                       // CALC - number of rows in matrix
    int cols;                       // CALC - number of columns in matrix
};

/*******************************************************************************
* CONSTRUCTOR MATRIX
*_______________________________________________________________________________
* This constructor constructs an empty Matrix object.
*_______________________________________________________________________________
* PRE-CONDITIONS
* None
*
* POST-CONDITIONS
* None
*******************************************************************************/

template <typename T>
Matrix<T>::Matrix()
{
    // PROCESSING - instantiates empty 2D array
    rows = MAXROWS;
    cols = MAXCOLS;
    T array[MAXROWS][MAXCOLS] = {};
}

/*******************************************************************************
* FUNCTION PRINTMATRIX
*_______________________________________________________________________________
* This function prints out the contents of the Matrix object.
*_______________________________________________________________________________
* PRE-CONDITIONS
* None
*
* POST-CONDITIONS
* None
*******************************************************************************/

template <typename T>
void Matrix<T>::printMatrix() const
{
    // PROCESSING - traversing 2D array
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << array[i][j] << "  ";

        }
        cout << endl;
    }
}

/*******************************************************************************
* FUNCTION SETELEMENT
*_______________________________________________________________________________
* This function sets the passed/indicated element of the matrix to the passed
* in value.
*_______________________________________________________________________________
* PRE-CONDITIONS
* int row, int col, T value
*
* POST-CONDITIONS
* None
*******************************************************************************/

template <typename T>
void Matrix<T>::setElement(int row,                 // IN - number of row
                           int col,                 // IN - number of column
                           T value)                 // IN - value to be stored
{
    // PROCESSING - set to passed value
    array[row][col] = value;
}

/*******************************************************************************
* FUNCTION SETMATRIX
*_______________________________________________________________________________
* This function sets the matrix to the 1D array that is passed in.
*_______________________________________________________________________________
* PRE-CONDITIONS
* const T m[]
*
* POST-CONDITIONS
* None
*******************************************************************************/

template <typename T>
void Matrix<T>::setMatrix(const T m[])              // IN - 1D array
{
    int index = 0;      // CALC - for incrimenting 1D array
    // PROCESSING - traversing 2D array
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            array[i][j] = m[index];
            index++;
        }
    }
}

/*******************************************************************************
* FUNCTION SETMATRIX
*_______________________________________________________________________________
* This function sets the matrix to the passed in 2D array.
*_______________________________________________________________________________
* PRE-CONDITIONS
* const T m[][MAXCOLS]
*
* POST-CONDITIONS
* None
*******************************************************************************/

template <typename T>
void Matrix<T>::setMatrix(const T m[][MAXCOLS])           // IN - 2D array
{
    // PROCESSING - traversing 2D array
    for (int i = 0; i < MAXROWS; i++)
    {
        for (int j = 0; j < MAXCOLS; j++)
        {
            array[i][j] = m[i][j];
        }
    }
}

/*******************************************************************************
* FUNCTION OPERATOR+
*_______________________________________________________________________________
* This function overloads the + operator for the Matrix class.
*_______________________________________________________________________________
* PRE-CONDITIONS
* const Matrix<T> &m
*
* POST-CONDITIONS
* const Matrix<T>
*******************************************************************************/

template <typename T>
const Matrix<T> Matrix<T>::operator+(const Matrix<T> &m) const // IN - mtrx obj
{
    Matrix<T> temp;
    // PROCESSING - traversing 2D array
    for (int i = 0; i < MAXROWS; i++)
    {
        for (int j = 0; j < MAXCOLS; j++)
        {
            temp.setElement(i,j,array[i][j] + m.array[i][j]);
        }
    }
    return temp;
}

#endif // MATRIX_H
