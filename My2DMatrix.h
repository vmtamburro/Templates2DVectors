#ifndef MY2DMATRIX_H_INCLUDED
#define MY2DMATRIX_H_INCLUDED

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <new>


using namespace std;



/*************matrix class*************/
template<class T>
class My2DMatrix
{
private:
   //vector<vector<T>> myMatrix;
   T **myMatrix;
   int rowSize;
   int colSize;
   int arraySize;

public:
    My2DMatrix()
    { rowSize = 0; colSize = 0; }

    //constructor
    My2DMatrix(int sizeOfRow, int sizeOfCol);
    //copy constructor
    My2DMatrix(const My2DMatrix &);

    class MemoryError
    {   };
    class SubscriptError
    {    };
    class MatrixDimensionError
    {   };

    int getRowSize()
    {   return rowSize; }

    int getColSize()
    {   return colSize; }

    int getArraySize()
    {   return arraySize;   }

    T getMatrix()
    {   return myMatrix;  }

    T getElementAt(int row, int col);
    void putElementAt(int row, int col, T value);
    void showArray();
    T sumArray();
    T sumRow(int row);
    T sumCol(int col);

    template<class T2>
    My2DMatrix<T> operator +(My2DMatrix<T2> &right);

    template<class T2>
    void operator =(My2DMatrix<T2>);
    void operator =(My2DMatrix);

    template<class T2>
    My2DMatrix operator -(My2DMatrix<T2> &right);
    My2DMatrix operator -(My2DMatrix &right);


    template<class T2>
    My2DMatrix operator *(My2DMatrix<T2> &right);
    My2DMatrix operator *(My2DMatrix &right);
    ~My2DMatrix();






};


template<class T>
My2DMatrix<T>::My2DMatrix(int sizeOfRow, int sizeOfCol)
{
    rowSize = sizeOfRow;
    colSize = sizeOfCol;
    arraySize = rowSize * colSize;

    //vector<vector<T>>items(rowSize, vector<T>(colSize));
    //myMatrix = items;

    try
    {
        myMatrix = new T*[rowSize];
        for(int i = 0; i<rowSize; i++)
        {
            myMatrix[i]=new T[colSize];
        }
    }
    catch(bad_alloc)
    {
        cout<<"Error: Insufficient Memory\n";
    }


    for(int i = 0; i < rowSize; i++)
    {
        for(int j = 0; j < colSize; j++)
        {
            myMatrix[i][j] = 0;
        }
    }


}



/**************copy constructor*************/

template<class T>
My2DMatrix<T>::My2DMatrix(const My2DMatrix &obj)
{
    if(arraySize == 0);
        throw MemoryError();

    rowSize = obj.rowSize;
    colSize = obj.colSize;
    arraySize = obj.arraySize;
    myMatrix = obj.myMatrix;

}

/********************Destructor**********/
template<class T>
My2DMatrix<T>::~My2DMatrix()
{
    for(int i = 0; i < rowSize; i++)
        delete myMatrix[i];
    delete myMatrix;
}


/********Get Element At Location**************/
template<class T>
T My2DMatrix<T>:: getElementAt(int row, int col)
{
    if(row < 0 || row >= rowSize || col < 0 || col >= colSize)
        throw SubscriptError();

    return myMatrix[row][col];

}





/***********Put Element At Location***************/

template<class T>
void My2DMatrix<T>::putElementAt(int row, int col, T value)
{
    if(row < 0 || row >= rowSize || col < 0 || col >= colSize)
        throw SubscriptError();

    myMatrix[row][col] = value;
}

/**************Display Matrix***************/

template<class T>
void My2DMatrix<T>::showArray()
{
    for(int x = 0; x < rowSize; x++)
    {
        for(int y = 0; y < colSize; y++)
        {
            cout<<setw(colSize)<< myMatrix[x][y] << " ";
        }
        cout <<endl;
    }

}



/*************Sum Array******************/

template <class T>

T My2DMatrix<T>::sumArray()

{
    T total = 0;
    for(int row = 0; row < rowSize; row++)
    {
        for(int col = 0; col < colSize; col++)
            total+= myMatrix[row][col];
    }

    return total;
}



/********* Sum Row ***************/
template <class T>
T My2DMatrix<T>::sumRow(int row)
{
    T total = 0;
    for(int col = 0; col < colSize; col++)
        total += myMatrix[row][col];

    return total;
}



/********* Sum Col ***************/
template <class T>
T My2DMatrix<T>::sumCol(int col)
{
    T total = 0;
    for(int row = 0; row < rowSize; row++)
        total += myMatrix[row][col];

    return total;
}



