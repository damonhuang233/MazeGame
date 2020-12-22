/*********************************************
 *Program Filename:maze.cpp
 *Author: Jianlong Huang
 *Date: 3/17
 *Description:set map
 *Input:
 *Output:
 * ******************************************/
#include<iostream>
#include<fstream>
#include<string>
#include"mazelevel.hpp"
#include"wall.hpp"
#include"openspace.hpp"

/*******************************************
 *Function:MazeLevel
 *Description:set default 
 *Parameters:
 *Pre-Conditions:
 *Post-Conditions:
 * ****************************************/
MazeLevel::MazeLevel(){
   this->row = 0;
   this->col = 0;
   this->s_row = -1;
   this->s_col = -1;
};

/*******************************************
 *Function:set
 *Description:set vector based on txt file
 *Parameters:ifstream int int
 *Pre-Conditions:
 *Post-Conditions:
 * ****************************************/
void MazeLevel::set(std::ifstream& infile, int row, int col){
   this->row = row;
   this->col = col;
   for(int r=0; r<this->row; r++){
      std::vector<MazeLocation *> temp;
      for(int c=0; c<this->col; c++){
	 char c1;
	 infile.get(c1);
	 if(c1 == '#'){
	    temp.push_back(new Wall);
	 }
	 else if(c1 == ' '){
	    temp.push_back(new OpenSpace);
	 }
	 else if(c1 == '@'){
	    OpenSpace* os = new OpenSpace;
	    os->set_has_begin(true);
	    temp.push_back(os);
	    this->s_row = r;
	    this->s_col = c;
	 }
	 else if(c1 == '^'){
	    OpenSpace* os = new OpenSpace;
	    os->set_has_ladder(true);
	    temp.push_back(os);	 
	 }
	 else if(c1 == '%'){
	    OpenSpace* os = new OpenSpace;
	    os->set_has_instructor(true);
	    temp.push_back(os);
	 }
	 else                                     // ignore new line character until the end of txt file
	    if(! infile.fail())	   	          // get out of loop if reach the end 
	       c -= 1;
      }
      this->locations.push_back(temp);
   }
}

/*******************************************
 *Function:~MazeLevel
 *Description:free memory
 *Parameters:
 *Pre-Conditions:
 *Post-Conditions:
 * ****************************************/
MazeLevel::~MazeLevel(){
   for(int r=0; r<this->row; r++)
      for(int c=0; c<this->col; c++)
	 delete this->locations[r][c];
}

/*******************************************
 *Function:get_location
 *Description:return single pointer
 *Parameters:
 *Pre-Conditions:
 *Post-Conditions:
 * ****************************************/
MazeLocation* MazeLevel::get_location(int r, int c){
   return this->locations[r][c];
}

/*******************************************
 *Function:get_s_row
 *Description:get begin row
 *Parameters:
 *Pre-Conditions:
 *Post-Conditions:
 * ****************************************/
int MazeLevel::get_s_row(){
   return this->s_row;
}

/*******************************************
 *Function:get_s_col
 *Description:get begin col
 *Parameters:
 *Pre-Conditions:
 *Post-Conditions:
 * ****************************************/
int MazeLevel::get_s_col(){
   return this->s_col;
}
