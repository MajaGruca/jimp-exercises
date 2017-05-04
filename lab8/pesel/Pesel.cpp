//
// Created by ktr on 25.04.2017.
//

#include "Pesel.h"
#include <string>
#include <cstring>
namespace academia
{
   /* Pesel::Pesel(const char * a)
    {
        std::string str;
        int j=0;
        while(a[j])
        {
            str=str+a[j];
j++;
        }
        if(str.length()!=11)
            throw InvalidPeselLength();
        for(int i=0 ;i<11;i++)
        {
            if(!isdigit(str[0]))
            {
                throw InvalidPeselChecksum('a',1);
            }

        }
        int tab[11]={1,3,7,9,1,3,7,9,1,3,1};
        int sum=0;
        for(int i=0 ;i<11;i++)
        {
            sum=sum+tab[i]*(str[i]-'0');
        }
        //for()
        //int sum=1*(str[0]-'0')+atoi(str[1])*3+7*atoi(str[2])+9*atoi(str[3])+atoi(str[4])+3*atoi(str[5])+7*atoi(str[6])+9*atoi(str[7])+1*atoi(str[8])+3*atoi(str[9])+1*atoi(str[10]);
        if(!sum%10)
            throw InvalidPeselChecksum('a',1);
    }*/
}