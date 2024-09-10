#include<iostream>
int main(){
    int annee,bis;
    std::cout<<"Donner votre annee : ";
    std::cin>>annee;
    if (annee%4==0)    
        std::cout<<"L'annee est bisextile";
    else 
        std::cout<<"L'annee n'est pas bisextille";

}
