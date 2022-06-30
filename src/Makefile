# Compiler and its flags
CC              := gcc
FLAGS           := -Wall -Werror -Wextra -std=c11 -g #-fsanitize=address
INC_DIRS        := -I.
TEST_FLAGS      := -lcheck -lm -lpthread
COV_FLAGS       := --coverage
ifeq ($(shell uname -s),Linux)
	TEST_FLAGS  += -lrt -lsubunit
endif

LINT_DIR        := $(wildcard ../materials/linters/*)
LINT_FILES      := cpplint.py CPPLINT.cfg 
LINT_EXEC       := python3 cpplint.py --extensions=c
CPPC_EXEC       := cppcheck --enable=all --suppress=missingIncludeSystem 

ALL_C           := $(shell find . -name "*.c")

LIB_DIR         := lib/
TESTS_DIR       := tests/
COV_DIR         := coverage_info/
OBJ_DIR         := obj/
LIB_OBJ_DIR     := $(OBJ_DIR)$(LIB_DIR)
COV_OBJ_DIR     := $(COV_DIR)$(OBJ_DIR)

LIB_HEADER      := s21_math.h
LIB_SRCS        := $(addprefix $(LIB_DIR),s21_abs.c \
                                          s21_acos.c \
                                          s21_asin.c \
                                          s21_atan.c \
                                          s21_ceil.c \
                                          s21_cos.c \
                                          s21_exp.c \
                                          s21_fabs.c \
                                          s21_floor.c \
                                          s21_fmod.c \
                                          s21_log.c \
                                          s21_pow.c \
                                          s21_sin.c \
                                          s21_sqrt.c \
                                          s21_tan.c \
                                          s21_trunc.c)
TEST_SRCS       := $(addprefix $(TESTS_DIR),s21_abs_test.c \
                                            s21_acos_test.c \
                                            s21_asin_test.c \
                                            s21_atan_test.c \
                                            s21_ceil_test.c \
                                            s21_cos_test.c \
                                            s21_exp_test.c \
                                            s21_fabs_test.c \
                                            s21_floor_test.c \
                                            s21_fmod_test.c \
                                            s21_log_test.c \
                                            s21_pow_test.c \
                                            s21_sin_test.c \
                                            s21_sqrt_test.c \
                                            s21_tan_test.c \
                                            s21_trunc_test.c \
                                            test_main.c)

LIB_OBJS        := $(patsubst %.c,\
                              $(OBJ_DIR)%.o,\
                              $(LIB_SRCS))
COV_OBJS        := $(patsubst %.c,\
                              $(COV_OBJ_DIR)%.o,\
                              $(LIB_SRCS))

LIB_STATIC      := s21_math.a
TEST_EXEC       := test_main
COV_EXEC        := $(COV_DIR)test_cov

COV_INFO        := $(COV_DIR)s21_math.info
COV_REPORT      := $(COV_DIR)lib/index.html

vpath %.c $(LIB_DIR)

.PHONY: all test gcov_report clean static_analysis

all: test gcov_report

test: $(TEST_SRCS) $(LIB_STATIC)
	$(CC) $(FLAGS) $(INC_DIRS) $^ $(TEST_FLAGS) -o $(TEST_EXEC)
	./$(TEST_EXEC)

gcov_report: $(TEST_SRCS) $(COV_OBJS)
	$(CC) $(FLAGS) $(INC_DIRS) $(COV_FLAGS) $^ $(TEST_FLAGS) -o $(COV_EXEC)
	@-./$(COV_EXEC)
	@gcov -f $(COV_EXEC) -o $(COV_DIR)
	@lcov -q -c -d $(COV_DIR) -o $(COV_INFO) --exclude "$(TESTS_DIR)*"
	@genhtml -q $(COV_INFO) -o $(COV_DIR)
	@open $(COV_REPORT)

$(LIB_STATIC): $(LIB_OBJS)
	@ar -rc $@ $^
	@ranlib $@

# Compile object files for static lib
$(LIB_OBJ_DIR)%.o: %.c $(LIB_HEADER)
	@mkdir -p $(LIB_OBJ_DIR)
	$(CC) $(FLAGS) $(INC_DIRS) -c $< -o $@

# Compile object files for coverage report
$(COV_OBJ_DIR)%.o: %.c $(LIB_HEADER)
	@mkdir -p $(COV_OBJ_DIR)$(LIB_DIR)
	@$(CC) $(FLAGS) $(INC_DIRS) $(COV_FLAGS) -c $< -o $@

static_check:
	@-cp $(LINT_SRC) .
	-$(LINT_EXEC) $(ALL_C)
	@-rm $(LINT_FILES)
	-$(CPPC_EXEC) $(ALL_C)

clean:
	@-rm -rf $(OBJ_DIR) $(LIB_STATIC) $(TEST_EXEC) $(COV_DIR)\
		     *.dSYM *.gcda *.gcno *.gcov
