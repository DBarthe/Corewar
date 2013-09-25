/*
** params.h for vm - corewar in /home/delemo_b/epitech_1/corewar/corewar/includes
** 
** Made by barthelemy delemotte
** Login   <delemo_b@epitech.net>
** 
** Started on  Mon Jan 28 16:27:21 2013 barthelemy delemotte
** Last update Sun Mar 31 20:38:30 2013 barthelemy delemotte
*/

#ifndef		PARAMS_H_
# define	PARAMS_H_

#include	"params_types.h"

t_params	*params_new(void);
void		params_free(t_params *params);
int		params_init(t_params *params, int argc, const char **argv);
int		params_get_dump_cycle(int argc, const char **argv);
int		params_get_files(t_list *programs, int argc,
				 const char **argv);
int		params_check_double_id(t_params *params);

#endif /* !PARAMS_H_ */
