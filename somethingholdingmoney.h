#ifndef SOMETHINGHOLDINGMONEY_H
#define SOMETHINGHOLDINGMONEY_H

#include <string>
#include <cstdlib>
#include <ctime>

class SomethingHoldingMoney
{
public:
    SomethingHoldingMoney(int64_t id, std::string clientLogin, double initialBalance, double percents, time_t creationTime);

    int64_t getId() const { return id; }
    double getBalance() const { return balance; }
    double getPercents() const { return percents; }
    time_t getCreationTime() const { return creationTime; }
    std::string getClientLogin() const { return clientLogin; }

protected:
    int64_t id;
    std::string clientLogin;
    double balance;
    double percents;
    time_t creationTime;
};

#endif // SOMETHINGHOLDINGMONEY_H