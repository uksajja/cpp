#ifndef matrixSTL_
#define matrixSTL_

#include<iostream>
#include<vector>

template <class T>
class MatrixSTL {
    private:
        std::vector<std::vector<T> > mat;
        unsigned int mRows;
        unsigned int mCols;
    public:
    //Constructors
        MatrixSTL(unsigned int r, unsigned int c, const T& iniVal);
        MatrixSTL(std::vector<std::vector<T>> m);
        MatrixSTL(const MatrixSTL<T>& rhs );//Copy constructor
    //Destructor
        virtual ~MatrixSTL() {};

    //Matrix-Matrix operations    
        MatrixSTL<T> operator+(const MatrixSTL<T>& rhs) const;
        MatrixSTL<T> operator-(const MatrixSTL<T>& rhs) const;
        MatrixSTL<T> operator*(const MatrixSTL<T>& rhs) const;
    //Operators
        MatrixSTL<T>& operator=(const MatrixSTL& rhs); //Assignment
        MatrixSTL<T>& operator+=(const MatrixSTL<T>& rhs);
        MatrixSTL<T>& operator-=(const MatrixSTL<T>& rhs);
        bool operator==(const MatrixSTL& rhs) const {
            if( mRows!=rhs.mRows || mCols!=rhs.mCols){
                return false;
            }
            return (mat == rhs.mat);
        }
    
    //Matrix-Scalar operations
        MatrixSTL<T> operator+( const T& x);
        MatrixSTL<T> operator-( const T& x);
        MatrixSTL<T> operator*( const T& x);
        MatrixSTL<T> operator/( const T& x);

    //Matrix-Vector operations
        friend std::vector<T> MatVecProd(const MatrixSTL<T>& A, const std::vector<T> x);
    //Matrix Display
        void display() const {
            for (unsigned int i = 0; i < mRows; i++){
                std::cout << std::endl;
                for (unsigned int j = 0; j < mCols; j++){
                    std::cout << mat[i][j] << "   " ;
                }
            }
            std::cout << std::endl;
        };
    //Member access
        unsigned int getRows() const{
            return mRows;
        };
        unsigned int getCols() const{
            return mCols;
        };
};

