#include <iostream>
using namespace std;
#ifndef EVENT_H
#define Event_H
class Event{
private:
string name; // variable for the name
string venue; // variable for the venue
string date; // variable for the date
int total_tickets; // variable for the total number of tickets
int available_tickets; // variable for the number of available tickets
public:
Event(string Name,string venue,string date, int Total_tickets); 
// constructor that initializes the variables of the class
string get_name() const; // A function to return the value of the name variable
string get_date() const; // A function to return the value of the date variable
string get_venue() const; // A function to return the value of the variable venue
int get_total_tickets()const; // A function to return the value of the total tickets
int get_available_tickets() const; // A function to return the value of the available tickets
void set_name(string NAME); // A function to set the value of the name variable
void set_date(string DATE); // A function to set the value for the date variable
void set_venue(string VENUE); // A function to set the value for the venue variable
void decrease_available_tickets();
// A function to decrease the number of the available tickts when a customer purchases one 
void increase_available_tickets();
// A function to increase the number of the available tickts when a customer cancels one 
void Display_Event()const;
// A function to display the event information
};
#endif 