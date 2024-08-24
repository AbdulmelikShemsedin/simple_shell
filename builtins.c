#include "main.h"

BuiltinCommands init_builtins() {
static char *builtin_str[] = {
"cd",
"help",
"exit"
};

static int (*builtin_func[])(char **) = {
&lsh_cd,
&lsh_help,
&lsh_exit
};

BuiltinCommands commands = {builtin_str, builtin_func, 3};
return commands;
}
