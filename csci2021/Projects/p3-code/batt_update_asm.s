# rax needs return value
# rax rcx rdx rdi rsi r8 r9 r10 r11  # Caller save registers
.text
.global  set_batt_from_ports
        
## ENTRY POINT FOR REQUIRED FUNCTION
set_batt_from_ports:
        ## assembly instructions here

        ## a useful technique for this problem
        movX    SOME_GLOBAL_VAR(%rip), %reg
        # load global variable into register
        # Check the C type of the variable
        #    char / short / int / long
        # and use one of
        #    movb / movw / movl / movq 
        # and appropriately sized destination register

        ret                                            

### Change to definint semi-global variables used with the next function 
### via the '.data' directive
.data
	
my_int:                         # declare location an single integer named 'my_int'
        .int 1234               # value 1234

other_int:                      # declare another int accessible via name 'other_int'
        .int 0b0101             # binary value as per C

my_array:                       # declare multiple ints sequentially starting at location
        .int 10                 # 'my_array' for an array. Each are spaced 4 bytes from the
        .int 0x00014            # next and can be given values using the same prefixes as 
        .int 0b11110            # are understood by gcc.

        ret


## WARNING: Don't forget to switch back to .text as below
## Otherwise you may get weird permission errors when executing 
.text
.global  set_display_from_batt

## ENTRY POINT FOR REQUIRED FUNCTION
set_display_from_batt:  
        ## assembly instructions here

	## two useful techniques for this problem
        movl    my_int(%rip),%eax    # load my_int into register eax
        leaq    my_array(%rip),%rdx  # load pointer to beginning of my_array into rdx


.text
.global batt_update
        
## ENTRY POINT FOR REQUIRED FUNCTION
batt_update:
	## assembly instructions here

        ret


    
