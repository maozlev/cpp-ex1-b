#include "snowman.hpp"
#include <iostream>
// #include <stdexcept>
#include <array>
#include <string>
#include <algorithm>

using namespace std;
   
int main(){

    cout<<"hello you, lets build a snowman!"<<endl;
    cout<<"all you need is writing a number with 8 digits, every digit is between 1-4..."<<endl;
    cout<<"every snow man have 4 parts:"<<endl;
    cout<<"hat, face, torso, base"<<endl;
    cout<<"every part has 4 options, you can choose by write here numbers between 1-4"<<endl;
    cout<<"hats:    noses:    eyes:     arms:    torso:     base:\n1)_===_  1) ,      1) (. .)  1) < >   1) ( : )   1) ( : )\n\n2) ___   2) .      2) (o o)  2) \\ /   2) (] [)   2) (\" \")  \n  ..... \n3)  _    3)  _     3) (O O)  3) / \\   3) (> <)   3) (___) \n   /_\\  \n4) ___   4) none   4) (- -)  4) none  4) (   )   4) (   )\n  (_*_) \n" <<endl;
    cout<<"notice: be carful and dont write number between 5-9 or 0.. no snowman for those digits "<<endl;
    cout<<"notice: do not write a number without 8 digits it will not work... "<<endl;
    cout<<"lets print some examples"<<endl;
    cout<<""<<endl;
    cout<<"11111111 will be ==== "<<endl;
    cout<<ariel::snowman(11111111)<<endl;
    cout<<""<<endl;
    cout<<"22222222 will be ==== "<<endl;
    cout<<ariel::snowman(22222222)<<endl;
    cout<<""<<endl;
    cout<<"now lets try"<<endl;
    cout<<""<<endl;
    
    int num;
    while(1){
    cin>> num ;
    try{
    cout<<ariel::snowman(num)<<endl;
    }
    catch(exception& e){
        cout<<""<<endl;
        cout<<"try again with leagle arguments!"<<endl;
        cout<<""<<endl;
        
    }
    cout<<""<<endl;
    cout<<"to exit press ctrl+c"<<endl;
    }


     }
   