/************Overloaded Addition************/
template <class T>
template <class T2>
My2DMatrix<T> My2DMatrix<T>::operator +(My2DMatrix<T2> &right)
{
    if (rowSize != right.getRowSize() || colSize != right.getColSize())
        throw MatrixDimensionError();

    My2DMatrix<T> temp(rowSize, colSize);

    T tempVal;
    for(int row = 0; row < rowSize; row++)
    {
        for(int col = 0; col < colSize; col++)
        {
            tempVal = myMatrix[row][col]+right.getElementAt(row, col);
            temp.putElementAt(row, col, tempVal);
        }
    }

    return temp;
}


/****************Overloaded = T2 Parameter*************/
template <class T>
template <class T2>
void My2DMatrix<T>::operator =(My2DMatrix<T2> right)
{
  if (rowSize != right.getRowSize() || colSize != right.getColSize())
        throw MatrixDimensionError();

    for(int row = 0; row < rowSize; row++)
    {
        for(int col = 0; col < colSize; col++)
        {
            myMatrix[row][col] = right.getElementAt(row, col);
        }
    }

}

/****************Overloaded = T Parameter*************/
template <class T>
void My2DMatrix<T>::operator =(My2DMatrix<T> right)
{
  if (rowSize != right.getRowSize() || colSize != right.getColSize())
        throw MatrixDimensionError();

    for(int row = 0; row < rowSize; row++)
    {
        for(int col = 0; col < colSize; col++)
        {
            myMatrix[row][col] = right.getElementAt(row, col);
        }
    }

}



/************Overloaded Subtraction T2 Parameter************/

template <class T>
template <class T2>
My2DMatrix<T> My2DMatrix<T>::operator -(My2DMatrix<T2> &right)

{
 if (rowSize != right.getRowSize() || colSize != right.getColSize())
        throw MatrixDimensionError();

    My2DMatrix<T> temp(rowSize, colSize);

    T tempVal;
    for(int row = 0; row < rowSize; row++)
    {
        for(int col = 0; col < colSize; col++)
        {
            tempVal = myMatrix[row][col]-right.getElementAt(row, col);
            temp.putElementAt(row, col, tempVal);
        }
    }


    return temp;
}


/************Overloaded Subtraction T Parameter************/

template <class T>
My2DMatrix<T> My2DMatrix<T>::operator -(My2DMatrix<T> &right)

{
 if (rowSize != right.getRowSize() || colSize != right.getColSize())
        throw MatrixDimensionError();

    My2DMatrix<T> temp(rowSize, colSize);

    T tempVal;
    for(int row = 0; row < rowSize; row++)
    {
        for(int col = 0; col < colSize; col++)
        {
            tempVal = myMatrix[row][col]-right.getElementAt(row, col);
            temp.putElementAt(row, col, tempVal);
        }
    }


    return temp;
}

/************Overloaded Multiplication T2 Parameter ************/
template <class T>
template <class T2>
My2DMatrix<T> My2DMatrix<T>::operator *(My2DMatrix<T2> &right)
{
    if(colSize != right.getRowSize())
        throw MatrixDimensionError();

    int tempRow = rowSize;
    int tempCol = right.getColSize();

    T tempVal = 0;
    My2DMatrix<T> temp(tempRow, tempCol);
    for(int row = 0; row < rowSize; row++)
    {
        for(int col = 0; col < right.getColSize(); col++)
        {
        //Multiply the row of A by the column of B to get the product
           for(int inner = 0; inner < colSize; inner++)
           {

               tempVal += myMatrix[row][inner] * right.getElementAt(inner, col);


           }
           temp.putElementAt(row, col, tempVal);
           tempVal = 0;

        }
    }


    return temp;
}

/************Overloaded Multiplication T Parameter************/
template <class T>
My2DMatrix<T> My2DMatrix<T>::operator *(My2DMatrix<T> &right)
{
    if(colSize != right.getRowSize())
        throw MatrixDimensionError();

    int tempRow = rowSize;
    int tempCol = right.getColSize();

    T tempVal = 0;
    My2DMatrix<T> temp(tempRow, tempCol);
    for(int row = 0; row < rowSize; row++)
    {
        for(int col = 0; col < right.getColSize(); col++)
        {
        //Multiply the row of A by the column of B to get the product
           for(int inner = 0; inner < colSize; inner++)
           {

               tempVal += myMatrix[row][inner] * right.getElementAt(inner, col);


           }
           temp.putElementAt(row, col, tempVal);
           tempVal = 0;

        }
    }


    return temp;
}


#endif // MY2DMATRIX_H_INCLUDED
