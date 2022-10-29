# rax needs return value
# rax rcx rdx rdi rsi r8 r9 r10 r11  # Caller save registers


# rdi offsetts not done fix later
// short is 2
// char is 4

.text
.global  set_batt_from_ports
        
## ENTRY POINT FOR REQUIRED FUNCTION
set_batt_from_ports:

        movw BATT_VOLTAGE_PORT(%rip), %ax       # put the val of voltage in batt in ax
        cmpw $0, %ax                            # test if voltage is negative
        jl .FAIL                                # jump to fail if it is

        # set values
        sarw $1, %ax                            # divides ax by 2 to get mlvolts
        movw %ax, 0(%rdi)                       # set the batt voltage
        movq $0, %rax                           # set return val to 0 because success
        
        # set percentage
        cmpw $3000, 0(%rdi)                     # if more than 3k mlvolts
        jg .POSITIVE_BATT                       # jump to positive
        movb $0, 2(%rdi)                        # else batt empty set to 0
        jmp .SET_MODE                           # jump to set mode because percent set

.POSITIVE_BATT:                                 # if the voltage is greater than 3k or % is positive
        movw (%rdi), %cx                        # set cx to do math
        subw $3000, %cx                         # should subtract 3k from rcx
        sarw $3, %cx                            # divide by 8, should give percentage
        cmpw $100, %cx                          # if rcx less than 100%
        jl .NOT_MAX                             # jump to NOT_MAX
        movb $100, 2(%rdi)                      # if rcx bigger than 100% set batt % to 100%
        jmp .SET_MODE                           # jump to set mode

.NOT_MAX:
        movb %cl, 2(%rdi)                       # set percent
        jmp .SET_MODE

.SET_MODE:
        movl BATT_STATUS_PORT(%rip), %ecx       # takes val from stat port and saves to ecx
        and $16, %ecx                           # check 4th bit to check val
        cmp $16, %ecx                           # compare if = to set batt status
        je .PERCENT                             # if it wants percent jump there
        movb $2, 3(%rdi)                        # it wants volt set the mode
        ret                                     # return at this point batt is set and the eax was set to 0 a long time ago

.PERCENT:
        movb $1, 3(%rdi)                        # wants % set mode
        ret

.FAIL:
        movq $1, %rax                           # set return val to 1 for fail
        ret                                     # returns

### Change to definint semi-global variables used with the next function 
### via the '.data' directive
.data
	
batt_level_cmp:                 # used to compare percent against
        .int 5                  # batt level 0
        .int 30                 # batt level 1
        .int 50                 # batt level 2
        .int 70                 # batt level 3
        .int 90                 # batt level 4

num_vals:                       # declare multiple ints sequentially starting at location
        .int 0b0111111          # 0
        .int 0b0000110          # 1
        .int 0b1011011          # 2
        .int 0b1001111          # 3
        .int 0b1100110          # 4
        .int 0b1101101          # 5
        .int 0b1111101          # 6
        .int 0b0000111          # 7
        .int 0b0111111          # 8
        .int 0b1101111          # 9


# WARNING: Don't forget to switch back to .text as below
## Otherwise you may get weird permission errors when executing 
.text
.global  set_display_from_batt

## ENTRY POINT FOR REQUIRED FUNCTION
set_display_from_batt:  
        ## assembly instructions here

        ## two useful techniques for this problem
        leaq    batt_level_cmp(%rip),%rax    # load my_int into register eax

        # START OF MY CODE-------------------------------------------------------------------------
        # rax = the compares for batt level
        # rbx = the address to the global display var
        
        movq $0, %rcx           # set rcx to be used as offset in loop