template <class T> MatrixSTL<T>::MatrixSTL(unsigned int r, unsigned int c, const T& iniVal) :mRows(r), mCols(c){
    mat.resize(mRows);
    for (unsigned int i = 0; i < mRows; i++){
        mat[i].resize(mCols, iniVal);
    }
}
template <class T> MatrixSTL<T>::MatrixSTL(std::vector<std::vector<T>> m) {
    mRows = m.size();
    mCols = m[0].size();
    mat = m;
}
//Copy constructor
template <class T> MatrixSTL<T>::MatrixSTL(const MatrixSTL<T>& rhs){
    mat.resize(rhs.mRows);
    for (unsigned int i = 0; i < mRows; i++){
        mat[i].resize(rhs.mCols);
        for (unsigned int j = 0; j < mCols; j++){
            mat[i][j] = rhs.mat[i][j];
        }
    }
    mRows = rhs.mRows;
    mCols = rhs.mCols;
}
template <class T>
MatrixSTL<T> MatrixSTL<T>::operator+(const MatrixSTL<T>& rhs) const {
    if(mRows != rhs.mRows || mCols != rhs.mCols){
        std::cout << "Error: Matrices are not equal size. Addition not possible." << std::endl;
    }
    MatrixSTL<T> result(mRows, mCols, 0.0);
    result.mRows = mRows;
    result.mCols = mCols;
    for(unsigned int i=0; i<mRows; i++){
        for(unsigned int j=0; j<mCols; j++){
            result.mat[i][j] = mat[i][j]+rhs.mat[i][j];
        }
    }
    return result;
}
template <class T>
MatrixSTL<T> MatrixSTL<T>::operator-(const MatrixSTL<T>& rhs) const{
    if (mRows != rhs.mRows || mCols != rhs.mCols){
        std::cout << "Error: Matrices are not equal size. Subtraction not possible." << std::endl;
    }
    MatrixSTL result(mRows, mCols, 0.0);
    result.mRows = mRows;
    result.mCols = mCols;
    for (unsigned int i = 0; i < mRows; i++){
        for (unsigned int j = 0; j < mCols; j++){
            result.mat[i][j] = mat[i][j] - rhs.mat[i][j];
        }
    }
    return result;
}
template <class T>
MatrixSTL<T> MatrixSTL<T>::operator*(const MatrixSTL<T>& rhs) const {
    if (mCols != rhs.mRows){
        std::cout << "Error: Matrices are not compatible for multiplication. Product not possible." << std::endl;
    }
    MatrixSTL result(mRows, rhs.mCols, 0.0);
    
    for (unsigned int i = 0; i < mRows; i++) {
        for (unsigned int j = 0; j < result.mCols; j++) {
            for(unsigned int k=0; k<mCols; k++) {
                result.mat[i][j] += mat[i][k] * rhs.mat[k][j];
            }
        }
    }
    result.mRows = mRows;
    result.mCols = rhs.mCols;
    return result;
}
//Assignment operator
template <class T>
MatrixSTL<T>& MatrixSTL<T>::operator=(const MatrixSTL<T>& rhs){
    if (this == &rhs){
        return *this;
    }
    mRows = rhs.mRows;
    mCols = rhs.mCols;
    mat.resize(mRows);
    for (unsigned int i = 0; i < mRows; i++){
        mat[i].resize(mCols);
    }
    for (unsigned int i = 0; i < mRows; i++){
        for (unsigned int j = 0; j < mCols; j++){
            mat[i][j] = rhs.mat[i][j]; // rhs(i,j) if operator() is defined
        }
    }
    return *this;
}
template<class T> MatrixSTL<T>& MatrixSTL<T>::operator+=(const MatrixSTL<T>& rhs) {
    for(unsigned int i = 0; i< mRows; i++) {
        for(unsigned int j=0; j< mCols; j++) {
            mat[i][j] += rhs.mat[i][j];
        }
    }
    return *this;
}
template<class T> MatrixSTL<T>& MatrixSTL<T>::operator-=(const MatrixSTL<T>& rhs){
    for (unsigned int i = 0; i < mRows; i++){
        for (unsigned int j = 0; j < mCols; j++){
            mat[i][j] -= rhs.mat[i][j];
        }
    }
    return *this;
}


template <class T> MatrixSTL<T> MatrixSTL<T>::operator+(const T& x){
    MatrixSTL<T> result(*this);
    if (mRows == mCols){
        for (unsigned int i = 0; i < mRows; i++){
            result.mat[i][i] = mat[i][i] + x;
        }
    }
    return(result);
}
template <class T> MatrixSTL<T> MatrixSTL<T>::operator-(const T& x){
    MatrixSTL<T> result(*this);
    
    if (mRows == mCols){
        for (unsigned int i = 0; i < mRows; i++){
            result.mat[i][i] = mat[i][i] - x;
        }
    }
    return(result);
}

template <class T> MatrixSTL<T> MatrixSTL<T>::operator*(const T& x){
    MatrixSTL<T> result(mRows, mCols, 0.0);
    
    for (unsigned int i = 0; i < mRows; i++){
        for (unsigned int j = 0; j < mCols; j++){
            result.mat[i][j] = mat[i][j] * x;
        }
    }
    return(result);
}
template <class T> MatrixSTL<T> MatrixSTL<T>::operator/(const T& x){
    MatrixSTL<T> result(mRows, mCols, 0.0);
    for (unsigned int i = 0; i < mRows; i++){
        for (unsigned int j = 0; j < mCols; j++){
            result.mat[i][j] = mat[i][j] / x;
        }
    }
    return(result);
}
template <class T>
std::vector<T> MatVecProd(const MatrixSTL<T>& A, const std::vector<T> x){
    std::vector<T> v(A.mRows, 0.0);
    for (unsigned int i = 0; i < A.mRows; i++){
        for (unsigned int j = 0; j < A.mCols; i++){
            v[i] += A.mat[i][j] * x[j];
        }
    }
    return(v);
}

#endif /* matrixSTL_ */
