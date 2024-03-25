#include <iostream>
#include <string>
#include <stack>
#include <queue>
#include "customer.cpp"
using namespace std;
int main ()
{
// declaring the events and customer objects    
Event e1("Amr diab", "1/5/2023", "The gardens",2);
Event e2("Amr diab 2", "1/5/2023", "Mansour hall",2 );
    Customer customer1("9123213313", "Mohammed", "Mohammed@gmail.com");
    Customer customer2("8125213314", "Ahmed", "Ahmed@gmail.com");
    Customer customer3("2345960455", "Mariam", "Mariam@gmail.com");
    Customer customer4("4568694043", "Sara" , "Sara@gmail.com");
    Customer customer5("3296044595", "Paul", "Paul@gmail.com");
    Customer customer6("5420294003",  "John", "John@gmail.com");
    cout << "The Available Events:" << endl; // displaying the events
    e1.Display_Event();
    cout << endl;
    e2.Display_Event();
    cout << endl;

    cout << "The Registered Customers:" << endl; // displaying the customers
    customer1.displayCustomer();
    cout << endl;
    customer2.displayCustomer();
    cout << endl;
    customer3.displayCustomer();
    cout << endl;
    customer4.displayCustomer();
    cout << endl;
    customer5.displayCustomer();
    cout << endl;
    customer6.displayCustomer();
    cout << endl;

    Ticket t1(e1.get_name(), "458964" , customer1.get_name(), true,&e1); // declaring the tickets
    Ticket t2(e1.get_name(), "239490" , customer2.get_name(), true,&e1);
    Ticket t3(e2.get_name(), "349905" , customer3.get_name(), true,&e2);
    Ticket t4(e2.get_name(), "593464" , customer4.get_name(), true,&e2);

    customer1.record_a_ticket(&t1); // booking tickets for the customers
    customer2.record_a_ticket(&t2);
    customer3.record_a_ticket(&t3);
    customer4.record_a_ticket(&t4);
            
    e1.Display_Event(); // displaying the events after booking the tickets
    cout << endl;
    e2.Display_Event();
    cout << endl;

    customer1.displayCustomer(); // displaying the customers before canceling tickets
    cout << endl;
    customer2.displayCustomer();
    cout << endl;
    customer3.displayCustomer();
    cout << endl;
    customer4.displayCustomer();
    cout << endl;
    customer5.displayCustomer();
    cout << endl;
    customer6.displayCustomer();
    cout << endl;

    customer1.cancel_a_ticket(&t1); // canceling tickets
    customer2.cancel_a_ticket(&t2);
    customer3.cancel_a_ticket(&t3);
    customer4.cancel_a_ticket(&t4);

    customer1.displayCustomer(); // displaying customers' information after canceling tickets
    cout << endl;
    customer2.displayCustomer();
    cout << endl;
    customer3.displayCustomer();
    cout << endl;
    customer4.displayCustomer();
    cout << endl;
    customer5.displayCustomer();
    cout << endl;
    customer6.displayCustomer();
    cout << endl;
    e1.Display_Event(); // displaying the information of the event
    cout << endl;
    e2.Display_Event();
    cout << endl;
    queue <Customer*> waiting_list; // initializing a queue for the customers in the waiting list
    Customer customer9("3296044595", "Paul", "Paul@gmail.com");
    Customer customer10("8420244003",  "John", "John@gmail.com");
    Customer customer7("9216094595", "Batman", "Batman@gmail.com");
    Customer customer8("1120294603",  "Alfred", "Alfred@gmail.com");
   if (e1.get_available_tickets()>0) 
   // if there are no available tickets, then the customer is added to the waiting list
   {
   Ticket t5(e1.get_name(), "458964" , customer9.get_name(), true,&e1);
    customer9.record_a_ticket(&t5);
   }
   else
   {
    waiting_list.push(&customer9);
   }
    if (e1.get_available_tickets()>0)
   {
   Ticket t6(e1.get_name(), "459795" , customer10.get_name(), true,&e1);
   customer10.record_a_ticket(&t6);
   }
   else
   {
    waiting_list.push(&customer10);
   }
   if (e1.get_available_tickets()>0)
   {
   Ticket t7(e2.get_name(), "653595" , customer7.get_name(), true,&e2);
   customer7.record_a_ticket(&t7);
   }
   else
   {
    waiting_list.push(&customer7);
   }
    
    if (e1.get_available_tickets()>0)
   {
   Ticket t8(e2.get_name(), "369795" , customer8.get_name(), true,&e2);
   customer8.record_a_ticket(&t8);
   }
   else
   {
    waiting_list.push(&customer8);
   }
    return 0;
}