//
// Created by Paulina Kapłon on 04.03.2017.
//
#include "Palindrome.h"
using namespace std;

bool is_palindrome(string str){
    int i,j;
    int size;
    size= (int) str.size();

    for(i=0, j=size-1;i<=size/2;i++)
    {
        if(str[i]!=str[j]) {
            cout << "nie palindrom" << endl;
            return false;
        }
        j--;
    }

    cout<<"palindrom"<<endl;
    return true;

}
