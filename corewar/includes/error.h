/*
** error.h for corewar in /home/raphy/Projects/prog_elem/corewar/corewar/includes
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Wed Jan 30 22:08:59 2013 raphael defreitas
** Last update Sun Mar 31 20:23:36 2013 barthelemy delemotte
*/

#ifndef		ERROR_H_
# define	ERROR_H_

#include	"my.h"

/*
** General errors messages
*/
#define	ERR_GENERAL		"an error has been occured"
#define	ERR_MALLOC		"inefficient memory"

/*
** Graphic errors messages
*/
#define	ERR_SDL_INIT		"cannot init SDL: %s"

/*
** Command line errors messages
*/
#define	ERR_INVALID_PARAMS	"unknown parameter"
#define	ERR_DUMP_INVALID_VAL	"invalid value for dump cycle"
#define	ERR_DUMP_NO_VAL		"no value for dump cycle"
#define	ERR_DUMP_REPEAT		"dump cycle repeated"
#define	ERR_A_NO_VAL		"no value for load address"
#define	ERR_A_INVALID_VAL	"invalid value for load address"
#define	ERR_A_REPEAT		"load_address repeated"
#define	ERR_N_NO_VAL		"no value for player id"
#define	ERR_N_INVALID_VAL	"invalid value for player id"
#define	ERR_N_REPEAT		"player id repeated"
#define	ERR_FILE_UNEXIST	"a file unexist"

/*
** Program errors messages
*/
#define	ERR_LOAD_FILE		"cannot load files datas"
#define	ERR_UNDEF_LDA		"load addresses must be all[un/.]definded"
#define	ERR_CONFLICT_DATA	" memory conflict with some programs"
#define	ERR_NO_PRGM		"there are no programs"
#define	ERR_TOO_LONG_PRGM	"memory size too small to greet all programs"
#define	ERR_INVALID_HEADER	"invalid header in a champion file"
#define	ERR_CONTENT_EMPTY	"a champion file has no instructions content"
#define	ERR_BAD_MAGIC		"bad magic code"

/*
** Input fd errors messages
*/
#define	ERR_OPEN_RD		"cannot open file in read only"
#define	ERR_READ		"cannot read file"
#define	ERR_LSEEK		"lseek has failed. File is not a regular file"
#define	WAR_CLOSE		"warning: cannot close fd"

/*
** Rules game errors messages
*/
#define	ERR_NEG_CYCLE_NBR	"corewar: a number of cycle can't be negative"

int		error_int(int code, const char *msg, ...);
void		*error_ptr(void *ptr, const char *msg, ...);
t_bool		error_bool(t_bool val, const char *msg, ...);

#endif /* !ERROR_H_ */
