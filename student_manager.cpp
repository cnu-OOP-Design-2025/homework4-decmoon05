#include "student_manager.h"
#include "student.h"

/* StudentManager */
int StudentManager::last_student_id = 1000;

void StudentManager::addStudent(char const* name, float midterm, float final) {
    int id = ++last_student_id;
    /* TODO */
    Student new_student(name, id, midterm, final);
    students[num_of_students] = new_student;
    num_of_students++;
    
}

void StudentManager::deleteStudent(int id) {
    /* TODO */
    int index = findStudentByID(id);

    // 배열 재정렬
    for (int i = index; i < num_of_students - 1; ++i) {
        students[i] = students[i + 1];
    }
    
    num_of_students--;
}

void StudentManager::modifyStudent(const Student& student) {
    /* TODO */
    
    int new_student_id = student.getID();
    for(int i = 0; i < num_of_students; i++){
        if(students[i].getID() == new_student_id){
            students[i].updateRecord(student.getName().c_str(), student.getRecord().getMidterm(), student.getRecord().getFinal());
            break;
        }
    }
}

int StudentManager::findStudentByID(int id) const {
    /* TODO */
    for(int i = 0; i < num_of_students; i++){
        if(students[i].getID() == id){
            return i;
        }
    }
    return -1;
}

int StudentManager::findBestStudentInMidterm() const {
    /* TODO */
    float bestMidterm = 0.0f;
    int index  = -1;
        for(int i = 0; i < num_of_students; i++){
            if(bestMidterm < students[i].getRecord().getMidterm()){
                bestMidterm = students[i].getRecord().getMidterm();
                index = students[i].getID();
            }

        }
    return index;

}

int StudentManager::findBestStudentInFinal() const {
    /* TODO */
    float bestFinal = 0.0f;
    int index = -1;
        for(int i = 0; i < num_of_students; i++){
            if(bestFinal < students[i].getRecord().getFinal()){
                bestFinal = students[i].getRecord().getFinal();
                index = students[i].getID();
            }

        }
    return index;
}

int StudentManager::findBestStudent() const {
    /* TODO */
    float bestTotal = 0.0f;
    int index = -1;
        for(int i = 0; i < num_of_students; i++){
            if(bestTotal < students[i].getRecord().getTotal()){
                bestTotal = students[i].getRecord().getTotal();
                index = students[i].getID();
            }

        }
    return index;
}

float StudentManager::getMidtermAverage() const {
    /* TODO */
    float totalsum = 0.0f;
    for(int i = 0; i < num_of_students; i++){
        totalsum += students[i].getRecord().getMidterm();
    }
    
    return (totalsum / num_of_students);
}

float StudentManager::getFinalAverage() const {
    /* TODO */
    float totalsum = 0.0f;
    for(int i = 0; i < num_of_students; i++){
        totalsum += students[i].getRecord().getFinal();
    }
    
    return (totalsum / num_of_students);
}

float StudentManager::getTotalAverage() const {
    /* TODO */
    float totalsum = 0.0f;
    for(int i = 0; i < num_of_students; i++){
        totalsum += students[i].getRecord().getTotal();
    }
    
    return (totalsum / num_of_students);
}

