/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ande-sou <ande-sou@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 13:48:47 by ande-sou          #+#    #+#             */
/*   Updated: 2021/03/12 13:48:47 by ande-sou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
#include <stdint.h>
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdint.h>
# include <stdio.h>
# include <limits.h>

typedef struct s_flags
{
    int         already_prynt;
    int         type;
    int         minus;
    int         zero;
    int         dot;
    int         star;
    int         spacesleft;
    int         spacesright;
    int         size_of_dot;
    int         size_of_zero;
    char		l;
	char		h;
    char		ll;
	char		hh;
    int			wprint;
    int         hash;
    int         neg;
}               t_flags;

t_flags     ft_init_flags(void);
int         ft_putchar(char c);
void	    ft_putnbr(intmax_t nb);
void        ft_putstr(char *str);
void        ft_putstrl(char *str, int len);
void	    ft_putnbrui(unsigned int nb);
int		    ft_is_in_type_list(int c);
t_flags	    ft_minus(t_flags flags);
t_flags	    ft_dot(t_flags flags);
int         from_str_to_num(char str, int current_num);
int         getNextParam(va_list *arg_ptr_, int current_num);
int         ft_flags(const char *save, int i, t_flags *flags, va_list *arg_ptr_);
int         ft_putspaces(int spaces, char c, int len, int neg);
int        ft_putzero(int zero, char c, int len);
int        ft_put_args(const char *save, va_list *arg_ptr);
int	       ft_printf(const char *input, ...);
char	   *ft_memcpy(char *dst, const char *src, size_t n);
int        ft_strlen(const char *str);
char	   *ft_strdup(const char *s1);
int         apply2Nums(int num1, int num2);
int         ft_printc(char c, va_list *arg_ptr, t_flags *flags);
int         ft_printdi(char c, va_list *arg_ptr, t_flags *flags);
int         ft_prints(char c, va_list *arg_ptr, t_flags *flags);
int         ft_printu(char c, va_list *arg_ptr, t_flags *flags);
int         ft_printx(char c, va_list *arg_ptr, t_flags *flags);
int         ft_printp(char c, va_list *arg_ptr, t_flags *flags);
int         ft_print_ls(const char *save, va_list *arg_ptr, t_flags *flags);
t_flags     ft_length_modifiers(const char *save, int i, t_flags flags);
int         ft_printn(va_list *arg_ptr_, t_flags *flags, intmax_t count);
int     	ft_putwchar(wchar_t c,  t_flags *flags);
int     	ft_print_wchars( t_flags *flags, size_t size, unsigned char str[4]);
int	    	ft_wcharlen(wchar_t c);
void        ft_putnbr_base(unsigned long nbr, char *base, va_list nb);
int         ft_flagsd(char c, t_flags *flags, int len, intmax_t aux1);
int         ft_flagsld(t_flags *flags, int len);
int	ft_flagsx(char c, t_flags *flags, int len);
int	ft_flagslx(t_flags *flags, int len);

#endif
