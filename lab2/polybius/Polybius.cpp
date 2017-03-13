#include <Polybius.h>

std::string PolybiusCrypt(std::string message)
{
    int i,j,k;
    char letter=97;
    char pol[5][5];
    for(i=0;i<5;i++)
    {
        for(j=0;j<5;j++)
        {
            if(letter==106)
                letter++;
            pol[i][j]=letter;
            letter++;
        }
    }
    std::string crypted;
    for(i=0;i<message.length();i++)
    {
    	if(message[i]==' ')
    		continue;
        message[i] = tolower(message[i]);
        if(message[i]=='j')
            message[i] = 'i';
        for(j=0;j<5;j++)
        {
            for(k=0;k<5;k++)
            {
                if(pol[j][k]==message[i])
                {
                    crypted += std::to_string(j+1);
                    crypted += std::to_string(k+1);
                    break;
                }
            }
        }
    }
    return crypted;
}

std::string PolybiusDecrypt(std::string crypted)
{
    int i,j;
    char letter=97;
    char pol[5][5];
    for(i=0;i<5;i++)
    {
        for(j=0;j<5;j++)
        {
            if(letter==106)
                letter++;
            pol[i][j]=letter;
            letter++;
        }
    }
    std::string decrypted;
    for(i=0;i<crypted.length();i=i+2)
    {
    	int row, column;
    	for(j=1;j<6;j++)
    	{
    		if(j==crypted[i] - '0')
    			row=j;
    		if(j==crypted[i+1] - '0')
    			column=j;
		}
		decrypted += pol[row-1][column-1];
    }
    return decrypted;
}

