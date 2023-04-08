Owen Swearingen,CSCI4211s23,2/25/2023
JAVA,DNSServer.java,DNSServer.class

## Compilation
    We assume that you have the required files to run java files

    Open a terminal and navigate to the folder
### Server
    call javac .\DNSServer.java
### Client
    Call javac .\DNSClient.java


## Execution
    Open 2 terminals one for the client and one for the server and navigate to the folder

    Run the following commands, one in each terminal

    $ java DNSServer
    $ java DNSClient

    enter a hostname into the client terminal and the server will return the ip

## Description
    Open up input from the socket
    Open up output to the socket

    take in the hostname

    Open up a write to the log and to the cache, if these files don't exist create them
    open up a read to the cache 

    create a TreeMap in order to store a hostname and array of ip addresses
    read out data from cache file

    check if hostname is in cache, if it is send to client, print to server, and output to logfile

    if it isn't we check if it exists and take the result, send to client, send to server, output to logfile, and add it to cache

    we then close every open reader and writer.