section .text

global main
extern openfile
extern splitFile
; extern main
; _start:
;       lea	ecx, [esp+4]
;       push	ecx
;       push	DWORD[esp+4]
;       call	main
;       mov	ebx, eax
;       mov	eax,1
;       int	0x80
;       ret

main:
  ;initialize
    push	ebp
    mov		ebp, esp
    ;get argc
    mov		eax ,[ebp+8]
    ;check that there are enough args
    cmp		eax, 2
    jl		END
    ;call open file use argv[0] now in stack
    mov		ecx, ebp
    add		ecx, 12
    push 	ecx
    call	openfile
    ;push args for external functions
    push	0
    push 	eax
    push	DWORD[ebp+12]
    push	0
    call	splitFile
    
END:    mov esp, ebp
	pop ebp
	ret
    
