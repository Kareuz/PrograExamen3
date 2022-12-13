#include <iostream>
using namespace std;

class Pet
{
public:
    Pet(int hunger = 0, int boredom = 0, int tiredness = 0);
    void Talk();
    void Eat(int food = 4);
    void Play(int fun = 4);
    void Walk(int health = 4);
    void Stats();
    void Death();
    bool death = true;

private:
    int m_Hunger;
    int m_Boredom;
    int m_Tiredness;
    int GetMood() const;
    void PassTime(int time = 1);
};

Pet::Pet(int hunger, int boredom, int tiredness) :
    m_Hunger(hunger),
    m_Boredom(boredom),
    m_Tiredness(tiredness)
{}

inline int Pet::GetMood() const
{
    return (m_Hunger + m_Boredom);
}

void Pet::Death(){
    cout << "Tu mascota ha muerto" << endl;
    death = false;
}

void Pet::Stats() {

    cout << "Hambre: " << m_Hunger << endl;
    cout << "Aburrimiento: " << m_Boredom << endl;
    cout << "Cansancio: " << m_Tiredness << endl;
}

void Pet::PassTime(int time)
{
    m_Hunger += time;
    m_Boredom += time;
    m_Tiredness += time;
}

void Pet::Talk()
{
    /*cout << "\n\n Humano estoy: ";
    int mood = GetMood();

    if (mood > 15)
    {
        cout << "muriendo. \n";
    }
    else if (mood > 10)
    {
        cout << "mal. \n";
    }
    else if (mood > 5)
    {
        cout << "ok. \n";
    }
    else {
        cout << "feliz. \n";
    }*/
    if (m_Hunger < 8 && m_Boredom < 8 && m_Tiredness < 8) {
        cout << "Estoy bien" << endl;
    }

    if (m_Hunger >= 20) {
        Death();
    }
    else if (m_Hunger > 15) {
        cout << "Tengo que comer... algo" << endl;
    }
    else if (m_Hunger > 8) {
        cout << "Humano, tengo hambre" << endl;
    }

    if (m_Boredom >= 20) {
        Death();
    }
    else if (m_Boredom > 15) {
        cout << "Estoy muy aburrido... aaaa!" << endl;
    }
    else if (m_Boredom > 8) {
        cout << "Humano, me estoy aburriendo" << endl;
    }

    if (m_Tiredness >= 20) {
        Death();
    }
    else if (m_Tiredness > 15) {
        cout << "Ya... no puedo... mas" << endl;
    }
    else if (m_Tiredness > 8) {
        cout << "Humano, estoy cansado" << endl;
    }

    PassTime();
}

void Pet::Eat(int food)
{
    cout << "\Brrup. \n";
    m_Hunger -= food;

    if (m_Hunger < 0)
    {
        m_Hunger = 0;
    }

    PassTime();
}

void Pet::Play(int fun)
{
    cout << "\n Wheeee \n";
    m_Boredom -= fun;

    if (m_Boredom < 0)
    {
        m_Boredom = 0;
    }

    PassTime();
}

void Pet::Walk(int health)
{
    cout << "\n Yappers! \n";
    m_Tiredness -= health;

    if (m_Tiredness < 0)
    {
        m_Tiredness = 0;
    }

    PassTime();
}

int main()
{

    Pet pet;
    pet.Talk();
    int choice;

   

    do {
        cout << "\n Mascotas Virtuales\n\n";
        cout << "0 -  Salir\n";
        cout << "1 -  Escucha a tu macota\n";
        cout << "2 -  Alimentar\n";
        cout << "3 -  Jugar con mascota\n";
        cout << "4 -  Descansar mascota\n";
        cout << "5 -  Necesidades\n";
        cout << "Elige una opción: \n";

        cin >> choice;

        switch (choice)
        {
        case 0:
            cout << "Vuelve pronto!. \n";
            break;
        case 1:
            pet.Talk();
            break;
        case 2:
            pet.Eat();
            break;
        case 3:
            pet.Play();
            break;

        case 4:
            pet.Walk();
            break;

        case 5:
            pet.Stats();
            break;
        default:
            cout << "\nTu elección se inválida. \n";
        }

        if (!pet.death) {
            
            break;
        }

    } while (choice != 0);
}