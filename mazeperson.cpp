/*********************************************
 *Program Filename:mazeperson.cpp
 *Author: Jianlong Huang
 *Date: 3/17
 *Description:
 *Input:
 *Output:
 * ******************************************/
#include<iostream>
#include"mazeperson.hpp"

/*******************************************
 *Function:MazePerson
 *Description:set default
 *Parameters:
 *Pre-Conditions:
 *Post-Conditions:
 * ****************************************/
MazePerson::MazePerson(){
   this->row = -1;
   this->col = -1;
}

/*******************************************
 *Function:set_location
 *Description:seter
 *Parameters:int int
 *Pre-Conditions:
 *Post-Conditions:
 * ****************************************/
void MazePerson::set_location(int row, int col){
   this->row = row;
   this->col = col;
}

/*******************************************
 *Function:get_row
 *Description:return row
 *Parameters:
 *Pre-Conditions:
 *Post-Conditions:
 * ****************************************/
int MazePerson::get_row(){
   return this->row;
}

/*******************************************
 *Function:get_col
 *Description:return col
 *Parameters:
 *Pre-Conditions:
 *Post-Conditions:
 * ****************************************/
int MazePerson::get_col(){
   return this->col;
}
