# libasm
*Le but de ce projet est de se familiariser avec le langage assembleur.*

## Note
***100/100*** :white_check_mark:

## Prototype
```
size_t ft_strlen(const char *str)
int strcmp(const char *s1, const char *s2)
char *ft_strcpy(char *dest, const char *src)
char *ft_strdup(const char *s)
ssize_t ft_write(int fd, const void *buf, size_t count)
ssize_t ft_read(int fd, void *buf, size_t count)
```

## Utilisation
The ft_strlen() function calculates the length of the string pointed to by str, excluding the terminating null byte ('\0').\
The ft_strcmp() function  compares  the two strings s1 and s2. It returns an integer less than, equal to, or greater than zero if s1 is found, respectively, to be  less  than, to match, or be greater than s2.\
The ft_strcpy() function copies the string pointed to by src, including the terminating null byte ('\0'), to the buffer pointed to by dest.\
The ft_strdup() function returns a pointer to a new string which is a duplicate of the string s.\
The ft_write() function writes up to count bytes from the buffer starting at buf to the file referred to by the file descriptor fd.\
The ft_read() function attempts to read up to count bytes from file descriptor fd into the buffer starting at buf.\

## Ressources
[NASM tutorial](https://cs.lmu.edu/~ray/notes/nasmtutorial/)\
[Assembly - Logical Instructions](https://www.tutorialspoint.com/assembly_programming/assembly_logical_instructions.htm)\
[Linux x86 SysCall table](https://blog.rchapman.org/posts/Linux_System_Call_Table_for_x86_64/)\
[GDB Dashboard](https://github.com/cyrus-and/gdb-dashboard)

## Cheat sheet
### Registers
```ASM
; 64-bit [QWORD]
R0  R1  R2  R3  R4  R5  R6  R7  R8  R9  R10  R11  R12  R13  R14  R15
RAX RCX RDX RBX RSP RBP RSI RDI

; 32-bit [DWORD]
R0D R1D R2D R3D R4D R5D R6D R7D R8D R9D R10D R11D R12D R13D R14D R15D
EAX ECX EDX EBX ESP EBP ESI EDI

; 16-bit [WORD]
R0W R1W R2W R3W R4W R5W R6W R7W R8W R9W R10W R11W R12W R13W R14W R15W
AX  CX  DX  BX  SP  BP  SI  DI

; 8-bit [BYTE]
R0B R1B R2B R3B R4B R5B R6B R7B R8B R9B R10B R11B R12B R13B R14B R15B
AL  CL  DL  BL  SPL BPL SIL DIL

; 128-bit (used for floating point operations mostly)
XMM0 ... XMM15
```
### Common
```ASM
; Save register
push    REG
pop     REG

; Set register value
mov        REG, VALUE    ; DEST = VALUE

; Common operations
add        DEST, VALUE    ; DEST = DEST + VALUE
sub        -            ; DEST = DEST - VALUE
inc        REG            ; REG++
dec        -            ; REG--
and        DEST, REG    ; DEST = DEST & REG
xor        -            ; DEST = DEST ^ REG
xor        REG, REG    ; = mov    REG, 0
mul        REG            ; REG = REG * RAX
div        REG            ; REG = REG / RAX

; Dereferenced value
[REG]        ; = *REG

; Compare
cmp    REG, VALUE        ; Set flags used by jmp variants

; Label
label:
        jmp    label    ; next jumps depends on compare flags from cmp
        je    -        ; is equal
        jne    -        ; is not equal
        jl    -        ; < VALUE
        jle    -        ; <= VALUE
        jz    -        ; = 0
        jnz    -        ; != 0
        jg    -        ; > VALUE
        jge    -        ; >= VALUE
```
### Functions
```ASM
; Function call
call    FUNCTION

; Parameters registers
RDI RSI RDX RCX R8 R9

; Register to preserve
RBP RBX R12 R13 R14 R15    ; You must push/pop them if you use them

; Return register
RAX

; syscall
mov        rax, CODE    ; Then RDI, RSI etc.. for params, check Linux x86 SysCall table to choose CODE
syscall
```
