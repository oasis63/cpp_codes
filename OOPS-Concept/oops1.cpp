#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
#define ll long long

// Base class
class Vehicle {
  private: 
  		string vehicle;
  public: 
    string brand = "Ford";
    void honk() {
      cout << "Tuut, tuut! \n" ;
    }
    void setVehicle(string input){
    	this->vehicle = input;
    }
    string getVehicle(){
    	return this->vehicle;
    }
};

class Motor{
private:
	string motorName = "motorName";
public:
	void motor(){
		cout<<"Motor is used in Car"<<endl;
	}
};

// Derived class
class Car: public Vehicle,public Motor {
  public: 
    string model = "Mustang";
};


int main(){
		
	Car car;
	car.setVehicle("Baleno-car");
	car.honk();
	cout<<car.getVehicle()<<endl;
	cout<<car.model<<endl;

	car.model = "my_new_car_model";
	cout<<car.model<<endl;	
	car.motor();

	// cout<<car.motor<<endl;


	return 0;
}