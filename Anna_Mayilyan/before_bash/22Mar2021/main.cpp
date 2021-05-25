#include <iostream>
#include <string.h>
#include <ctime>
char func (char *str);

int main() {
clock_t t1, t2;
t1=clock();

char* letter1 = new char[26]; // new array
          
               
           for(char ch = 'a'; ch <= 'z'; ++ch)// fills alphabet array with the alphabet
           {
               letter1[ch-'a']=ch;
           } 
char* letter2 = new char[26]; // new array


           for(char ch = 'A'; ch <= 'Z'; ++ch)// fills alphabet array with the alphabet
           {
               letter2[ch-'A']=ch;
           } 
char s1=func(letter1);
char s2= func(letter2);          
std::cout<<s1<<std::endl;
std::cout<<s2<<std::endl;
t2=clock();
float diff((float)t2-(float)t1);
  std::cout<<diff<<std::endl;
    return 0;
}


char func (char *str){
        char* letter1 = str;
for(int i=0; i < 26; i++){
std::cout<<letter1[i];
}
}

