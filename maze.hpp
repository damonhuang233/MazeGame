/*********************************************
 *Program Filename:maze.hpp
 *Author: Jianlong Huang
 *Date: 3/17
 *Description:
 *Input:
 *Output:
 * ******************************************/
#ifndef MAZE_HPP
#define MAZE_HPP
#include<vector>
#include"mazelevel.hpp"
#include"intrepidstudent.hpp"
#include"ta.hpp"
#include"instructor.hpp"
#include"openspace.hpp"

class Maze {
   private:
      std::vector<MazeLevel* > levels;
      int NUM_LEVELS;
      int LEVEL_HEIGHT;
      int LEVEL_WIDTH;
      int student_level;
      IntrepidStudent* student;
      TA* ta1;
      TA* ta2;
      Instructor* ins;
   
   public:
      Maze(std::ifstream& infile);
      ~Maze();

      void print_level();
      void set_level();
      void move();
      int check();

};

#endif