.SET_BATT_IMAGE:        # set the first 7 bits and jump to set nums when done
        movq  %rdi, %r10                # copy struct to r10
        sarq $16, %r10                  # shift so we have the bits we want
        andq $0xFF, %r10                # and so no leading bits
        movl (%rax, %rcx, 4), %r11d
        cmpq %r11, %r10      # compare percent to each level 
        # rax contains all comparisons, rcx contains the arr loc, 4 should be num bytes

        jl .SET_NUMS            # loop finished

        shlq (%rsi)                     # shift left first shift does nothing, second + moves 1 to left for inc to set correct bit
        incq (%rsi)                     # set the last bit to 1
        incq %rcx                       # increment the arr

        jmp .SET_BATT_IMAGE     # loop to check next batt level
        

.SET_NUMS:
        leaq num_vals(%rip),%rcx        # load pointer to beginning of my_array into rcx

        # put mode into %r10
        movq  %rdi, %r10                # copy struct to r10
        sarq $24, %r10                  # shift so we have the bits we want
        andq $0xFF, %r10                # and so no leading bits
        cmpq $1, %r10                   # compare percent in rdi to rax offset increment until rax < rdi

        je .DISPLAY_VOLTAGE             # if mode = 1 jump to voltage
        jmp .DISPLAY_PERCENT            # if mode = 2 jump to percent !!!!!!!!!!!!!!!!!!!!! may need to fix if val is not 1 or 2

.DISPLAY_VOLTAGE:                       # if mode is set to voltage
        movw %ax, (%rdi)                # repurpose rax to be used as voltage
        movq $10, %r10
        divq %r10                       # do we round up
        cmp $5, %rdx                    # compare remainder to see if round up
        add $1, %ax                     # add 1 to round up
        
        movq $100, %r10                 # use r10 as div counter
        shlq $7, (%rsi)                 # move the bits in batt image to the correct spot
        divq %r10                       # div 100 put 100s place into rax
        movq (%rcx, %rax, 1), %r10
        or %r10, (%rsi)           # set the 100's place
        movq %rdx, %rax                 # move the remainder into rax

        shlq $7, (%rsi)                 # move the bits in batt image to the correct spot
        movq $10, %r10                  # use r10 as div counter
        divq %r10                       # div 10 put 10s place into rax
        
        movq (%rcx, %rax, 1), %r10
        or %r10, (%rsi)           # set the 10's place
        shlq $7, (%rsi)                 # move the bits in batt image to the correct spot
        movq (%rcx, %rdx, 1), %r10
        or %r10, (%rsi)           # set the 1's place using remainder
        shlq $3, (%rsi)                 # shift left to set final bits
        or $0b110, (%rsi)                # set the decimal bit and the v bit

        movq $0, %rax
        ret

.DISPLAY_PERCENT:       # if mode is set to percent
        movb %al, (%rdi)                # repurpose rax to be used as percent
        shlq $7, (%rsi)                 # move the bits in batt image to the correct spot
        movq $100, %r10
        divq %r10                       # div 100 put 100s place into rax

        cmp $0, %rax                    # test for leading 0
        je .TENS                        # if leading 0 jump to 10s 

        movq (%rcx, %rax, 1), %r10
        or %r10, (%rsi)           # set 100s place

.TENS:
        movq %rdx, %rax                 # put remainder into rax
        shlq $7, (%rsi)                 # move the bits in batt image to the correct spot
        movq $10, %r10
        divq %r10                        # find num in 10s place

        cmp $0, %rax                    # test for leading 0
        je .ONES                        # if leading 0 jump to ones

        movq (%rcx, %rax, 1), %r10
        or %r10, (%rsi)

.ONES:
        shlq $7, (%rsi)                  # move the bits in batt image to the correct spot
        movq (%rcx, %rdx, 1), %r10
        or %r10, (%rsi)            # set the 1s place
        shlq $3, (%rsi)                  # shift left to set final bits
        or $0b001, (%rsi)                 # set the percent symbol

        movq $0, %rax
        ret
.text
.global batt_update
        
## ENTRY POINT FOR REQUIRED FUNCTION
batt_update:
	## assembly instructions here

        ret


    
