	shift_sp 1
	push_const EXIT
	push_reg fp
	push_reg sp
	pop_reg fp
	jump main
EXIT:
	exit
kk:
	shift_sp 2
kk_start:
	push_reg fp
	push_const 1
	add
	push_const 0
	add
	push_reg sp
	fetch
	push_const 3
	assign
	fetch
	shift_sp -1
	push_reg fp
	push_const 1
	add
	push_const 1
	add
	push_reg sp
	fetch
	push_const 4
	assign
	fetch
	shift_sp -1
	push_reg fp
	push_const -1
	add
	push_const -2
	add
	push_reg fp
	push_const 1
	add
	fetch
	assign
	push_reg fp
	push_const -1
	add
	push_const -1
	add
	push_reg fp
	push_const 2
	add
	fetch
	assign
	jump kk_final
kk_final:
	push_reg fp
	pop_reg sp
	pop_reg fp
	pop_reg pc
kk_end:
main:
	shift_sp 2
main_start:
	push_reg fp
	push_const 1
	add
	push_reg sp
	fetch
	shift_sp 2
	push_const label_0
	push_reg fp
	push_reg sp
	push_const -0
	add
	pop_reg fp
	jump kk
label_0:
	push_reg fp
	push_const 1
	add
	assign
	fetch
	push_reg fp
	push_const 2
	add
	push_reg fp
	push_const 1
	add
	fetch
	assign
	shift_sp -1
	push_reg fp
	push_const 1
	add
	push_const 0
	add
	fetch
	write_int
main_final:
	push_reg fp
	pop_reg sp
	pop_reg fp
	pop_reg pc
main_end:
Lglob.data 0
