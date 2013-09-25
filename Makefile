##
## Makefile for corewar in /home/delemo_b/epitech_1/corewar
## 
## Made by barthelemy delemotte
## Login   <delemo_b@epitech.net>
## 
## Started on  Tue Jan 29 14:25:22 2013 barthelemy delemotte
## Last update Sat Mar 30 23:38:51 2013 barthelemy delemotte
##

all	:
		make -C asm/
		make Bonus -C corewar/

clean	:
		make clean -C asm/
		make Bonus-clean -C corewar/


fclean	:
		make fclean -C asm/
		make Bonus-fclean -C corewar/

norme	:
		@sh ./tools/norme.sh

re	:	fclean	all