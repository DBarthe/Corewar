##
## Makefile for corewar in /home/raphy/Projects/prog_elem/corewar/asm
## 
## Made by raphael defreitas
## Login   <defrei_r@epitech.net>
## 
## Started on  Sun Jan 27 17:34:18 2013 raphael defreitas
## Last update Sun Mar 31 11:05:41 2013 barthelemy delemotte
##

NAME		=	asm

SRC		=	src/instruction/instruct_len.c \
			src/instruction/parse_instruct.c \
			src/instruction/instruct_error.c \
			src/instruction/tab.c \
			src/instruction/instructions.c \
			src/coffee.c \
			src/new_file/new_file.c \
			src/asm/asm_label.c \
			src/asm/asm_epur_line.c \
			src/asm/asm_display.c \
			src/asm/asm_fill_code.c \
			src/asm/asm_fill_extra_datas.c \
			src/asm/asm.c \
			src/asm/asm_assamble.c \
			src/asm/asm_write.c \
			src/asm/asm_fill_len_and_labels.c \
			src/parser/recovery.c \
			src/parser/cleaner.c \
			src/param/param_value.c \
			src/param/param_type.c \
			src/param/unsigned_getnbr_base.c \
			src/param/param_label_value.c \
			src/param/param_oct_nb.c \
			src/main.c \
			src/error.c

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
			@$(CC) -o $(NAME) $(OBJ) $(LDFLAGS)

clean		:
			@rm -rf $(OBJ)

fclean		:	clean
			@rm -rf $(NAME)

norme           :
			@sh ../tools/norme.sh

re		:	fclean all

.PHONY: all clean fclean norme re
