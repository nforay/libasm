; ------------------------------------------------------------------------------
; char	*ft_strcpy(char *dest, const char *src)
; The ft_strcpy()  function copies the string pointed to by src, including the
; terminating null byte ('\0'), to the buffer pointed to by dest.
; parameters register: dest = rdi, src = rsi
; returned value register: rax
; ------------------------------------------------------------------------------

			global	ft_strcpy
			section	.text

ft_strcpy:
			xor		rax, rax				; i = 0
compare:
			cmp		byte [rsi + rax], 0		; while (src[i])
			jz		terminate				; {
while:
			mov		dl, byte [rsi + rax]
			mov		byte [rdi + rax], dl	; dest[i] = src[i]
			inc		rax						; i++
			jmp		compare					; }
terminate:
			mov		byte [rdi + rax], 0		; dest[i] = '\0';
			mov		rax, rdi				; return (dest);
			ret