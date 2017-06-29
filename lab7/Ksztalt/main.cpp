//
// Created by ktr on 24.04.2017.
//

#include <vector>
#include <iostream>
#include <cstdlib>
#include "ctime"
#include "Kolo.h"
#include "Kwadrat.h"
#include "Trojkat.h"
#include <list>

int main() {
    std::list<Ksztalt*> lista;
    Ksztalt *k;
    int i=1,n;
    srand(time(NULL));
    while(i<10)
    {
        n=rand()%3+1;
        if(n==1)
            k=new Kwadrat;
        if(n==2)
            k=new Kolo;
        if(n==3)
            k=new Trojkat;
        lista.push_back(k);
        i++;
    }
    for(std::list<Ksztalt*>::iterator iter=lista.begin();iter != lista.end();iter++ )
    {

        std::cout << (*iter)->draw() << std::endl; //po prostu rysuje
    }

    return 0;
}