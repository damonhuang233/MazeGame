/*********************************************
 *Program Filename:mazelocation.hpp
 *Author: Jianlong Huang
 *Date: 3/17
 *Description:
 *Input:
 *Output:
 * ******************************************/
#ifndef MAZELOCATION_HPP
#define MAZELOCATION_HPP

class MazeLocation{
   public:
      virtual bool is_occupiable();
      virtual char get_display_character();
};

#endif
