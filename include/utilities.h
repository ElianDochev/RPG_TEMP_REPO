/*
** EPITECH PROJECT, 2022
** HEADER FILE
** File description:
** Header File for Utilities
*/

#ifndef UTIL_H
    #define UTIL_H

    #include <SFML/Graphics.h>
    #include <SFML/Audio.h>

    #define EXIT_ERR_EPI 84
/*###########################################################################
######################BEGINING OF STANDERED UTIL FUNCTIONS###################
#############################################################################*/
//this is 4096 bytes or 4 KB
    #define BUFF_SIZE 1 << 12
//gives the alsolute value
    #define ABS(x) (x < 0 ? -x : x)
//returns the smallest value
    #define MIN(x, y) (x < y ? x : y)
//displays an error msg
void error (char *str);
//retuns the lenght of a str
int my_strlen(char const *str);
//copies one string to another
void str_copy(char *dest, char *scr);
//duplicates a string (malloces)
char *str_dup(char *scr);
//sets a buff to '\0'
void empty_buffer(char *str, int size);
//calculates the power of a int number rec
int calc_pow(int nb, int p);
//converts an int to str (handles negatives)
char *int_to_str(sfInt32 scr);
//compares two strings
int str_cmp(char const *str_one, char const *str_two);
//joins two string into one (mallocs) and frees the second one
char *str_join_free(char const *str_one, char *str_two);
//joins two string into one (mallocs)
char *str_join(char const *str_one, char *str_two);
//makes it so it frees a ptr and sets it to NULL if already NULL do nothing
void xfree(void **ptr);
//retuns the lenght of 2d array
int two_d_arr_len(char **arr);
/*###########################################################################
#######################END OF STANDERED UTIL FUNCTIONS#######################
-----------------------------------------------------------------------------*/


/*###########################################################################
#######################BEGINING OF MASK STUFF SEGMENT########################
#############################################################################*/
    #define CHK_FLAG(mask, flag) (mask & flag)
    #define SET_FLAG(mask, flag) (mask |= flag)
    #define UNSET_FLAG(mask, flag) (mask &= ~flag)
    #define TOGGLE_FLAG(mask, flag) (mask ^= flag)

/*###########################################################################
#######################END OF MASK STUFF SEGEMENT############################
-----------------------------------------------------------------------------*/


/*###########################################################################
######################BEGINING OF SUPPORT FUNCS##############################
#############################################################################*/
//splits a string into an word array ending in null using a callback
//(return 1 if it is a sep otherwise return 0)
char **split_str(char *scr, int (*sep)(char));
//finds if the string is in a word_array return 0 on success
//and then gives the rest until it reaches the end returns 1 on falier
int str_in_word_arr(char *dest, char **word_arr, char *sub_arr);
//gives a buffer with size BUFF_SIZE from file,
//displays the err msg to sdterr on failaire
char *fopen_file(char *path, char *err_msg);
//compares two strings up to a given length or untill the end of one
int str_ncmp(char const *str_one, char const *str_two, int length);
//gets the length of a null termiated 2d string
int get_len_two_d(char **w_arr);
//this returns 1 if the ch == '\n' otherwise retuns 0
int split_endl(char ch);
//nulls a static buffer
void null_buff (char *buff, int size);
/*###########################################################################
#######################END OF SUPPORT FUNCS##################################
-----------------------------------------------------------------------------*/


/*###########################################################################
##########BEGINING OF VECTOR CREATOR, COMPARE AND CONVERT FUNCS##############
#############################################################################*/
//creates a int rect for some functions
sfIntRect create_int_rect(int left, int top, int height, int wight);
//creates a float rect
sfFloatRect create_float_rect(float left, float top,
float heigth, float width);
//coverts an int rect to a float one
sfFloatRect convert_from_int_rect(sfIntRect rect);
//coverts an float rect to an int one
sfIntRect convert_from_floar_rect(sfFloatRect rect);
//creates a float vector
sfVector2f create_fvector(float x, float y);
//creates an unsinded int vector
sfVector2u create_uvector(unsigned int x, unsigned int y);
//creates an int vector
sfVector2i create_ivector(int x, int y);
//converts a int vector to a float vector
sfVector2f con_vi_to_vf(sfVector2i vector);
//covernts an unsigned int vector to a float one
sfVector2f con_vu_to_vf(sfVector2u vector);
//compares vectors of type float
int comp_fvector(sfVector2f *vect_one, sfVector2f *vect_two);
//compares vectors of type int
int comp_ivector(sfVector2i *vect_one, sfVector2i *vect_two);
//compares vectors of type unsigned int
int comp_uvector(sfVector2u *vect_one, sfVector2u *vect_two);
/*###########################################################################
#########################END OF VECTORS######################################
-----------------------------------------------------------------------------*/



/*###########################################################################
#########################BEGINING OF LIST####################################
#############################################################################*/
//struct for list
typedef struct list {
    void *value;
    struct list *next;
} node_t;
/*incerts a node in the list give the pointer + the type
the item_type are 0 for background, 1 for player NOTE: more will be added later*/
node_t *list_incert(node_t *list, void *value);
//starts from 0 peeks the node fron the list at the specified index
node_t *peek_index(node_t *list, int index);
//destroys the list but not the eles whitin it
void destroy_list(node_t **list);
/*###########################################################################
#########################END OF LIST#########################################
-----------------------------------------------------------------------------*/
#endif
