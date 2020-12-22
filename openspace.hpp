/*********************************************
 *Program Filename:openspace.hpp
 *Author: Jianlong Huang
 *Date: 3/17
 *Description:
 *Input:
 *Output:
 * ******************************************/
#ifndef OPENSPACE_HPP
#define OPENSPACE_HPP
#include"mazelocation.hpp"

class OpenSpace : public MazeLocation{
   private:
      bool student;
      bool ta;
      bool instructor;
      bool ladder;
      bool skill;
      bool begin;
   public:
      OpenSpace();

      virtual bool is_occupiable();
      virtual char get_display_character();
      void set_has_student(bool student);
      bool has_student();
      void set_has_ta(bool ta);
      bool has_ta();
      void set_has_instructor(bool instructor);
      bool has_instructor();
      void set_has_ladder(bool ladder);
      bool has_ladder();
      void set_has_skill(bool skill);
      bool has_skill();
      void set_has_begin(bool begin);
      bool has_begin();
};

#endif
