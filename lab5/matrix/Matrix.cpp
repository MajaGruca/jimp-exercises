//
// Created by maj3 on 03.04.17.
//

#include <cstring>
#include "iostream"
#include "Matrix.h"
using namespace std;
Matrix::Matrix(){}

Matrix::Matrix(int r, int c){
    row=r;
    col=c;
        mat = new complex<double> *[row];
        for(auto i=0;i<row;i++)
        {
            mat[i]=new complex<double> [col];
        }
    }

Matrix::Matrix(const char* a){

        string cp;
        int siz=1, counter=0;
        col=1;
        for(int i=0;i<strlen(a);i++) {
            cp.push_back(a[i]);
            if (a[i] == ' ') {
                siz++;
                col++;
            }
            if (a[i] == ';')
                col = 0;
        }
        vector<complex<double>> tab;
        row=1;

        for(int i=0;i<cp.size();i++)
        {
            int pos1;
            int pos2;
            double real=0;
            double im=0;
            if(cp[i]=='[')
                continue;
            else{
                if(isdigit(cp[i]))
                {
                    pos1=i;
                    while(isdigit(cp[i+1]) || cp[i+1]=='.')
                    {
                        i++;
                    }
                    pos2=i;

                    const string &temp1 = cp.substr(pos1,pos2);
                    real = stod(temp1);
                    if(cp[i+1]=='i')
                    {
                        i += 2;
                        pos1=i;
                        while(isdigit(cp[i+1]) || cp[i+1]=='.')
                        {
                            i++;
                        }
                        pos2=i;
                        const string &temp2 = cp.substr(pos1,pos2);
                        im = stod(temp2);
                    }
                    tab.push_back(complex<double>(real,im));
                }
                else{
                    if(cp[i]==' ')
                        continue;
                    else{
                        if(cp[i]==';')
                        {
                            row++;
                            continue;
                        }
                        else
                            break;
                    }
                }
            }
        }

        int k=0;
        mat = new complex<double> *[row];

        for(auto i=0;i<row;i++)
        {
            mat[i]=new complex<double> [col];
        }
        for(auto i=0;i<row;i++)
        {
            for(auto j=0;j<col;j++){
                mat[i][j] = tab[k];
                k++;
            }
        }
    }

Matrix::~Matrix(){
        for(auto i=0 ;i<row;i++)
        {
            delete [] mat[i] ;
        }
        delete [] mat ;
    }
Matrix Matrix::add(Matrix a){
    Matrix result;
    if(row==a.row && col==a.col)
    {
        result.col=col;
        result.row=row;
        for(auto i=0;i<row;i++)
        {
            for(auto j=0;j<col;j++)
            {
                result.mat[i][j]=mat[i][j]+a.mat[i][j];

            }
        }

    }return result;
}
Matrix Matrix::sub(Matrix a){}
Matrix Matrix::mul(Matrix a){}
Matrix Matrix::div(Matrix a){}
Matrix Matrix::pow(int a){}
string Matrix::print(){
        string temp="\n";
        string tt = "";
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                tt=to_string(mat[i][j].real());
                int s=tt.size()-1;
                while(tt[s]=='0')
                {
                    tt.pop_back();
                    --s;
                    if(tt[s]=='.')
                    {
                        tt.pop_back();
                        break;
                    }
                }
                temp += tt;
                if(mat[i][j].imag()!=0){
                    temp +='i';
                    tt=to_string(mat[i][j].imag());
                    s=tt.size()-1;
                    while(tt[s]=='0')
                    {
                        tt.pop_back();
                        --s;
                        if(tt[s]=='.')
                        {
                            tt.pop_back();
                            break;
                        }
                    }
                    temp += tt;
                }
                temp +='\t';
            }
            temp += '\n';
        }
        return temp;
    }

Matrix::Matrix(const Matrix& a){
        row=a.row;
        col=a.col;
        mat = new complex<double> *[a.row];
        for(auto i=0;i<a.row;i++)
        {
            mat[i]=new complex<double> [a.col];
        }
        for(auto i=0;i<a.row;i++)
        {
            for(auto j=0;j<a.col;j++)
                mat[i][j] = a.mat[i][j];
        }
    }