/* Read a binary file which has the below structure and print contacts
   (name/email) belonging to a single department. 

   The structure of the binary file is as follows.

   1. file_header_t struct
      - inital identifying bytes which should be {0xDE,'D','I','R'}
      - size of following array of dept_offset_t array
   2. array of dept_offset_t structs
      - dept_code, offset, and num_contacts
      - length of this array is given in initial file_header_t
      - contains field offset which is bytes at which contacts for an
        associated department start
   3. array of contact_t structs
      - name and email fields
      - array is arranged by department
      - array of dept_offset_t structs indicate where each department starts
        and how many contacts are in it

   A verbose plain text example of this would be something along the
   following. Note that offsets are given by line while in the binary
   file they are given by byte offset.

   1. DEDIR 3 departments (file_header_t)
   2. CS, starts at line 5, 8 contacts (dept_offset_t)
   3. EE, starts at line 13, 6 contacts (dept_offset_t)
   4. IT, starts at line 19, 5 contacts (dept_offset_t)
   5. Arindam Banerjee, baner029@umn.edu (contact_t)
   6. Daniel Boley, boley@umn.edu (contact_t)
   7. Abhishek Chandra, chandra@umn.edu (contact_t)
   8. David Hung-Chang Du, du@umn.edu (contact_t)
   9. Maria Gini, gini@umn.edu (contact_t)
   10. Stephen Guy, sjguy@umn.edu (contact_t)
   11. Tian He, tianhe@umn.edu (contact_t)
   12. Mats Heimdahl, heimdahl@umn.edu (contact_t)
   13. Mehmet Akcakaya, akcakaya@umn.edu (contact_t)
   14. Massoud Amin, amin@umn.edu (contact_t)
   15. Raj Aravalli, aravalli@umn.edu (contact_t)
   16. Kia Bazargan, kia@umn.edu (contact_t)
   17. Itshak Bergel, ibergel@umn.edu (contact_t)
   18. Stephen Campbell, scampbell@umn.edu (contact_t)
   19. Joseph Axberg, jaxberg@umn.edu (contact_t)
   20. Carl Follstad, follstad@umn.edu (contact_t)
   21. Valarie Griep, griep003@umn.edu (contact_t)
   22. Richard Howey, howe0156@umn.edu (contact_t)
   23. Scott Kerlin, kerli012@umn.edu (contact_t)
*/


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <string.h>

// macro to add a byte offset to a pointer, arguments are a pointer
// and a # of bytes (usually size_t)
#define PTR_PLUS_BYTES(ptr,off) ((void *) (((size_t) (ptr)) + ((size_t) (off))))

// type for individual contact
typedef struct {
  char name[128];      // name of contact person
  char email[128];     // email address 
} contact_t;

// type indicating position and size of array of contacts in the file
typedef struct {
  char dept_code[16];  // short identifier code for department
  size_t offset;       // byte offset in file where contact_t array starts
  int num_contacts;    // number of contact_t's for this department
} dept_offset_t;

// type indicating initial identifying and size information
typedef struct {
  unsigned char ident[4]; // identifying bytes should be {0xDE,'D','I','R'}
  int num_depts;          // number of departments in dept_offset_t array
} file_header_t;

int main(int argc, char *argv[]){
  if(argc < 3){
    printf("usage: %s <file.dat> <department>\n",argv[0]);
    printf("  department is one of\n");
    printf("  CS : computer science department\n");
    printf("  EE : electrical engineering department\n");
    printf("  IT : information technology department\n");
    return 1;
  }
  char *filename  = argv[1];
  char *dept_code = argv[2];

  // memory map the binary data file
  int fd = open(filename, O_RDONLY);         // open file to get file descriptor
  struct stat stat_buf;
  fstat(fd, &stat_buf);                      // get stats on the open file such as size
  int size = stat_buf.st_size;               // size for mmap()'ed memory is size of file
  char *file_bytes =                         // pointer to file contents
    mmap(NULL, size, PROT_READ, MAP_SHARED,  // call mmap with given size and file descriptor
         fd, 0);                             // read only, potentially share, offset==0

  ////////////////////////////////////////////////////////////////////////////////
  // CHECK the file_header_t struct for integrity, size of department array
  file_header_t *header = PTR_PLUS_BYTES(file_bytes,0); // binary header struct is first thing in the file
  int ident_matches =                                   // check the first bytes to ensure correct file format
    header->ident[0] == 0xDE &&
    header->ident[1] == 'D'  &&
    header->ident[2] == 'I'  &&
    header->ident[3] == 'R';

  if(!ident_matches){
    printf("'%s' does not appear to be a binary department directory file\n",
           filename);
    exit(1);
  }

  int num_depts = header->num_depts; // header was ok, retrieve the number of departments

  ////////////////////////////////////////////////////////////////////////////////
  // SEARCH the array of department offsets for the department named
  // on the command line

  dept_offset_t *offsets_arr =           // after file header, array of dept_offset_t structures
    PTR_PLUS_BYTES(file_bytes, sizeof(file_header_t));

  size_t offset = -1;
  int num_contacts = -1;
  for(int i=0; i<num_depts; i++){        // iterate over the array checking for desired department_code
    printf("Dept Name: %s Offset: %lu\n",
           offsets_arr[i].dept_code, offsets_arr[i].offset);

    if( strcmp(dept_code, offsets_arr[i].dept_code)==0 ){
      offset = offsets_arr[i].offset;    // found correct department
      num_contacts = offsets_arr[i].num_contacts;
    }
  }
  
  if(offset == -1){                      // check if department not found
    printf("Department code '%s' not found\n", 
           dept_code);
    exit(1);
  }

  ////////////////////////////////////////////////////////////////////////////////
  // PRINT out all personnel in the specified department
  // - offset set to byte position from beginning of file for desired department
  // - num_contacts set to the number of contacts for that department

  // get a pointer to array of contact_t's for the given department
  contact_t *dept_contacts = PTR_PLUS_BYTES(file_bytes, offset);
  
  printf("\n%d Contacts for %s department\n",num_contacts,dept_code);

  for(int i=0; i<num_contacts; i++){         // iterate over array and print contacts
    printf("%s <%s>\n", dept_contacts[i].name, dept_contacts[i].email);
  }

  munmap(file_bytes, size);                  // unmap and close file
  close(fd);

  return 0;
}
