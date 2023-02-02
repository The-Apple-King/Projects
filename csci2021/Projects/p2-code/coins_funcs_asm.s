### coins_funcs_asm.s: Implements several functions in assembly that
### do simple arithmetic operations. The functions also operate on
### structs and pointers to structs requiring an understanding of
### how structs are handled in assmebly.

.text
.globl  set_coins
set_coins:
### args are
### %edi = int cents
### %rsi = coints_t *coins
        ## BLOCK A
        cmpl    $99,%edi        # is edi >= a dollar
        jg      .OOB            # if greater than jump to fail
        cmpl    $0,%edi         # if edi < 0
        jl      .OOB            #if its less tahn 0 jump to fail
        
        ## BLOCK B
        # Quarters
        movl    %edi,%eax       # eax now has cents
        cqto                    # prep for division
        movl    $25,%r8d        # put 25 into the divisor loc
        idivl   %r8d            # do the divide
        movb    %al,0(%rsi)     # coins->quarters = cents / 25
        movl    %edx,%eax       # cents = cents % 25

        # Dimes
        cqto                    # prep for division
        movl    $10,%r8d        # move 10 into divisor loc
        idivl   %r8d            # do the divide
        movb    %al,1(%rsi)     # coins->dimes = cents / 10
        movl    %edx,%eax       # cents = cents % 10
        cqto                    # prep for division
        
        ## BLOCK C: Complete for nickels and pennies
        ## COMPLETE THIS CODE
        
        # Nickles
        movl    $5,%r8d         #move the 5 into the divisor loc
        idivl   %r8d            #do the divide
        movb    %al,2(%rsi)    # %al is the struct cents, 2 is offset for nickles, rsi is answer to div
        movl    %edx,%eax       
        cqto

        # Pennies
        movl    $1,%r8d         #move the 1 into the divisor loc
        idivl   %r8d            #do the divide
        movb    %al,3(%rsi)    # set the pennies in struct to answer of div


        ## Return 
        movl    $0,%eax         # return value
        ret
.OOB:                           #set up to problem failed
        movl    $1, %eax        # set return val to 1
        ret                     # returnn val


### UNCOMMENT the function below once you complete the first
### function. While it is commented, one can run
### `make test-hybrid` to use the C version during testing.
	
### Use a block uncomment command in your editor to remove the //
### on each of the lines below OR do a find-replace of "// " with ""
### in your editor to uncomment the lines below.

.globl  total_coins
total_coins:
### args are
### %rdi packed coin_t struct with struct fields in the following bit ranges
###  {0-7: quarters, 8-15: dimes, 16-23-: nickels,  24-31: pennies}
        movl    $0,%eax          # tot = 0
        
        movq    %rdi,%rdx        # extract quarters
        ## sarq    $0,%rdx         # no shift needed
        andq    $0xFF,%rdx       # rdx = quarters, mask low byte
        imul    $25,%edx         # rdx *= 25
        addl    %edx,%eax        # tot += coins.quarters*25
        
        movq    %rdi,%rdx        # extract dimes
        sarq    $8,%rdx          # move dimes to low order bits
        andq    $0xFF,%rdx       # rdx = dimes
        imul    $10,%edx         # rdx *= 10
        addl    %edx,%eax        # tot += coins.dimes*10
        
        ## BLOCK D: add on nickels and then pennies
	## COMPLETE THIS CODE

        ## Nickels
        movq    %rdi,%rdx        # extract nickels
        sarq    $16,%rdx          # move nickels to low order bits # idk if this works or if we need 16 now
        andq    $0xFF,%rdx       # rdx = nickels
        imul    $5,%edx          # rdx *= 5
        addl    %edx,%eax        # tot += coins.nickels*5

        ## Pennies
        movq    %rdi,%rdx        # extract pennies
        sarq    $24,%rdx          # move pennies to low order bits
        andq    $0xFF,%rdx       # rdx = pennies
        addl    %edx,%eax        # tot += coins.pennies*1

        ## return value already in eax
        ret

