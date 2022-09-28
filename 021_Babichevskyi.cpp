//
//  
//  
//
//  
//

#ifndef game_h
#define game_h


#include <iostream>
using namespace std;

class Weapon
{
protected:
    string m_name;
    string m_model;
public:
    Weapon(string model = "", string name = "Unknown Weapon") : m_name{ name }, m_model{ model } {
        //        cout << "Weapon CONSTRUCTOR" << endl;
    }

    virtual ~Weapon() //= 0;
    {
        //        cout << "Weapon DESTRUCTOR" << endl;
    }

    virtual void Atack() = 0;
    //    {
    //        cout << "Atack !" << endl;
    //    }

    virtual void ShowInfo() final {
        cout << "Info about Weapon !" << endl;

        Print();
    }

    virtual void Print() {
        cout << getName() << (m_model.empty() ? "" : " " + m_model) << endl;
    }

    virtual string& getName() final { return m_name; };
};

class Knife : public Weapon
{
public:
    Knife(string model = "") : Weapon(model, "Knife") {
        //        cout << "Knife CONSTRUCTOR" << endl;
    }

    ~Knife() {
        //        cout << "Knife DESTRUCTOR" << endl;
    }

    void Atack() override {
        cout << "Atack with a Knige !" << endl;
    }

    //    string getName() override { return m_name; };
    void Print() override {
        cout << getName() << (m_model.empty() ? "" : " " + m_model) << endl;
    }
};

class Gun : public Weapon
{
public:
    Gun(string model = "") : Weapon(model, "Gun") {
        //        cout << "Gun CONSTRUCTOR" << endl;
    }

    ~Gun() {
        //        cout << "Gun DESTRUCTOR" << endl;
    }

    void Atack() override {
        cout << "Atack with a Gun !" << endl;
    }
};

class Granata : public Weapon
{
public:
    Granata(string model = "") : Weapon(model, "Granata") {
        //        cout << "Granata CONSTRUCTOR" << endl;
        m_name = "Granata";
    }

    ~Granata() {
        //        cout << "Granata DESTRUCTOR" << endl;
    }

    void Atack() override {
        cout << "Atack with a Granata !" << endl;
    }
};

//1 Array of Weapon 4
//2 Constructie = NULL
//3 Add (1, 2, Granata)
//4 Remove
//4 Attac ()
//5 Select(1-4) if null selec NEXT
//5.1 ShowAllGans
//6 Create class Granata

typedef Weapon* TpWeapon;
class Player {
    int m_maxWeaponCount = 4;
    //Weapon** m_pWeaponSt = nullptr;
    TpWeapon* m_pWeaponSt = nullptr;
    int m_activeWeapon = 0;
public:
    Player() {
        cout << "Playe CONSTRUCTOR" << endl;
        //        m_pWeaponSt = new Weapon*[maxWeaponCount];
        m_pWeaponSt = new TpWeapon[m_maxWeaponCount];

        for (int i = 0; i < m_maxWeaponCount; i++) {
            m_pWeaponSt[i] = NULL;
        }
    }

    ~Player() {
        cout << "Playe DESTRUCTOR" << endl;
        for (int i = 0; i < m_maxWeaponCount; i++) {
            Weapon* pWeapon = m_pWeaponSt[i];
            if (pWeapon != NULL)
                delete pWeapon;
        }

        delete m_pWeaponSt;
    }

    void IncreaseWaponsSize(int addCount = 1) {
        int maxWeaponCountTmp = m_maxWeaponCount + addCount;
        //Weapon** pWeaponStTmp = new Weapon*[maxWeaponCount];
        TpWeapon* pWeaponStTmp = new TpWeapon[maxWeaponCountTmp];

        for (int i = 0; i < maxWeaponCountTmp; i++) {
            if (i < m_maxWeaponCount)
                pWeaponStTmp[i] = m_pWeaponSt[i];
            else
                pWeaponStTmp[i] = NULL;
        }

        if (m_pWeaponSt != nullptr)
            delete m_pWeaponSt;

        m_maxWeaponCount = maxWeaponCountTmp;
        m_pWeaponSt = pWeaponStTmp;

        cout << "Weapons increased to " << m_maxWeaponCount << endl;
    }

