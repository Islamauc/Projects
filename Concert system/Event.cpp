#include <iostream>
#include <fstream>
#include <string>
#include  "Event.h"
using namespace std;
Event :: Event(string Name,string Venue,string Date, int Total_tickets)
{
    name = Name;
    venue = Venue;
    date = Date;
    total_tickets=Total_tickets;
    available_tickets = Total_tickets;
}
string Event :: get_name() const
{
    return name;
}
string Event :: get_date() const
{
    return date;
}
string Event :: get_venue() const
{
    return venue; 
}
int Event :: get_total_tickets()const
{
    return total_tickets;
}
int Event :: get_available_tickets() const
{
    return available_tickets;
}
void Event :: set_name(string NAME)
{
 name= NAME;
}
void Event :: set_date(string DATE)
{
    date= DATE;
}
void Event :: set_venue (string VENUE) 
{
    venue = VENUE;
}
void Event :: decrease_available_tickets() 
{
 available_tickets--;
}
void Event :: increase_available_tickets()
{
 available_tickets++;
}
void Event :: Display_Event()const
{
    cout << "The name of the event is:" << name <<endl;
    cout << "The venue of the event is:" << venue <<endl;
    cout << "The date of the event is:" << date <<endl;
    cout << "The number of the total tickets is : " << total_tickets <<endl;
    cout << "The number of the available tickets is : " <<available_tickets <<endl;
}
