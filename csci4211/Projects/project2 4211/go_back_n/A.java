public class A {
    int seq;
    int estimated_rtt;
    circular_buffer c_b;
    public A(){
        /* go back n, the initialization of A
        // You can set the estimated_rtt to be 30, which is used as a parameter when you call start_timer
        // initialize the initial sequence number to 0.
        // you need to initialize the circular buffer, using "new circular_buffer(int max)". max is the number of the packets that the buffer can hold.
         */
        // Set the initial sequence number to 0
        seq = 0;

        // Set the estimated RTT to 30
        estimated_rtt = 30;

        // Initialize the circular buffer with a maximum capacity
        c_b = new circular_buffer(5);
    }
    public void A_input(simulator sim, packet p){
        /* go back n, A_input
        // verify that the packet is not corrupted.
        // update the circular buffer according to the acknowledgement number using "pop()"
         */
        // Check if the packet is not corrupted

        // Verify that the packet is not corrupted
        if(p.checksum == p.get_checksum()) {
            if (seq == p.acknum) {
                sim.envlist.remove_timer();
                c_b.pop();
            } else {
                sim.to_layer_three('A', c_b.buffer[c_b.read]);
                sim.envlist.start_timer('A', estimated_rtt);
            }
        }else{
            //System.out.println("packet corrupted");
        }
    }
    public void A_output(simulator sim, msg m){
        /* go back n, A_output
        // if the buffer is full, just drop the packet.
        // construct the packet. Make sure that the sequence number is correct.
        // send the packet and save it to the circular buffer using "push()" of circular_buffer
        // Set the timer using "sim.envlist.start_timer", and the time should be set to estimated_rtt. Make sure that there is only one timer started in the event list.
         */
        if(!c_b.isfull()){
            packet p = new packet(seq, seq, m);
            sim.to_layer_three('A', p);
            c_b.push(p);
            sim.envlist.start_timer('A', estimated_rtt);
            seq++;
        }
        else {
            return;
        }
    }
    public void A_handle_timer(simulator sim){
        /* go back n, A_handle_timer
        // read all the sent packet that it is not acknowledged using "read_all()" of the circular buffer and resend them
        // If you need to resend packets, set a timer after that
         */
        packet[] p = c_b.read_all();
        for (int i = 0; i < c_b.count; i++){
            sim.to_layer_three('A', p[i]);
            sim.envlist.start_timer('A', estimated_rtt);
        }
    }
}
