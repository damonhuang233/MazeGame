/*********************************************
 *Program Filename: escape.cpp
 *Author: Jianlong Huang
 *Date: 3/17
 *Description: Play the game escape for cs162
 *Input: txt file
 *Output:
 * ******************************************/

#include<iostream>
#include<fstream>
#include"maze.hpp"

int main(int argc, char* argv[]){

   if(argc != 2){
      std::cout<< "Invalid filename. "<<std::endl;
      return 1;
   }

   std::ifstream infile;
   infile.open(argv[1]);
   if(infile.fail()){
      std::cerr<<"Invalide filename. "<<std::endl;   // check txt file
      return 1;
   }
   infile.close();

   int win = 0;

   do{
      std::ifstream infile; 
      infile.open(argv[1]); 
      Maze m1(infile);                       //create maze based on txt file
      m1.set_level();                        // set student, ta, skill
      do{         
         win = m1.check();                   //check whether student meet ta or get skill
	 m1.print_level();                   // print map
       	 m1.move();                          // student move and ta move
       	 win = m1.check();                   // check ladder or instructor
      }while(win == 0);                      // turns
   }while(win == 2);                         // restart if fail

   

   return 0;
}
