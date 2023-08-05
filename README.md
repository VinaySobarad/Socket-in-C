# Socket-in-C

Here I've written a simple socket program in c.
Here are some basic things which you need to know:

For server side we use the following functions:
socket()  --> we create a tcp socket
bind()  --> To bind a server on a particular port
listen()  --> listening for incoming connections
accept()  --> to accept conections
send()  --> sending the data
recv()  --> To receive data



Client side:
We ll be using winsock32 library n windows for programming our client
Functions used:
socket()
connect()  --> sane as bind 
send()
recv()
