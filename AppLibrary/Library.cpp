#include "Library.h"
#include<iostream>

using namespace std; 
Library::~Library(){
    for(auto l_borrowerRecord : borrowers){
        delete l_borrowerRecord.second; 
    }
    for(auto book : stocks){
        delete book.second; 
    }
}
void Library::addBorrowerRecord(){
    while(true){
        system("clear");  
        string a_id, a_name, a_phone; 
        cout << "\n\t\t\t\t\tADD BORROWER RECORD";
        cout << "\n\n\t\t\tID BorrowerRecord(Enter \\q to quite): "; 
        cin >> a_id; 
        if(a_id == R"(\q)"){break;}
        cin.ignore(); 
        cout << "\n\t\t\tName: "; 
        getline(cin, a_name); 
        cout << "\n\t\t\tPhone NO.: "; 
        cin >> a_phone; 
        try{
            pqxx::connection C("host=localhost dbname=postgres user=alee password=123456"); 
            if(C.is_open()){
                pqxx::work W(C); 
                W.exec("set search_path to csdl_library;");
                W.exec_params(
                    "insert into borrower_record(id_borrower, name, phone) values ($1, $2, $3)",
                    a_id,
                    a_name, 
                    a_phone
                ); 
                W.commit(); 
                BorrowerRecord* newBor = new BorrowerRecord(a_id, a_name, a_phone, 0, "binh thuong"); 
                borrowers.insert({a_id, newBor}); 
                cout << "\n\t\t\t\t\t\t\t\t\tDone!"; 
                cout << "\n\t\t\t\t\t\t\t\t\tPress Enter to continue!"; 
            }
            else{
                throw std::runtime_error("Cannot open database"); 
            }    
            cin.ignore(); 
            cin.get(); 
            break; 
        }
        catch(const pqxx::sql_error& e){
            std::cerr << "ERROR: " << e.what() << std::endl; 
            cin.ignore(); 
            cin.get(); 
        }
        catch(const std::bad_alloc& e){
            std::cerr << "ERROR: NOT ENOUGH MEMORY!" << std::endl; 
            cin.get(); 
            exit(1); 
        }
        catch(const std::exception& e){
            std::cerr << "ERROR: " << e.what() << std::endl;
            cout << "Inspect and Enter Info again, Please!"; 
            cout << "\r\nPress Enter to continue!"; 
            cin.get(); 
        }
    }   
}
void Library::p_addBorrowerRecord(string id, BorrowerRecord* newBor){
    borrowers.insert({id, newBor}); 
}
void Library::removeBorrowerRecord(){
    while(true){
        system("clear");
        cout << "\n\t\t\t\t\tREMOVE_BORROWERRECORD"; 
        string r_id; 
        cout << "\n\t\t\tEnter User'ID(Enter \\q to quite): "; 
        cin >> r_id;
        if(r_id == R"(\q)"){
            break; 
        }
        if(borrowers.find(r_id) == borrowers.end()){
            cout << "\n\t\t\t\t\t\t\tUser'ID not found"; 
            cin.ignore(); 
            cin.get(); 
        } 
        else{
            auto toDelete = borrowers.find(r_id); 
            try{
                pqxx::connection C("host=localhost dbname=postgres user=alee password=123456"); 
                if(C.is_open()){
                    pqxx::work W(C); 
                    W.exec("set search_path to csdl_library"); 
                    W.exec_params("delete from borrower_record where id_borrower=$1",
                    r_id
                    ); 
                    W.commit(); 
                    borrowers.erase(toDelete); 
                    cout << "\n\t\t\t\t\t\tDone!"; 
                    cin.ignore();
                    cin.get();  
                    break; 
                }
                else{
                    throw std::runtime_error("Cannot open database"); 
                }
            }
            catch(const pqxx::sql_error& e){
                std::cerr << "ERROR: " << e.what() << std::endl; 
            }
        }
    }
}; 
void Library::p_removeBorrowerRecord(string id){
    if(borrowers.find(id) == borrowers.end()){
        cout << "\n\t\t\t\t\t\t\tUser'ID not found"; 
        cin.ignore(); 
        cin.get(); 
    } 
    else{
        auto toDelete = borrowers.find(id); 
        try{
            pqxx::connection C("host=localhost dbname=postgres user=alee password=123456"); 
            if(C.is_open()){
                pqxx::work W(C); 
                W.exec("set search_path to csdl_library"); 
                W.exec_params("delete from borrower_record where id_borrower=$1",
                id
                ); 
                W.commit(); 
                borrowers.erase(toDelete); 
                cout << "\n\t\t\t\t\t\tDone!"; 
                cin.ignore();
                cin.get();  
            }
            else{
                throw std::runtime_error("Cannot open database"); 
            }
        }
        catch(const pqxx::sql_error& e){
            std::cerr << "ERROR: " << e.what() << std::endl; 
        }
    }
};
void Library::updateBorrowerRecord(){
    while(true){
        system("clear");  
        string u_id, u_name, u_phone, u_status;
        int u_nbViolate;  
        cout << "\n\t\t\t\t\tUPDATE BORROWER RECORD";
        cout << "\n\n\t\t\tID BorrowerRecord(Enter \\q to quite): "; 
        cin >> u_id; 
        if(u_id == R"(\q)"){
            break; 
        }
        if(borrowers.find(u_id) == borrowers.end()){
            cout << "\n\t\t\t\t\t\t\t\t\tNot found User'ID"; 
            cin.ignore(); 
            cin.get(); 
            continue;
        } 
        cin.ignore(); 
        cout << "\n\t\t\tName: "; 
        getline(cin, u_name); 
        cout << "\n\t\t\tPhone NO.: "; 
        cin >> u_phone; 
        cout << "\n\t\t\tNumber Of Violate: ";
        cin >> u_nbViolate; 
        cin.ignore(); 
        cout << "\n\t\t\tStatus('binh thuong', 'xau'): "; 
        getline(cin, u_status);  
        try{
            pqxx::connection C("host=localhost dbname=postgres user=alee password=123456"); 
            if(C.is_open()){
                BorrowerRecord* newBor = new BorrowerRecord(u_id, u_name, u_phone, u_nbViolate, u_status); 
                pqxx::work W(C); 
                W.exec("set search_path to csdl_library;");
                W.exec_params(
                    R"(update borrower_record 
                    set name = $1, phone = $2, violations = $3, status = $4
                    where id_borrower = $5)",
                    u_name,
                    u_phone,
                    u_nbViolate,
                    u_status,
                    u_id
                ); 
                W.commit();
                auto toDelete = borrowers.find(u_id); 
                delete toDelete -> second; 
                borrowers.erase(toDelete);
                borrowers.insert({u_id, newBor}); 
                cout << "\n\t\t\t\t\t\t\t\t\tDone!"; 
                cout << "\n\t\t\t\t\t\t\t\t\tPress Enter to continue!"; 
            }
            else{
                throw std::runtime_error("Cannot open database"); 
            }    
            cin.ignore(); 
            cin.get(); 
            break; 
        }
        catch(const pqxx::sql_error& e){
            std::cerr << "ERROR: " << e.what() << std::endl; 
            cin.ignore(); 
            cin.get(); 
        }
        catch(const std::exception& e){
            std::cerr << "ERROR: " << e.what() << std::endl;
            cout << "Inspect and Enter Info again, Please!"; 
            cout << "\r\nPress Enter to continue!"; 
            cin.get(); 
        }
    } 
}
void Library::p_updateBorrowerRecord(string id, string name, string phone, int violations, string status){
    if(borrowers.find(id) == borrowers.end()){
        cout << "\n\t\t\t\t\t\t\t\t\tNot found User'ID"; 
        return; 
    } 
    try{
        pqxx::connection C("host=localhost dbname=postgres user=alee password=123456"); 
        if(C.is_open()){
            BorrowerRecord* newBor = new BorrowerRecord(id, name, phone, violations, status); 
            pqxx::work W(C); 
            W.exec("set search_path to csdl_library;");
            W.exec_params(
                R"(update borrower_record 
                set name = $1, phone = $2, violations = $3, status = $4
                where id_borrower = $5)",
                name,
                phone,
                violations,
                status,
                id
            ); 
            W.commit();
            auto toDelete = borrowers.find(id); 
            delete toDelete -> second; 
            borrowers.erase(toDelete);
            borrowers.insert({id, newBor}); 
            cout << "\n\t\t\t\t\t\t\t\t\tDone!"; 
            cout << "\n\t\t\t\t\t\t\t\t\tPress Enter to continue!"; 
        }
        else{
            throw std::runtime_error("Cannot open database"); 
        }     
    }
    catch(const pqxx::sql_error& e){
        std::cerr << "ERROR: " << e.what() << std::endl; 
        cin.ignore(); 
        cin.get(); 
    }
    catch(const std::exception& e){
        std::cerr << "ERROR: " << e.what() << std::endl;
        cout << "Inspect and Enter Info again, Please!"; 
        cout << "\r\nPress Enter to continue!"; 
        cin.get(); 
    }
}
void Library::addBook(){
    string a_id, a_author, a_title, a_intro;
    double a_price; 
    int a_quantity; 
    while(true){
        system("clear"); 
        cout << "\n\t\t\t\t\tADD BOOK"; 
        cout << "\n\t\t\tEnter ID(Enter \\q to quite): "; 
        cin >> a_id; 
        if(a_id == R"(\q)") break;
        cin.ignore(); 
        cout << "\n\t\t\tEnter Author: "; 
        getline(cin, a_author); 
        cout << "\n\t\t\tEnter Title: ";
        getline(cin, a_title);  
        cout << "\n\t\t\tEnter Intro: ";
        getline(cin, a_intro); 
        cout << "\n\t\t\tEnter Price: "; 
        cin >> a_price; 
        cout << "\n\t\t\tEnter Quantity: "; 
        cin >> a_quantity; 
        try{
            Book* newBook = new Book(a_id, a_author, a_title, a_intro, a_price, a_quantity); 
            pqxx::connection C("host=localhost dbname=postgres user=alee password=123456"); 
            if(C.is_open()){
                pqxx::work W(C);
                W.exec("set search_path to csdl_library;");  
                W.exec_params(R"(insert into book(id_book, author, title, price, intro, quantity)
                    values($1, $2, $3, $4, $5, $6);)",
                a_id,
                a_author,
                a_title,
                a_price,
                a_intro,
                a_quantity); 
                W.commit(); 
                stocks.insert({a_id, newBook}); 
                cout << "\n\t\t\t\t\t\t\t\tDone!"; 
                cin.ignore(); 
                cin.get(); 
                break; 
            }
            else{
                throw std::runtime_error("Cannot open database"); 
            }
        }
        catch(const pqxx::sql_error &e){
            std::cerr << "ERROR: " << e.what() << endl; 
            cin.ignore();
            cin.get(); 
        }
        catch(const std::exception &e){
            std::cerr << "ERROR: " << e.what() << endl; 
            cin.ignore(); 
            cin.get(); 
        }
    } 
}
void Library::p_addBook(string id, Book* newBook){
    stocks.insert({id, newBook}); 
}
void Library::removeBook(){
    string r_id; 
    while(true){
        system("clear"); 
        cout << "\n\t\t\t\t\tREMOVE BOOK"; 
        cout << "\n\t\t\tEnter Book'ID(Enter \\q to quite): "; 
        cin >> r_id; 
        if(r_id == R"(\q)") break; 
        if(stocks.find(r_id) == stocks.end()){
            cout << "\n\t\t\t\t\t\t\tBook'ID not found";
            cin.ignore(); 
            cin.get(); 
            continue; 
        }
        try{
            pqxx::connection C("host=localhost dbname=postgres user=alee password=123456"); 
            if(C.is_open()){
                pqxx::work W(C); 
                W.exec("set search_path to csdl_library;"); 
                W.exec_params("delete from book where id_book = $1;",
                r_id); 
                W.commit(); 
                cout << "\n\t\t\t\t\t\tDone!"; 
                auto book = stocks.find(r_id); 
                stocks.erase(book); 
                delete book -> second; 
                cin.ignore(); 
                cin.get(); 
            }
            else{
                throw std::runtime_error("Cannot open database"); 
            }
        }
        catch(const pqxx::sql_error &e){
            std::cerr << "ERROR: " << e.what() << endl; 
            cin.ignore(); 
            cin.get(); 
        }
    }
}
void Library::menu(){
    p:
    system("clear"); 
    int choice; 
    cout << "\tMENU"; 
    cout << "\n1.AddBorrowerRecord";
    cout << "\n2.RemoveBorrowerRecord"; 
    cout << "\n3.UpdateBorrowerRecord";
    cout << "\n4.AddBook"; 
    cout << "\n5.RemoveBook"; 
    cout << "\n6.UpdateBook"; 
    cout << "\n7.LendOneBook"; 
    cout << "\n8.ReturnOneBook"; 
    cout << "\n9.DisplayBookAvailableForLoan"; 
    cout << "\n10.GetInfoABook"; 
    cout << "\n11.GetInfoBorrowerRecord"; 
    cout << "\n12.DisplayInfoAllBook"; 
    cout << "\n13.Exit"; 
    cout << "\nEnter Your Choice: "; 
    cin >> choice; 
    switch(choice){
        case 1:
        addBorrowerRecord(); 
        break; 
        case 2:
        removeBorrowerRecord(); 
        break; 
        case 3:
        updateBorrowerRecord(); 
        break; 
        case 4:
        addBook(); 
        break; 
        case 5:
        removeBook(); 
        break; 
        case 6:
        //updateBook(); 
        break; 
        case 7:
        //lendOneBook(); 
        break; 
        case 8:
        //returnOneBook(); 
        break; 
        case 9:
        //displayBookAvailableForLoan(); 
        break; 
        case 10:
        //getInfoABook(); 
        break; 
        case 11:
        //getInfoABorrowerRecord(); 
        break; 
        case 12:
        //displayInfoAllBook(); 
        break; 
        case 13:
        exit(1); 
        break; 
        default:
        cout << "Invalid enter, please again..."; 
        cin.ignore(); 
        cin.get(); 
    }
    goto p; 
}