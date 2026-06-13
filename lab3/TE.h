#ifndef TE_H
#define TE_H
class Section; 
class TE{
    Section* section; 
    double grade; 
    public:
    TE(Section* section, double grade); 
    void setSection(Section* section); 
    void setGrade(double grade); 

    Section* getSection(); 
    double getGrade(); 

    void dislay(); 
}; 
#endif