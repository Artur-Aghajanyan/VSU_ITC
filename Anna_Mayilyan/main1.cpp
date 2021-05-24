#include <iostream>
using namespace std;
 class Man {
         public:
         int age;

         Man(){
                 age=5;}
         double* data=new double[10];
         Man(const Man &a){
        this ->  age=a.age;
                this -> data=new double[10];
                 for(int i=0; i<10; i++){
                        this -> data[i]=a.data[i];
                 }}
 };
         int main(){

       Man p;
p.age=12;
cout<<p.age<<endl;
for(int i=0; i<10; i++){
                 p.data[i]=i;
//cout<<p.data[i];     

}
Man p1=p;
p1.data[0]=11;
cout<<p.data[0]<<endl;
cout<<p1.data[0];
        return 0;
}

