#include <iostream>
#include <new>
#include "My2DMatrix.h"
#include "MinMaxAbs.h"
#include "My2DMatrixImplementation.h"
#include "OtherFunctions.h"
#include <vector>

using namespace std;

int main()
{
  int val1 = 10, val2 = 100;
   double val3 = 10.1, val4 = -10.203;
   float val5 = 7.5, val6 = 11.9;

   cout << "Testing minimum of "<< val1 << " and " << val2<<endl;
   cout << minimum(val1, val2)<<endl;

   cout << "\nTesting minimum of "<< val3 << " and " << val4<<endl;
   cout << minimum(val3, val4)<<endl;

   cout << "\nTesting minimum of "<< val5 << " and " << val6<<endl;
   cout << minimum(val5, val6)<<endl;

   cout << "\nTesting maximum of "<<val1 << " and " <<val2<<endl;
   cout << maximum(val1, val2) <<endl;

   cout << "\nTesting maximum of "<<val3 << " and " <<val4<<endl;
   cout << maximum(val3, val4);

   cout << "\nTesting maximum of "<<val5 << " and "<<val6<< endl;

   cout <<"\nTesting absolute value of " <<val4 <<endl;
   cout << absoluteVal(val4)<<endl;

   cout << "\nTesting absolute value of " <<val3<<endl;
   cout <<absoluteVal(val3)<<endl;


   cout << "\nTesting My2DMatrixClass..."<<endl;


    //Create Matrix of Zeros
   My2DMatrix<double> matrix(10, 10);
   matrix.showArray();

   try
   {
        //Add Values to Matrix
        for(int i = 0; i < matrix.getRowSize(); i++)
        {
            for(int j = 0; j < matrix.getColSize(); j++)
            {
                matrix.putElementAt(i, j, (j+1));
            }
        }
   }

   catch(My2DMatrix<int>::SubscriptError)
   {
       cout<<"Error: Invalid Subscript"<<endl;
   }
    cout << endl;
    matrix.showArray();

    //Create a new matrix of doubles.
    My2DMatrix<double> doubleMatrix(10, 10);


    double num = 0.5;
   for(int i = 0; i < doubleMatrix.getRowSize(); i++)
   {
       for(int j = 0; j < doubleMatrix.getColSize(); j++)
       {
           doubleMatrix.putElementAt(i, j, num);

       }
   }

   cout <<endl;
   doubleMatrix.showArray();

   cout<< "Testing addition overloaded operator. \n";

   cout<<endl;
   matrix3.showArray();



   return 0;
}


