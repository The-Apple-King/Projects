<Owen Swearingen>,CSCI4211s23,<2/25/2023>
<JAVA>,<DNSServer.java>,<DNSServer.class>

### Compilation

### Execution

### Description
    Open up input from the socket
    Open up output to the socket

    take in the hostname

    Open up a write to the log and to the cache
    open up a read to the cache 

    create a TreeMap in order to store a hostname and array of ip addresses
    read out data from cache file

    check if hostname is in cache, if it is send to client, print to server, and output to logfile

    if it isn't we check if it exists and take the result, send to client, send to server, output to logfile, and add it to cache

    we then close every open reader and writer.