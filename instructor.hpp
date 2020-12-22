/*********************************************
 *Program Filename:instructor.hpp
 *Author: Jianlong Huang
 *Date: 3/17
 *Description:
 *Input:
 *Output:
 * ******************************************/
#ifndef INSTRUCTOR_HPP
#define INSTRUCTOR_HPP
#include"mazeperson.hpp"

class Instructor : public MazePerson{
   public:
      virtual char get_move();
};

#endif
