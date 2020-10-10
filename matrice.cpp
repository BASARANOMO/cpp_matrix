#include "matrice.h"
#include <cassert>
#include <assert.h>
using namespace std;

// Author: ZHANG Mofan
// Edit time: 09/27/2020


// init tab value
void Matrice::init() {
    for (int i = 0; i < nrow * ncol; i++)
        tab[i] = 0;
}


// constructor
Matrice::Matrice(int m, int n) {
    nrow = m;
    ncol = n;
    tab = new double[nrow * ncol];
    compteur = new int(1);
    init();
    cout << "Matrix constructed & memory allocated." << endl;
}


// constructor overload, initialization by a given value
Matrice::Matrice(int m, int n, double val) {
    nrow = m;
    ncol = n;
    tab = new double[nrow * ncol];
    compteur = new int(1);
    for (int i = 0; i < nrow * ncol; i++)
        tab[i] = val;
    cout << "Matrix constructed & memory allocated." << endl;
}


// constructor overload, construction with a dimension array
Matrice::Matrice(int m, int n, double* Array) {
    nrow = m;
    ncol = n;
    tab = new double[nrow * ncol];
    compteur = new int(1);
    for (int i = 0; i < nrow * ncol; i++)
        tab[i] = Array[i];
    cout << "Matrix constructed & memory allocated." << endl;
}


// shallow copy constructor (memory sharing)
Matrice::Matrice(const Matrice& matrice2) {
    nrow = matrice2.nrow;
    ncol = matrice2.ncol;
    tab = matrice2.tab;
    compteur = matrice2.compteur;
    ++(*compteur);
    cout << "Matrix constructed by shallow copy, memory sharing count = " << *compteur << endl;
}


// deep copy
void Matrice::deepCopy(const Matrice& matrice2) {
    nrow = matrice2.nrow;
    ncol = matrice2.ncol;
    tab = new double[nrow * ncol];
    compteur = new int(1);
    double* src = matrice2.tab, * dst = tab;
    for (int i = 0; i < nrow * ncol; i++)
        *dst++ = *src++;
}


// deconstructor
Matrice::~Matrice() {
    if (0 == --(*compteur))
    {
        delete[] tab;
        delete compteur;
        cout << "Matrix destructed, memory released." << endl;
    }
    else
        cout << "Matrix destructed, memory sharing count = " << *compteur << endl;
}


// shallow copy assignment
Matrice& Matrice::operator=(const Matrice& matrice2) {
    if (0 == --(*compteur))
    {
        delete[] tab;
        delete compteur;
    }
    nrow = matrice2.nrow;
    ncol = matrice2.ncol;
    tab = matrice2.tab;
    compteur = matrice2.compteur;
    ++(*compteur);
    cout << "Shallow copy assignment, memory sharing count = " << *compteur << endl;
    return *this;
} 


/* assignment
Matrice& Matrice::operator=(const Matrice& matrice2) {
    if (0 == --(*compteur))
    {
        delete[] tab;
        delete compteur;
    }
    nrow = matrice2.nrow;
    ncol = matrice2.ncol;
    tab = new double[nrow*ncol];
    compteur = new int(1);
    double *src = matrice2.tab, *dst = tab;
    for(int i=0; i<nrow*ncol; i++)
        *dst++ = *src++;
    return *this;
}
*/

// multiplication operator
Matrice Matrice::operator*(const Matrice& matrice2) const{
    Matrice multip(nrow, matrice2.ncol, 0.0); // call the constructor
    // verify dimension of matrix
    assert(ncol == matrice2.nrow);

    double temp;
    // multiplication
    for (int i = 0; i < nrow; i++)
        for (int j = 0; j < matrice2.ncol; j++)
        {
            temp = 0.0;
            for (int k = 0; k < ncol; k++)
                temp += tab[i * ncol + k] * matrice2.tab[k * matrice2.ncol + j];
            multip.tab[i * matrice2.ncol + j] = temp;
        }
    return multip;
}


// get element
double Matrice::get(int m, int n) const {
    return tab[m * ncol + n];
}


// set element
void Matrice::set(int m, int n, double val) {
    tab[m * ncol + n] = val;
}


// print matrix
void Matrice::show() const {
    cout << *this << endl;
}


// overload << operator
std::ostream& operator<<(std::ostream& OS, const Matrice& matrice) {
    for (int i = 0; i < matrice.nrow; i++)
    {
        for (int j = 0; j < matrice.ncol; j++)
        {
            OS << matrice.tab[i * matrice.ncol + j] << " ";
        }
        OS << std::endl;
    }
    return OS;
}


// get memory sharing count
int Matrice::getCount() const {
    return *compteur;
}