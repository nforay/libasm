; ------------------------------------------------------------------------------
; size_t	ft_strlen(const char *str)
; The ft_strlen()  function calculates the length of the string pointed to by
; str, excluding the terminating null byte ('\0').
; parameter register: rdi
; returned value register: rax
; ------------------------------------------------------------------------------

			global	ft_strlen
			section	.text

ft_strlen:
			xor		rax, rax			; i = 0
			jmp		while				; enter while loop

increment:
			inc		rax					; i++

while:
			cmp		byte [rdi + rax], 0	; compare str[i] with 0
			jne		increment			; if not equal increment

return:
			ret							; return (i)