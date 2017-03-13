#include <Polybius.h>

int main(std::string file1, std::string file2, int option)
{
    std::ifstream file_to_open(file1);
    std::ofstream file_to_save(file2, std::ios_base::in | std::ios_base::app);
    char line[256];

    if(!file_to_open)
        std::cout << "Nie mozna otworzyc pliku!" << std::endl;
    if(option==0)
    {
        while(!file_to_open.eof())
        {
            file_to_open.getline(line,256);
            file_to_save << PolybiusCrypt(line) << std::endl;
        }

    }
    else
    {
        while(!file_to_open.eof())
        {
            file_to_open.getline(line,256);
            file_to_save << PolybiusDecrypt(line) << std::endl;
        }
    }

    file_to_open.close();
    file_to_save.close();
    return 0;
}