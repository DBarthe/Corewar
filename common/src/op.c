/*
** op.c for corewar in /home/delemo_b/epitech_1/corewar/vm/src
** 
** Made by barthelemy delemotte
** Login   <delemo_b@epitech.net>
** 
** Started on  Wed Jan 23 17:23:51 2013 barthelemy delemotte
** Last update Thu Mar 21 19:20:21 2013 marie lefebvre
*/

/*
** Ne pas passer ce fichier dans la moulinette de Norme. ?
*/

#include	"op.h"

t_op		op_tab[] =
  {
    {"live",	1,	{T_DIR},		1,	10,	"alive"		},
    {"ld",	2,	{T_DIR | T_IND, T_REG},	2,	5,	"load"		},
    {"st",	2,	{T_REG, T_IND | T_REG},	3,	5,	"store"		},
    {"add",	3,	{T_REG, T_REG, T_REG},	4,	10,	"addition"	},
    {"sub",	3,	{T_REG, T_REG, T_REG},	5,	10,	"soustraction"	},
    {"and",	3,	{T_REG | T_DIR | T_IND,
			 T_REG | T_IND | T_DIR,
			 T_REG},		6,	6,	"bin and"	},
    {"or",	3,	{T_REG | T_IND | T_DIR,
			 T_REG | T_IND | T_DIR,
			 T_REG},		7,	6,	"bin or"	},
    {"xor",	3,	{T_REG | T_IND | T_DIR,
			 T_REG | T_IND | T_DIR,
			 T_REG},		8,	6,	"bin xor"	},
    {"zjmp",	1,	{T_DIR},		9,	20,	"jump if zero"	},
    {"ldi",	3,	{T_REG | T_DIR | T_IND,
			 T_DIR | T_REG, T_REG},	10,	25,	"load index"	},
    {"sti",	3,	{T_REG,
			 T_REG | T_DIR | T_IND,
			 T_DIR | T_REG},	11,	25,	"store index"	},
    {"fork",	1,	{T_DIR},		12,	800,	"fork"		},
    {"lld",	2,	{T_DIR | T_IND, T_REG},	13,	10,	"long load"	},
    {"lldi",	3,	{T_REG | T_DIR | T_IND,
			 T_DIR | T_REG, T_REG},	14,	50,	"long load idx"	},
    {"lfork",	1,	{T_DIR},		15,	1000,	"long fork"	},
    {"aff",	1,	{T_REG},		16,	2,	"aff"		},
    {0,		0,	{0},			0,	0,	0		}
  };
