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

class UserAccount
{    
public:
    QString email;
    QString country;
    QString password;

    QString fisrtName;
    QString secondName;
    QString phoneNumber;
    QString birthDate;
    SecretQuestionTypes sq_type;
    QString sq_answer;
    double balance;

    UserAccount();
};

#endif // USERACCOUNT_H
