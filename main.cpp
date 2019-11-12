#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <unistd.h>

using namespace std;


int stockbuy;
char answer;
double s1dec;
int stock1posneg;
long double stock1change;
long double stocksell;
long double spendmoney;
long double stock1;
long double money = 100; 
int day = 0;
int stock1owned = 0;

void reshow ()
{
  system ("clear");
  cout.precision(2);
  cout << "$" << fixed << money << endl;
  cout << "Day " << day << endl << endl << endl;
  cout << "(1) GOO $" << fixed << stock1;
  cout << " " << stock1owned << " Stocks Owned" ;
  cout << " " << stock1change << "% Change" << endl << endl;
}
void math ()
{
  day ++;
  srand(time(0));
  stock1posneg = rand () % 10;
  stock1change = rand () % 200;
  stock1change = stock1change / 10000;
  if (stock1posneg >=5) //Positive Increase
  {
    stock1 = (stock1change * stock1) + stock1;
    stock1change = stock1change * 100;
  }
  if (stock1posneg < 5)
  {
    stock1 = -(stock1change * stock1) + stock1; //Negative Decrease
    stock1change = stock1change * 100;
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
  s1dec = rand () % 100;
  stock1 = (s1dec/100) + stock1; 
  math ();
  text();
  
}

int main()
{
  startmath ();
}
