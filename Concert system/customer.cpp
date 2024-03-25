#include <iostream>
#include <string>
#include <stack>
#include "customer.h"
using namespace std;

Customer ::Customer(string Customer_ID, string Name, string Email_address)
{
    customer_ID=Customer_ID;
    name = Name;
    email_address=Email_address;
}
void Customer ::set_customer_ID(string ID)
{
    customer_ID =ID;
}
void Customer ::set_name(string customer_name)
{
    name = customer_name;
}
void Customer ::set_email_address(string address)
{
    email_address=address;
}
string Customer ::get_customer_ID()const
{
    return customer_ID;
}
string Customer ::get_name() const
{
    return name;
}
string Customer ::get_email_address()const
{
    return email_address;
}
void Customer :: record_a_ticket(Ticket*ticket)
{
    Tickets.push(ticket);
    Tickets.top()->get_event()->decrease_available_tickets();
}
void Customer ::cancel_a_ticket(Ticket*ticket)
{    stack <Ticket*> tempStack; 
    Tickets.top()->get_event()->increase_available_tickets();  
     while (!Tickets.empty())
    {
      
        if (Tickets.top() == ticket) {
                Tickets.pop();
            
            }
            else {
            tempStack.push(Tickets.top());
            Tickets.pop();
            }
        }
        while (!tempStack.empty())
        {
            Tickets.push(tempStack.top());
            tempStack.pop();
        }
      
    }
    void Customer :: displayCustomer()
    {
        cout << customer_ID <<endl;
        cout << name <<endl;
        cout << email_address <<endl;
    }
