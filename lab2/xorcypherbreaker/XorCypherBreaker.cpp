//
// Created by ktr on 13.03.2017.
//

#include "XorCypherBreaker.h"
#include <iostream>

using std::find;
using std::string;
using std::cout;

string XorCypherBreaker(const vector<char> &cryptogram,
                        int key_length,
                        const vector<string> &dictionary)

{
        string temp;
        char key[key_length+1];
        key[key_length]='\0';
        char temp_key[key_length];
        int iterator[key_length];
        int itt;
        int match;
        int match_max = 0;
        char letter;
        for(int j=0;j<key_length-1;j++)
            iterator[j]=97;
        iterator[key_length-1]=96;
        while(iterator[0]<=122)
        {
            iterator[key_length-1]++;
            for(int i=key_length-1;i>=0;i--)
            {
                if(iterator[i]>122 && i!=0)
                {
                    iterator[i-1]++;
                    iterator[i]=97;
                }
            }
            if(iterator[0]==123)
            {
                break;
            }
            for(int i=0;i<key_length;i++)
            {
                temp_key[i] = (char)(iterator[i]);
            }
            match = 0;
            temp="";
            itt=0;
            for (int it : cryptogram)
            {
                letter = (char)(temp_key[itt % key_length] xor it);
                if ((letter >= 97) && (letter <= 122))
                    temp+=letter;
                else
                {
                    if (temp.length()>key_length-1 && find(dictionary.begin(), dictionary.end(), temp) != dictionary.end())
                    {
                        match++;
                    }
                    temp="";
                }
                itt++;
            }
            if(match>match_max)
            {
                match_max=match;
                for(int k=0;k<key_length;k++)
                {
                    key[k]=temp_key[k];
                }
            }
        }
    return key;
}


/*    wersja dla 3 zmiennych

{
        string temp;
        string key="";
        string temp_key = "   ";
        int itt;
        int match;
        int match_max = 0;
        char letter;
        for(int i =97;i<=122;i++)
        {
            for(int j=97;j<=122;j++)
            {
                for (int k = 97; k < 122; k++)
                {
                    temp_key[0]=(char)(i);
                    temp_key[1]=(char)(j);
                    temp_key[2]=(char)(k);
                    match = 0;
                    temp="";
                    itt=0;
                    for (int it : cryptogram)
                    {
                        letter = (char)(temp_key[itt % key_length] xor it);
                        if ((letter >= 97) && (letter <= 122))
                            temp+=letter;
                        else
                        {
                            if (temp.length()>2 && find(dictionary.begin(), dictionary.end(), temp) != dictionary.end())
                            {
                                match++;
                            }
                            temp="";
                        }
                        itt++;
                    }

                    if(match>match_max)
                    {
                        match_max=match;
                        key=temp_key;
                    }
                }
            }
        }
        return key;
}*/
