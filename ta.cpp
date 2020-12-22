/*********************************************
 *Program Filename:ta.cpp
 *Author: Jianlong Huang
 *Date: 3/17
 *Description:
 *Input:
 *Output:
 * ******************************************/
#include<iostream>
#include<cstdlib>
#include<ctime>
#include"ta.hpp"

/*******************************************
 *Function:TA
 *Description:set default appeased to 0
 *Parameters:
 *Pre-Conditions:
 *Post-Conditions:
 * ****************************************/
TA::TA(){
   this->appeased = 0;
}

/*******************************************
 *Function:get_move
 *Description:get random move
 *Parameters:
 *Pre-Conditions:
 *Post-Conditions:
 * ****************************************/
char TA::get_move(){
   srand(time(NULL));
   int n = rand()%4;
   if(n == 0)
      return 'w';
   else if(n == 1)
      return 's';
   else if(n == 2)
      return 'a';
   else
      return 'd';
}

/*******************************************
 *Function:set_appeased
 *Description:set appeased
 *Parameters:
 *Pre-Conditions:
 *Post-Conditions:
 * ****************************************/
void TA::set_appeased(){
   this->appeased = 10;
}

/*******************************************
 *Function:turn
 *Description:appeased -1
 *Parameters:
 *Pre-Conditions:
 *Post-Conditions:
 * ****************************************/
void TA::turn(){
   if(appeased > 0)
      appeased -= 1;
}

/*******************************************
 *Function:is_appeased
 *Description:retun true if appeased
 *Parameters:
 *Pre-Conditions:
 *Post-Conditions:
 * ****************************************/
bool TA::is_appeased(){
   if(this->appeased == 0)
      return false;
   else{
      return true;
   }
}

/*******************************************
 *Function:get_appeased
 *Description:return appeased
 *Parameters:
 *Pre-Conditions:
 *Post-Conditions:
 * ****************************************/
int TA::get_appeased(){
   return this->appeased;
}
