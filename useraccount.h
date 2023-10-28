#ifndef USERACCOUNT_H
#define USERACCOUNT_H
#include <QString>

//Страна / код
//USA +1
//Canada +1
//Russia +7
//UK +44
//France +33
//German +49
//Japan +81
//China +86

enum class SecretQuestionTypes
{
    CITY_OF_BIRTH = 10,
    NAME_OF_FAVORITE_PET = 20,
    MOTHER_MAIDEN_NAME = 30,
    FAVORITE_FOOD = 40,
    MAKE_OF_FIRST_CAR = 50,
    FIRST_PHONE_MODEL = 60
};

class Lib
{
public:
    bool eldenRing = false;
    bool godOfWar = false;
    bool stray = false;
    bool plagueTale = false;
    bool horizon = false;
    bool lastOfUs = false;
    bool cuphead = false;
    bool dyingLight = false;
    bool warhammer = false;

    void setValues(const QString& _res)
    {
        bool boolArray[9];
        for(int i = 0; i < 9; ++i)
        {
            if(_res[i] == '1')
                boolArray[i] = true;
            else
                boolArray[i] = false;
        }


        eldenRing = boolArray[0];
        godOfWar = boolArray[1];
        stray = boolArray[2];
        plagueTale = boolArray[3];
        horizon = boolArray[4];
        lastOfUs = boolArray[5];
        cuphead = boolArray[6];
        dyingLight = boolArray[7];
        warhammer = boolArray[8];
    }
};

class UserAccount
{    
public:
    int id;
    QString email;
    QString country;
    QString password;
    QString userName;

    QString fisrtName;
    QString secondName;
    QString phoneNumber;
    QString birthDate;
    SecretQuestionTypes sq_type;
    QString sq_answer;
    double balance;

    Lib lib;

    UserAccount();
};

#endif // USERACCOUNT_H
