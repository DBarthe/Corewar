/*
** op.h for corewar in /home/delemo_b/epitech_1/corewar/vm/includes
** 
** Made by barthelemy delemotte
** Login   <delemo_b@epitech.net>
** 
** Started on  Wed Jan 23 16:58:01 2013 barthelemy delemotte
** Last update Fri Apr  5 15:35:09 2013 barthelemy delemotte
*/

#ifndef		OP_H_
# define	OP_H_

/*
** Some rules define ...
*/
#define		MEM_SIZE		(8 * 1024 + 717)
#define		IDX_MOD			512
#define		MAX_ARGS_NUMBER		4
#define		REG_NUMBER		16

/*
** Define asm's syntax
*/
#define		COMMENT_CHAR		'#'
#define		LABEL_CHAR		':'
#define		DIRECT_CHAR		'%'
#define		SEPARATOR_CHAR		','
#define		LABEL_CHARS		"abcdefghijklmnopqrstuvwxyz_0123456789"
#define		NAME_CMD_STRING		".name"
#define		COMMENT_CMD_STRING	".comment"

/*
** enum mask/flag for args types
*/
typedef	char	t_args_type;

enum
  {
    T_REG	=	0x01,
    T_DIR	=	0x02,
    T_IND	=	0x04,
    T_LAB	=	0x08
  };

/*
** operator structure and typedef
** Global tab op[]
*/
typedef struct	s_op
{
  char		*mnemonique;
  char		nbr_args;
  t_args_type	type[MAX_ARGS_NUMBER];
  char		code;
  int		nbr_cycles;
  char		*comment;
}		t_op;

extern	t_op	op_tab[];

/*
** size for memory access
*/
#define		IND_SIZE		2
#define		REG_SIZE		4
#define		DIR_SIZE		REG_SIZE

/*
** param octet codage 
*/
enum
  {
    POC_REG	=	1,
    POC_DIR	=	2,
    POC_IND	=	3
  };

/*
** Header for executable ".cor"
*/
#define		COREWAR_EXEC_MAGIC	"\x00\xea\x83\xf3"
#define		MAGIC_LEN		4
#define		PROG_NAME_LENGTH	128
#define		SIZE_CONTENT_LENGTH	8
#define		COMMENT_LENGTH		2048

typedef struct	s_header
{
  int		magic;
  char		prog_name[PROG_NAME_LENGTH + 1];
  int		prog_size;
  char		comment[COMMENT_LENGTH + 1];
}		t_header;

/*
** Defines for cycle informations ...
*/
#define		CYCLE_TO_DIE		1536
#define		CYCLE_DELTA		5
#define		NBR_LIVE		40

t_op		*op_get_by_opcode(const char opcode);
t_op		*op_get_by_mnemonique(const char *mne);

#endif /* !OP_H_ */
