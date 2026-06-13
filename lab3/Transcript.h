#ifndef TRANSCRIPT_H
#define TRANSCRIPT_H
#include <list>
#include <string>
class Section; 
class TE; 
class Transcript{
    private:
    std::list<TE*> TEs;   
    public:
    ~Transcript(); 
    void addTEs(TE* newTE); 
    void dropSection(Section* section); 
    std::list<TE*> getTEs();  
    void displayTE(); 
}; 
#endif