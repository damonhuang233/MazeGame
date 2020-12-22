/*********************************************
 *Program Filename:mazeperson.hpp
 *Author: Jianlong Huang
 *Date: 3/17
 *Description:
 *Input:
 *Output:
 * ******************************************/
#ifndef MAZEPERSON_HPP
#define MAZEPERSON_HPP

class MazePerson {
   private:
      int row;
      int col;
   public:
      MazePerson();

      virtual char get_move() = 0;
      void set_location(int, int);
      int get_row();
      int get_col();
};

#endif
