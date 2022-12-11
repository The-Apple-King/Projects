// Template to complete the loadfunc program which locates a function
// in the text section of an ELF file. Sections that start with a
// CAPITAL in their comments require additions and modifications to
// complete the program (unless marked as PROVIDED).

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/mman.h>
#include <elf.h>

// macro to add a byte offset to a pointer
#define PTR_PLUS_BYTES(ptr,off) ((void *) (((size_t) (ptr)) + ((size_t) (off))))

// address at which to map the ELF file
#define MAP_ADDRESS  ((void *) 0x0000600000000000)

int main(int argc, char **argv){
  if(argc < 4){                              // PROVIDED: command line checks for proper # args
    printf("usage: %s <file> <funcname> <mode> [arg ...] \n",argv[0]);
    return 0;
  }

  // PROVIDED: required command line arguments
  char *objfile_name = argv[1]; // name of file to operate  on
  char *func_name = argv[2];    // name of function to work on 
  char *mode = argv[3];         // what to do with the functin (print, call, etc...)
                        
  // PROVIDED: open file to get file descriptor, determine file size
  int fd = open(objfile_name, O_RDWR);       // open file to get file descriptor
  struct stat stat_buf;
  fstat(fd, &stat_buf);                      // get stats on the open file such as size
  int file_size = stat_buf.st_size;

  // CREATE memory map via mmap() call, ensure that pages are readable
  // AND executable. Map to virtual address MAP_ADDRESS, first arg to mmap().
  char *file_bytes =                         // pointer to file contents
    0; /// ???;

  // CHECK for failure in memory map, print message and return 1 if
  // failed; otherwise, print pointer value of memory map
  if(file_bytes == 0){ /// ???
    printf("ERROR: failed to mmap() file %s\n",objfile_name);
    return 1;
  }
  printf("file_bytes at: %p\n",file_bytes);

  // CREATE A POINTER to the intial bytes of the file which are an ELF64_Ehdr struct
  Elf64_Ehdr *ehdr = NULL; /// ???

  // CHECK e_ident field's bytes 0 to for for the sequence {0x7f,'E','L','F'}.
  // Exit the program with code 1 if the bytes do not match
  int magic_match =
    0; /// ???

  if(!magic_match){
    printf("ERROR: Magic bytes wrong, this is not an ELF file\n");
    return 1;
  }

  // PROVIDED: check for a 64-bit file
  if(ehdr->e_ident[EI_CLASS] != ELFCLASS64){
    printf("ERROR: Not a 64-bit file ELF file\n");
    return 1;
  }

  // PROVIDED: check for x86-64 architecture
  if(ehdr->e_machine != EM_X86_64){
    printf("ERROR: Not an x86-64 file\n");
    return 1;
  }
  // could check hear for ehdr->e_ident[EI_OSABI] for ELFOSABI_LINUX


  // SET UP a pointer to the array of section headers.  Determine the
  // offset of the Section Header Array (e_shoff) and the number of
  // sections (e_shnum). These fields are from the ELF File
  // Header. The print accroding to the format below
  Elf64_Shdr *shdr = 0L; /// ???
  printf("Section Headers Found:\n");
  printf("- %lu bytes from start of file\n",0L); /// ???
  printf("- %hu sections total\n",0); /// ???
  printf("- %p section header virtual address\n", NULL); /// ???

  // SET UP a pointer to the Section Header String Table
  // .shstrtab. Find the its section index in the ELF header with the
  // fiel (e_shstrndx).  The index into the array of section headers
  // to find the position in the file and set up a pointer to it. See
  // the spec diagram for a visual representation.
  uint16_t shstrndx = 0; /// ???
  char *shstrab = NULL; /// ???
  printf("Section Header Names in Section %d\n",0); /// ???
  printf("- %lu bytes from start of file\n",0L); /// ???
  printf("- %lu total bytes\n", 0L); /// ???
  printf("- %p .shstrtab virtual address\n",NULL); /// ???

  // SEARCH the Section Header Array for sections with names .symtab
  // (symbol table) .strtab (string table), and .text (executable code
  // section).  Note their positions in the file (sh_offset field).
  // Also note the size in bytes (sh_size) and and the size of each
  // entry (sh_entsize) for .symtab so its number of entries can be
  // computed. Finally, note the .data section's index (i value in
  // loop) and its load address (sh_addr).
  Elf64_Shdr *symtab_sh = NULL;
  Elf64_Shdr *strtab_sh = NULL;
  Elf64_Shdr *text_sh   = NULL;

  printf("\n");
  printf("Scanning Section Headers for Relevant Sections\n");
  for(int i=0; i<0; i++){   /// ???
    char *secname = 0L;
    printf("[%2d]: %s\n",i,secname);
    // CHECK for .symtab
    // CHECK for .strtab
    // CHECK for .text
  }

  printf("\n");

  // CHECK that the symbol table was found; if not, error out. SET UP
  // a pointer to the .symtab section and print information as shown.
  if(symtab_sh == NULL){
    printf("ERROR: Couldn't find symbol table\n");
    return 1;
  }
  uint64_t symtab_num = 0L; /// ???
  Elf64_Sym *symtab = NULL; /// ???
  printf(".symtab located\n");
  printf("- %lu bytes from start of file\n",0L); /// ???
  printf("- %lu bytes total size\n",0L); /// ???
  printf("- %lu bytes per entry\n",0L); /// ???
  printf("- %lu number of entries\n",0L); /// ???
  printf("- %p .symtab virtual addres\n",NULL); /// ???


  // CHECK that .strtab (string table) section is found. Error out if
  // not. SET UP a pointer to it and print information as shown.
  if(strtab_sh == NULL){
    printf("ERROR: Couldn't find .strtab section\n");
    return 1;
  }
  char *strtab = NULL;
  printf(".strtab located\n");
  printf("- %lu bytes from start of file\n",0L); /// ???
  printf("- %lu total bytes in section\n",  0L); /// ???
  printf("- %p .strtab virtual addres\n",NULL); /// ???

  // CHECK that the text section is found. Error out if so. SET UP a
  // pointer to it and Print information as shown.
  if(text_sh == NULL){
    printf("ERROR: Couldn't find .text section\n");
    return 1;
  }
  char *text = NULL; /// ???
  printf(".text located\n");
  printf("- %lu bytes offset from start of file\n",0L);/// ???
  printf("- 0x%lx preferred address for .text\n",  0L);/// ???
  printf("- %p .text virtual addres\n",NULL); /// ???

  printf("\n");

  // ITERATE through the symbol table (.symtab section), an array of
  // Elf64_Sym structs. Print the index and name of each symbol in the
  // format indicated. Compare names looking for the symbol (function)
  // name indicated on the command line and obtain a pointer to it.
  printf("Scanning Symbol Table for symbol '%s'\n",func_name);
  Elf64_Sym *sym_st = NULL;
  for(int i=0; i<0L; i++){
    char *cur_name = 0L;
    printf("[%2d]: %s\n",i,cur_name);
    // CHECK to see if current name matches
  }

  printf("\n");

  // CHECK whether symbol was found; error out if not. Print info as
  // indicated when found.
  if(sym_st == NULL){
    printf("ERROR: Symbol '%s' not found in symbol table\n",func_name);
    return 1;
  }
  printf("Found '%s' in symbol table\n",func_name);
  printf("- %lu size\n",0L); /// ???
  printf("- %hu section index\n",0); /// ???
  printf("- %hhu info\n",0); /// ???

  // CHECK that the symbol corresponds to a function (calling
  // ELF64_ST_TYPE(st_info) must yield value STT_FUNC)
  if( 0L ){
    printf("ERROR: '%s' is not a function\n", func_name);
    return 1;
  }

  // CALCULATE the offset of the value into the .text section. The
  // 'value' field of the symbol is its preferred virtual address. The
  // .text section also has a preferred load virtual address. The
  // difference between these two is the offset into the .text section
  // of the mmap()'d file. Print out information on the location of
  // the function in the memory map.
  uint64_t funcoff = 0L;       /// ???
  char *funcaddr = 0L;       /// ???
  printf("Calculating location of '%s' in .text section\n", func_name);
  printf("- 0x%lx preferred address of function (st_value)\n",0L); /// ???
  printf("- 0x%lx preferred address of .text section\n",0L); /// ???
  printf("- %ld offset in .text of start of function\n",0L); /// ???
  printf("- %p virtual address of .text section\n",NULL); /// ???
  printf("- %p virtual address of function\n",NULL); /// ???
  printf("\n");

  // Execute one of the modes of the function: print / call supported
  if(0){}

  // PRINT MODE: iterate through the bytes of the loaded function
  else if( strcmp(mode, "print")==0 ){
    printf("MODE: print\n");
    printf("%lu bytes of function '%s'",0L, func_name); /// ???
    for(int b=0L; 0; b++){  /// ???
      if(b % 8 == 0){
        printf("\n%04x: ",b);
      }
      printf("%02hhx ", 0); /// ???
    }
    printf("\n");
  }

  // CALL MODE: call the function according to the type
  // provided. Three types of functions are supported as indicated
  // below. A pointer to the function bytes can be caste using the
  // string type associated with it as in
  //
  // int (*func)(void) = (int (*)(void)) ptr;
  // int ret = func();
  else if( strcmp(mode, "call")==0 ){ 
    printf("MODE: call\n");

    // Check that funciton type exists as next commandline arg
    if(argc < 5){
      printf("ERROR: 'call' mode requires additional parameters like 'int (*)(void)'\n");
      return 1;
    }
    char *func_type = argv[4];
    printf("func_type: %s\n",func_type);
    // CASES for the function type
    if(0){}

    // int (*)(void) : no args, int return
    else if( strcmp(func_type, "int (*)(void)")==0 ){
      int (*func)(void) = (int (*)(void)) funcaddr;
      printf("running function (no arguments)\n");
      int ret = func();
      printf("returned: %d\n",ret);
    }

    // TODO: int (*)(int,int) : 2 int args, int return
    else if( strcmp(func_type, "int (*)(int,int)")==0 ){
      if(argc < 7){
        printf("ERROR: mode '%s' requires 2 more integer command line argument\n",func_type);
        return 1;
      }
      
      // TODO: cast function, obtain 2 int arguments from command line
      /// ???
      printf("running function with arguments (%d,%d)\n",0,0); /// ???
      // TODO: call function and capture return value
      /// ???
      printf("returned: %d\n",0);       /// ???
    }

    // TODO: void (*)(int*) : 1 argument, an int pointer, no return
    else if( strcmp(func_type, "void (*)(int*)")==0 ){
      if(argc < 6){
        printf("ERROR: mode '%s' requires one more integer command line argument\n",func_type);
        return 1;
      }
      // TODO: cast function, get 1 command line arg
      /// ???
      printf("running function, arg points to %d\n",0);       /// ???
      // TODO: call function with pointer to argument
      /// ???
      printf("arg is now: %d\n",0);       /// ???
    }

    else{
      printf("ERROR: unknown func_type '%s'\n",func_type);
      return 1;
    }
  }
  else{
    printf("ERROR: Unknown mode '%s'\n",mode);
    return 1;
  }

  return 0;
}
