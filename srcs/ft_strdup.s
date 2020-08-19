; ------------------------------------------------------------------------------
; char *ft_strdup(const char *s)
; The ft_strdup() function returns a pointer to a new string which is a
; duplicate of the string s.
; parameters register: s = rdi
; returned value register: rax
; ------------------------------------------------------------------------------

			extern ft_strlen		; param: rdi return: rax
			extern ft_strcpy		; params: dst:rdi, src:rsi, return: rax
			extern malloc			; param: number of BYTES as rdi, return: rax
			global	ft_strdup
			section	.text

ft_strdup:
			call	ft_strlen		; rax = strlen(s)
			inc		rax				; rax++ to account for '\0'
			push	rdi				; save register rdi on stack
			mov		rdi, rax		; prepare param before malloc call
			call	malloc			; malloc, rax = allocated bytes pointer
			pop		rdi				; restore rdi from stack
			cmp		rax, 0
			jz		null			; malloc failed, return NULL
			mov		rsi, rdi		; prepare params before ft_strcpy (src)
			mov		rdi, rax		; prepare params before ft_strcpy (dst)
			call	ft_strcpy		; call ft_strcpy, rax = dest pointer
			ret

null:
			xor		rax, rax		; return (NULL)
			ret