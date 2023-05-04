#include <iostream>

using namespace std;
class Car{
    private:
    int m_price;
    
    public:
    string m_brand;
    string m_model;
    int m_year;
    int m_seat;
    Car(string x,string y,int z,int s){
        m_brand=x;
        m_model=y;
        m_year=z;
        m_seat=s;
        m_price=10000;
    }
    int get_MaxSeat(){
        return m_seat;
    }
    int get_price(){
        return m_price*m_seat;
    }
};

class BMW_Car : public Car{
    private:
    string m_DriveMode;
    
    public:
    BMW_Car(string y,int z,int s):Car("BMW",y,z,s){
        cout<<"Constructing BMW_Car\n";
        m_DriveMode = "Rear_wheel";
    }
    string get_DriveMode(){
        return m_DriveMode;
    }
};

class Audi_Car : public Car{
    private:
    string m_DriveMode;
    
    public:
    Audi_Car(string y,int z,int s):Car("Audi",y,z,s){
        cout<<"Constructing Audi_Car\n";
        m_DriveMode = "Front_wheel";
    }
    string get_DriveMode(){
        return m_DriveMode;
    }
};

class Benz_Car : public Car{
    private:
    string m_DriveMode;
    
    public:
    Benz_Car(string y,int z,int s):Car("Benz",y,z,s){
        cout<<"Constructing BMW_Car\n";
        m_DriveMode = "Front_wheel";
    }
    string get_DriveMode(){
        return m_DriveMode;
    }
};

int main(){
    BMW_Car car_1("X5",2023,6);
    cout<<car_1.m_brand<<":DriveMode = "<<car_1.get_DriveMode()<<endl;
    
    Audi_Car car_2("A1",2023,5);
    cout<<car_2.m_brand<<":DriveMode = "<<car_2.get_DriveMode()<<endl;
    
    Benz_Car car_3("E300",2022,4);
    cout<<car_3.m_brand<<":DriveMode = "<<car_3.get_DriveMode()<<endl;
    return 0;
}