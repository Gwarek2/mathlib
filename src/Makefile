# Compiler and its flags
CC              := gcc
FLAGS           := -Wall -Werror -Wextra -std=c11 -g #-fsanitize=address
TEST_FLAGS      := -lcheck -lm -lpthread
ifeq ($(shell uname -s),Linux)
	TEST_FLAGS  += -lrt -lsubunit
endif

ALL_C           := $(shell find . -name "*.c")

# Directories
LIB_DIR         := lib
TESTS_DIR       := tests
COV_DIR         := coverage_info
OBJ_DIR         := obj
COV_BUILD_DIR   := $(COV_DIR)/build
LIB_OBJ_DIR	    := $(OBJ_DIR)/$(LIB_DIR)
COV_OBJ_DIR     := $(COV_BUILD_DIR)

# Src files
LIB_SRCS        := $(LIB_DIR)/%.c
LIB_HEADER      := s21_math.h
TEST_SRCS       := $(TESTS_DIR)/*.c

# Objects and executables files
LIB_OBJS        := $(patsubst %.c,$(OBJ_DIR)/%.o,$(shell find $(LIB_DIR) -name "*.c"))
LIB_STATIC      := s21_math.a
COV_OBJS        := $(patsubst $(LIB_DIR)/%.c,$(COV_OBJ_DIR)/%.o,$(shell find $(LIB_DIR) -name "*.c"))
TEST_EXEC       := test_main
COV_EXEC        := $(COV_BUILD_DIR)/test_coverage

COV_INFO        := $(COV_DIR)/s21_math.info

.PHONY: all test gcov_report clean static_analysis

all: test gcov_report

test: $(TEST_SRCS) $(LIB_STATIC)
	$(CC) $(FLAGS) $^ $(TEST_FLAGS) -o $(TEST_EXEC)

gcov_report: $(TEST_SRCS) $(COV_OBJS)
	$(CC) $(FLAGS) --coverage $^ $(TEST_FLAGS) -o $(COV_EXEC)
	@-./$(COV_EXEC)
	@gcov -ucn $(COV_EXEC) --object-directory=$(COV_BUILD_DIR)
	@lcov -q -c -d $(COV_BUILD_DIR) --output-file $(COV_INFO) --exclude "tests/*"
	@genhtml -q $(COV_INFO) --output-directory $(COV_DIR) --function-coverage --branch-coverage

$(LIB_STATIC): $(LIB_OBJS)
	@ar -rc $@ $^
	@ranlib $@

# Compile object files for static lib
$(LIB_OBJ_DIR)/%.o: $(LIB_SRCS) $(LIB_HEADER)
	@mkdir -p $(LIB_OBJ_DIR)
	$(CC) $(FLAGS) -c $< -o $@

# Compile object files for coverage report
$(COV_OBJ_DIR)/%.o: $(LIB_SRCS) $(LIB_HEADER)
	@mkdir -p $(COV_OBJ_DIR)
	@$(CC) $(FLAGS) --coverage -c $< -o $@

# Setup cpplint and cppcheck on .c files
static_analysis:
	@-cp ../materials/linters/* .
	-python3 cpplint.py --extensions=c $(ALL_C)
	@-rm cpplint.py CPPLINT.cfg
	-cppcheck --enable=all --suppress=missingIncludeSystem $(ALL_C)

clean:
	@-rm -rf $(OBJ_DIR) $(LIB_STATIC) $(TEST_EXEC) $(COV_DIR) *.dSYM *.gcda *.gcno *.gcov
