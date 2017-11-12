#include <iostream>
#include <string>

class Beverage {
public:
    std::string description = "Unknown beverage";
    std::string getDescription() {
        return description;
    };
    virtual double cost() = 0;   
       // Abstract
    
};

class CondimentDecorator : public Beverage {
public:
    Beverage *beverage;
    virtual std::string getDescription() = 0;
};

class HouseBlend : public Beverage {
public:
    HouseBlend() {
        this->description = "HouseBlend Coffee";
    }
    
    double cost() {
        return 0.89;
    }
};

class DarkRoast : public Beverage {
public:
    DarkRoast() {
        this->description = "DarkRoast Coffee";
    }
    double cost() {
        return 0.99;
    }
};

class Decaf : public Beverage {
public:
    Decaf() {
        this->description = "Decaf";
    }
    double cost() {
        return 1.05;
    }
};

class Espresso : public Beverage {
public:
    Espresso() {
        this->description = "Espresso";
    }
    double cost() {
        return 1.99;
    }
};

class SteamedMilk : public CondimentDecorator {
public:
    SteamedMilk(Beverage *beverage){
        this->beverage = beverage;
    }
    std::string getDescription() {
        return this->beverage->getDescription() + ", SteamedMilk";
    }
    double cost(){
        return 0.10 + this->beverage->cost();
    }
};

class Mocha : public CondimentDecorator {
public:
    Mocha(Beverage *beverage){
        this->beverage = beverage;
    }
    std::string getDescription() {
        return this->beverage->getDescription() + ", Mocha";
    }
    double cost(){
        return 0.20 + this->beverage->cost();
    }
};

class Soy : public CondimentDecorator {
public:
    Soy(Beverage *beverage){
        this->beverage = beverage;
    }
    std::string getDescription() {
        return this->beverage->getDescription() + ", Soy";
    }
    double cost(){
        return 0.15 + this->beverage->cost();
    }
};

class Whip : public CondimentDecorator {
public:
    Whip(Beverage *beverage){
        this->beverage = beverage;
    }
    std::string getDescription() {
        return this->beverage->getDescription() + ", Whip";
    }
    double cost(){
        return 0.10 + this->beverage->cost();
    }
};

int main(int argc, char **argv)
{
    Beverage beverage = Espresso();
    std::cout << beverage.getDescription() << "$ " << beverage.cost() << std::endl;
    
    Beverage beverage2 = DarkRoast();
    beverage2 = Mocha( &beverage2);
    beverage2 = Mocha( &beverage2);
    beverage2 = Whip( &beverage2);
    std::cout << beverage2.getDescription() << "$ " << beverage2.cost() << std::endl;
    
    Beverage beverage3 = HouseBlend();
    beverage3 = Soy( &beverage3);
    beverage3 = Mocha( &beverage3);
    beverage3 = Whip( &beverage3);
    std::cout << beverage3.getDescription() << "$ " << beverage3.cost() << std::endl;
   
}
