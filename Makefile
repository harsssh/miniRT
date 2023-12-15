NAME := miniRT

SRC_DIR := src
BUILD_DIR := build

LIBFT := libft/libft.a
LIBMLX := minilibx/libmlx.a

CFLAGS := -Wall -Wextra -Werror

# Flags for release build (optimizations enabled)
RELEASE_FLAGS := -O3
# Flags for debug build (no optimizations, with sanitizer)
DEBUG_FLAGS := -g -O0 -fsanitize=address

INCLUDES := -Iinclude -Isrc -Ilibft/include -Iminilibx

LDFLAGS := -Llibft -Lminilibx
LDLIBS := -lft -lmlx -lm

# Flags to generate dependency files
DEPFLAGS = -MT $@ -MMD -MP -MF $(BUILD_DIR)/$*.d

SRC := $(shell find $(SRC_DIR) -name '*.c')
OBJ := $(patsubst $(SRC_DIR)/%.c,$(BUILD_DIR)/%.o,$(SRC))
DEP := $(patsubst $(SRC_DIR)/%.c,$(BUILD_DIR)/%.d,$(SRC))

.PHONY: all
all: CFLAGS+=$(RELEASE_FLAGS)
all: $(NAME)

.PHONY: debug
debug: CFLAGS+=$(DEBUG_FLAGS)
debug: $(NAME)

.PHONY: bonus
bonus: all

$(NAME): $(LIBFT) $(LIBMLX) $(OBJ)
	$(CC) $(CFLAGS) $(INCLUDES) $(LDFLAGS) -o $@ $^ $(LDLIBS)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	-@mkdir -p $(@D)
	$(CC) $(CFLAGS) $(INCLUDES) $(DEPFLAGS) -c -o $@ $<

$(LIBFT):
	@make -C libft

$(LIBMLX):
	-@git submodule update --init
	-make -C minilibx

.PHONY: clean
clean:
	-@make -C libft clean
	-@make -C minilibx clean
	-$(RM) $(OBJ) $(DEP)

.PHONY: fclean
fclean: clean
	-@make -C libft fclean
	-$(RM) $(NAME)

.PHONY: re
re: fclean all

-include $(DEP)
