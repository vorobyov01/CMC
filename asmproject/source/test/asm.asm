section .data
    x dq 0.0
    three dq 2.0
    mtwo dq -2.0
    eight dq 8.0

global f1 ; e^x + 2
f1:
    push ebp
    mov ebp, esp

    finit
    fld qword [ebp + 8]
    fldl2e
    fmulp
    
    fld ST0
    fld1

    fxch ST0, ST2

    frndint
    
    fsub ST1, ST0
    fxch ST1, ST0
    f2xm1
    fadd ST0, ST2
    fscale
    fld qword[three]
    faddp

    mov esp, ebp
    pop ebp
    ret

global f2 ; -2x + 8 
f2:
    push ebp
    mov ebp, esp
    
    mov eax, dword[ebp + 8]
    mov dword[x], eax
    mov eax, dword[ebp + 12]
    mov dword[x + 4], eax
    
    finit
    fld qword[x]
    fld qword[mtwo]
    fmul
    fld qword[eight]
    fadd
    
    mov esp, ebp
    pop ebp
    ret