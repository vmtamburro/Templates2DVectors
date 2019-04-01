#ifndef MINMAXABS_H_INCLUDED
#define MINMAXABS_H_INCLUDED

#include <iostream>
using namespace std;

/****************min function*************/
template<class T>
T minimum(const T &val1, const T &val2)
{
    if(val1 < val2)
        return val1;
    else if(val2 < val1)
        return val2;
    else if(val1==val2)
    {
        string exceptionString = "Error, Values are Equal.";
        throw exceptionString;
    }
    return 0;
}
/****************max function************/
template<class T>
T maximum(const T &val1, const T &val2)
{
    if(val1 > val2)
        return val1;
    else if(val2 > val1)
        return val2;
    else if(val1==val2)
    {
        string exceptionString = "Error, Values are Equal.";
        throw exceptionString;

    }
    return 0;
}

/****************abs val function **********/
template<class T>
T absoluteVal(T val)
{
    if (val < 0)
        val = val * -1;

    return val;
}


#endif // MINMAXABS_H_INCLUDED
