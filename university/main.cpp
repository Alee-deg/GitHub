#include<iostream>
#include<string>
#include "university.h"
#include "universitySchool.h"

using namespace std;

int main(){
    //1.Create an University
    University *Internaion = new University("DHQG Tp HCM"); 
    //2.
    UniversitySchool *school1 = new UniversitySchool("HCMUS", "Nguyen Van Cu");
    UniversitySchool *school2 = new UniversitySchool("BKU", "Quan 10"); 
    UniversitySchool *school3 = new UniversitySchool("UIT", "Linh Trung, Thu Duc");
    //3.
    Internaion->attachSchool(school1); 
    Internaion->attachSchool(school2); 
    Internaion->attachSchool(school3);
    //4.
    Internaion->displayInf();
    Internaion->displaySchool();
    //5.
    Internaion->dettachSchool(school3); 
    //6.
    Internaion->displayInf(); 
    Internaion->displaySchool(); 
    //7.
    Internaion->attachSchool(school3);
    //8.
    Internaion->displayInf(); 
    Internaion->displaySchool(); 
    delete Internaion; 
    delete school1, school2, school3; 
    return 0; 
}