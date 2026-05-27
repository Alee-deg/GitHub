#include<iostream>
#include<time.h>
#include<cstdlib>
#include "Bank.h"
#include "Account.h"

int main(){
    srand((unsigned)time(NULL)); 
    Bank *bank = new Bank("MB Bank", "Linh Trung, Thu Duc"); 
    bank -> addCurrentAccount("Le Hoai Hau", 86686666); 
    bank -> addRegularAccount("Le Hoai Hau", 98888888);
    bank -> addCurrentAccount("Pham Hai"); 
    bank -> addRegularAccount("Le Phuoc"); 
    bank -> depositMoney(86686666, 120);
    bank -> depositMoney(98888888, 150);
    bank -> displayInfo(); 
    bank -> displayAccount(); 
    bank -> drawMoney(86686666, 170); 
    bank -> drawMoney(98888888, 60); 
    cout << "\n"; 
    bank -> displayAccount(); 
    delete bank; 
    return 0; 
}
