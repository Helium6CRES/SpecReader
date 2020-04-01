#include <iostream>
#include <fstream>
using namespace std;

int main ()
    {
    streampos size;
    char * memblock;
    int * data;

    //declare an input filestream object in binary format,
    //opened to the end of the file (ios:ate)
    ifstream file ("/home/brent/Desktop/SpecFiles/Freq_data_2020-03-25-17-36-18_000000.spec", ios::in|ios::binary|ios::ate);
    if (file.is_open())
        {
        size = file.tellg();
        std::cout << "File size = " << size << "\n";
        memblock = new char [size];
        file.seekg (0, ios::beg);
        file.read (memblock, size);
        file.close();

        std::cout << "The entire file content is in memory\n";
        //data = new int[size];
        //data = (int*)memblock;

        ofstream outfile ("/home/brent/Desktop/CSV_Spectrum_Data/Freq_data_2020-03-25-17-36-18_000000.csv");
        if (outfile.is_open())
            {
            int a = 0;
            for (int x = 0; x < 8192; x++)
                {
                a =  memblock[x+32];
                outfile << a << "\n";
                }
            std::cout << "Output copied to file\n";
            }

        delete[] memblock;
        }
    else
        {
        std::cout << "Unable to open file";
      }

    return 0;
    }
