#include <iostream>
#include <string>
#include "Event.cpp"
using namespace std;
#ifndef TICKET_H
#define TICKET_H
class Ticket
{
private:
    string event_name; // A variable to specify the name of the event for that ticket
    string ticket_ID; // A variable for the ID of the ticket
    string customer_name; // A variable for the customer name
    bool reserved; // A variable to determine if the ticket is reserved or not
    Event* event;
public:
    Ticket(string name,string ID,string custname,bool reserve, Event* e);
    // A constructor that initializes the variables of the Ticket object  
    string get_event_name()const; // A function to return the name of the event for the ticket
    string get_ticket_ID()const; // A function to return the ID of the ticket
    string get_customer_name()const; // A function to return the name of the customer
    bool get_reserved()const; // A function to return the reserve status for the ticket
    void set_event_name(string name); // A function to set the name of the event for the ticket
    void set_ticket_ID(string ID); // A function to set the ID ticket
    void set_customer_name(string custname); // A function to set the name of the customer
    void reserve_ticket(bool reserve); // A function to reserve the ticket
    void cancel_reservation(); // A function to cancel the reservation of a ticket
    void display_ticket()const; // A function to display the information for the ticket
    Event* get_event();
}; 
#endif