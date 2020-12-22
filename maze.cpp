/*********************************************
 *Program Filename:maze.cpp
 *Author: Jianlong Huang
 *Date: 3/17
 *Description:all game function
 *Input:
 *Output:
 * ******************************************/
#include<iostream>
#include<fstream>
#include<cstdlib>
#include<ctime>
#include"maze.hpp"

/*******************************************
 *Function:Maze
 *Description:set default
 *Parameters:
 *Pre-Conditions:
 *Post-Conditions:
 * ****************************************/
Maze::Maze(std::ifstream& infile){
   this->student_level = 0;
   this->student = NULL;
   this->ta1 = NULL;
   this->ta2 = NULL;
   this->ins = NULL;
   infile >> this->NUM_LEVELS;
   infile >> this->LEVEL_HEIGHT;
   infile >> this->LEVEL_WIDTH;
   for(int n=0; n<NUM_LEVELS; n++){
      MazeLevel* temp = new MazeLevel;
      temp->set(infile, LEVEL_HEIGHT, LEVEL_WIDTH);
      levels.push_back(temp);
   }
   infile.close();
}

/*******************************************
 *Function:print_level
 *Description:print level
 *Parameters:
 *Pre-Conditions:
 *Post-Conditions:
 * ****************************************/
void Maze::print_level(){
   for(int r=0; r<this->LEVEL_HEIGHT;r++){
      for(int c=0; c<this->LEVEL_WIDTH;c++){
	 std::cout<<levels[student_level]->get_location(r,c)->get_display_character();
      }
      std::cout<<std::endl;
   }
   std::cout<<"Number of skills: "<< student->get_skills() <<std::endl;   
   std::cout<<"TA appeased round left: "<< ta1->get_appeased() <<std::endl;
   
}

/*******************************************
 *Function:set_level
 *Description:set map
 *Parameters:
 *Pre-Conditions:
 *Post-Conditions:
 * ****************************************/
void Maze::set_level(){
   
   srand(time(NULL));
   
   int b_row, b_col;
   b_row = this->levels[student_level]->get_s_row();                        //set new student to beginning 
   b_col = this->levels[student_level]->get_s_col();
   this->student = new IntrepidStudent;                                     
   student->set_location(b_row, b_col);
   ((OpenSpace*)(this->levels[student_level]->get_location(b_row, b_col)))->set_has_student(true);
   
   this->ta1 = new TA;                                                      //random place TA
   this->ta2 = new TA;
   int t_row, t_col;
   do{
      t_row = rand()%(this->LEVEL_HEIGHT);
      t_col = rand()%(this->LEVEL_WIDTH);
   }while(this->levels[student_level]->get_location(t_row,t_col)->is_occupiable()==false);
   ta1->set_location(t_row,t_col);
   ((OpenSpace*)(this->levels[student_level]->get_location(t_row, t_col)))->set_has_ta(true);
   do{
      t_row = rand()%(this->LEVEL_HEIGHT);
      t_col = rand()%(this->LEVEL_WIDTH);
   }while(this->levels[student_level]->get_location(t_row,t_col)->is_occupiable()==false);
   ta2->set_location(t_row,t_col);
   ((OpenSpace*)(this->levels[student_level]->get_location(t_row, t_col)))->set_has_ta(true);

   int k_row;                                                               //random place 3 skills
   int k_col;
   for(int i=0; i<3; i++){ 
      bool c_skill = false;
      do{     
	 k_row = rand()%(this->LEVEL_HEIGHT);     
	 k_col = rand()%(this->LEVEL_WIDTH);
	 if(this->levels[student_level]->get_location(k_row, k_col)->is_occupiable()==true)
	    if( ((OpenSpace*)(this->levels[student_level]->get_location(k_row, k_col)))->has_skill()==false )
	       if( ((OpenSpace*)(this->levels[student_level]->get_location(k_row, k_col)))->has_instructor()==false )
		  c_skill = true;
      }while(c_skill == false);
      ((OpenSpace*)(this->levels[student_level]->get_location(k_row, k_col)))->set_has_skill(true);
   }
}

/*******************************************
 *Function:move
 *Description:move base on input
 *Parameters:
 *Pre-Conditions:
 *Post-Conditions:
 * ****************************************/
