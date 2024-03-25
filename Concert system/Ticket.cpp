#include <iostream>
#include <fstream>
#include <string>
#include  "Ticket.h"
using namespace std;

    Ticket::Ticket( string name,string ID,string custname,bool reserve,Event* e) 
    {
        event_name =name;
        ticket_ID =ID;
        customer_name=custname;
        reserved=reserve;
        event =e;
    }
    string Ticket::get_event_name() const
    {
        return event_name;
    }
    string Ticket::get_ticket_ID() const
    {
        return ticket_ID;
    }
    string Ticket::get_customer_name() const
    {
        return customer_name;
    }
    bool Ticket::get_reserved() const
    {
        return reserved;
    }
    void Ticket::set_event_name(string name) 
    {
        event_name = name;
    }
    void Ticket::set_ticket_ID(string ID) 
    {
        ticket_ID = ID;
    }
    void Ticket::set_customer_name(string custname) 
    {
        customer_name = custname;
    }
    void Ticket::reserve_ticket(bool reserve) 
    {
        if (!reserved)
        reserved = reserve;
        else 
        cout << "This ticket is already reserved" <<endl;
    }
    void Ticket::cancel_reservation()
    {
        if (reserved)
        reserved= false;
        else
        cout << "It is not reserved" <<endl;
    }
    void Ticket::display_ticket() const
    {
        cout << "The event name is " << event_name <<endl
             << "The ticket ID is " << ticket_ID <<endl
             << "The customer name is " << customer_name <<endl;
             if(reserved)
             cout << "Reserved" <<endl;
             else
             cout << "Not reserved" << endl;
    }
    Event* Ticket :: get_event()
    {
        return event;
    }