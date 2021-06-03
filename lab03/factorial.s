.globl factorial

.data
n: .word 8

.text
main:
    la t0, n
    lw a0, 0(t0)
    jal ra, factorial

    addi a1, a0, 0
    addi a0, x0, 1
    ecall # Print Result

    addi a1, x0, '\n'
    addi a0, x0, 11
    ecall # Print newline

    addi a0, x0, 10
    ecall # Exit

factorial:
    add t0 x0 a0
    addi t1 x0 1
    addi t2 x0 1
loop:
    blt t0 t2 break
    mul t1 t1 t0
    addi t0 t0 -1
    jal x0 loop
break:
    add a0 x0 t1
    jr ra