void Maze::move(){
   ta1->turn();                                                 // ta appeased -1
   char dir;                                                    // move for ta1  
   int m_row, m_col;
   do{
      m_row = ta1->get_row();
      m_col = ta1->get_col();
      dir = ta1->get_move();
      if(dir == 'w')
	 m_row -= 1;
      if(dir == 's')
	 m_row += 1;
      if(dir == 'a')
	 m_col -= 1;
      if(dir == 'd')
	 m_col += 1;
   }while(this->levels[student_level]->get_location(m_row, m_col)->is_occupiable()==false);       
   ((OpenSpace*)(this->levels[student_level]->get_location(ta1->get_row(), ta1->get_col())))->set_has_ta(false);
   ((OpenSpace*)(this->levels[student_level]->get_location(m_row, m_col)))->set_has_ta(true);
   ta1->set_location(m_row , m_col);
   
   do{                                                         //move for ta2
      m_row = ta2->get_row();
      m_col = ta2->get_col();
      dir = ta2->get_move();
      if(dir == 'a')
	 m_row -= 1;
      if(dir == 'd')
	 m_row += 1;
      if(dir == 'w')
	 m_col -= 1;
      if(dir == 's')
	 m_col += 1;
   }while(this->levels[student_level]->get_location(m_row, m_col)->is_occupiable()==false);   
   ((OpenSpace*)(this->levels[student_level]->get_location(ta2->get_row(), ta2->get_col())))->set_has_ta(false);
   ((OpenSpace*)(this->levels[student_level]->get_location(m_row, m_col)))->set_has_ta(true);
   ta2->set_location(m_row , m_col);

   std::cout<<"| move up: w |  move left: a |  move down: s |  move right: d |"<<std::endl;
   std::cout<<"| Demonstrate a Programming Skill: p  |  Climb up the ladder: u |"<<std::endl;
   
   bool next = false;                                         // student in ladder 
   do{
      m_row = student->get_row();                             // move for student
      m_col = student->get_col();
      dir = student->get_move();
      if(dir == 'w')
	 m_row -= 1;
      if(dir == 's')
	 m_row += 1;
      if(dir == 'a')
	 m_col -= 1;
      if(dir == 'd')
	 m_col += 1;
      if(dir == 'p'){                                        // use skill , count for turn
	 if(student->get_skills() >0){
	    student->de_skill();
	    ta1->set_appeased();
	 }	    
	 else
	    std::cout<<"You have no skill."<<std::endl;
      }
      if(dir == 'u'){                                          //climb ladder , count for turn
	 if(((OpenSpace*)(this->levels[student_level]->get_location(m_row, m_col)))->has_ladder()==true){
	    this->student_level += 1;                          // set student to next level
	    int skill = student->get_skills();                 // delete student, ta
	    delete this->student;                              // set next map
	    delete this->ta1;
	    delete this->ta2;
	    this->set_level();
	    for(int i=0;i<skill;i++)
	       this->student->get_skill();
	    next = true;
	 }
      }
   }while(this->levels[student_level]->get_location(m_row, m_col)->is_occupiable()==false);   
   if(next == false){  
      ((OpenSpace*)(this->levels[student_level]->get_location(student->get_row(), student->get_col())))->set_has_student(false);  
      ((OpenSpace*)(this->levels[student_level]->get_location(m_row, m_col)))->set_has_student(true);  
      student->set_location(m_row , m_col);
   }
}

/*******************************************
 *Function:check
 *Description:control game flow
 *Parameters:
 *Pre-Conditions:
 *Post-Conditions:
 * ****************************************/
