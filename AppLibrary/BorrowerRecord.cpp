#include "BorrowerRecord.h"
#include <stdexcept>

BorrowerRecord::BorrowerRecord(string b_id, string b_name, string b_phone, int b_nbViolate, string b_status){
    this -> setID(b_id); 
    this -> setName(b_name); 
    this -> setPhone(b_phone); 
    this -> setStatus(b_status); 
    this -> setViolate(b_nbViolate);     
}

void BorrowerRecord::setID(string b_id){
    if(b_id.empty()){
        throw std::invalid_argument("ID cannot be left blank!"); 
    }
    this -> b_id = b_id; 
}
void BorrowerRecord::setName(string b_name){
    if(b_name.empty()){
        throw std::invalid_argument("Name cannot be left blank!"); 
    }
    this -> b_name = b_name; 
}
void BorrowerRecord::setPhone(string b_phone){
    if(b_phone.empty()){
        throw std::invalid_argument("Phone cannot be left blank!"); 
    }
    this -> b_phone = b_phone; 
}
void BorrowerRecord::setStatus(string b_status){
    if(b_status.empty()){
        throw std::invalid_argument("Status cannot be left blank!"); 
    }
    else if(b_status != "binh thuong" && b_status != "xau"){
        throw std::invalid_argument("Invalid!"); 
    }
    this -> b_status = b_status; 
}
void BorrowerRecord::setViolate(int b_violate){
    if(b_violate < 0){
        throw std::invalid_argument("Invalid!"); 
    }
    this -> b_nbViolate = b_violate; 
}


