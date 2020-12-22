/*********************************************
 *Program Filename:mazelocation.cpp
 *Author: Jianlong Huang
 *Date: 3/17
 *Description:
 *Input:
 *Output:
 * ******************************************/
#include<iostream>
#include"mazelocation.hpp"

/*******************************************
 *Function: is_occupiable()
 *Description:default return false
 *Parameters:
 *Pre-Conditions:
 *Post-Conditions:
 * ****************************************/
bool MazeLocation::is_occupiable(){
   return false;
}

/*******************************************
 *Function:get_display_character()
 *Description:return character
 *Parameters:
 *Pre-Conditions:
 *Post-Conditions:
 * ****************************************/
char MazeLocation::get_display_character(){
   return '#';
}
