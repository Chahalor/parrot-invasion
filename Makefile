NAME_INTERFACE	:= interface
NAME_INVASION	:= invasion

CC			:= cc
CFLAGS		:= -Wall -Wextra -Werror -Iincludes -g3

_DIR_OBJ		:= .build
_DIR_SRC		:= src
_DIR_BIN		:= bin
_DIR_INC		= includes

_SRC_INTERFACE	:= $(_DIR_SRC)/interface.c $(_DIR_SRC)/mains/main_interface.c
_SRC_INVASION	:= $(_DIR_SRC)/invasion.c $(_DIR_SRC)/mains/main_invasion.c
_SRC_RAID		:= $(_DIR_SRC)/raid.c

_OBJ_INTERFACE	:= $(patsubst $(_DIR_SRC)/%.c,$(_DIR_OBJ)/%.o,$(_SRC_INTERFACE))
_OBJ_INVASION	:= $(patsubst $(_DIR_SRC)/%.c,$(_DIR_OBJ)/%.o,$(_SRC_INVASION))
_OBJ_RAID		:= $(_DIR_OBJ)/raid.o

all: $(NAME_INTERFACE) $(NAME_INVASION)

$(NAME_INTERFACE): $(_OBJ_RAID) $(_OBJ_INTERFACE)
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -o $(_DIR_BIN)/$@ $^

$(NAME_INVASION): $(_OBJ_RAID) $(_OBJ_INVASION)
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -o $(_DIR_BIN)/$@ $^
	xxd -i $(_DIR_BIN)/$@ invasion.h

$(_DIR_OBJ)/%.o: $(_DIR_SRC)/%.c
	mkdir -p $(_DIR_OBJ)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(_DIR_OBJ)/*.o

fclean: clean
	rm -rf $(_DIR_BIN)
	rm -rf $(_DIR_OBJ)

re: fclean all