#include <iostream>
using namespace std;

class Critter {
    int hunger;
    int boredom;
    
    int Get_mood() {
        return boredom + hunger;
    }
    void Pass_time(int time = 1);
public:
    Critter(int hunger=0,int boredom=0)
    {
        this->boredom = boredom;
        this->hunger = hunger;
    }
    
    void Talk();
    void Eat(int food = 1);
    void Play(int fun);
    
};

void Critter::Pass_time(int time) {
    boredom += time;
    hunger += time;
}

void Critter::Eat(int food) {
    cout << "I eat"<<endl;
    if (hunger - food >= 0) {
        hunger -= food;
    }
    Pass_time();
}

void Critter::Talk() {
    if (Get_mood() > 15) {
        cout << "I'm so angry!"<<endl;
    }else if (Get_mood() > 10) {
        cout << "I'm frustrated..." << endl;
    }
    else if (Get_mood() > 5) {
        cout << "I'm okay.";
    }
    else {
        cout << "I'm happppppyyyyy!"<<endl;
    }
    Pass_time();
}

void Critter::Play(int fun=1) {
    cout << "Whee!" << endl;
    if (boredom - fun >= 0) {
        boredom -= fun;
    }
    Pass_time();
}

int main()
{
    Critter cri;
    cri.Talk();
    int choice;
    int pass = 0;
    do {
        cout << "\tWhat's your choice:" << endl;
        cout << "\t0-end game" << endl;
        cout << "\t1-Feed your critter" << endl;
        cout << "\t2-Talk to your critter" << endl;
        cout << "\t3-Play with your critter" << endl;
        cout << "\t4-Next day" << endl;
        cout << "choice: ";
        cin >> choice;
        switch (choice) {
        case 0:
            cout << "Good-bye" << endl;
            break;
        case 1:
            cri.Eat();
            ++pass;
            break;
        case 2:
            cri.Talk();
            ++pass;
            break;
        case 3:
            cri.Play();
            ++pass;
            break;
        }
    } while (choice != 0);
}

