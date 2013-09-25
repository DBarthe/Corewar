/*
** my_explode.c for libmy in /home/raphy/Developement/Libraries/libmy/string
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Sat Jan 26 21:21:59 2013 raphael defreitas
** Last update Wed Jan 30 22:46:30 2013 raphael defreitas
*/

#include	<stdlib.h>
#include	"my.h"

static int	get_size(const char *, const char *);
static void	fill(char **, char *, const char *);

int		my_explode(char ***arr_ptr, const char *str, const char *dlm)
{
  int		size;
  char		*str_cpy;

  if (str == NULL)
    return (RET_ERROR);
  size = get_size(str, dlm);
  *arr_ptr = malloc((size + 1) * sizeof(char *)
		 + (my_strlen(str) + 1) * sizeof(char));
  if (*arr_ptr == NULL)
    return (RET_ERROR);
  str_cpy = ((char *)(*arr_ptr) + (size + 1) * sizeof(char *));
  my_strcpy(str_cpy, str);
  fill(*arr_ptr, str_cpy, dlm);
  (*arr_ptr)[size] = NULL;
  return (size);
}

static void	fill(char **arr, char *str, const char *dlm)
{
  int		i;
  int		j;

  j = 0;
  i = 0;
  while (str[i] && my_strpos(dlm, str[i]) != RET_ERROR)
    i++;
  while (str[i])
    {
      arr[j] = str + i * sizeof(char);
      j++;
      while (str[i] && my_strpos(dlm, str[i]) == RET_ERROR)
	i++;
      while (str[i] && my_strpos(dlm, str[i]) != RET_ERROR)
	{
	  str[i] = '\0';
	  i++;
	}
    }
}

static int	get_size(const char *str, const char *dlm)
{
  int		i;
  int		size;

  size = 0;
  i = 0;
  while (str[i] && my_strpos(dlm, str[i]) != RET_ERROR)
    i++;
  while (str[i])
    {
      while (str[i] && my_strpos(dlm, str[i]) == RET_ERROR)
	i++;
      size++;
      while (str[i] && my_strpos(dlm, str[i]) != RET_ERROR)
	i++;
    }
  return (size);
}
