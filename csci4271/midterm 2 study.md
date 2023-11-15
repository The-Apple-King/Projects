DES,
cryptography
stream cipher works on one character as a time, example uses subtraction from a max value

generator function in format c^x = y chinese remainder theorem
3*3 mod 5 = 4 *3 mod 5 = 2 ... in this case 3 is c and 3 4 5 are x 

ssrf is server side request forgery and top 10 attacks in 2021

creating unique temporary files is insecure if the program chooses a a unique filename and the caller creates it.

if we want to guarentee that there is a duplicate we need to test n if we want the chance to be more likely than not we need sqrt(n)

if you have execute permission but not read permission on a Unix directory, this means that: 
    You can access files in the directory if you know their names.

system is not a system call but it does need system calls to work

Which of these lists of people gave their initials to a popular public-key cryptographic primitive?
    Rivest, Shamir, and Adleman

blind sql injection reveals a small amount of info at a time 

xss that involves a database is called persistent cross site scripting

# php line initialize oxide string
oxide("C= location_ox = <<$location_php>>;");

if we send in a closing string, call a function and then close that we can make an attack

` >>; self_destruct(); #'

php means injection attack

# ECD block cipher similar to a stream cipher
example given uses a symbolic link so the actual file name isn't important 
don't let the computer make it, make it yourself,
before the file is opened and edited but after the check we update it to a symbolic link
you cant replace temp files that can only be done by their owners

how to make a race condition work in your favor or TOCTTOU



# xss

# hash/pre image
midterm fall has us find pre image attacks by hand but they are simple ones
need to learn xor functionality well
most of them seem to be used with 0s

# matching blank to word section,

diffusion is when a small input change could affect any part of the output

when multiple names refer to the same inode is hard link

a statement that is true in all situations tautology

container a kernal abstraction that isolates all namespace

fstat a system call fetching inode metadata form a file description

TOCTTOU a kind of race between a check and an unsafe operation

CSS a declaritive language for specifying document appearance

second preimage if h(x) = y , another x' !- x with h(x') = y

CSRF attack that submits a request on another website

XSS an attack getting JavaScript to run under a different origin

inode structure holding the permission and contents of a file

integrity a security policy about preventing data modification

chroot is a filesystem-only isolation technique

Diffie-Hellman is a public key anonymous key exchange protocol

chown is a system call to set a files user and group

stat is a system call fetching inode metadata from a file name

CTR a mode of operation that can be used like a stream cipher

factoring if a quantum computer could solve this quickly it could break RSA

GCHQ a UK government agency that develops cryptography

superuser another word for the user with UID 0

Feistel cipher is the structure used in DES

discrete log given y, compute x such that g^x = y

accesing unintended file system locations with directory traversal

OFB a mode of operation that can be used like a stream cipher

RSA an algorithm that would be insecure if factoring were easy

root the standard name for UID 0 

hypervisor a virtual machine implemented underneath a noraml kernal

XSS another name for JavaScript injection

free collision any pair x, y with x != y such that h(x) = h(y)

chmod unix system call for changing file permissions

confidentiality a security policy that forbids information disclosure

origin subject for access control in web browsers

preimage attack given y, compute an x such that h(x) = y

chroot unix sstem call for filesystem isolation

random oracle idealized functionality equivalent to a random function 

tautology a logical statement that is always true

ACL for an object records allowed subjects and operations

sniffing reading plaintext data from a network

cookie used to implement sessions for web applicatinos

one-time pad truly random bits used as a keystream

supervisor bit: When set, the CPU allows all instructions to execute

TOCTTOU: A common kind of race condition vulnerability

MAC: Cryptographic primitive for integrity protection

reference monitor: Trusted code that checks all sensitive operations

race condition: Effect depends on which of two actions happens first

CTR A parallelizable mode of operation

response splitting: Injection into HTTP headers

encrypt and mac (E(M ), MAC(M ))

block cipher: Implements a pseudo-random permutation

clickjacking: Can fake interest in advertisements

mutation: A small random modification to a program input

encrypt then mac (E(M ), MAC(E(M )))

paravirtualization: Slightly modifying an OS kernel to run better in a VM

sql injection: E.g., OR 1 = 1;--

AFL: A fuzzing tool named after a breed of rabbits

setuid: A program that runs with the identity of its file owner

XSRF: Malicious requests made to another web site

sticky bit: Used on directories with multiple independent users

substitution-permutation network: A block cipher design based on invertible components

birthday paradox: Explains why free collisions are easier to find

## need to define
substitution-permutation network
    a series of linked operations used in block cipher algorithms can be undone by reversing the proces, using inverses in reverse order
    S-boxes swap the value of chars, P-boxes reorder chars

## XSRF/CSRF
    an exploit where unauthorized commands are submitted from a user the web application trusts. like someone is logged into youtube and the victim goes to another website that uses their account to post a comment without telling the user.

## block cipher/stream cipher
    block ciphers convert plaintext to ciphertext block by block while stream ciphers do it byte by byte

## reference monitor
    its a concept that referes to an idealized trusted component/system
    complete mediation: every access checked
    tamper proof: the reference monitor can't be tampered
    simple: must be simpler to minimize vulnerabilities

## one time pad
    theoretically unbreakable key idea: new key, truly random used each time same length as message. xor message with key, same at other end.
    issue is that key must be true random, the source and dest must get the same key and each key can only be used once.
    this is also not the best for encrypting large amounts of data as it doubles the size.

## CTR
    counter mode a mode of operation for block ciphers that turns a block cipher into a stream cipher.


## random oracle


## all preimage attacks


## origin subject


## virtual machine design
    Type 1 hypervisor: 'superkernel' underneath vm
    hosted: regular OS underneath VMs
    paravirtualization: modify kernels in VMs for ease of virtualization

    hardware based is fastest and common no
    partial translation original vmware
    full emulation will allow for different cpu architechture

    chromium uses vm as it keeps the browser kernal seperate from the rest of the machine.

## RSA


## OFB


## discrete log


## Feistel cipher


## GCHQ


## factoring


## Diffie-Hellman


## fstat/stat


## DES

## permissions
only file owner or root can change permissions
* 7 = rwx
* 6 = rw
* 5 = rx
* 4 = r
* 0 - no access
* sticky bit 01000
* when 02000 but set new entries have parent's group
* 04000 setuid bit newly exec'd process will take uid of its file owner, effective uid read is unchanged

### linux commands
* cp copy_src copy_dst : copies file 
* rm file : delets file
* mv new_name old_name : changes the name by moving a file
* chmod 0777 file : changes the permissions to a file
* chown username filename : changes the owner of the file
* chgrp group filename : changes the group of the file
* setuid a function which sets user id upon execution, similar to windows run as admin
* chroot change root directory only available to root

## CFAA
    computer fraud and abuse act of 1986 
    civil and criminal liability

## /tmp files
    unique required, unguessable better
    mktemp(3) unsafe design func
    must use 0_EXCL for atomnicity

## Read it twice WOOT'12
    only download signed apps, use a different signature while its being checked after install the desired app. this gets passed that check and installs anything with a fake signature

## supervisor bit
    all instructions available
    user mode: no hardware or vm conttrol instructions
    only way to switch to kernal mode is specified entry point

## TCB
    trusted computing base: minimize permissions of users so there is less chance to break security

## SFI
    Software-based fault isolation

## System-call interposition
    trusted process will check all syscalls to make sure they are allowed.
