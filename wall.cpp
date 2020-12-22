/*********************************************
 *Program Filename:wall.cpp
 *Author: Jianlong Huang
 *Date: 3/17
 *Description:
 *Input:
 *Output:
 * ******************************************/
#include<iostream>
#include"wall.hpp"

/*******************************************
 *Function:is_occupiable()
 *Description:return false
 *Parameters:
 *Pre-Conditions:
 *Post-Conditions:
 * ****************************************/
bool Wall::is_occupiable(){
   return false;
}

/*******************************************
 *Function:get_display_character()
 *Description:return character
 *Parameters:
 *Pre-Conditions:
 *Post-Conditions:
 * ****************************************/
char Wall::get_display_character(){
   return '#';
}
