#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <unistd.h>
#include <string>

using namespace std;


int stockbuy;
int stock1posneg;
int stock2posneg;
int stock3posneg;
char answer;
char stock1pm;
char stock2pm;
char stock3pm;
double s1dec;
double s2dec;
double s3dec;
long double stock1change;
long double stock2change;
long double stock3change;
long double stocksell;
long double spendmoney;
long double stock1;
long double stock2;
long double stock3;
string monthtext;
long double money = 100; 
int showday = 0;
int day = 0;
int month = 1;
int year = 2000;
int stock1owned = 0;
int stock2owned = 0;
int stock3owned = 0;

void date (){
   if (month == 1) //31 days
  {
    monthtext = "January";
    if (day == 32)
    {
      month ++;
      day = 1;
    }
  }
  if (month == 2){
    monthtext = "February";
    if (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0))
    {
      if (day == 30)
      {
        month ++;
        day = 1;
      }    
      else if (day == 29)
      {
        month ++;
        day = 1;
      }
    }
  }
  if (month == 3){
    monthtext = "March";
    if (day == 32){
      month ++;
      day = 1;
    }
  }
  if (month == 4){
    monthtext = "April";
    if (day == 31){
      month ++;
      day = 1;
    }
  }
  if (month == 5){
    monthtext = "May";
    if (day == 32){
      month ++;
      day = 1;
    }
  }
  if (month == 6){
    monthtext = "June";
    if (day == 31){
      month ++;
      day = 1;
    }
  }
  if (month == 7){
    monthtext = "July";
    if (day == 32){
      month ++;
      day = 1;
    }
  }
  if (month == 8){
    monthtext = "August";
    if (day == 32){
      month ++;
      day = 1;
    }
  }
  if (month == 9){
    monthtext = "September";
    if (day == 31){
      month ++;
      day = 1;
    }
  }
  if (month == 10){
    monthtext = "October";
    if (day == 32){
      month ++;
      day = 1;
    }
  }
  if (month == 11){
    monthtext = "November";
    if (day == 31)
    {
      month ++;
      day = 1;
    }
  }
  if (month == 12){
    monthtext = "December";
    if (day == 32){
      year ++;
      month = 1;
      day = 1;
    }
  }
}
void reshow ()
{
  date ();
  system ("clear");
  cout.precision(2);
  cout << "$" << fixed << money << endl;
  cout << monthtext << ' ' << day << ", " << year << endl;
  cout << "Day " << showday << endl << endl << endl;
  cout << "(1) GOO $" << fixed << stock1;
  cout << " " << stock1owned << " Stocks Owned" ;
  cout << " " << stock1pm << stock1change << "% Change" << endl << endl;
  cout << "(2) REPL $" << fixed << stock2;
  cout << " " << stock2owned << " Stocks Owned" ;
  cout << " " << stock2pm << stock2change << "% Change" << endl << endl;
  cout << "(3) MAMA $" << fixed << stock3;
  cout << " " << stock3owned << " Stocks Owned" ;
  cout << " " << stock3pm << stock3change << "% Change" << endl << endl;
}
void math ()
{
  day ++;
  showday ++;
  srand(time(0));
  stock1posneg = rand () % 10;
  stock1change = rand () % 200;
  stock2posneg = rand () % 11 - 1;
  stock2change = rand () % 200;
  stock3posneg = rand () % 10;
  stock3change = rand () % 200;
  stock1change = stock1change / 10000;
  stock2change = stock2change / 10000;
  stock3change = stock3change / 10000;
  if (stock1posneg >= 5) //Positive Increase
  {
    stock1 = (stock1change * stock1) + stock1;
    stock1change = stock1change * 100;
    stock1pm = ' ';
  }
  else if (stock1posneg < 5){
    stock1 = -(stock1change * stock1) + stock1; //Negative Decrease
    stock1change = stock1change * 100;
    stock1pm = '-';
  }
  if (stock2posneg >= 5){
    stock2 = (stock2change * stock2) + stock2;
    stock2change = stock2change * 100;
    stock2pm = ' ';
  }
  else if (stock2posneg < 5){
    stock2 = -(stock2change * stock2) + stock2;
    stock2change = stock2change * 100;
    stock2pm = '-';
  }
  if (stock3posneg >= 5){
    stock3 = (stock3change * stock3) + stock3;
    stock3change = stock3change * 100;
    stock3pm = ' ';
  }
  else if (stock3posneg < 5){
    stock3 = -(stock3change * stock3) + stock3;
    stock3change = stock3change * 100;
    stock3pm = '-';
  }
  
}
void buy ()
{
  reshow ();
  cout << "\n\nWhat stock do you want to buy?" << endl;
  cin >> answer;
  if (answer == '1')
  {
    cout << "How many shares would you like to buy?" << endl;
    cin >> stockbuy;
    spendmoney = stock1 * stockbuy;
    if (spendmoney <= money)
    {
      stock1owned = stock1owned + stockbuy;
      money = money - spendmoney;
    }
  }
  if (answer == '2'){
    cout << "How many shares would you like to buy?" << endl;
    cin >> stockbuy;
    spendmoney = stock2 * stockbuy;
    if (spendmoney <= money){
      stock2owned = stock2owned + stockbuy;
      money = money - spendmoney;
    }
  }
  if (answer == '3'){
    cout << "How many shares would you like to buy?" << endl;
    cin >> stockbuy;
    spendmoney = stock3 * stockbuy;
    if (spendmoney <= money){
      stock3owned = stock3owned + stockbuy;
      money = money - spendmoney;
    }
  }
}

