/*********************************************
 *Program Filename:maze.hpp
 *Author: Jianlong Huang
 *Date: 3/17
 *Description:
 *Input:
 *Output:
 * ******************************************/
#ifndef MAZELEVEL_HPP
#define MAZELEVEL_HPP
#include<vector>
#include"mazelocation.hpp"

class MazeLevel{
   private:
      std::vector<std::vector<MazeLocation*> > locations;
      int row;
      int col;
      int s_row;
      int s_col;
   public:
      MazeLevel();
      ~MazeLevel();
      
      void set(std::ifstream& infile, int row, int col);
      MazeLocation* get_location(int r, int c);
      int get_s_row();
      int get_s_col();
};

#endif
