#include<iostream>
#include<fstream>
#include<sstream>
#include<cstdlib>
#include<thread>
#include<chrono>

using namespace std; 

class Bill{
    private:
    string Item; 
    int Rate, Quantity;
    public:
    Bill():Item(""), Rate(0), Quantity(0){}

    void setItem(string item){this -> Item = item;}
    void setRate(int rate){this -> Rate = rate;}
    void setQuantity(int quantity){this -> Quantity = quantity;}

    string getItem(){return this -> Item;}
    int getRate(){return this -> Rate;}
    int getQuantity(){return this -> Quantity;}

}; 

void addItem(Bill b){
    bool close = false; 
    while(!close){
        int choice; 
        cout << "\t1.Add."<< endl; 
        cout << "\t2.Close." << endl;
        cout << "\tEnter Choice: "; 
        cin >> choice;  
        if(choice == 1){
            system("clear"); 
            string item; 
            int rate, quant; 

            cout << "\tEnter Item Name: "; 
            cin >> item; 
            b.setItem(item); 

            cout << "\tEnter Rate Of Item: "; 
            cin >> rate; 
            b.setRate(rate); 

            cout << "\tEnter Quantity Of Item: "; 
            cin >> quant; 
            b.setQuantity(quant); 

            ofstream out("/home/alee/HocTap/Cpp_Language/Oop/SuperMarketBillingSystem/bill.txt", ios::app); 
            if(!out){
                out << "\tError: File Can't Open!" << endl; 
            }
            else{
                out << "\t" << b.getItem() << " : " << b.getRate() << " : " << b.getQuantity() << endl << endl;  
            }
            out.close(); 
            cout << "\tItem Added Successfuly" << endl; 
            std::this_thread::sleep_for(std::chrono::milliseconds(3000)); 
        }
        else if(choice == 2){
            system("clear"); 
            close = true; 
            cout<<"\tBack To Main Menu!" << endl; 
            std::this_thread::sleep_for(std::chrono::milliseconds(3000)); 
        }
    }
}

void printBill(Bill b){
    system("clear"); 
    int count = 0; 
    bool close = false; 
    while(!close){
        system("clear"); 
        int choice; 
        cout << "\t1.Add Bill." << endl; 
        cout << "\t2.Close Session." << endl; 
        cout << "\tEnter Choice: ";
        cin >> choice; 
        if(choice == 1){
            string item; 
            int quant; 
            cout << "\tEnter Item: ";
            cin >> item; 
            cout << "\tEnter Quantity: "; 
            cin >> quant;  

            ifstream in("/home/alee/HocTap/Cpp_Language/Oop/SuperMarketBillingSystem/bill.txt"); 
            ofstream out("/home/alee/HocTap/Cpp_Language/Oop/SuperMarketBillingSystem/Temp.txt"); 

            string line; 
            bool found = false; 

            while(getline(in, line)){
                stringstream ss; 
                ss << line; 
                string itemName; 
                int itemRate, itemQuant; 
                char delimiter; 
                ss >> itemName >> delimiter >> itemRate >> delimiter >> itemQuant;  

                if(item == itemName){
                    found = true; 
                    if(quant <= itemQuant){
                        int amount = itemRate*quant;
                        cout << "\t Item | Rate | Quantity | Amount" << endl; 
                        cout << "\t" <<itemName<<"\t "<<itemRate<<"\t "<<quant<<"\t "<<amount<<endl; 
                        int newQuant = itemQuant - quant; 
                        itemQuant = newQuant; 
                        count += amount; 
                        
                        out << "\t" << itemName << " : " << itemRate << " : " << itemQuant << endl << endl; 
                    }
                    else{
                        cout << "\tSorry, " << item << " Ended!" << endl; 
                    }
                }
                else{
                    out << line << endl; 
                }
            }
            if(!found){
                cout << "\tItem Not Available!" << endl; 
            }
            out.close(); 
            in.close(); 
            remove("/home/alee/HocTap/Cpp_Language/Oop/SuperMarketBillingSystem/bill.txt"); 
            rename("/home/alee/HocTap/Cpp_Language/Oop/SuperMarketBillingSystem/Temp.txt", "/home/alee/HocTap/Cpp_Language/Oop/SuperMarketBillingSystem/bill.txt"); 
        }
        else if(choice == 2){
            close = true; 
            cout << "\tCounting Total Bill" << endl; 
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(3000)); 
    }
    system("clear"); 
    cout << endl << endl; 
    cout << "\t Total Bill -------------------- : " << count << endl << endl;
    cout << "\tThanks For Shopping!" << endl; 
    std::this_thread::sleep_for(std::chrono::milliseconds(5000));  
 }

int main(){
    Bill b; 
    bool exit = false; 
    while(!exit){
        system("clear"); 
        int val; 

        cout << "\tWelcom To Super Market Billing System"<<endl; 
        cout << "\t*************************************"<<endl; 
        cout << "\t\t1.Add Item."<<endl; 
        cout << "\t\t2.Print Bill."<<endl; 
        cout << "\t\t3.Exit."<<endl; 
        cout << "\t\tEnter Choice: "; 
        cin >> val; 
        if(val == 1){
            system("clear");
            addItem(b); 
            std::this_thread::sleep_for(std::chrono::milliseconds(3000)); 
        }
        else if(val == 2){
            printBill(b); 
        }
        else if(val == 3){
            system("clear"); 
            exit = true; 
            cout << "\tGood Luck!" << endl; 
            std::this_thread::sleep_for(std::chrono::milliseconds(3000)); 
        }
    }
    return 0; 
}
