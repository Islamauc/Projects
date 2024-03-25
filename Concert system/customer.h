#include <iostream>
#include <string>
#include <stack>
#include "Ticket.cpp"
using namespace std;
class Customer {
private:
string customer_ID, name, email_address;// Variables for the ID of the customer, his name and his email
stack <Ticket*> Tickets; // A stack for pointer of tickets
public:
Customer(string Customer_ID, string Name, string Email_address);
// A constructor that initializes the variables of customer object 
void set_customer_ID(string ID);
// A setter for the customer ID
void set_name(string customer_name);
// A setter for the name of the customer
void set_email_address(string address);
// A setter for the email address of the customer
string get_customer_ID()const;
// A getter for the customer's ID
string get_name()const;
// A getter for the name of the customer
string get_email_address()const;
// A getter for the email of the customer
void record_a_ticket(Ticket*ticket);
// A function that books a ticket for the customer
void cancel_a_ticket(Ticket*ticket);
// A function that cancels a ticket for the customer
void displayCustomer();
// A function that displays the information of the customer


};
