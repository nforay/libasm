; ------------------------------------------------------------------------------
; ssize_t ft_read(int fd, void *buf, size_t count)
; ft_read()  attempts to read up to count bytes from file descriptor fd into
; the buffer starting at buf.
; parameters register: fd = rdi, buf = rsi, count = rdx
; returned value register: rax
; ------------------------------------------------------------------------------

			extern	__errno_location
			global	ft_read
			section	.text

ft_read:
			mov		rax, 0				; 1 is read() syscall number
			syscall
			cmp		rax, 0				; on error -1 is returned
			jl		error
			ret

error:
			neg		rax					; get absolute value of syscall return
			mov		rdi, rax			; set rdi to rax
			call	__errno_location
			mov		[rax], rdi			; set the value of errno
			mov		rax, -1
			ret