##
## Makefile for corewar in /home/raphy/Projects/prog_elem/corewar/corewar
## 
## Made by raphael defreitas
## Login   <defrei_r@epitech.net>
## 
## Started on  Sun Jan 27 17:34:18 2013 raphael defreitas
## Last update Sun Mar 31 23:10:26 2013 barthelemy delemotte
##

NAME		=	corewar

SRC		=	./src/params/params_init.c \
			./src/params/params_new.c \
			./src/params/params_get_dump_cycle.c  \
			./src/params/params_free.c \
			./src/params/params_get_files.c \
			./src/params/params_check_double_id.c \
			./src/instruction/instruction_get_arg_type.c \
			./src/instruction/instruction_get_next.c \
			./src/instruction/instruction_parse_args.c \
			./src/instruction/read_write/instruction_rw_store.c \
			./src/instruction/read_write/instruction_rw_aff.c \
			./src/instruction/read_write/instruction_rw_load.c \
			./src/instruction/read_write/instruction_rw_live.c \
			./src/instruction/read_write/instruction_rw_xor.c \
			./src/instruction/read_write/instruction_write.c \
			./src/instruction/read_write/instruction_rw_and.c \
			./src/instruction/read_write/instruction_rw_storei.c \
			./src/instruction/read_write/instruction_r_op.c \
			./src/instruction/read_write/instruction_rw_sub.c \
			./src/instruction/read_write/instruction_read.c \
			./src/instruction/read_write/instruction_rw_zjump.c \
			./src/instruction/read_write/instruction_rw_add.c \
			./src/instruction/read_write/instruction_read_args.c \
			./src/instruction/read_write/instruction_rw_loadi.c \
			./src/instruction/read_write/instruction_rw_or.c \
			./src/instruction/read_write/instruction_rw_fork.c \
			./src/instruction/instruction_new.c \
			./src/instruction/instruction_load.c \
			./src/instruction/instruction_free.c \
			./src/instruction/instruction_get_val.c \
			./src/process/process_get_registre.c \
			./src/process/process_new.c \
			./src/process/process_create.c \
			./src/process/process_set_registre.c \
			./src/process/process_execute.c \
			./src/process/process_dup.c \
			./src/process/process_init.c \
			./src/process/process_disp.c \
			./src/process/process_free.c \
			./src/brain/brain_init.c \
			./src/brain/brain_run.c \
			./src/brain/brain_load.c \
			./src/brain/brain_put_programs.c \
			./src/brain/brain_new.c \
			./src/brain/brain_free.c \
			./src/program/program_load_data.c \
			./src/program/program_new.c \
			./src/program/program_init_load_addr.c \
			./src/program/program_init_name.c \
			./src/program/program_display.c \
			./src/program/program_free.c \
			./src/program/program_list_init.c \
			./src/program/program_attrib_id.c \
			./src/game/game_init.c \
			./src/game/game_end.c \
			./src/game/game_free.c \
			./src/game/game_set_players_id.c \
			./src/game/game_do_cycle.c \
			./src/game/game_is_ended.c \
			./src/game/game_new.c \
			./src/game/game_live.c \
			./src/cpu/cpu_execution.c \
			./src/cpu/cpu_new.c \
			./src/cpu/cpu_add_process.c \
			./src/cpu/cpu_kill_process.c \
			./src/cpu/cpu_create_processes.c \
			./src/cpu/cpu_free.c \
			./src/cpu/cpu_disp_processes.c \
			./src/main.c \
			./src/ram/ram_put_program.c \
			./src/ram/ram_new.c \
			./src/ram/ram_put_program_list.c \
			./src/ram/ram_set.c \
			./src/ram/ram_init.c \
			./src/ram/ram_get.c \
			./src/ram/ram_free.c \
			./src/ram/ram_dump.c \
			./src/ram/ram_hook_set.c \
			./src/error.c

SRC		+=	./../common/src/op_get_case.c \
			./../common/src/op.c \
			./../common/src/xmalloc.c \
			./../common/src/my/standard/my_fprintf.c \
			./../common/src/my/standard/my_getnbr.c \
			./../common/src/my/standard/my_fputchar.c \
			./../common/src/my/standard/my_printf.c \
			./../common/src/my/standard/my_putnbr.c \
			./../common/src/my/standard/my_fputnbr_base.c \
			./../common/src/my/standard/my_putstr.c \
			./../common/src/my/standard/my_fputnbr.c \
			./../common/src/my/standard/my_getnbr_base.c \
			./../common/src/my/standard/my_vfprintf.c \
			./../common/src/my/standard/my_fputstr.c \
			./../common/src/my/standard/my_putnbr_base.c \
			./../common/src/my/standard/my_putchar.c \
			./../common/src/my/memory/my_realloc.c \
			./../common/src/my/memory/my_calloc.c \
			./../common/src/my/memory/my_mem_isequal.c \
			./../common/src/my/memory/my_memset.c \
			./../common/src/my/memory/my_memshow.c \
			./../common/src/my/memory/my_memcpy.c \
			./../common/src/my/list/my_list_length.c \
			./../common/src/my/list/my_list_delete.c \
			./../common/src/my/list/my_list_top.c \
			./../common/src/my/list/my_list_reverse.c \
			./../common/src/my/list/my_list_bot.c \
			./../common/src/my/list/my_list_insert.c \
			./../common/src/my/list/my_list_swap.c \
			./../common/src/my/list/my_list_item_free.c \
			./../common/src/my/list/my_list_push.c \
			./../common/src/my/list/my_list_free.c \
			./../common/src/my/list/my_list_item_new.c \
			./../common/src/my/list/my_list_new.c \
			./../common/src/my/list/my_list_insert_item.c \
			./../common/src/my/list/my_list_peek_bot.c \
			./../common/src/my/list/my_list_peek_top.c \
			./../common/src/my/list/my_list_enqueue.c \
			./../common/src/my/string/my_strncpy.c \
			./../common/src/my/string/my_strchr.c \
			./../common/src/my/string/my_strncat.c \
			./../common/src/my/string/my_revstr.c \
			./../common/src/my/string/my_strpos.c \
			./../common/src/my/string/my_match.c \
			./../common/src/my/string/my_strclean.c \
			./../common/src/my/string/my_strncmp.c \
			./../common/src/my/string/my_strcpy.c \
			./../common/src/my/string/my_strcat.c \
			./../common/src/my/string/my_getline.c \
			./../common/src/my/string/my_strndup.c \
			./../common/src/my/string/my_strstr.c \
			./../common/src/my/string/my_strcmp.c \
			./../common/src/my/string/my_explode.c \
			./../common/src/my/string/my_strlen.c \
			./../common/src/my/string/my_str_isnum.c \
			./../common/src/my/string/my_strdup.c

OBJ		=	$(SRC:.c=.o)

INCLUDES	=	-I ./includes -I ../common/includes

CFLAGS		=	-Wall -pedantic -ansi $(INCLUDES)

LDFLAGS		=	$(CFLAGS)

CC		=	gcc

all		:	$(NAME)

$(NAME)		:	$(OBJ)
			$(CC) -o $(NAME) $(OBJ) $(LDFLAGS)

clean		:
			@rm -rf $(OBJ)

fclean		:	clean
			@rm -rf $(NAME)

norme		:
			@sh ../tools/norme.sh

re		:	fclean all

Bonus		:
			make -C bonus/
			@cp ./bonus/corewar ./

Bonus-clean	:
			make clean -C bonus/

Bonus-fclean	:
			make fclean -C bonus/

Bonus-re	:
			make re -C bonus/
			@cp ./bonus/corewar ./
