#include<iostream>
int main(){
    int age;
    std::cout<<"Donnez l'age de votre fille : \n";
    std::cin>>age;
    if(age<25){
        age=age/2;
        std::cout<<"WAW c'est jeune : "<<age;
     }else 
        std::cout<<"Tranquille il est bon la gamine";
}
