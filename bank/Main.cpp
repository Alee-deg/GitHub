#include<iostream>
#include<stdio.h>
#include<fstream>
#include<ctime>

using namespace std; 

class bank{
    private:
    int pin;  
    float balance; 
    string id, pass, name, fname, address, phone;  
    public:
    void menu(); 
    void bank_management(); 
    void atm_management(); 
    void new_user(); 
    void withdraw();
    void deposit();
    void already_user(); 
    void transfer(); 
    void payment(); 
    void search(); 
    void edit(); 
    void del(); 
    void show_records(); 
    void show_payment(); 
    void user_balance(); 
    void withdraw_atm(); 
    void check_detail(); 
}; 
void bank::menu(){
    p:
    system("clear");
    int choice; 
    string pin, pass; 
    string email; 
    cout << "\n\n\t\t\tControl Panel";
    cout << "\n\n 1.Bank Mangement"; 
    cout << "\n 2.ATM Mangement"; 
    cout << "\n 3.Exit";
    cout << "\n\n Enter Your Choice : "; 
    cin >> choice; 
    switch(choice){
        case 1:
            system("clear"); 
            cout << "\n\n\t\tLogin Account"; 
            cout << "\n\n E-mail : "; 
            cin >> email; 
            cin.ignore(); 
            cout << "\n\n\t\t\t Pin Code : "; 
            system("stty -echo"); 
            cin >> pin; 
            cout << "\n\n\t\t\t Password : "; 
            cin >> pass; 
            system("stty echo"); 
            if(email == "lhau2849" && pin == "12345" && pass == "12345"){
                bank_management();
            }
            else{
                cout << "Your E-mail, Pin & Password is wrong ..." << endl; 
                cin.get(); 
            }
            break; 
        case 2:
            atm_management(); 
            break; 
        case 3:
            exit(0); 
        default:
            cout << "\n\n Invalid Value...Please Try Again" << endl; 
    } 
    cin.get(); 
    goto p; 
}
void bank::bank_management(){
        p:
    system("clear"); 
    int choice; 
    cout << "\n\n\t\t\tBank Mangement System"; 
    cout << "\n\n1. New User";
    cout << "\n2. Already User"; 
    cout << "\n3. Deposit Option"; 
    cout << "\n4. Withdraw Option";
    cout << "\n5. Transfer Option";
    cout << "\n6. Payment Option";
    cout << "\n7. Search User Record";
    cout << "\n8. Edit User Record";
    cout << "\n9. Delete User Record";
    cout << "\n10. Show All Record";
    cout << "\n11. Payment All Record";
    cout << "\n12. Go Back";
    cout << "\n\n Enter Your Choice : "; 
    cin >> choice; 
    switch(choice){
        case 1:
            new_user(); 
            break; 
        case 2:
            already_user(); 
            break; 
        case 3:
            deposit(); 
            break;
        case 4:
            withdraw(); 
            break;
        case 5:
            transfer(); 
            break; 
        case 6:
            payment();  
            break; 
        case 7:
            search(); 
            break;
        case 8:
            edit(); 
            break;
        case 9:
            del(); 
            break;
        case 10:
            show_records(); 
            break;
        case 11:
            show_payment(); 
            break;
        case 12:
            menu(); 
        default:
            cout << "\n\n Invalid Value...Please Try Again" << endl; 
    }
    cin.get(); 
    goto p; 
}
void bank::atm_management(){
    p:
    system("clear"); 
    int choice; 
    cout << "\n\n\t\t\tATM Mangement System"; 
    cout << "\n\n1.User Login & Check Balance";
    cout << "\n2.Withdraw Amount"; 
    cout << "\n3.Account Detailes"; 
    cout << "\n4.Go Back";
    cout << "\n\n Enter Your Choice : ";
    cin >> choice; 
    switch(choice){
        case 1:
            user_balance(); 
            break; 
        case 2:
            withdraw_atm(); 
            break; 
        case 3:
            check_detail(); 
            break;
        case 4:
            menu();
        default:
            cout << "\n\n Invalid Value...Please Try Again" << endl; 
    }
    cin.get(); 
    goto p; 
}
void bank::new_user(){
    p:
    system("clear"); 
    fstream file;
    int p; 
    float b;
    string n, f, pa, a, ph, i;
    cout << "\n\n\t\t\tAdd New User"; 
    cout << "\n\n User ID : "; 
    cin >> id;
    cout << "\n\n\t\tName : ";
    cin >> name;
    cout << "\n\n Father Name : ";
    cin >> fname;
    cout << "\n\n\t\tAdress : ";
    cin >> address;
    cout << "\n\n Pin Code (5 digit) : "; 
    cin >> pin;
    cout << "\n\n\t\tPassword : ";
    cin >> pass;
    cout << "\n\n Phone No. : ";
    cin >> phone;
    cout << "\n\n\t\tCurrent Balance : ";
    cin >> balance;   
    cin.ignore(); 
    file.open("bank.txt", ios::in);
    if(!file){
        file.open("bank.txt", ios::app | ios::out);
        file << " " << id << " " << name << " " << fname << " " << address << " " << pin << " " << pass << " " << phone << " " << balance << "\n";
        file.close(); 
    }
    else{
        file >> i >> n >> f >> a >> p >> pa >> ph >> b;
        while(!file.eof()){
            if(i == id){
                cout << "\n\n User Id already Exist..."; 
                cin.get();
                goto p;
            }
            file >> i >> n >> f >> a >> p >> pa >> ph >> b;
        }
        file.close(); 
        file.open("bank.txt", ios::app | ios::out);
        file << " " << id << " " << name << " " << fname << " " << address << " " << pin << " " << pass << " " << phone << " " << balance << "\n";
        file.close(); 
    }
    cout << "\n\n Add New User Account Created Successfully..." << endl;
}
void bank::already_user(){
    system("clear");
    fstream file;
    string t_id;
    int found = 0; 
    cout << "\n\n\t\t\tAlready User Account";
    file.open("bank.txt", ios::in); 
    if(!file){
        cout << "\n\n File Opening Error...";
        cin.get(); 
    }
    else{
        cout << "\n\n User ID : ";
        cin >> t_id;
        file >> id >> name >> fname >> address >> pin >> pass >> phone >> balance;
        while(!file.eof()){
            if(t_id == id){
                found = 1; 
                system("clear");
                cout << "\n\n\t\t\t Already User Account";
                cout << "\n\n User ID: " << id << "     PinCode: " << pin << "      Pass:" << pass << endl; 
                cin.ignore(); 
            }
            file >> id >> name >> fname >> address >> pin >> pass >> phone >> balance; 
        }
        file.close(); 
        if(found == 0){
            cout << "\n\n User ID Can't Found..."; 
            cin.get(); 
        }
    }
    
}
void bank::deposit(){
    system("clear");
    float dep; 
    fstream file, file1;
    string t_id; 
    int found = 0; 
    cout << "\n\n\t\t\tDeposit Amount Option";
    file.open("bank.txt", ios::in);
    if(!file){
        cout << "\n\n File Opening Error...";
    }
    else{
        file1.open("bank1.txt", ios::app | ios::out); 
        cout << "\n\n User ID : ";
        cin >> t_id;
        file >> id >> name >> fname >> address >> pin >> pass >> phone >> balance; 
        while(!file.eof()){
            if(id == t_id){
                cout << "\n\n Amount For Deposit : ";
                cin >> dep;
                balance += dep;
                file1 << id << " " << name << " " << fname << " " << address << " " << pin << " " << pass << " " << phone << " " << balance << "\n"; 
                found ++;
                cout << "\n\n\t\t\t Your Amount" << dep << " Sucessfully Deposit...";
                cin.get(); 
            }
            else{
                file1 << id << " " << name << " " << fname << " " << address << " " << pin << " " << pass << " " << phone << " " << balance << "\n"; 
            }
            file >> id >> name >> fname >> address >> pin >> pass >> phone >> balance;
        }
        file.close(); 
        file1.close();
        remove("bank.txt");
        rename("bank1.txt", "bank.txt");
        if(found == 0){
            cout << "\n\n User ID Can't Found..."; 
            cin.get(); 
        }
    }
}
void bank::withdraw(){
    system("clear");
    float with; 
    fstream file, file1;
    string t_id; 
    int found = 0; 
    cout << "\n\n\t\t\tWithdraw Amount Option";
    file.open("bank.txt", ios::in);
    if(!file){
        cout << "\n\n File Opening Error...";
    }
    else{
        file1.open("bank1.txt", ios::app | ios::out); 
        cout << "\n\n User ID : ";
        cin >> t_id;
        file >> id >> name >> fname >> address >> pin >> pass >> phone >> balance; 
        while(!file.eof()){
            if(id == t_id){
                cout << "\n\n Amount For Withdraw : ";
                cin >> with;
                if(with <= balance){
                    balance -= with;
                    file1 << id << " " << name << " " << fname << " " << address << " " << pin << " " << pass << " " << phone << " " << balance << "\n"; 

                    cout << "\n\n\t\t\t Your Amount" << with << " Sucessfully Withdraw...";
                    cin.get(); 
                }
                else{
                    cout << "\n\n\t\t\tYour Current Balance "<< balance <<" is Less..."; 
                    file1 << id << " " << name << " " << fname << " " << address << " " << pin << " " << pass << " " << phone << " " << balance << "\n"; 
                    cin.get(); 
                }
                found ++;
            }
            else{
                file1 << id << " " << name << " " << fname << " " << address << " " << pin << " " << pass << " " << phone << " " << balance << "\n"; 
            }
            file >> id >> name >> fname >> address >> pin >> pass >> phone >> balance;
        }
        file.close(); 
        file1.close();
        remove("bank.txt");
        rename("bank1.txt", "bank.txt");
        if(found == 0){
            cout << "\n\n User ID Can't Found..."; 
        }
    }
}
void bank::transfer(){
    fstream file, file1; 
    system("clear");
    string r_id, s_id; int found = 0; 
    double amount; 
    cout << "\n\n\t\t\tPayment Transfer Option"; 
    file.open("bank.txt", ios::in);
    if(!file){
        cout << "\n\n File Opening Error..."; 
        cin.get(); 
    }
    else{
        cout << "\n\n Sender User ID For Transaction : ";
        cin >> s_id;
        cout << "\n\n Reciver User ID For Transaction : "; 
        cin >> r_id; 
        cout << "\n\n Enter Transaction Amount : ";
        cin >> amount; 
        file >> id >> name >> fname >> address >> pin >> pass >> phone >> balance;
        while(!file.eof()){
            if(s_id == id && balance >= amount){
                found += 1; 
            }
            else if(r_id == id){
                found += 1; 
            }
            file >> id >> name >> fname >> address >> pin >> pass >> phone >> balance;
        }
        file.close(); 
        if(found == 2){
            file1.open("bank1.txt", ios::app | ios::out); 
            file.open("bank.txt", ios::in); 
            file >> id >> name >> fname >> address >> pin >> pass >> phone >> balance; 
            while(!file.eof()){
                if(s_id == id){
                    balance -= amount; 
                    file1 << id << " " << name << " " << fname << " " << address << " " << pin << " " << pass << " " << phone << " " << balance << "\n"; 
                }
                else if(r_id == id){
                    balance += amount; 
                    file1 << id << " " << name << " " << fname << " " << address << " " << pin << " " << pass << " " << phone << " " << balance << "\n"; 
                }
                else{
                    file1 << id << " " << name << " " << fname << " " << address << " " << pin << " " << pass << " " << phone << " " << balance << "\n"; 
                }
                file >> id >> name >> fname >> address >> pin >> pass >> phone >> balance; 
            }
            file.close(); 
            file1.close();
            remove("bank.txt"); 
            rename("bank1.txt", "bank.txt");
            cout << "\n\n\t\t\tTransaction Sucessfully..."; 
        }
        else{
            cout << "\n\n\t\t\tBoth Transaction User ID's & Balance Invalid...." << endl; 
            cin.get(); 
        }
    }
}
void bank::payment(){
    system("clear");
    int found = 0; 
    fstream file, file1;
    string t_id, b_name;
    double amount;  
    time_t current = time(0); 
    tm *ltm = localtime(&current); 
    file.open("bank.txt", ios::in); 
    cout << "\n\n\t\t\tBills Payment Option";
    if(!file){
        cout << "\n\n File Opening Error..."; 
        cin.get(); 
    }
    else{
        file1.open("bank1.txt", ios::app | ios::out); 
        cout << "\n\n User ID : ";
        cin >> t_id; 
        cout << "\n\n Bill Name : ";
        cin >> b_name;
        cout << "\n\n Bill Amount : ";
        cin >> amount; 
        file >> id >> name >> fname >> address >> pin >> pass >> phone >> balance; 
        while(!file.eof()){
            if(t_id == id && balance >= amount){
                found ++; 
                balance -= amount; 
                file1 << id << " " << name << " " << fname << " " << address << " " << pin << " " << pass << " " << phone << " " << balance << "\n"; 
            }
            else{
                file1 << id << " " << name << " " << fname << " " << address << " " << pin << " " << pass << " " << phone << " " << balance << "\n"; 
            }
            file >> id >> name >> fname >> address >> pin >> pass >> phone >> balance; 
        }
        file.close(); 
        file1.close();
        remove("bank.txt");
        rename("bank1.txt", "bank.txt"); 
        if(found == 1){
            file.open("bill.txt", ios::app | ios::out); 
            file << t_id << " " << b_name << " " << amount << " " << ltm ->tm_mday << " " << 1 + ltm->tm_mon << " " << 1900 + ltm->tm_year << " " << ltm->tm_hour << " " << ltm -> tm_min << "\n"; 
            file.close(); 
            cout << "\n\n\t\t\t" << b_name << " Bill Pay Sucessfully..."; 
            cin.ignore(); 
            cin.get(); 
        }
        else{
            cout << "\n\n\t\t\t User ID OR Amount Invalid..."; 
        }
    }
}
void bank::search(){
    system("clear");
    fstream file; 
    string t_id; 
    file.open("bank.txt", ios::in); 
    int found = 0; 
    if(!file){
        cout << "\n\nFile Opening Error..."; 
    }
    else{
        cout << "\n\n User ID: ";
        cin >> t_id; 
        file >> id >> name >> fname >> address >> pin >> pass >> phone >> balance;
        while(!file.eof()){
            if(t_id == id){
                system("clear"); 
                cout << "\n\n\t\t\tSearch User Record";
                cout << "\n\n\n User ID: " << id <<" Name: " << name << " Father's Name: " << fname;
                cout << "\n Address: " << address << " Pin: " << pin << " Pass: " << pass ;
                cout << "\n Phone No.: " << phone << " Current Balance: " << balance; 
                cin.get(); 
                found ++; 
            }
            file >> id >> name >> fname >> address >> pin >> pass >> phone >> balance;
        }
        file.close(); 
        if(found == 0){
            cout << "User ID can't Found..."; 
        }
    }
}
void bank::edit(){
    system("clear");
    fstream file, file2;
    cout << "\n\n\t\t\tEdit User Record"; 
    float bal; 
    int found = 0; 
    string t_id, n, f, a, pi, p, ph; 
    file.open("bank.txt", ios::in); 
    if(!file){
        cout << "\n\nFile Openning Error...";
    }else{
        cout << "\n\n User ID : ";
        cin >> t_id; 
        file2.open("bank2.txt", ios::app | ios::out); 
        file >> id >> name >> fname >> address >> pin >> pass >> phone >> balance; 
        while(!file.eof()){
            if(id == t_id){
                    cout << "\n\n\t\tName : ";
                    cin >> n;
                    cout << "\n\n Father Name : ";
                    cin >> f;
                    cout << "\n\n\t\tAdress : ";
                    cin >> a;
                    cout << "\n\n Pin Code (5 digit) : "; 
                    cin >> pi;
                    cout << "\n\n\t\tPassword : ";
                    cin >> p;
                    cout << "\n\n Phone No. : ";
                    cin >> ph;
                    cout << "\n\n\t\tCurrent Balance : ";
                    cin >> bal;   
                    file2 << id << " " << n << " " << f << " " << a << " " << pi << " " << pass << " " << ph << " " << bal << "\n";
                    found ++; 
                    cout << "\n\n\t\t\tRecord Edit Sucessfully..."; 
                    cin.get(); 
            }
            else{
                file2 << id << " " << name << " " << fname << " " << address << " " << pin << " " << pass << " " << phone << " " << balance << "\n"; 
            }
            file >> id >> name >> fname >> address >> pin >> pass >> phone >> balance; 
        }
        file2.close(); 
        file.close(); 
        remove("bank.txt"); 
        rename("bank2.txt", "bank.txt"); 
        if(found == 0){
            cout << "\n\n User Id Can't Found..."; 
            cin.get(); 
        }
    }
}
void bank::del(){
    system("clear");
    fstream file, file2;
    cout << "\n\n\t\t\tDelete User Record"; 
    float bal; 
    int found = 0; 
    string t_id; 
    file.open("bank.txt", ios::in); 
    if(!file){
        cout << "\n\nFile Openning Error...";
    }else{
        cout << "\n\n User ID : ";
        cin >> t_id; 
        file2.open("bank2.txt", ios::app | ios::out); 
        file >> id >> name >> fname >> address >> pin >> pass >> phone >> balance; 
        while(!file.eof()){
            if(id == t_id){
                cout << "\n\n\t\t\tRecore Deleted Sucessfully..."; 
                found ++; 
                cin.get(); 
            }
            else{
                file2 << id << " " << name << " " << fname << " " << address << " " << pin << " " << pass << " " << phone << " " << balance << "\n"; 
            }
            file >> id >> name >> fname >> address >> pin >> pass >> phone >> balance; 
        }
        file2.close(); 
        file.close(); 
        remove("bank.txt"); 
        rename("bank2.txt", "bank.txt"); 
        if(found == 0){
            cout << "\n\n User Id Can't Found..."; 
            cin.get(); 
        }
    }
}
void bank::show_records(){
    system("clear");
    fstream file; 
    int found = 0; 
    cout << "\n\n\t\t\tShow All User's Records"; 
    file.open("bank.txt", ios::in);
    if(!file){
        cout << "\n\nFile Opening Error...";
    }  
    else{
        file >> id >> name >> fname >> address >> pin >> pass >> phone >> balance; 
        while(!file.eof()){
            cout << "\n\n\n User ID: " << id;
            cout << "\n Name : " << name; 
            cout << "\n Father Name: " << fname;
            cout << "\n Adress: " << address;
            cout << "\n Pin : " << pin; 
            cout << "\n Password: " << pass; 
            cout << "\n Phone No.: " << phone;
            cout << "\n Current Balance: " << balance; 
            cout << "\n\n=========================================="; 
            file >> id >> name >> fname >> address >> pin >> pass >> phone >> balance; 
            cin.get(); 
            found ++; 
        }
        file.close(); 
        if(found == 0){
            cout << "\n\n Data Base is Empty..."; 
            cin.get(); 
        }
    }
}   
void bank::show_payment(){
    system("clear");
    fstream file; 
    float amount; 
    int found = 0, c_date, c_month, c_year, c_hour, c_minute; 
    cout << "\n\n\t\t\tShow All Bill's Records"; 
    file.open("bill.txt", ios::in);
    if(!file){
        cout << "\n\nFile Opening Error...";
    }  
    else{
        file >> id >> name >> amount >> c_date >> c_month >> c_year >> c_hour >> c_minute; 
        while(!file.eof()){
            cout << "\n\n\n User ID: " << id;
            cout << "\n Bill Name : " << name; 
            cout << "\n Bill Amount : " << amount;
            cout << "\n Date: " << c_date;
            cout << "\n Month : " << c_month; 
            cout << "\n Year: " << c_year; 
            cout << "\n Hour: " << c_hour;
            cout << "\n Minute: " << c_minute; 
            cout << "\n\n=========================================="; 
            file >> id >> name >> amount >> c_date >> c_month >> c_year >> c_hour >> c_minute; 
            cin.get(); 
            found ++; 
        }
        file.close(); 
        if(found == 0){
            cout << "\n\n Data Base is Empty..."; 
            cin.get(); 
        }
    }
}   
void bank::user_balance(){
    system("clear"); 
    cout << "\n\n\t\t\tUser Login & Check Balance";
    fstream file;
    string t_id, t_pass; 
    int t_pin, found = 0; 
    file.open("bank.txt", ios::in);
    if(!file){
        cout << "\n\n File Opening Error...";
        cin.get(); 
    }
    else{
        cout << "\n\n User ID : ";
        cin >> t_id;
        cout << "\n\n\t\t\tPin Code : ";
        system("stty -echo");
        cin >> t_pin; 
        cout << "\n\nPassword : ";
        cin >> t_pass; 
        system("stty echo"); 
        file >> id >> name >> fname >> address >> pin >> pass >> phone >> balance; 
        while(!file.eof()){
            if(t_id == id && t_pin == pin && t_pass == pass){
                cout << "\n\n\t\t\t Your Current Balance is : " << balance; 
                found ++; 
                cin.ignore(); 
                cin.get(); 
            }
            file >> id >> name >> fname >> address >> pin >> pass >> phone >> balance; 
        }
        file.close(); 
        if(found == 0){
            cout << "\n\n\t\t\t User ID, Pin & Password Invalid..."; 
            cin.get(); 
        }
    }
}
void bank::withdraw_atm(){
    system("clear");
    float with; 
    string t_id, t_pass; 
    int t_pin; 
    fstream file, file1;
    int found = 0; 
    cout << "\n\n\t\t\tWithdraw Amount Option";
    file.open("bank.txt", ios::in);
    if(!file){
        cout << "\n\n File Opening Error...";
    }
    else{
        file1.open("bank1.txt", ios::app | ios::out); 
        cout << "\n\n User ID : ";
        cin >> t_id;
        cout << "\n\n\t\t\tPin Code : "; 
        system("stty -echo"); 
        cin >> t_pin; 
        cout << "\n\nPassword : "; 
        cin >> t_pass; 
        system("stty echo"); 
        file >> id >> name >> fname >> address >> pin >> pass >> phone >> balance; 
        while(!file.eof()){
            if(id == t_id && t_pin == pin && t_pass == pass){
                cout << "\n\n Amount For Withdraw : ";
                cin >> with;
                if(with <= balance){
                    balance -= with;
                    file1 << id << " " << name << " " << fname << " " << address << " " << pin << " " << pass << " " << phone << " " << balance << "\n"; 

                    cout << "\n\n\t\t\t Your Amount " << with << " Sucessfully Withdraw...";
                    cout << "\n\n\t\t Your Current Balance " << balance; 
                    cin.get(); 
                }
                else{
                    cout << "\n\n\t\t\tYour Current Balance "<< balance <<" is Less..."; 
                    file1 << id << " " << name << " " << fname << " " << address << " " << pin << " " << pass << " " << phone << " " << balance << "\n"; 
                    cin.get(); 
                }
                found ++;
            }
            else{
                file1 << id << " " << name << " " << fname << " " << address << " " << pin << " " << pass << " " << phone << " " << balance << "\n"; 
            }
            file >> id >> name >> fname >> address >> pin >> pass >> phone >> balance;
        }
        file.close(); 
        file1.close();
        remove("bank.txt");
        rename("bank1.txt", "bank.txt");
        if(found == 0){
            cout << "\n\n User ID, Pin & Pass Invalid"; 
        }
    } 

}
void bank::check_detail(){
    system("clear");
    fstream file;
    cout << "\n\n\t\t\tCheck_Detail ATM"; 
    float bal; 
    int found = 0; 
    string t_id, t_pass;
    int t_pin;  
    file.open("bank.txt", ios::in); 
    if(!file){
        cout << "\n\nFile Openning Error...";
    }else{
        cout << "\n\n User ID : ";
        cin >> t_id; 
        cout << "\n\n\t\t\t Pin Code: ";
        system("stty -echo");
        cin >> t_pin;
        cout << "\n\n Password: "; 
        cin >> t_pass; 
        system("stty echo");   
        file >> id >> name >> fname >> address >> pin >> pass >> phone >> balance; 
        while(!file.eof()){
            if(id == t_id && pin == t_pin && pass == t_pass){
                    cout << "\n\n\t\tName : "; cout << name; 
                    cout << "\n\n Father Name : "; cout << fname; 
                    cout << "\n\n\t\tAdress : "; cout << address; 
                    cout << "\n\n Phone No. : "; cout << phone; 
                    cout << "\n\n\t\tCurrent Balance : "; cout << balance; 
                    found ++;  
                    cin.get(); 
            }
            file >> id >> name >> fname >> address >> pin >> pass >> phone >> balance; 
        }
        file.close(); 
        if(found == 0){
            cout << "\n\n User Id, Pin & Password Invalid..."; 
            cin.get(); 
        }
    }
}
void introduction(){
    system("clear"); 
    cout << "\n\n\n\n\n\n\n\t\t";
    for(int i = 1; i<=65; i ++) cout << "*";
    cout << "\n\t\t ";
    for(int i = 1; i<=63; i ++) cout << "*"; 
    cout << "\n\t\t  "; 
    for(int i = 1; i<=61; i ++) cout << "*";
    cout << "\n\n\t\t\t\t Bank & ATM Management System \n\n\t\t  "; 
    for(int i = 1; i<=61; i ++) cout << "*";
    cout << "\n\t\t ";
    for(int i = 1; i<=63; i ++) cout << "*"; 
    cout << "\n\t\t"; 
    for(int i = 1; i <= 65; i ++) cout << "*"; 
    cout <<"\n";
    cin.get(); 
    system("clear"); 
} 
int main(){
    bank obj; 
    introduction(); 
    obj.menu(); 
}