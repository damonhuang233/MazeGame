/*********************************************
 *Program Filename:wall.hpp
 *Author: Jianlong Huang
 *Date: 3/17
 *Description:
 *Input:
 *Output:
 * ******************************************/
#ifndef WALL_HPP
#define WALL_HPP
#include"mazelocation.hpp"

class Wall : public MazeLocation{
   public:
      virtual bool is_occupiable();
      virtual char get_display_character();
};

#endif
