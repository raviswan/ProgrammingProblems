C++
What is encapsulation? Hiding data
What is virtual function table? How is it used? Ans: Dynamic Binding
Explain vptr, and how it is used.
Do we have a virtual constructor? Why not? NO
Why do we need a virtual destructor?
Can abstract class pointer be called on its derived class object methods? YES
What are the differences between C++11 and C++98?
What is object slicing?
What are different cast in C++? Static_cast, dynamic_cast,const_cast, and reinterpret_cast?When is each used?
What are the default constructor that C++ provides?


REMEMBER:
What happens when we write only a copy constructor – does compiler create default constructor?
Compiler doesn’t create a default constructor if we write any constructor even if it is copy constructor. For example, the following program doesn’t compile.

TCP:
What is 3 way handshake?
Can somone eavsdrop on TCP communication?
What is the difference between flow control and congestion control in TCP?
How can TCP be made secure? ANS: By using SSL on top
Why do we have public key and a private key in SSL?
How do you achieve reliability in UDP? ANS: gave e.g. of RTCP in RTP scenario
Why is UDP not reliable? It's faster coz of lack of ACKs




OnSite Q:

1)Implement memmove() or memcpy() when there's memory overlap? Copy from reverse
2) An object declared on stack does not use vptr;

3)How would you Implement a periodic sequence like this. The function should be self-contained.
6
3
7
8
6
3
7
8
6
3
7
8

The below should return false as soon as you determine the sequqnce is not periodic.

6
3
7
8
6
8

Assume the numbers within a sequence are unique. And max length of sequence is 128.
#define MAX_NUM 128
bool func(int x){

}
4) Using -1 using XOR
5) Removing an element in linkedlist with just pointer to it
6) task Queue problem. Producer-consumer problem. Have a unit of work to be done. Multiple elements doing it.



