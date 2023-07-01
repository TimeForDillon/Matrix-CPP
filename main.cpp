/*******************************************************************************
* AUTHOR       : Dillon Welsh, David Dang
* LAB15        : MATRIX
* CLASS        : CS 3A
* SECTION      : 71206
* DUE DATE     : 11/18/2020
*******************************************************************************/

#include "matrix.h"

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

int main()
{
    ofstream test;              // CALC - output file stream variable

    test.open("output.txt");      // OUTPUT - file for output

    // OUTPUT - testing functions and methods
    cout << "Demonstrating with string matrix:" << endl << endl;
    test << "Demonstrating with string matrix:" << endl << endl;

    Matrix<string> c;       // String Matrix

    string array[6] = {"Congra", "y", "ar", "alm", "don", "La"};

    c.setMatrix(array);     // setMatrix() - sets matrix to passed in 2D array

    cout << "Matrix set to first array" << endl << endl;
    test << "Matrix set to first array" << endl << endl;

    c.printMatrix();        // printMatrix() - prints out each element of matrix
    cout << endl;
    test << c << endl;

    Matrix<string> d;       // String Matrix

    // setElement() - sets the passed elements of matrix to the passed in value.
    d.setElement(0,0,"tulations");
    d.setElement(0,1,"ou");
    d.setElement(0,2,"e");
    d.setElement(1,0,"ost");
    d.setElement(1,1,"e with the");
    d.setElement(1,2,"b!");

    c = c + d;          // Testing + operator

    // OUTPUT - testing functions and methods
    cout << "Matrix incremented by second array" << endl << endl;
    test << "Matrix incremented by second array" << endl << endl;
    cout << c << endl;
    test << c << endl;
    cout << "Demonstrating with int matrix:" << endl << endl;
    test << "Demonstrating with int matrix:" << endl << endl;

    Matrix<int> a;      // Int Matrix
    int array2[2][3] = {{1,2,3},{4,5,6}};   // CALC - 2D array

    // setMatrix() - sets matrix to passed in 2D array
    a.setMatrix(array2);

    // OUTPUT - testing functions and methods
    cout << "Matrix set to first array" << endl << endl;
    test << "Matrix set to first array" << endl << endl;
    cout << a << endl;
    test << a << endl;

    int array3[6] = {6,5,4,3,2,1};      // CALC - 1D array
    Matrix<int> e;      // Int Matrix
    // setMatrix() - sets matrix to passed in 2D array
    e.setMatrix(array3);

    a = a + e;          // Testing + operator

    // OUTPUT - testing functions and methods
    cout << "Matrix incremented by second array" << endl << endl;
    test << "Matrix incremented by second array" << endl << endl;
    cout << a << endl;
    test << a << endl;
    cout << "Demonstrating with float matrix:" << endl << endl;
    test << "Demonstrating with float matrix:" << endl << endl;

    Matrix<double> b;   // Double Matrix
    double array4[6] = {1.6, 2.5, 3.4, 4.3, 5.2, 6.1};
    // setMatrix() - sets matrix to passed in 2D array
    b.setMatrix(array4);

    // OUTPUT - testing functions and methods
    cout << "Matrix set to first array" << endl << endl;
    test << "Matrix set to first array" << endl << endl;
    cout << b << endl;
    test << b << endl;

    Matrix<double> add; // Double Matrix
    // setElement() - sets the passed elements of matrix to the passed in value.
    add.setElement(0,0,5.4 + 0.7);
    add.setElement(0,1,4.5 + 0.7);
    add.setElement(0,2,3.6 + 0.7);
    add.setElement(1,0,2.7 + 0.7);
    add.setElement(1,1,1.8 + 0.7);
    add.setElement(1,2,0.9 + 0.7);

    b = b + add;        // Testing + operator

    // OUTPUT - testing functions and methods
    cout << "Matrix incremented by second array" << endl << endl;
    test << "Matrix incremented by second array" << endl << endl;
    cout << b << endl;
    test << b << endl;

    test.close();       // closing text file

    return 0;
}