    bool Add(Weapon* pWeapon, int pos = 0) //1-4
    {
        if (pWeapon == NULL)
            return false;

        pos--;

        if (pos < 0) {
            for (int i = 0; i < m_maxWeaponCount; i++) {
                if (m_pWeaponSt[i] == NULL) {
                    pos = i;

                    break;
                }
            }
        }

        if (pos >= 0 && pos < m_maxWeaponCount) {
            Weapon* pWeaponTmp = m_pWeaponSt[pos];

            if (pWeaponTmp != NULL)
                delete pWeaponTmp;

            m_pWeaponSt[pos] = pWeapon;

            return true;
        } /*else if (pos < 0) {
            for (int i = 0; i < m_maxWeaponCount; i++){
                if (m_pWeaponSt[i] == NULL){
                    m_pWeaponSt[i] = pWeapon;

                    return true;
                }
            }
        } */

        return false;
    }

    void Attack(int pos = 0) //1-4
    {
        pos--;
        Weapon* pWeapon = NULL;
        if (pos >= 0 && pos < m_maxWeaponCount)
            pWeapon = m_pWeaponSt[pos];

        if (pWeapon == NULL) {
            for (int i = 0; i < m_maxWeaponCount; i++) {
                pWeapon = m_pWeaponSt[i];
                if (pWeapon != NULL)
                    break;
            }
        }

        if (pWeapon != NULL) {
            pWeapon->Atack();
        }
        else {
            cout << "Atack with hends :((( !" << endl;
        }
    }

    void ShowAllWeapons()
    {
        bool showTitle = false;

        for (int i = 0; i < m_maxWeaponCount; i++) {
            Weapon* pWeapon = m_pWeaponSt[i];

            if (pWeapon != NULL) {
                if (!showTitle) {
                    cout << "========== Weapons ==========" << endl;
                    showTitle = true;
                }
                pWeapon->Print();
            }
            //            string s = pWeapon != NULL ? pWeapon->getName() : "EMPTY";
            //            cout << "Weapon[" << i << "] - " << s << endl;
        }
        if (showTitle)
            cout << "=============================" << endl << endl;
    }

    void Remove(int pos) //1-4
    {
        pos--;

        if (pos >= 0 && pos < m_maxWeaponCount)
        {
            Weapon* pWeaponTmp = m_pWeaponSt[pos];

            if (pWeaponTmp != NULL) {
                delete pWeaponTmp;
                m_pWeaponSt[pos] = NULL;
            }
        }
    }
};

int main()
{
    Player pl1;
    pl1.Attack();
    pl1.Attack(3);
    pl1.Add(new Knife(), 2);
    pl1.Attack(1);
    pl1.ShowAllWeapons();
    pl1.Add(new Gun(), 2);
    pl1.Add(new Granata(), 3);
    pl1.Attack(1);
    pl1.Attack(3);
    //pl1.Add(new Granata(), 1);
    pl1.Add(new Granata());
    pl1.Add(new Knife(), 4);
    pl1.Attack(4);
    pl1.Attack(1);
    bool b = pl1.Add(new Granata());
    if (!b)
        cout << "Can't add weapon" << endl;
    pl1.ShowAllWeapons();
    pl1.IncreaseWaponsSize();
    b = pl1.Add(new Granata());
    if (!b)
        cout << "Can't add weapon" << endl;
    pl1.ShowAllWeapons();

    cout << "======= Remove 1 and 3 ======" << endl;

    pl1.Remove(1);
    pl1.Remove(3);
    pl1.ShowAllWeapons();
    pl1.Attack();



    //    Weapon weapon0;
    //    Knife weapon1;
    //    Gun weapon2;
    //
    ////    weapon0.Atack();
    ////    weapon1.Atack();
    ////    weapon2.Atack();
    //
    //    Weapon * pWeapon1 = &weapon1;
    //    Weapon * pWeapon2 = &weapon2;
    //
    //    pWeapon1->Atack();
    //    pWeapon2->Atack();
    //

    //    Weapon * pKnife = new Knife();
    //    pKnife->Atack();
    //    delete pKnife;
    //
    //    Gun * pGun = new Gun;
    //    pGun->Atack();
    //    delete pGun;

    //    pWeapon1->ShowInfo();
    //    pWeapon2->ShowInfo();


}



#endif /* game_h */