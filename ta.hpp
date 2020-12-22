/*********************************************
 *Program Filename:ta.hpp
 *Author: Jianlong Huang
 *Date: 3/17
 *Description:
 *Input:
 *Output:
 * ******************************************/
#ifndef TA_HPP
#define TA_HPP
#include"mazeperson.hpp"

class TA : public MazePerson{
   private:
      int appeased;
   public:
      TA();

      virtual char get_move();
      void set_appeased();
      void turn();
      bool is_appeased();
      int get_appeased();
};

#endif