void sell ()
{
  reshow ();
  cout << "\n\nWhat stock do you want to sell?" << endl;
  cin >> answer;
  if (answer == '1')
  {
    cout << "How many shares would you like sell?" << endl;
    cin >> stocksell;
    if (stocksell <= stock1owned)
    {
      stock1owned = stock1owned - stocksell;
      stocksell = stock1 * stocksell;
      money = money + stocksell;
    }
  }
  else if (answer == '2'){
    cout << "How many shares would you like sell?" << endl;
    cin >> stocksell;
    if (stocksell <= stock2owned){
      stock2owned = stock2owned - stocksell;
      stocksell = stock2 * stocksell;
      money = money + stocksell;
    }
  }
  else if (answer == '3'){
    cout << "How many shares would you like sell?" << endl;
    cin >> stocksell;
    if (stocksell <= stock3owned){
      stock3owned = stock3owned - stocksell;
      stocksell = stock3 * stocksell;
      money = money + stocksell;
    }
  }
}

void options ()
{
  reshow ();
  cout << "\nWhat would you like to do?\n\nYou can:\n" << endl;
  cout << "(a). Buy a stock" << endl;
  cout << "(b). Sell a stock" << endl;
  cout << "(c). End day" << endl;
  cin >> answer;
  if (answer == 'a' || answer == 'A')
  {
    buy ();
    options ();
  }
  else if (answer == 'b' || answer == 'B')
  {
    sell ();
    options ();
  }
  else if (answer == 'c' || answer == 'C')
  {
    math ();
    options ();
  }
  else
  {
    cout << "Option not found." << endl;
    sleep(1);
  }
}

void text ()
{
  options ();
  text ();
}

void startmath ()
{
  srand(time(0));
  stock1 = rand() % 100; 
  stock2 = rand() % 30;
  stock3 = rand() % 150;
  s1dec = rand () % 100;
  s2dec = rand () % 99 + 1;
  s3dec = rand () % 100;
  stock1 = (s1dec/100) + stock1;
  stock2 = (s2dec/100) + stock2;
  stock3 = (s3dec/100) + stock3; 
  math ();
  text();
  
}

int main()
{
  startmath ();
}
