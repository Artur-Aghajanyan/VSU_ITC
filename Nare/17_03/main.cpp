#include <iostream>
#include "view.h"
#include "button.h"
#include "text.h"

int main(){
/*    View v1(1,5,"asd");
    std::cout<<v1.getX()<<" "<<v1.getY()<<" "<<v1.getColor()<<std::endl;
    v1.print();
*/

/*      Button b1(1,5,"asd",15,16);
       std::cout<<b1.getX()<<" "<<b1.getY()<<" "<<b1.getColor()<<" "<<b1.getWidth()<<" "<<b1.getHeight()<<std::endl;
        b1.print();     
*/
         Text t1(1,5,"asd","zxc","nmd");                                                                                  
        std::cout<<t1.getX()<<" "<<t1.getY()<<" "<<t1.getColor()<<" "<<t1.getText()<<" "<<t1.getTextColor()<<std::endl;
         t1.print();                                               
         return 0;
}  
