/*********************************************
 *Program Filename:intrepidstudent.hpp
 *Author: Jianlong Huang
 *Date: 3/17
 *Description:
 *Input:
 *Output:
 * ******************************************/
#ifndef INTREPIDSTUDENT_HPP
#define INTREPIDSTUDENT_HPP
#include"mazeperson.hpp"

class IntrepidStudent : public MazePerson{
   private:
      int skills;
   public:
      IntrepidStudent();
      
      virtual char get_move();
      void get_skill();
      void de_skill();
      int get_skills();

};

#endif
