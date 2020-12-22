/*********************************************
 *Program Filename:openspace.cpp
 *Author: Jianlong Huang
 *Date: 3/17
 *Description:
 *Input:
 *Output:
 * ******************************************/
#include<iostream>
#include"openspace.hpp"

/*******************************************
 *Function:OpenSpace()
 *Description:set default
 *Parameters:
 *Pre-Conditions:
 *Post-Conditions:
 * ****************************************/
OpenSpace::OpenSpace(){
   this->student = false;
   this->ta = false;
   this->instructor = false;
   this->ladder = false;
   this->skill = false;
   this->begin = false;
}

/*******************************************
 *Function:is_occupiable()
 *Description:return ture
 *Parameters:
 *Pre-Conditions:
 *Post-Conditions:
 * ****************************************/
bool OpenSpace::is_occupiable(){
   return true;
}

/*******************************************
 *Function:get_display_character()
 *Description:get character
 *Parameters:
 *Pre-Conditions:
 *Post-Conditions:
 * ****************************************/
char OpenSpace::get_display_character(){  
   if(this->student == true)
      return '*';
   else if(this->ta == true)                   //print character: student>ta>instructor>ladder>begin>skill>space
      return 'T';
   else if(this->instructor == true)
      return '%';
   else if(this->ladder == true)
      return '^';
   else if(this->begin == true)
      return '@';
   else if(this->skill == true)
      return '$';
   else
      return ' ';
}

/*******************************************
 *Function:set_has_student
 *Description:set student
 *Parameters:
 *Pre-Conditions:
 *Post-Conditions:
 * ****************************************/
void OpenSpace::set_has_student(bool student){
   this->student = student;
}

/*******************************************
 *Function:has_student
 *Description:return student
 *Parameters:
 *Pre-Conditions:
 *Post-Conditions:
 * ****************************************/
bool OpenSpace::has_student(){
   return this->student;
}

/*******************************************
 *Function:set_has_ta
 *Description:set ta
 *Parameters:
 *Pre-Conditions:
 *Post-Conditions:
 * ****************************************/
void OpenSpace::set_has_ta(bool ta){
   this->ta = ta;
}

/*******************************************
 *Function:has_ta
 *Description:return ta
 *Parameters:
 *Pre-Conditions:
 *Post-Conditions:
 * ****************************************/
bool OpenSpace::has_ta(){
   return this->ta;
}

/*******************************************
 *Function:set_has_instructor
 *Description:set instructor
 *Parameters:
 *Pre-Conditions:
 *Post-Conditions:
 * ****************************************/
void OpenSpace::set_has_instructor(bool instructor){
   this->instructor = instructor;
}

/*******************************************
 *Function:has_instructor
 *Description:return instructor
 *Parameters:
 *Pre-Conditions:
 *Post-Conditions:
 * ****************************************/
bool OpenSpace::has_instructor(){
   return this->instructor;
}

/*******************************************
 *Function:set_has_ladder
 *Description:set_ladder
 *Parameters:
 *Pre-Conditions:
 *Post-Conditions:
 * ****************************************/
void OpenSpace::set_has_ladder(bool ladder){
   this->ladder = ladder;
}

/*******************************************
 *Function:has_ladder
 *Description:return ladder
 *Parameters:
 *Pre-Conditions:
 *Post-Conditions:
 * ****************************************/
bool OpenSpace::has_ladder(){
   return this->ladder;
}

/*******************************************
 *Function:set_has_skill
 *Description:set skill
 *Parameters:
 *Pre-Conditions:
 *Post-Conditions:
 * ****************************************/
void OpenSpace::set_has_skill(bool skill){
   this->skill = skill;
}

/*******************************************
 *Function:has_skill
 *Description:return skill
 *Parameters:
 *Pre-Conditions:
 *Post-Conditions:
 * ****************************************/
bool OpenSpace::has_skill(){
   return this->skill;
}

/*******************************************
 *Function:set_has_begin
 *Description:set begin
 *Parameters:
 *Pre-Conditions:
 *Post-Conditions:
 * ****************************************/
void OpenSpace::set_has_begin(bool begin){
   this->begin = begin;
}

/*******************************************
 *Function:has_begin
 *Description:return begin
 *Parameters:
 *Pre-Conditions:
 *Post-Conditions:
 * ****************************************/
bool OpenSpace::has_begin(){
   return this->begin;
}
