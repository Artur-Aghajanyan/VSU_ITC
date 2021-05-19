#include <iostream>
#include <time.h>
#include <fstream>
#include <unistd.h>
const int arrSize = 35450;
int size = 35425;

std::string col1[arrSize];
std::string col2[arrSize];
std::string col3[arrSize];
std::string col4[arrSize];
std::string GNAT;

void myOpenFile(std::string fileName);
int nat(std::string* col4);

int main() {
    clock_t start, end;
    double cpu_time_used;

    start = clock();
std::cin >> GNAT;
    int num = 0;
   myOpenFile("ATP");
   sleep(1);
   myOpenFile("WTA");
   myOpenFile("ATP1");
   myOpenFile("WTA1");


    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    std::cout << "Time used without threads " << cpu_time_used << std::endl;
    return 0;
}

void myOpenFile(std::string fileName) {
    int num = 0; 
    std::fstream my_file;
    my_file.open(fileName.c_str());
    if(my_file.fail()) {
        std::cout << "No such file" << std::endl;
       exit(0);
    }
    while(!my_file.eof()){
        my_file >> col1[num];
        my_file >> col2[num];
        my_file >> col3[num];
        my_file >> col4[num];
        
        ++num;
    }

    std::cout << nat(col4) << std::endl;
    my_file.close();

}

int nat(std::string* col4) {
    int count = 0;
    for(int i = 0; i < size; ++i) {
        if(col4[i] == GNAT) {
            ++count;
        }
    }
    return count;
}
