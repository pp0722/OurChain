#ifndef BITCOIN_CONTRACT_OURCONTRACT_H
#define BITCOIN_CONTRACT_OURCONTRACT_H

#define BYTE_READ_STATE 0
#define BYTE_SEND_TO_ADDRESS -1
#define BYTE_SEND_TO_CONTRACT -2
#define BYTE_CALL_CONTRACT -3

#include <stdint.h>
#include <stdbool.h>

/* non-reentrant entry point of runtime */
int start_runtime(int argc, char **argv);

/* contract call can be nested */
int call_contract(const char *contract, int argc, char **argv);

/* print to runtime error log */
int err_printf(char *str, ...);

/* wrapper around snprintf */
int str_printf(char *str, unsigned size, const char *format, ...);

/* wrapper around strncmp */
int str_cmp(const char *s1, const char *s2, int n);

/* print to contract output */
// int out_printf(const char *format, ...);

/* clear contract output */
// int out_clear(void);

/* read the state file of the calling contract */
int state_read(void *buf, int count);

/* write the state file of the calling contract */
int state_write(const void *buf, int count);

#endif // BITCOIN_CONTRACT_OURCONTRACT_H
