        push_const EXIT
        push_reg fp
        push_reg sp
        pop_reg fp
        jump main
EXIT:
        exit
main:
        shift_sp 3
main_start:
label_0:
        push_reg fp
        push_const 1
        add
        fetch
        push_reg fp
        push_const 2
        add
        fetch
        equal
        branch_false label_1
        push_reg fp
        push_const 3
        add
        push_reg sp
        fetch
        push_const 1
        assign
        fetch
        shift_sp -1
        jump label_2
label_1:
        push_reg fp
        push_const 3
        add
        push_reg sp
        fetch
        push_const 0
        assign
        fetch
        shift_sp -1
label_2:
main_final:
        push_reg fp
        pop_reg sp
        pop_reg fp
        pop_reg pc
main_end:
Lglob.  data 0
