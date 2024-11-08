#include <iostream>
#include <string>
#include <vector>
#include <windows.h>
#include <ctime>
using namespace std;

class Animal
{
protected:
    string name;
private:
    int age;
    static int animalNum;
public:
    Animal(string _name = "Animal") : name(_name) 
    {
        animalNum++;
    }
    virtual void move() = 0;
    virtual void shout() = 0;
    virtual void guessShout() = 0;
    string getName() { return name; }
    int getAge() { return age; }
    static int getAnimalNum() { return animalNum; }
    void setName(string _name) { name = _name; }
    void setAge(int _age) { age = _age; }
};

class Dog : virtual public Animal
{
    static int dogNum;
public:
    Dog(string _name = "Dog") : Animal(_name) 
    {
        dogNum++;
        setAge(dogNum);
    }
    void move() { cout << "Run " << 5 + 0.1 * getAge() << " inches! "; }
    void shout() { cout << "Bark Bark! it's " << getName() << "(age " << getAge() << ")" << endl; }
    void guessShout() { cout << "Bark Bark! it's Animal (age " << getAge() << ")" << endl; }
    static int getDogNum() { return dogNum; }
};

class Frog : virtual public Animal
{
    static int frogNum;
public:
    Frog(string _name = "Frog") : Animal(_name) 
    {
        frogNum++;
        setAge(frogNum);
    }
    void move() { cout << "Jump " << 1 + 0.1 * getAge() << " inches! "; }
    void shout() { cout << "Croak Croak! it's " << getName() << "(age " << getAge() << ")" << endl; }
    void guessShout() { cout << "Croak Croak! it's Animal (age " << getAge() << ")" << endl; }
    static int getFrogNum() { return frogNum; }
};

class Bird : virtual public Animal
{
    static int birdNum;
public:
    Bird(string _name = "Bird") : Animal(_name) 
    {
        birdNum++;
        setAge(birdNum);
    }
    void move() { cout << "Fly " << 10 + 0.1 * getAge() << " inches! "; }
    void shout() { cout << "Tweet Tweet! it's " << getName() << "(age " << getAge() << ")" << endl; }
    void guessShout() { cout << "Tweet Tweet! it's Animal (age " << getAge() << ")" << endl; }
    static int getBirdNum() { return birdNum; }
};

class Cat : virtual public Animal
{
    static int catNum;
public:
    Cat(string _name = "Cat") : Animal(_name) 
    {
        catNum++;
        setAge(catNum);
    }
    void move() { cout << "Run " << 6 + 0.1 * getAge() << " inches! "; }
    void shout() { cout << "Meow Meow! it's " << getName() << "(age " << getAge() << ")" << endl; }
    void guessShout() { cout << "Meow Meow! it's Animal (age " << getAge() << ")" << endl; }
    static int getCatNum() { return catNum; }
};

class Zoo
{
    vector<Animal*> animals;
public:
    void addAnimal(Animal* animal) 
    {
        animals.push_back(animal);
    }
    Animal* getAnimal(int index) { return animals[index]; }
    void showAllAnimals()
    {
        for (int i = 0; i < animals.size(); i++)
        {
            cout << animals[i]->getName() << " ";
        }
        cout << endl;
    }
};


