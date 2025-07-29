use 'gdb ./loop_crackme' to start.
'b main' to breakpoint a main.
'r' to run.

  0x7fffffffd948:	0x00000000 // is 0x8, %rbp;	// int sum; in C.
  0x7fffffffd94c:	0x00000000 // is 0x4, %rbp;	// int i; in C.
  
						     FOR LOOP.

  0x0000000000400496 <+32>:	jmp    0x4004b6 <main+64> // go to main+64;

  0x00000000004004b2 <+60>:	addl   $0x1,-0x4(%rbp)	// we add 0x1 to -0x4 (we add 1 to i) // i++; in C.
  0x00000000004004b6 <+64>:	cmpl   $0x4,-0x4(%rbp)	// we use cmpl to compare i to 0x4 // i <= 4 or i < 5; in C.
  0x00000000004004ba <+68>:	jle    0x400498 <main+34> 	// jump back to <main+34>

  0x0000000000400498 <+34>:	mov    -0x4(%rbp),%eax	// we put -0x4 to %eax.
  0x000000000040049b <+37>:	add    %eax,-0x8(%rbp)	// we add %eax(-0x4) to -0x8(sum). // sum += i; in C.
						  printf("") in ASM.
 
   0x00000000004004bc <+70>:	mov    -0x8(%rbp),%eax	// put -0x8(sum) in to %eax. for finale argument of 'printf'.
   0x00000000004004bf <+73>:	mov    %eax,%esi	// put eax(-0x8(sum)) in to esi. 2nd argumet of 'printf'.
   0x00000000004004c1 <+75>:	mov    $0x4011e0,%edi	// link address: '0x4011e0' to %edi. 1st argument of 'printf'.
   0x00000000004004c6 <+80>:	mov    $0x0,%eax	// clear eax using 0x0 for 'printf'.
   0x00000000004004cb <+85>:	call   0x400380 <printf@plt>	// printf.
   
					       	HOW TO CRACK THE LOOP?
b *0x4004b6 // breakpoint for cmpl. We want this because we need to change the 0x4(4) in to something we want.
r // to run

x/5b 0x4004b6 // '5' is 5 bytes we look what will have 5 bytes, 'b' is bytes, '0x4004b6' is the address.
you will see something like that: 0x4004b6 <main+64>:	0x83	0x7d	0xfc	0x04	0x7e. // we need 0x04 from here.

set {char}0x4004b9 0x02 // we use 0x4004b9 because we have 0x4004b6 + 3 bytes(0x83, 0x7d, 0xfc) 0x02 is the number we want.
check with x/5b 0x4004b6

done, u cracked a loop.
