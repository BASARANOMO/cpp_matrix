#include "matrice.h"
#include <cstdlib>
#include <time.h>
using namespace std;

// Author: ZHANG Mofan
// Edit time: 09/27/2020
// Edit time: 06/10/2020


int main(){
    // constructor 1
    cout << "***************************************************" << endl;
    cout << "Test constructor without attribute" << endl;
    Matrice A(2,3);
    cout << "Matrix A" << endl;
    A.show();

    // constructor 2
    cout << "***************************************************" << endl;
    cout << "Test constructor with a double" << endl;
    Matrice B(2, 3, 1.5);
    cout << "Matrix B" << endl;
    B.show();

    // constructor 3
    cout << "***************************************************" << endl;
    cout << "Test constructor with an array" << endl;
    double* arr1 = new double[20];
    double* arr2 = new double[30];
    srand(time(NULL));
    for (int i = 0; i < 20; i++)
        arr1[i] = rand() / double(RAND_MAX/(10));
    for (int i = 0; i < 30; i++)
        arr2[i] = rand() / double(RAND_MAX);

    Matrice C(4, 5, arr1);
    cout << "Matrix C" << endl;
    C.show();

    Matrice D(5, 6, arr2);
    cout << "Matrice D" << endl;
    D.show();

    // set element value
    cout << "***************************************************" << endl;
    cout << "Test set element" << endl;
    A.set(1, 2, 1.11);
    cout << "Matrix A" << endl;
    A.show();

    // get element value
    cout << "***************************************************" << endl;
    cout << "Test get element: " << C.get(2, 3) << endl;
    cout << "Matrix C" << endl;
    C.show();

    // multiplication
    cout << "***************************************************" << endl;
    cout << "Test matrix multiplication" << endl;
    Matrice E = C * D;
    cout << "Matrix E = C * D" << endl;
    E.show();

    // assignement
    cout << "***************************************************" << endl;
    cout << "Test assignment" << endl;
    D = B;
    cout << "D = B" << endl;
    D.show();
    cout << "Matrix D memory sharring count: " << D.getCount() << endl;

    // shallow copy
    cout << "***************************************************" << endl;
    cout << "Test shallow copy constructor" << endl;
    cout << "Matrix F(D)" << endl;
    Matrice F(D);
    cout << "Matrix F memory sharring count: " << F.getCount() << endl;
    cout << "Matrix D memory sharring count: " << D.getCount() << endl;

    cout << "Matrix G(F)" << endl;
    Matrice G(F);
    cout << "Matrix G memory sharring count: " << G.getCount() << endl;
    cout << "Matrix F memory sharring count: " << F.getCount() << endl;
    cout << "Matrix D memory sharring count: " << D.getCount() << endl;

    // assignment
    cout << "***************************************************" << endl;
    cout << "Test again assignment" << endl;
    F = A;
    cout << "F = A" << endl;
    cout << "Matrix G memory sharring count: " << G.getCount() << endl;
    cout << "Matrix F memory sharring count: " << F.getCount() << endl;
    cout << "Matrix D memory sharring count: " << D.getCount() << endl;
    cout << "Matrix B memory sharring count: " << B.getCount() << endl;
    cout << "Matrix A memory sharring count: " << A.getCount() << endl;

    // destructor
    cout << "***************************************************" << endl;
    cout << "Destructor" << endl;
    return 0;
}