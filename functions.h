#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include <QString>
#include "useraccount.h"

bool checkCorrect_email(const QString& _email);
bool checkCorrect_password(const QString& _password);
SecretQuestionTypes getQuestionType(const QString& _question);

bool checkCorrect_name(const QString& _name);
bool checkCorrect_date(const QString& _date);
bool checkCorrect_phoneNumber(const QString& _number);
QString getStandardNumber(const QString& _number);
#endif // FUNCTIONS_H
