/*
** my.h for libmy in /home/raphy/Developement/Libraries/libmy
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Fri Jan 25 22:14:23 2013 raphael defreitas
** Last update Sun Mar 31 01:42:51 2013 raphael defreitas
*/

#ifndef		MY_H_
# define	MY_H_

#include	<stdarg.h>

/*
** Functions parameters.
*/
#define		READ_SIZE	1024
#define		BYTES_PER_LINE	32
/*
** Files descriptors.
*/
#define		STD_INPUT	0
#define		STD_OUTPUT	1
#define		ERR_OUTPUT	2

/*
** Functions returns.
*/
#define		RET_ERROR	-1
#define		RET_SUCCESS	0
#define		RET_FAILURE	1

/*
** Numeric bases.
*/
#define		BASE_BIN	"01"
#define		BASE_OCT	"01234567"
#define		BASE_DEC	"0123456789"
#define		BASE_HEX	"0123456789abcdef"

/*
** Macros.
*/
#define		MIN(X, Y)	(((X) < (Y)) ? (X) : (Y))
#define		MAX(X, Y)	(((X) > (Y)) ? (Y) : (X))
#define		ABS(X)		(((X) < 0) ? -(X) : (X))

/*
** Declaration of the boolean type.
*/
typedef enum
  {
    FALSE = 0,
    TRUE = !FALSE,
    false = FALSE,
    true = TRUE
  }		t_bool;

/*
** Lists structures.
*/
typedef enum
  {
    LIST_LINKED,
    LIST_CIRCULAR
  }		t_list_mode;

typedef struct	s_list_item	t_list_item;
struct		s_list_item
{
  void		*data;
  int		id;
  t_list_item	*next;
  t_list_item	*previous;
};

typedef struct
{
  t_list_item	*top;
  t_list_item	*bot;
  t_list_mode	mode;
  int		next_id;
  int		length;
  void		(*data_free_fptr)();
}		t_list;

/*
** ./list functions.
** The list mode LIST_CIRCULAR not implemented yet.
*/
t_list		*my_list_new(t_list_mode mode, void (*data_free_fptr)());
void		my_list_free(t_list *list);
t_list_item	*my_list_item_new(t_list *list, void *data);
void		my_list_item_free(t_list *list, t_list_item *item);
int		my_list_enqueue(t_list *list, void *data);
int		my_list_push(t_list *list, void *data);
void		*my_list_top(t_list *list);
void		*my_list_bot(t_list *list);
int		my_list_swap(t_list_item *item1, t_list_item *item2);
int		my_list_length(t_list *list);
int		my_list_reverse(t_list *list);
void		*my_list_peek_top(t_list *list);
void		*my_list_peek_bot(t_list *list);
int		my_list_insert(t_list *list, t_list_item *ref, void *data);
int		my_list_insert_item(t_list *list, t_list_item *ref,
				    t_list_item *item);
int		my_list_delete(t_list *list, t_list_item *item);

/*
** ./memory functions.
*/
void		*my_calloc(int size);
void		*my_realloc(void *ptr, int old_size, int new_size);
int		my_memset(void *ptr, int c, int size);
int		my_memcpy(void *dest, const void *src, int size);
t_bool		my_mem_isequal(const void *ptr1, const void *ptr2, int size);
int		my_memshow(const void *ptr, int size);
int		my_memshow_n(const void *ptr, int size, int bytes_per_line);
void		*xmalloc(unsigned int size);

/*
** ./standard functions.
*/
int		my_fputchar(const int fd, int c);
int		my_putchar(int c);
int		my_fputstr(const int fd, const char *str);
int		my_putstr(const char *str);
int		my_fputnbr_base(const int fd, int nbr, const char *base);
int		my_putnbr_base(int nbr, const char *str);
int		my_fputnbr(const int fd, int nbr);
int		my_putnbr(int nbr);
int		my_getnbr_base(const char *str, const char *base);
int		my_getnbr(const char *str);
int		my_vfprintf(const int fd, const char *format, va_list *vl);
int		my_fprintf(const int fd, const char *format, ...);
int		my_printf(const char *format, ...);

/*
** ./string functions.
*/
int		my_strlen(const char *str);
char		*my_strdup(const char *str);
char		*my_strndup(const char *str, int n);
int		my_explode(char ***arr_ptr, const char *str, const char *dlm);
t_bool		my_match(const char *str, const char *pattern);
char		*my_getline(const int fd);
int		my_strpos(const char *str, const int c);
const char	*my_strchr(const char *str, const int c);
const char	*my_strstr(const char *haystack, const char *needle);
int		my_strcpy(char *dest, const char *src);
int		my_strncpy(char *dest, const char *src, int n);
int		my_strcat(char *dest, const char *src);
int		my_strncat(char *dest, const char *src, int n);
int		my_strcmp(const char *str1, const char *str2);
int		my_strncmp(const char *str1, const char *str2, int n);
t_bool		my_str_isnum(const char *str);
int             my_strclean(char *str);
int		my_revstr(char *str);

#endif /* !MY_H_ */
