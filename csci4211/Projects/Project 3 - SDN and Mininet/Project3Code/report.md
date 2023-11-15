# Description
    My ethernet based self learning algorithm will take the mac address and the incoming port and save it into a dictionary specific to each switch, then whenever we need to send a packet back to the sender we have the port to send a packet out of saved. if we are sending a packet to an unknown host we flood the system in order to send the packet to the correct location. as the network continues to be used eventually the entire topology will be figured out

    I used a dictionary to store everything, a dictionary saves key value pairs which we use to save mac addresses to ports this way we can use mac addresses to find port numbers.


# Psuedocode

    ```python
    source = packet.source
    destination = packet.destination

    if source not in translationTable
        translationTable[source] = incoming port
    
    msg = new packet
    msg.fields = packet.fields

    if destination in translationTable
        msg.port = translationTable[destination]
    else
        msg.port = all
    send(msg)
    ```

    when a packet comes in we save source and destination mac addresses to be used later. 
    If the source address isn't saved in the mac_to_port dictionary save the source port to mac address in dictionary
    
    create a new flow mod
    give it all of the fields from the original packet

    if destination is in dictionary then we append the outgoing port in dictionary to the packet
    if the destination is not in the dictionary we set the port to op.OFPP_FLOOD which will send the packet through all ports available so that it will eventually find its destination
    then we send the package through whatever port we saved


# extra info
    https://github.com/att/pox/blob/master/pox/misc/of_tutorial.py
    this link provided base code that I built off of