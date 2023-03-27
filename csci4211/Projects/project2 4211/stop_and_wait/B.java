public class B {
    int seq;

    public B() {
        /* stop and wait, the initialization of B
        // The state only need to maintain the information of expected sequence number of packet
         */
        seq = 0;
    }

    public void B_input(simulator sim, packet p) {

        /* stop and wait, B_input
        // you need to verify the checksum to make sure that packet isn't corrupted
        // If the packet is the right one, you need to pass to the fifth layer using "sim.to_layer_five(entity, payload)"
        // Send acknowledgement using "send_ack(sim, entity, seq)" of packet based on the correctness of received packet
        // If the packet is the correct one, in the last step, you need to update its state ( update the expected sequence number)
         */


        if(p.checksum == p.get_checksum()){
            if(p.acknum == seq){ // if correct packet, send to layer 5 and update seq
                sim.to_layer_five('B', p.payload);
                seq++;
            }
            else{
//                System.out.println("Incorrect acknum\n acknum: " + p.acknum +"\n seq: " + seq);

            }
        }
        else{
            //System.out.println("checksum was incorrect");
        }
        packet.send_ack(sim, 'B', seq); // no matter what send ack


    }

    public void B_output(simulator sim) {
        System.out.println("This line shouldn't be reached in B_output");

    }

    public void B_handle_timer(simulator sim) {
        System.out.println("This line shouldn't be reached in B_handle_timer");
    }
}