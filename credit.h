#ifndef CREDIT_H
#define CREDIT_H

#include <string>
#include <cstdlib>
#include <ctime>

#include "currencyconverter.h"
#include "iinforming.h"

const double MIN_CREDIT_VALUE = 100.0;
const double MAX_CREDIT_VALUE = 10000.0;

const double MAX_CREDIT_MONTH_PERCENTS = 3.0;
const double MIN_CREDIT_MONTH_PERCENTS = 1.0;

const int MAX_MONTHS = 96;
const int MIN_MONTHS = 3;

class Credit : public IInforming
{
public:
    Credit(int64_t id, int months, double value, Currency currency,
           double monthlyPercents, time_t creationTime, time_t lastPaymentTime,
           double paidByClient, std::string clientLogin);

    int64_t getId() const { return id; }
    int getMonths() const { return months; }
    double getValue() const { return value; }
    Currency getCurrency() const { return currency; }
    double getMonthlyPercents() const { return monthlyPercents; }
    time_t getCreationTime() const { return creationTime; }
    time_t getLastPaymentTime() const { return lastPaymentTime; }
    double getPaidByClient() const { return paidByClient; }
    std::string getClientLogin() const { return clientLogin; }

    double getAmountOfMoneyClientMustPay() const;
    double getMonthlyPayment() const;
    int getMonthsFromLastPaymentTime() const;
    double getPaymentFromLastPaymentTime() const;

    void pay();

    std::string getInfo() const override;

private:
    int64_t id;
    int months;
    double value;
    Currency currency;
    double monthlyPercents;
    time_t creationTime;
    time_t lastPaymentTime;
    double paidByClient;
    std::string clientLogin;
};

double computePercentRate(int months);

#endif // CREDIT_H
