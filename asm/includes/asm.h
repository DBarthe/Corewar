/*
** asm.h for corewar - Asm in /home/delemo_b/epitech_1/corewar/asm/src/instruction
** 
** Made by barthelemy delemotte
** Login   <delemo_b@epitech.net>
** 
** Started on  Wed Mar 20 14:09:14 2013 barthelemy delemotte
** Last update Sat Mar 30 15:14:02 2013 damien sauvalle
*/

#ifndef		ASM_H_
# define	ASM_H_

#include	"my.h"

#define		INT16_MAX	32767
#define		INT16_MIN	-32768
#define		INT8_MAX	127
#define		INT8_MIN	-128
#define		INT8_MAX_UNSIGNED	255
#define		INT8_MIN_UNSIGNED	0
#define		SIGNED		0
#define		UNSIGNED	1

#define		COR_FILE_MODES	664

typedef struct	s_label
{
  char		*name;
  int		idx;
}		t_label;

t_label		*label_new(char *name, int idx);
void		label_free(t_label *label);

typedef struct	s_asm
{
  t_list	*file;
  t_list	*labels;
  char		*name;
  char		*comment;
  int		code_len;
  char		*code;
  int		fd;
}		t_asm;

t_asm		*asm_new(t_list *file, const int fd);
void		asm_free(t_asm *asm_datas);
void		asm_display(t_asm *asm_d, char *name_file);
void		epur_line_of_label(char *line);
int		clean_line(char *str);

/*
** Root of the asm
*/
int		asm_assamble(t_list *file, const int fd, char *name_file);

/*
** 1) fill name & comment, then remove those useless lines in (t_list *)file;
*/
int		asm_fill_extra_datas(t_asm *asm_d);

/*
** 2) count & fill len, and fill labels in the same time,
**    then remove begin of line where is a label and delete line with only a label
*/
int		asm_fill_len_and_labels(t_asm *asm_d);

/*
** 3) translate each instructions and malloc+fill asm_d->code
*/
int		asm_fill_code(t_asm *asm_d);

/*
** 4) write header+code in fd (.cor)
*/
int		asm_write(t_asm *asm_d);

#endif /* !ASM_H_ */
