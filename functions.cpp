#include "functions.h"
#include <QChar>
#include <QDebug>

bool checkCorrect_email(const QString &_email)
{
    char countOfAT = 0;
    char countOfDots = 0;
    char countOfLetters = 0;

    for(QChar elem : _email)
    {
        if(elem == '@')
            ++countOfAT;

        if(elem == '.')
            ++countOfDots;

        if(elem.isLetterOrNumber())
            ++countOfLetters;
    }

    if(countOfAT == 1 && countOfDots >= 1 && countOfLetters > 3)
        return true;
    else
        return false;
}

bool checkCorrect_password(const QString &_password)
{
    if(_password.size() < 8)
        return false;

    char countOfLetters = 0;
    char countOfDigits = 0;


    for (QChar elem : _password)
    {

        if(elem.isLetter())
            ++countOfLetters;

        if(elem.isNumber())
            ++countOfDigits;
    }

    qDebug() << countOfLetters;
    qDebug() << countOfDigits;

    if((countOfLetters > 0) && (countOfDigits > 0))
        return true;
    else
        return false;
}

SecretQuestionTypes getQuestionType(const QString &_question)
{
    if(_question == "The city in which you were born.")
        return SecretQuestionTypes::CITY_OF_BIRTH;

    else if(_question == "The name of your favorite pet.")
        return SecretQuestionTypes::NAME_OF_FAVORITE_PET;

    else if(_question == "The your favorite food.")
        return SecretQuestionTypes::FAVORITE_FOOD;

    else if(_question == "The maiden's name of your mother.")
         return SecretQuestionTypes::MOTHER_MAIDEN_NAME;

    else if(_question == "The make of your first car.")
        return SecretQuestionTypes::MAKE_OF_FIRST_CAR;
    else
        return SecretQuestionTypes::FIRST_PHONE_MODEL;
}

bool checkCorrect_name(const QString &_name)
{
    for(QChar elem : _name)
    {
        if(!elem.isLetter())
            return false;
    }

    return true;
}

bool checkCorrect_date(const QString &_date)
{
    QString year = "";
    for (int i = 0; i < 4; ++i)
        year += _date[i];

    if(year.toInt() > 2010)
        return false;

    return true;
}

bool checkCorrect_phoneNumber(const QString &_number)
{
    char countOfDigits = 0;
    for (QChar elem : _number)
    {
        if(elem.isDigit())
        {
            ++countOfDigits;
            continue;
        }

        if(elem != ' ' && elem != '(' && elem != ')' && elem != '-')
            return false;
    }

    if(countOfDigits != 10)
        return false;

    return true;
}

QString getStandardNumber(const QString &_number)
{
    //template of phone number: XXX XXX-XX-XX
    //from[0] to [2] are digits
    //[3] is space
    //from [4] to [6] are digits
    //[7] is '-'
    //from [8] to [9] are digits
    //[10] is '-'
    //from [11] to [12] are degits

    QString res = "";
    res.resize(13);
    char pos = 0;

    for (QChar elem : _number)
    {
        if(pos == 3)
        {
            res[pos] = ' ';
            ++pos;
        }

        if(pos == 7 || pos == 10)
        {
            res[pos] = '-';
            ++pos;
        }

        if(elem.isDigit())
        {
            res[pos] = elem;
            ++pos;
            continue;
        }
    }

    return res;
}
