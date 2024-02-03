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

INCLUDES := -Iinclude -Isrc -Ilibft/include -Iminilibx -I/usr/X11/include

LDFLAGS := -Llibft -Lminilibx -L/usr/X11/lib
LDLIBS := -lft -lmlx -lm -lX11 -lXext

# Flags to generate dependency files
DEPFLAGS = -MT $@ -MMD -MP -MF $(BUILD_DIR)/$*.d

SRC := src/camera/camera.c src/debug/print_config.c src/debug/print_object.c src/debug/print_vec.c src/main.c src/mlx/constructor.c src/mlx/destructor.c src/mlx/put_pixel.c src/mlx/render.c src/ray/ray.c src/scene/constructor.c src/scene/destructor.c src/scene/is_in_range.c src/scene/load_height_map.c src/scene/parse.c src/scene/parse_double.c src/scene/parse_line_each_object.c src/scene/parse_line_env.c src/scene/parse_line_object.c src/scene/parse_uint.c src/scene/parse_vec_str.c src/scene/utils.c src/tracer/calculate_diffuse.c src/tracer/calculate_specular.c src/tracer/checkers.c src/tracer/conical_bump.c src/tracer/conical_checker.c src/tracer/cylindrical_bump.c src/tracer/cylindrical_checker.c src/tracer/find_nearest_hit.c src/tracer/fix_by_axis.c src/tracer/height_map.c src/tracer/hit_circle.c src/tracer/hit_cone.c src/tracer/hit_cylinder.c src/tracer/hit_func.c src/tracer/hit_plane.c src/tracer/hit_sphere.c src/tracer/is_illuminated.c src/tracer/planar_bump.c src/tracer/quadratic.c src/tracer/ray_color.c src/tracer/render.c src/tracer/spherical_bump.c src/vector/basic_operations.c src/vector/basic_operations_scalar.c src/vector/bound.c src/vector/color.c src/vector/color_pallet.c src/vector/comparison.c src/vector/constructor.c src/vector/constructor_axis.c src/vector/getter_rgb.c src/vector/getter_vec.c src/vector/interpolate.c src/vector/operations.c src/vector/optical.c src/vector/rotate.c src/vector/utility.c
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
