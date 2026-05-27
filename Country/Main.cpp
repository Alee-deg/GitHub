#include "Contry.h"
#include "City.h"
// Con sai sot
int main(){
    Country* country = NULL; 
    while(1){
        cout << "1.Tao Country(only one)" <<"\t" << "2.Add City" << endl;
        cout << "3.Remove City" <<"\t" << "4.getCapital" << endl;
        cout << "5.Sum Population"<<"\t" << "6.ChangeCapital" << endl;
        cout << "7.Display" << "\t" << "8.Quit" << endl; 
        int n; cin >> n; 
        switch (n)
        {
        case 1:{
            cout << "Enter name of Country: "; 
            string name; cin >> name; 
            country = new Country(name); 
            break;
        }
        case 2:{
            if(!country){
                cout << "Start from step 1\n"; 
                continue;
            }
            cout << "Enter name of City: "; 
            string nameCity; cin >> nameCity;
            cout << "Enter Population: ";
            int population;  cin >> population; 
            country -> addNewCity(nameCity, population); 
            break; 
        }
        case 3:{
            if(!country){
                cout << "Start from step 1\n"; 
                continue;
            }
            cout << "Name of City to delete: ";
            string nameOfCity; cin >> nameOfCity;
            country -> removeCity(nameOfCity);
            break; 
        }
        case 4:{
            if(!country){
                cout << "Start from step 1\n"; 
                continue;
            }
            cout << "Capital of City: " << country->getCapital() << endl; 
            break; 
        }
        case 5:{
            if(!country){
                cout << "Start from step 1\n"; 
                continue;
            }
            cout << "Sum population: " << country->sumPerson() << endl; 
            break; 
        }
        case 6:{
            break; 
        }
        case 7:{
            if(!country){
                cout << "Start from step 1\n"; 
                continue;
            }
            country->displayInfo(); 
            country->displayInfoCity(); 
            break; 
        }
        default:
            cout << "select is invalid\n"; 
            break; 
        }
    }
}