; ------------------------------------------------------------------------------
; ssize_t ft_write(int fd, const void *buf, size_t count)
; ft_write()  writes up to count bytes from the buffer starting at buf to the
; file referred to by the file descriptor fd.
; parameters register: fd = rdi, buf = rsi, count = rdx
; returned value register: rax
; ------------------------------------------------------------------------------

			extern	__errno_location
			global	ft_write
			section	.text

ft_write:
			mov		rax, 1				; 1 is write() syscall number
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