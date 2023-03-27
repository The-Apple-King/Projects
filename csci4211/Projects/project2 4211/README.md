Owen Swearingen, CSCI4211S232, 03/22/2023
Java, A.java & B.java,goback


# Compilation and Execution 1
    I attempted to create a .bat file to compile and run each program in each folder.
    they still require you to have the necessary java stuff in order to run it

    both are in their respective folders:
    stop_and_wait.bat
    go_back_n.bat

    these should run the necessary commands and output the results to a terminal if not use the following 

# Compilation and Execution 2

## Compilation
    We assume that you have the required files to run java files

    Open a terminal and navigate to each folder based on which version you want to run
    
### ./stop_and_wait
    call javac .\simulator.java
### ./go_back_n
    Call javac .\simulator.java


## Execution
    Open up a terminal and navigete to the relative folder

    Run the following command

    $ java simulator

    the terminal will run the default test code from simulation

# description

## stop and wait
    on the sender side, A side
    when the a object is created instantiate the variables to default values

### A_input
    checks if the response from b says that the package was received
    if it was received we set the program ready to send another package and remove the timer
    if it wasn't received we restart the timer and resend the last packet

### A_output
    this function will send a packet to the other side when it recieves a message
    it turns a message into a packet and sends it to the other side
    it then updates lastpacket so that if we need to resend it it is saved
    set the state as wait_ack so that a waits for a response
    start a timer so we know if the ack is sent
    update seq so because we have sent the next packet in the seq

### A_handle_timer
    this is called if the timer ran out, this means that we need to resend a packet
    we send lastpacket to B side
    start a new timer
    and set state to wait_layer5

## go back n
    on the sender side, A side
    instantiate to default values, circular buffer size is 5

### A_input
    check if we got the correct packet, if correct packet we remove a timer and remove the same packet from the circular buffer
    if the checksum is correct but the ack is wrong we resend the first packet in the circular buffer
    
### A_output
    if the buffer is full we just return from the function without doing anything
    if the buffer isn't full we create a new packet and push it into the buffer we also start a timer and increase seq number

### A_handle_timer
    if we get a timeout we then resend every single packer in order to make sure they all are recieved at the destination

# B
## B on on both sides
    B is the reciever side 
    instantiate the seq to 0 at the start

### B_input
    if we get a correct packet we send the payload to layer 3 and increment seq
    then no matter what we send an ack,
    the ack contains the acknum but the acknum will only confirm we got the packet if we get the correct packet
    otherwise we send the ack of the previous packet recieved so that we can get a fixed version of the packet