#include "./virtual.h"

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <openssl/md5.h>


#define calloc(LENGTH,SIZE) LENGTH ? calloc(LENGTH, SIZE) : NULL;

typedef struct{
    char board_hash[MD5_DIGEST_LENGTH];
    int* analog_pins;
    int* digital_pins;
    int* serial_modules;
    int* can_modules;
}virtualBoard_t;

//private

static uint8_t create_ph_file(const char* ph_name, int* o_fd)
{
    int fd = open(ph_name, O_CREAT | O_WRONLY , 0644);
    if (fd < 0) {
        return EXIT_FAILURE;
    }

    *o_fd = fd;
    return EXIT_SUCCESS;
}

static int create_pheripherals(const char* board_hash, int *ph_list_fd,
        const uint8_t list_lengt, const char *name)
{
    ph_list_fd = calloc(list_lengt, sizeof(int));
    if (!ph_list_fd) {
        goto exit;
    }

    const char* analog_pins_dir = name;
    if (mkdir(analog_pins_dir, 0755) < 0) {
        fprintf(stderr, "error creating directory %s \n", analog_pins_dir);
        goto fail;
    }

    if(chdir(analog_pins_dir)){
        fprintf(stderr, "error entering %s directory\n",analog_pins_dir);
        goto fail;
    }
    
    const char* separator = SEPARATOR;
    const uint8_t name_len = strlen(name);
    for (uint8_t i=0; i< list_lengt; i++) {
        char ph_name[1024] = {};
        memcpy(ph_name, board_hash, MD5_DIGEST_LENGTH);
        ph_name[MD5_DIGEST_LENGTH] = '_';
        memcpy(&ph_name[MD5_DIGEST_LENGTH+1], name, name_len);
        ph_name[MD5_DIGEST_LENGTH + 1 + name_len] = '_';
        sprintf(&ph_name[MD5_DIGEST_LENGTH + 1 + name_len + 1], "%d", i);
        if (create_ph_file(ph_name, ph_list_fd)){
            fprintf(stderr, "failed creating ph file for: %s\n", ph_name);
            goto fail;
        }
    }
    chdir("..");
    
exit:
    return EXIT_SUCCESS;
fail:
    return EXIT_FAILURE;;
}

//public
virtualBoard* virtual_board_init(const char* board_hash, const boardSpecs* board_spec)
{
    if (!board_hash || !board_spec) {
        return NULL;
    }

    const char* dir = PH_ROOT_DIR;
    if(mkdir(dir, 0755) < 0){
        fprintf(stderr, "error creating pheripherals directory\n");
        return NULL;
    }

    if(chdir(dir)){
        fprintf(stderr, "error entering pheripherals directory\n");
        return NULL;
    }

    virtualBoard_t *res = calloc(1, sizeof(*res));
    if( 
            create_pheripherals(board_hash,res->analog_pins, board_spec->analog_pins, ANALOG_PINS) ||
            create_pheripherals(board_hash,res->digital_pins, board_spec->digital_pins, DIGITAL_PINS) ||
            create_pheripherals(board_hash,res->serial_modules, board_spec->serial_modules, SERIAL_MODULES) ||
            create_pheripherals(board_hash,res->can_modules, board_spec->can_modules, CAN_MODULES)
      ){
        return NULL;
    }

    return res;
}

void virtual_board_free(virtualBoard* board)
{
    free(board);
}
