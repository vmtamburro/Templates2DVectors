#include "My2DMatrix.h"
#include "MinMaxAbs.h"
#include <iostream>

using namespace std;

int main()
{


    char again;
    int val1, val2;
    do
    {
        cout<<"Enter first integer value: ";
        cin >> val1;
        cout<< "Enter second integer value: ";
        cin>>val2;

        try
        {
            cout << "Testing minimum of "<< val1 << " and " << val2<<endl;
            cout << minimum(val1, val2)<<endl;
            cout << "\nTesting maximum of "<<val1 << " and " <<val2<<endl;
            cout << maximum(val1, val2) <<endl;
        }
        catch(string exceptionString)
        {
            cout << exceptionString <<endl;
        }

        cout<< "Would you like to try again? Y or N: ";
        cin>> again;
        cout<<endl;

    }while(again == 'y' || again == 'Y');

    double val3, val4;
    do
    {
        cout<<"Enter first double value: ";
        cin >> val3;
        cout<< "Enter second double value: ";
        cin>>val4;

        try
        {
            cout << "Testing minimum of "<< val3 << " and " << val4<<endl;
            cout << minimum(val3, val4)<<endl;
            cout << "\nTesting maximum of "<<val3 << " and " <<val4<<endl;
            cout << maximum(val3, val4) <<endl;
        }
        catch(string exceptionString)
        {
            cout << exceptionString <<endl;
        }

        cout<< "Would you like to try again? Y or N: ";
        cin>> again;
        cout<<endl;

    }while(again == 'y' || again == 'Y');

    int val5;
    do
    {
        cout<<"Enter a positive or negative integer number: ";
        cin >> val5;


        try
        {
            cout <<"\nTesting absolute value of " <<val5 <<endl;
            cout << absoluteVal(val5)<<endl;
        }
        catch(string exceptionString)
        {
            cout << exceptionString <<endl;
        }

        cout<< "Would you like to try again? Y or N: ";
        cin>> again;
        cout<<endl;

    }while(again == 'y' || again == 'Y');

    double val6;
    do
    {
        cout<<"Enter a positive or negative double number: ";
        cin >> val6;


        try
        {
            cout <<"\nTesting absolute value of " <<val6<<endl;
            cout << absoluteVal(val6)<<endl;
        }
        catch(string exceptionString)
        {
            cout << exceptionString <<endl;
        }

        cout<< "Would you like to try again? Y or N: ";
        cin>> again;
        cout<<endl;

    }while(again == 'y' || again == 'Y');


    //Create a new matrix of doubles.
    cout<<"creating matrix 1"<<endl;
    My2DMatrix<double> Matrix1(5, 5);
    double doubleNum = 0.5;
   for(int i = 0; i < Matrix1.getRowSize(); i++)
   {
       for(int j = 0; j < Matrix1.getColSize(); j++)
       {
           Matrix1.putElementAt(i, j, j+doubleNum);
       }
   }
   Matrix1.showArray();

   cout<<"creating matrix 2"<<endl;
   My2DMatrix<int> Matrix2(5, 5);
   for(int i = 0; i < Matrix2.getRowSize(); i++)
   {
       for(int j = 0; j < Matrix2.getColSize(); j++)
       {
           Matrix2.putElementAt(i, j, j);

       }
   }
   Matrix2.showArray();


   cout<< "creating empty matrix 3"<<endl;

   My2DMatrix<double> Matrix3(5, 5);

   try
   {
        cout << "Storing Addition in Matrix3"<<endl;
        Matrix3 = Matrix1 + Matrix2;
        Matrix3.showArray();
   }
   catch(My2DMatrix<double>::MatrixDimensionError)
   {
       cout<<"Error, invalid matrix dimensions for addition"<<endl;
   }



   cout << "creating empty matrix 4"<<endl;

   int row = Matrix1.getRowSize();
   int col = Matrix2.getColSize();

   My2DMatrix<double>Matrix4(row, col);
   try
   {
        cout << "Storing Multiplication in Matrix 4"<<endl;
        Matrix4 = Matrix1 * Matrix2;
        Matrix4.showArray();
   }
   catch(My2DMatrix<double>::MatrixDimensionError)
   {
       cout<<"Error, invalid matrix dimensions for multiplication"<<endl;
   }


   try
   {
        cout<< "Storing Subtraction in Matrix 3"<<endl;
        Matrix3 = Matrix1 - Matrix2;
        Matrix3.showArray();
   }
   catch(My2DMatrix<double>::MatrixDimensionError)
   {
       cout<<"Error, invalid matrix dimensions for subtraction"<<endl;
   }






   return 0;

}

