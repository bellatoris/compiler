        push_const EXIT
        push_reg fp
        push_reg sp
        pop_reg fp
        jump main
EXIT:
        exit
main:
        shift_sp 2
main_start:
        push_reg fp
        push_const 1
        add
        push_reg sp
        fetch
        push_const 0
        assign
        fetch
        shift_sp -1
loop_continue_0:
        push_reg fp
        push_const 1
        add
        fetch
        push_const 10
        less
        branch_false loop_out_0
        push_reg fp
        push_const 1
        add
        push_reg sp
        fetch
        push_reg fp
        push_const 1
        add
        fetch
        push_const 1
        add
        assign
        fetch
        shift_sp -1
        push_reg fp
        push_const 1
        add
        push_reg sp
        fetch
        push_reg sp
        fetch
        fetch
        push_const 1
        add
        assign
        fetch
        push_const 1
        sub
        shift_sp -1
        jump loop_continue_0
loop_out_0:
main_final:
        push_reg fp
        pop_reg sp
        pop_reg fp
        pop_reg pc
main_end:
Lglob.  data 0
