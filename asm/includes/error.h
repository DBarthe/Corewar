/*
** error.h for corewar in /home/lefebv_z//projet/c-prog-elem/corewar/asm
** 
** Made by marie lefebvre
** Login   <lefebv_z@epitech.net>
** 
** Started on  Thu Mar 21 14:28:28 2013 marie lefebvre
** Last update Thu Mar 21 18:38:42 2013 marie lefebvre
*/

#ifndef		ERROR_H_
# define	ERROR_H_

#define		ERROR_MALLOC	"Could not alloc\n"

void		*error_ptr(char *);
int		error_int(char *);
int		v_error_int(char *, int);

#endif	/* !ERROR_H_ */
