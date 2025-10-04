SOURCE = 	parsing/get_the_token_type.c parsing/main_mini.c parsing/read_line.c parsing/is_only_space.c \
			parsing/ft_list.c  libft/ft_strncmp.c libft/ft_strchr.c libft/ft_substr.c libft/ft_strdup.c \
			parsing/expand_level.c parsing/expand_level_2.c libft/ft_isalpha.c  libft/ft_isdigit.c \
			parsing/pars_of_commands.c parsing/ft_realloc.c  libft/ft_split.c libft/ft_strlen.c \
			libft/ft_itoa.c  libft/ft_strlcat.c parsing/herdoc_utils.c libft/ft_memset.c \
			libft/ft_strlcpy.c   libft/ft_bzero.c libft/ft_strjoin.c  parsing/redic_token.c \
			parsing/handle_sig.c  parsing/case_of_expand_1.c parsing/case_of_expand_2.c \
			parsing/herdoc_utils_2.c libft/ft_putstr_fd.c builting/b_export.c \
			builting/b_cd.c builting/b_cd_2.c builting/b_env.c builting/b_exit.c \
			builting/b_pwd.c  builting/b_echo.c  builting/b_unset.c \
			builting/b_export_2.c builting/b_export_3.c libft/ft_atoi.c \
			libft/ft_lstlast_bonus.c libft/ft_lstclear_bonus.c \
			libft/ft_lstnew_bonus.c  libft/ft_lstadd_back_bonus.c \
			parsing/ft_malloc_free.c  libft/ft_lstdelone_bonus.c \
			parsing/mouadomouaad.c \
			execution/ex11_pipe.c execution/ex12_pipe.c execution/ex13_pipe.c execution/ex14_pipe.c \
			execution/ex01_execution_start.c execution/ex02_commands_counter.c \
			execution/ex03_one_command.c execution/ex05_ft_strcmp.c \
			execution/ex04_builtin_command.c execution/ex06_redirections.c \
			execution/ex07_external_command.c execution/ex08_find_path_handler.c \
			execution/ex09_signals_handler.c execution/ex10_errors_handler.c libft/ft_strtrim.c  
OBJ = $(SOURCE:.c=.o)
NAME = minishell
RM = rm -f
CC = cc
FLAGS =  -Wall -Wextra -Werror -g

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@ 

$(NAME): $(OBJ)
	$(CC) $(FLAGS)   -o   $(NAME) $(OBJ) -lreadline

all:$(NAME)

clean:
	@$(RM)  $(OBJ)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: clean  fclean  re  all
