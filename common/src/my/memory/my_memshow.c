/*
** my_memshow.c for libmy in /home/raphy/Developement/Libraries/libmy/memory
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Sun Jan 27 12:49:38 2013 raphael defreitas
** Last update Fri Mar  8 16:13:00 2013 barthelemy delemotte
*/

#include	<stdlib.h>
#include	"my.h"

static void	disp_offset(int);
static void	disp_hex(const unsigned char *, int, int, int);
static void	disp_ascii(const unsigned char *, int, int, int);

int		my_memshow(const void *ptr, int size)
{
  return (my_memshow_n(ptr, size, BYTES_PER_LINE));
}

int		my_memshow_n(const void *ptr, int size, int bytes_per_line)
{
  int		i;
  const unsigned char	*tmp;

  if (ptr == NULL)
    return (RET_FAILURE);
  tmp = (unsigned char *)ptr;
  my_printf("Offset\t\tHex values\t\t\t\t\t\t\t\t\t\t\t\tASCII values\n");
  i = 0;
  while (i < size)
    {
      disp_offset(i);
      disp_hex(tmp, i, size, bytes_per_line);
      disp_ascii(tmp, i, size, bytes_per_line);
      my_putchar('\n');
      i += bytes_per_line;
    }
  return (RET_SUCCESS);
}

static void	disp_ascii(const unsigned char *data, int idx, int size,
			   int bytes_per_line)
{
  int		i;

  i = 0;
  while (i < bytes_per_line && i + idx < size)
    {
      if (data[i + idx] >= ' ' && data[i + idx] <= '~')
	my_putchar(data[i + idx]);
      else
	my_putchar('.');
      i++;
    }
}

static void	disp_hex(const unsigned char *data, int idx, int size,
			 int bytes_per_line)
{
  int		i;

  i = 0;
  while (i < bytes_per_line && i + idx < size)
    {
      if (data[i + idx] <= 0xf)
	my_putchar('0');
      my_putnbr_base(data[i + idx], BASE_HEX);
      my_putchar(' ');
      i++;
    }
  while (i < bytes_per_line)
    {
      my_putstr("   ");
      i++;
    }
  my_putchar('\t');
}

static void	disp_offset(int offset)
{
  if (offset <= 0xf)
    my_putstr("0000000");
  else if (offset <= 0xff)
    my_putstr("000000");
  else if (offset <= 0xfff)
    my_putstr("00000");
  else if (offset <= 0xffff)
    my_putstr("0000");
  else if (offset <= 0xfffff)
    my_putstr("000");
  else if (offset <= 0xffffff)
    my_putstr("00");
  else if (offset <= 0xfffffff)
    my_putstr("0");
  my_putnbr_base(offset, BASE_HEX);
  my_putchar('\t');
}
