#include "snowman.hpp"
#include <iostream>
#include <stdexcept>
#include <array>
using namespace std;

namespace ariel{

const int maximum_digits = 99999999;
const int maximum_leagele_digits = 44444444;
const int fixed_one_for_array = 1;
const int ZERO = 0;
const int make_short_by_ten = 10;
const int one_digit_from_right = 10;
const int MAX_GOOD_NUMBER = 4;
const int MAX_LENGTH = 8;
const int left_arm_up = 2;
const int right_arm_up = 2;
const int snowmans_hat = 0;
const int snowmans_nose = 1;
const int snowmans_left_eye = 2;
const int snowmans_right_eye = 3;
const int snowmans_left_hand = 4;
const int snowmans_right_hand = 5;
const int snowmans_torso = 6;
const int snowmans_base = 7;


string snowman(const int input){
    if(input<ZERO){
        throw invalid_argument("not good - negative number...\n");
    }
    if(input == ZERO){
        throw invalid_argument("not good - invalid input...\n");
    }
    if(input>maximum_digits){
        throw invalid_argument("not good - too long number...\n");
    }
    if(input>maximum_leagele_digits){
        throw invalid_argument("not good - invalid input...\n");
    }
    
    // 8 arrays from them the snowman is build
    
    const array<string, 4> hat  { "       \n _===_ \n", "  ___  \n ..... \n","   _   \n  /_\\  \n","  ___  \n (_*_) \n" }; //0
    const array<string, 4> nose  { ",", ".", "_", " " }; // 1
    const array<string, 4> left_eye  { "(.", "(o", "(O", "(-" }; // 1
    const array<string, 4> right_eye  { ".)", "o)", "O)", "-)" }; // 1
    const array<string, 4> left_arm  { "<", "\\", "/", " " }; // if \ 1 else 2
    const array<string, 4> right_arm  { ">", "/", "\\", " " }; // if / 1 else 2
    const array<string, 4> torso  { "( : )", "(] [)", "(> <)", "(   )" }; // 2
    const array<string, 4> base  { " ( : ) ", " (\" \") ", " (___) " , " (   ) " }; // 3

    array<int, MAX_LENGTH> input_to_array {}; // my list to build a snowman!

     // count digits and find out if there are any invalid digits

    int calculate = input;
    int count = ZERO;
    int max_value_in_list = MAX_LENGTH-fixed_one_for_array; 

    while(calculate != ZERO){
        if(calculate % one_digit_from_right > MAX_GOOD_NUMBER){
            throw invalid_argument("not good - in input there is number between 5-9...\n");
        }
        if(calculate % one_digit_from_right == ZERO){
            throw invalid_argument("not good - in input there is number 0...\n");
        }
        input_to_array.at(max_value_in_list) = calculate % one_digit_from_right; // fill the input_to_array number for our snowman
        calculate = calculate / make_short_by_ten;
        max_value_in_list--; 
        count ++;
    }

    if(count > MAX_LENGTH){
        throw invalid_argument("not good - number of digits bigger then 8...\n");
    }
    if(count < MAX_LENGTH){
        throw invalid_argument("not good - number of digits smaller then 8...\n");
    }
    
    // cout<<"count is: "<< count<<endl;
    
    string snowman_out; // h n l r x y t b - order of snowman
    
    snowman_out+=hat.at(input_to_array.at(snowmans_hat)-fixed_one_for_array);
        if(input_to_array.at(snowmans_left_hand) == left_arm_up){
            snowman_out+= "\\";
        }
        else{
            snowman_out+=" ";
        }

    snowman_out+= left_eye.at(input_to_array.at(snowmans_left_eye)-fixed_one_for_array)+nose.at(input_to_array.at(snowmans_nose)-fixed_one_for_array)+right_eye.at(input_to_array.at(snowmans_right_eye)-fixed_one_for_array); 

        if(input_to_array.at(snowmans_right_hand) == right_arm_up){
            snowman_out+= "/\n";
        }
        else{
            snowman_out+=" \n";
        }
        if(input_to_array.at(snowmans_left_hand) != left_arm_up){
            snowman_out+= left_arm.at(input_to_array.at(snowmans_left_hand)-fixed_one_for_array);
        }
        else{
            snowman_out+=" ";
        }

    snowman_out+= torso.at(input_to_array.at(snowmans_torso)-fixed_one_for_array);

        if(input_to_array.at(snowmans_right_hand) != right_arm_up){
            snowman_out+= right_arm.at(input_to_array.at(snowmans_right_hand)-fixed_one_for_array)+"\n";
        }
        else{
            snowman_out+=" \n";
        }

    snowman_out+=base.at(input_to_array.at(snowmans_base)-fixed_one_for_array);
            
    // cout << "----------------------------" <<endl;
    // cout << snowman_out <<endl;
    // cout << "----------------------------" <<endl;

    return snowman_out;
    }
}


