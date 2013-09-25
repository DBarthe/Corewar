/*
** parser.h for corewar in /home/sauval_d//corewar/asm/includes
** 
** Made by damien sauvalle
** Login   <sauval_d@epitech.net>
** 
** Started on  Fri Feb  1 13:45:32 2013 damien sauvalle
** Last update Sat Mar 30 16:57:32 2013 damien sauvalle
*/

#ifndef		PARSER_H_
# define	PARSER_H_

#include	"my.h"

t_list		*recovery(char *av);
int		remove_comment(t_list *file);

#endif /* !PARSER_H */
