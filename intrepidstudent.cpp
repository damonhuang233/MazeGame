/*********************************************
 *Program Filename:intrepidstudent.cpp
 *Author: Jianlong Huang
 *Date: 3/17
 *Description:
 *Input:
 *Output:
 * ******************************************/
#include<iostream>
#include"intrepidstudent.hpp"

/*******************************************
 *Function:IntrepidStudent
 *Description:set default skill to 0
 *Parameters:
 *Pre-Conditions:
 *Post-Conditions:
 * ****************************************/
IntrepidStudent::IntrepidStudent(){
   this->skills = 0;
}

/*******************************************
 *Function:get_move
 *Description:get move char from user
 *Parameters:
 *Pre-Conditions:
 *Post-Conditions:
 * ****************************************/
char IntrepidStudent::get_move(){
   char c;
   do{
      std::cin >> c;
   }while( c != 'w' && c != 'a' && c != 's' && c != 'd' && c != 'p' && c !='u');
}

/*******************************************
 *Function:get_skill
 *Description:pick up skill
 *Parameters:
 *Pre-Conditions:
 *Post-Conditions:
 * ****************************************/
void IntrepidStudent::get_skill(){
   this->skills += 1;
}

/*******************************************
 *Function:de_skill
 *Description:use skill
 *Parameters:
 *Pre-Conditions:
 *Post-Conditions:
 * ****************************************/
void IntrepidStudent::de_skill(){
   this->skills -= 1;
}

/*******************************************
 *Function:get_skills
 *Description:return number of skills
 *Parameters:
 *Pre-Conditions:
 *Post-Conditions:
 * ****************************************/
int IntrepidStudent::get_skills(){
   return this->skills;
}
