branche		.text
	extern	printf
	global	main
main:
	mov		edi, txt
	mov		eax, 0
	call	printf


brache		.data
	txt db 'Hello, Holberton', 0xa, 0
