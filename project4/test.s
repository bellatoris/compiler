	shift_sp 1
	push_const EXIT
	push_reg fp
	push_reg sp
	pop_reg fp
	jump main
EXIT:
	exit
main:
main_final:
	push_reg fp
	pop_reg sp
	pop_reg fp
	pop_reg pc
Lglob.data 3
