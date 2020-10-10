#include <iostream>

// Author: ZHANG Mofan
// Edit time: 09/27/2020

class Matrice {
private:
    int nrow; // nomber of rows
    int ncol; // nomber of columns
    double* tab; // pointer for elements storage
    int* compteur; // count memory sharing

public:
    // init tab value by 0
    void init();

    // constructor, initialization by 0
    Matrice(int m, int n);

    // constructor overload, initialization by a given value
    Matrice(int m, int n, double val);

    // constructor overload, construction with one dimension array
    Matrice(int m, int n, double* Array);

    // copy constructor (memory sharing)
    Matrice(const Matrice& matrice2);

    // deep copy
    void deepCopy(const Matrice& matrice2);

    // destructor
    ~Matrice();

    // assignment
    Matrice& operator=(const Matrice& matrice2);

    // multiplication operator
    Matrice operator*(const Matrice& matrice2) const;

    // get element
    double get(int m, int n) const;

    // set element
    void set(int m, int n, double val);

    // print matrix
    void show() const;

    // get memory sharing count
    int getCount() const;

    // overload << operator
    friend std::ostream& operator<<(std::ostream& os, const Matrice& matrice);
};