int Maze::check(){  	  
   bool ins = false;                                              //adjence to instructor  
   bool t = false;                                                //adjence to ta
   if(((OpenSpace*)(this->levels[student_level]->get_location(student->get_row(), student->get_col())))->has_skill()==true){          //pick up skill
      student->get_skill();
      ((OpenSpace*)(this->levels[student_level]->get_location(student->get_row(), student->get_col())))->set_has_skill(false);  
   }
   
   if(this->levels[student_level]->get_location(student->get_row()-1,student->get_col())->is_occupiable()==true)                        //check instrcutor
      if(((OpenSpace*)(this->levels[student_level]->get_location(student->get_row()-1, student->get_col())))->has_instructor()==true)     
	 ins = true;      
   if(this->levels[student_level]->get_location(student->get_row()+1,student->get_col())->is_occupiable()==true)  
      if(((OpenSpace*)(this->levels[student_level]->get_location(student->get_row()+1, student->get_col())))->has_instructor()==true)     
	 ins = true;
   if(this->levels[student_level]->get_location(student->get_row(),student->get_col()-1)->is_occupiable()==true)  
      if(((OpenSpace*)(this->levels[student_level]->get_location(student->get_row(), student->get_col()-1)))->has_instructor()==true)     
	 ins = true;
   if(this->levels[student_level]->get_location(student->get_row(),student->get_col()+1)->is_occupiable()==true)  
      if(((OpenSpace*)(this->levels[student_level]->get_location(student->get_row(), student->get_col()+1)))->has_instructor()==true)     
	 ins = true;
   if(ins == true){                                                                                //has instructor print map and return 1 if not fail and 2 when fail
      this->print_level();
      if(student->get_skills() >= 3){
	 std::cout<<"You get a passing grade and escape from CS162!"<<std::endl;
	 return 1;
      }
      else{
	 std::cout<<"You fail the exam, you need to restart from first level."<<std::endl;
	 return 2;
      }
   }
   
   do{                                                                                                  // do loop to generate new map untill no ta adjence to begin
   t = false;                                                                                                                          
   if(this->ta1->is_appeased()==false){
   if(this->levels[student_level]->get_location(student->get_row(),student->get_col())->is_occupiable()==true)  
      if(((OpenSpace*)(this->levels[student_level]->get_location(student->get_row(), student->get_col())))->has_ta()==true)     
	 t = true;         
   if(this->levels[student_level]->get_location(student->get_row()-1,student->get_col())->is_occupiable()==true)  
      if(((OpenSpace*)(this->levels[student_level]->get_location(student->get_row()-1, student->get_col())))->has_ta()==true)     
	 t = true;      
   if(this->levels[student_level]->get_location(student->get_row()+1,student->get_col())->is_occupiable()==true)  
      if(((OpenSpace*)(this->levels[student_level]->get_location(student->get_row()+1, student->get_col())))->has_ta()==true)     
	 t = true;
   if(this->levels[student_level]->get_location(student->get_row(),student->get_col()-1)->is_occupiable()==true)  
      if(((OpenSpace*)(this->levels[student_level]->get_location(student->get_row(), student->get_col()-1)))->has_ta()==true)     
	 t = true;
   if(this->levels[student_level]->get_location(student->get_row(),student->get_col()+1)->is_occupiable()==true)  
      if(((OpenSpace*)(this->levels[student_level]->get_location(student->get_row(), student->get_col()+1)))->has_ta()==true)           //check ta
	 t = true;
   if(t == true){
      this->print_level();                                                                                                        // if get caught by ta, reset all skill
      std::cout<<"You get caught by a TA, you lose all your skills."<<std::endl;      	                                          // delete student, ta, skill in map   
      ((OpenSpace*)(this->levels[student_level]->get_location(student->get_row(),student->get_col())))->set_has_student(false);   // reset a new map
      delete this->student;
      ((OpenSpace*)(this->levels[student_level]->get_location(ta1->get_row(),ta1->get_col())))->set_has_ta(false); 
      delete this->ta1;
      ((OpenSpace*)(this->levels[student_level]->get_location(ta2->get_row(),ta2->get_col())))->set_has_ta(false); 
      delete this->ta2;
      for(int r=0; r<LEVEL_HEIGHT; r++)
	 for(int c=0; c<LEVEL_WIDTH; c++)
	    if(this->levels[student_level]->get_location(r,c)->is_occupiable()==true)	       	      
	       ((OpenSpace*)(this->levels[student_level]->get_location(r,c)))->set_has_skill(false); 
      this->set_level();
   }
   }
   }while(t == true);
   return 0;
}

/*******************************************
 *Function:~Maze
 *Description:free memory
 *Parameters:
 *Pre-Conditions:
 *Post-Conditions:
 * ****************************************/
Maze::~Maze(){
   delete this->student;
   delete this->ta1;
   delete this->ta2;
   for(int n=0; n<this->NUM_LEVELS; n++){
      delete this->levels[n];
   }
}
