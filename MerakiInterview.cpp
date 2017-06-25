1)
 #aligned malloc and aligned free

2) Phone keypad : 0,1 -nothing
				  2 - (abc)
				  3 -(def)
				  4 - (ghi) etc.


Given a number, return all posible values e.g.
22 should have (abc)(abc) = (aa ab ac ba bb bc ca cb cc)

Store the above in a map. 
phone(string )	{
	do a base case
	phone_helper(recurse)
}


3)pushing and popping frm a stack. 
4)inserting element into linked list
5) IGMP. Real life AP situation where MCAST was causing all TCP connections
from a given AP to client to slow down. When swithced to unicast, things improved
Explain why and code some of the functions

Ans. Switch from Mcast to Unicast when the problem is hit. Do that by
only chaning the dest MCast MAC address to dest unicast MAC address of the client without
changing the dest. IP address , which would still be a mutlicast. That is because
you don't want the live video streaming session to abort by changing the IP address.


igmp_register_client()

igmp_switch_unicase()


6) reversing a string
7) Counting number of ones in a given number.

