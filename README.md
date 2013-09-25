Corewar
=======

A battle of programs in a virtual machine


Compile:
  at the root of project, to compile the VM(graphic) and the ASM:
    make
  in asm/, to compile just the ASM:
    make
  in corewar/:
    make # just the console mode
    make Bonus # compile with the graphic mode (SDL+SDL_ttf)
    
Run:
  ./corewar [-dump numbers_of_cycles] [ [-a load_address] champion1.cor] ...
    -> -dump n: dumps the memory after n cycles and closes the war.
    
Champions are available in champions/tests/ or corewar/champs/ and have the extension ".cor"


This corewar is a first year project of an IT school. See "corewar_en.pdf"
