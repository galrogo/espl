section .text
  global cmpstr
cmpstr:
	;enter
	push	ebp
	mov	ebp, esp
	;initalize parameters
	mov eax, DWORD [ebp+8]
	movzx eax, BYTE [eax]
	mov ebx, DWORD [ebp+12]
	movzx ebx, BYTE [ebx]
    

LOOP:	
	cmp eax, ebx
	je EQ
	jg GR
	jl LS 
	
	
EQ:
	add	DWORD [ebp+8], 1
	add	DWORD [ebp+12], 1
	mov 	eax, DWORD [ebp+8]
	movzx	eax, BYTE [eax]
        mov	ebx, DWORD [ebp+12]
	movzx	ebx, BYTE [ebx]
	test	 al, al
	je LASTITER
	test	bl, bl
	je LASTITER
	jmp LOOP

GR:
	mov eax, 1
	jmp END

LS:
	mov eax, 2
	jmp END

LASTITER:
	cmp eax, ebx
	je ENDEQ
	jg GR
	jl LS

ENDEQ:
      mov eax, 0
      jmp END

END:
     mov esp, ebp
     pop ebp
     ret
