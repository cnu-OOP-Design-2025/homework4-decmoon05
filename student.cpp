#include "student.h"

#include <iostream>
#include <string>

/* StudentRecord */

StudentRecord::StudentRecord(float midterm, float final) 
/* TODO: Initializer list 사용해 초기화 해보기 */
    :midterm(midterm), final(final)
{

}

float StudentRecord::getTotal() const {
    /* TODO */
    return (midterm + final);
}

void StudentRecord::updateScores(float midterm, float final) {
    /* TODO: this keyword 사용해 보기 */
    this->midterm =midterm;
    this->final = final;
}


/* Student */

Student::Student() 
/* TODO: Initializer list 사용해 초기화 해보기 */
    : name("None"), id(0), record()
{}

Student::Student(const char *name, int id, float midterm, float final)
/* TODO: Initializer list 사용해 초기화 해보기 */
    : name(name), id(id), record(midterm,final)
{}

void Student::updateRecord(const char *name, float midterm, float final) {
    /* TODO */
    this->name = name;
    this->record.updateScores(midterm,final);
}

