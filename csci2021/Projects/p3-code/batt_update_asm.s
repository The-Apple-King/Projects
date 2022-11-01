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
        .int 0b1111111          # 8
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
        movl $0, %r13d          # set r13d empty to use as accumulator

        # set r10 to percent val
        movl  %edi, %r10d                # copy struct to r10
        sarl $16, %r10d                  # shift so we have the bits we want
        andl $0xFF, %r10d                # and so no leading bits

.SET_BATT_IMAGE:        # set the first 7 bits and jump to set nums when done
        movl (%rax, %rcx, 4), %r11d
        
        cmpl %r11d, %r10d      # compare percent to each level 
        # rax contains all comparisons, rcx contains the arr loc, 4 should be num bytes

        jl .SET_NUMS            # loop finished

        shll $1, %r13d                 # shift left first shift does nothing, second + moves 1 to left for inc to set correct bit
        incl %r13d                     # set the last bit to 1
        incq %rcx                       # increment the arr

        jmp .SET_BATT_IMAGE     # loop to check next batt level
        

.SET_NUMS:
        leaq num_vals(%rip),%rcx        # load pointer to beginning of my_array into rcx

        movl  %edi, %r10d                # copy struct to r10
        sarl $24, %r10d                  # shift so we have the bits we want

        cmpl $1, %r10d                  # compare mode against 1
        je .DISPLAY_PERCENT             # percent mode jump
        # otherwise fall

.DISPLAY_VOLTAGE:                       # if mode is set to voltage

        movl %edi, %eax                 # put struct in eax
        andl $0xFF, %eax                # remove percent and mode

        addl $5, %eax                   # add 5 to eax so it rounds up
        movl $10, %r10d
        cqto
        idivl %r10d                        # div by 10

        movl $100, %r10d
        cqto
        idivl %r10d                       # take 100s into eax
        movl (%rcx, %rax, 4), %r10d     # rcx has bit pattern, eax * 4 is loc in rcx
        shll $7, %r13d                  # r13 accumulator shift left 7
        orl %r10d, %r13d                # set bits in accum/r13

        movl %edx, %eax                 # put remainder into eax

        movl $10, %r10d
        cqto
        idivl %r10d                      # put 10s into eax
        movl (%rcx, %rax, 4), %r10d     # rcx has bit pattern, eax * 4 is loc in rcx
        shll $7, %r13d                  # r13 accumulator shift left 7
        orl %r10d, %r13d                # set bits in accum/r13

        movl (%rcx, %rdx, 4), %r10d     # rcx has bit pattern, eax * 4 is loc in rcx
        shll $7, %r13d                  # r13 accumulator shift left 7
        orl %r10d, %r13d                # set bits in accum/r13

        shll $3, %r13d                   # shift left to set final bits
        orl $0b110, %r13d                # set the decimal bit and the v bit

        movl %r13d, (%rsi)
        movl $0, %eax
        ret

.DISPLAY_PERCENT:       # if mode is set to percent

        movl %edi, %eax                 # put struct in eax
        sarl $16, %eax                  # shift to correct bit
        andl $0xFF, %eax                # remove mode

        shll $7, %r13d                  # move bits to make space for last digit
        movl $100, %r10d                # prep div
        cqto
        idivl %r10d                      # div by 100

        cmpl $0, %eax                   # if 0 in hundreds
        je .TENS                        # jump to tens


        # set 100 
        movl (%rcx, %rax, 4), %r10d     # put bit pattern into r10d
        orl %r10d, %r13d                # put bits from r10d into r13d
        movl (%rcx), %r10d
        shll $7, %r13d                  # move bits to make space for last digit
        orl %r10d, %r13d                # put bits from r10d into r13d
        shll $7, %r13d                  # move bits to make space for last digit
        orl %r10d, %r13d                # put bits from r10d into r13d
        shll $3, %r13d                  # shift left to set final bits
        orl $0b001, %r13d                 # set the percent symbol

        movl %r13d, (%rsi)              # put r13d into (%rsi) or display pos
        movl $0, %eax                   # set eax to 0 
        ret


.TENS:

        movl %edx, %eax                 # move the remainder into eax

        shll $7, %r13d                  # move bits to make space for last digit
        movl $10, %r10d                 # prep div
        cqto
        idivl %r10d                      # div by 10

        cmpl $0, %eax                   # if 0 in 10s
        je .ONES                        # jump to ones

        movl (%rcx, %rax, 4), %r10d     # put bit pattern into r10d
        orl %r10d, %r13d                # put bits from r10d into r13d

.ONES:

        shll $7, %r13d                  # shift bits into correct pos 

        movl (%rcx, %rdx, 4), %r10d     # put bit pattern into r10d
        orl %r10d, %r13d                # put bits from r10d into r13d

        shll $3, %r13d                  # shift left to set final bits
        orl $0b001, %r13d                 # set the percent symbol

        movl %r13d, (%rsi)              # put r13d into (%rsi) or display pos
        movl $0, %eax                   # set eax to 0 
        ret                             # return

.text
.global batt_update
        
## ENTRY POINT FOR REQUIRED FUNCTION
batt_update:
	## assembly instructions here

        ret


    
