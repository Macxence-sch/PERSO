#include<iostream>
using namespace std;

int main(){
    int a;

    cout<<"Donnez a :";
    cin>>a;

    switch(a) {
        case 1: 
            cout<<"c";
            break;     
        case 2: 
            cout<<"z";
            break;
        default: 
            cout<<"why";
    }             
}