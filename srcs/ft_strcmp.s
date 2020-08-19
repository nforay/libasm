; ------------------------------------------------------------------------------
; int strcmp(const char *s1, const char *s2)
; The  strcmp()  function  compares  the two strings s1 and s2.  It returns an
; integer less than, equal to, or greater than zero if s1 is found,
; respectively, to be  less  than, to match, or be greater than s2.
; parameters register: s1 = rdi, s2 = rsi
; returned value register: rax
; ------------------------------------------------------------------------------

			global	ft_strcmp
			section	.text

ft_strcmp:
			xor		rax, rax				; i = 0
			xor		cx, cx					; char tmp

while:
			mov		cl, byte [rdi + rax]	; tmp = s1[i]
			cmp		byte [rsi + rax], cl	; if (tmp != s2[i])
			jne		comp
			cmp		cl, 0					; if (tmp == '\0')
			jz		comp
			cmp		byte [rsi + rax], 0		; if (s2[i] == '\0')
			jz		comp
			inc		rax
			jmp		while					; i++

comp:
			sub		cl, byte [rsi + rax]
			jb		ret_neg					; s1 < s2 (jb: jump below) unsigned comparison
			ja		ret_pos					; s1 > s2 (ja: jump above) unsigned comparison
			jmp		ret_eq					; s1 == s2

ret_eq:
			mov		rax, 0					; return(0)
			ret

ret_neg:
			mov		rax, -1					; return(-1)
			ret

ret_pos:
			mov		rax, 1					; return(1)
			ret