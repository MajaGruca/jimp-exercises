//
// Created by Paulina Kapłon on 04.03.2017.
//

#include "Palindrome.h"

using namespace std;
int main(int value) {

    int x;string str;

    while(1){
        cout<<endl<<"SPRAWDZ PALINDROM //(wybierz 1)"<<endl<<"WYJSCIE //(wybierz 2)"<<endl;
        cin>> x;
        if (x==2)
        {
            break;
        }
        cout<<"podaj palindrom :";
        cin>>str;
        cout<<endl;
        is_palindrome(str);

    }
    return 0;
}