#ifndef SIGNUPWINDOW_H
#define SIGNUPWINDOW_H

#include <QWidget>

class QLineEdit;
class IBankSystemModel;

class SignupWindow : public QWidget
{
    Q_OBJECT
public:
    explicit SignupWindow(IBankSystemModel *bankSystem, QWidget *parent = nullptr);

signals:
    void showAuthWindow();

private slots:
    void back();
    void sendSignupRequest();

private:
    bool notAllFieldsAreFilled();

    QLineEdit *loginLine;
    QLineEdit *passwordLine;
    QLineEdit *nameLine;
    QLineEdit *phoneLine;
    QLineEdit *emailLine;

    IBankSystemModel *bankSystemModel;
};

#endif // SIGNUPWINDOW_H
