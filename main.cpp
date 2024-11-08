#include "animal.cpp"   
#define WHITE 7
#define RED 12
#define GREEN 10
#define PURPLE 13
int Animal::animalNum = 0;
int Dog::dogNum = 0;
int Frog::frogNum = 0;
int Bird::birdNum = 0;
int Cat::catNum = 0;
int questionNum = 5;

void setColor(int color)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
}

void colorTextForOneLine(string text, int color)
{
    setColor(color);
    cout << text;
    setColor(WHITE);
}

void addAnimalsToZoo(Zoo &zoo, int _dogNum = 8, int _frogNum = 7, int _birdNum = 10, int _catNum = 5)
{
    for (int i = 0; i < _dogNum; i++)
    {
        zoo.addAnimal(new Dog());
    }
    for (int i = 0; i < _frogNum; i++)
    {
        zoo.addAnimal(new Frog());
    }
    for (int i = 0; i < _birdNum; i++)
    {
        zoo.addAnimal(new Bird());
    }
    for (int i = 0; i < _catNum; i++)
    {
        zoo.addAnimal(new Cat());
    }
    cout << "*** Total " << Animal::getAnimalNum() << " animals in the zoo(" << 
Dog::getDogNum() << " dogs, " << 
Frog::getFrogNum() << " frogs, " << 
Bird::getBirdNum() << " birds, " << 
Cat::getCatNum() << " cats) ***" << endl;

}

void randomChooseAnimalToList(vector<Animal*> &animalList, Zoo &zoo)
{
    int total = Animal::getAnimalNum();
    int num = 5 + questionNum;
    int hasChoose[total] = {0};
    cout << "choose " << num << " animals to the list" << endl;
    cout << endl;
    for (int i = 0; i < num; i++)
    {
        int index = rand() % total;
        while (hasChoose[index] == 1)
        {
            index = rand() % total;
        }
        animalList.push_back(zoo.getAnimal(index));
        hasChoose[index] = 1;
    }
}
void test(vector<Animal*> &animalList)
{
    cout << "--------------------------------" << endl;
    cout << endl;
    cout << "Learn some animals first......" << endl;
    for (int i = 0; i < 5; i++)
    {
        animalList[i]->move();
        animalList[i]->shout();
    }
    cout << endl;
    cout << "--------------------------------" << endl;
    cout << endl;
    cout << "Let's guess the animals......(press any key to continue)......";
    getchar();
    cout << endl;
    int sum = 0;
    for (int i = 5; i < animalList.size(); i++)
    {
        animalList[i]->move();
        animalList[i]->guessShout();
        string name;
        cout << "  What's the name of the animal?: ";
        cin >> name;
        if (name == animalList[i]->getName())
        {
            colorTextForOneLine("  ¡Ì Correct! ", GREEN);
            cout << endl;
            sum += 20;
        }
        else
        {
            colorTextForOneLine("  ¡Á Wrong! ", RED);
            cout << endl;
        }
    }
    cout << "--------------------------------" << endl;
    cout << endl;
    cout << "*** Your final score: ";
    colorTextForOneLine(to_string(sum), PURPLE);
    cout << " ***" << endl;
}

void infoIntro()
{
    cout << "Welcome to the Zoo Game!" << endl;
    cout << "Press any key to start the game......";
    getchar();
    cout << endl;
    cout << "--------------------------------" << endl;
    cout << endl;
    cout << "There are 3 kinds of animals in the zoo: Dog, Frog, Bird" << endl;
    cout << "You need to learn 5 animals first, then guess the rest" << endl;
    cout << "Every correct answer will get 20 points" << endl;
    cout << "Let's start!" << endl;
    cout << "Press any key to continue......";
    getchar();
    cout << endl;
    cout << "--------------------------------" << endl;
    cout << endl;
}

void zooGame()
{
    setColor(WHITE);
    // infoIntro(); 
    Zoo zoo;
    addAnimalsToZoo(zoo, 8, 7, 10, 5);
    vector<Animal*> animalList;
    randomChooseAnimalToList(animalList, zoo);
    test(animalList);
}

int main()
{
    srand(time(NULL));
    zooGame();
    return 0;
}