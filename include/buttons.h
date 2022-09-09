/*
** EPITECH PROJECT, 2022
** MyDefender
** File description:
** button test .h
*/

#ifndef BUTTONS_H_
    #define BUTTONS_H_

    #include "sprites.h"

typedef enum{idle_bn, on_click, on_hover} button_state;
typedef struct button_s
{
    sfTexture *texture;
    sfSprite *button_shape;
    sfFloatRect hitbox;
    sfIntRect print_rect;
    void (*ptr)(void *value);
} button_t;



/*###########################################################################
######################BEGINING OF TEXT BOTTONS SEGMENT#######################
#############################################################################*/
//text button obj;
typedef struct {
    text_t *text;
    sfFloatRect hitbox;
    sfVector2f location;
    sfColor bn_color[on_hover + 1];
    void (*ptr)(void *value, int index);
} button_text_t;

//contains the location, colors ,offset and font size of the button
typedef struct {
    sfVector2f location;
    void *bn_color[on_hover + 1];
    sfVector2f offset;
    int font_size;
    char is_for_single_use;
} button_text_info_t;

//checks if the mouse is on the text button location
int is_mouse_on_btext(button_text_t *button, sfRenderWindow *window);
////////////////////////////////////////////////////////////
/// \brief creates a text button
///
/// \param info    contains the location, colors ,offset and font
///                size of the button (offset is ignored here)
/// \param ptr     the function that will be called when the button is
///                clicked (parameter will be type cast in the function itself)
///                and the index of the button will be passed as a sec parameter
/// \param font    pointer to a font object
/// \param msg     string that will be displayed on the button
///
/// \return malloced button_text_t
///
///////////////////////////////////////////////////////////
button_text_t *init_button_text(button_text_info_t *info, void(*ptr)(void *,
int), sfFont *font, char *msg);
//destroys a text button
void destroy_button_text(button_text_t *button, int mask);
//changes the color of a text botton
void change_bntxt_color(button_text_t *button, button_state state);
////////////////////////////////////////////////////////////
/// \brief sets up the additional info needed for the text button
///
/// \param location   the location of the fist element for text button
/// \param color      an array of 3 colors casted as a void pointer
///                   0 - idle, 1 - on_click, 2 - on_hover takes const
/// \param offset     the offset between the different elements
///                   (can be negative) ignored for the first button
/// \param font_size  the size of the font for the buttons
///
/// \return malloced button_text_info_t that contains all of the parameters
///
///////////////////////////////////////////////////////////
button_text_info_t *init_button_text_info(sfVector2f location,
void const  **color, sfVector2f offset, int font_size);
////////////////////////////////////////////////////////////
/// \brief Makes an array of buttons pixels appart each
///
/// \param font     takes a pointer to a font
/// \param info     takes a pointer to a button_text_info_t innitilized
/// \param msg_arr  2d Array of the text for the options ending on a NULL
/// \param ptr      an array of function pointers should be the same len
///                 as msg array (first args is element , second is index)
/// \return an array of text bottons ending on a NULL
///
///////////////////////////////////////////////////////////
button_text_t **set_up_menu_bntext(sfFont *font, button_text_info_t *info,
char **msg_arr, void (*ptr[])(void *, int));
////////////////////////////////////////////////////////////
/// \brief draws the menu of text buttons with a specified offset from
/// eachohter
///
/// \param menu     pointer to the menu object already innited DO NOT PASS NULL
/// \param window   Render window object
/// \param arg    the parameter that will be passed to the function
///  for the first and the last button
/// \param arg_two  the parameter that will be passed to the function
///  for the second and the second to last button
///////////////////////////////////////////////////////////
void draw_menu_bntext(button_text_t **menu , sfRenderWindow *window,
void *arg, void *arg_two);
void destroy_menu_bntext(button_text_t **menu, int mask);
//returns 1 if the mouse is on the botton and 0 if it not
int is_mouse_on_btext(button_text_t *button, sfRenderWindow *window);
//loops thoug a menu and passes the state obj to the func pointer
// void loop_menu(button_text_t *botton, states *state, sfEvent event,
// sfRenderWindow *window);
////////////////////////////////////////////////////////////
/// \brief func used in a loop for the menu dispay in a evevent loop
///
/// \param button     the button to be operated on
/// \param element    thing that will be passed to the button func
///                   typecast must be done in the func itself
/// \param window     the window to be passed to the button func
/// \param index      the index of the button in the menu
///
///////////////////////////////////////////////////////////
void loop_menu(button_text_t *botton, void *element,
sfRenderWindow *window, int index);
/*###########################################################################
#######################END OF TEXT BOTTONS SEGMENT###########################
-----------------------------------------------------------------------------*/

/*###########################################################################
######################BEGINING OF SLIDER_BUTTON SEGMENT######################
#############################################################################*/
//struct that contains the info for the txt part of the slider
// use the init_slider_text_info to innitilize it
typedef struct {
    sfColor txt_color;
    int font_size;
    sfFont *font;
    char *msg;
} slider_info_text_t;

//struct that contains the info for the slider part of the slider
// use the init_slider_info to innitilize it
typedef struct {
    void **colors;
    sfVector2f offset;
    sfVector2f size;
    sfVector2f o_thick;
} slider_info_slide_t;

//slider object
typedef struct {
    text_t *text;
    sfFloatRect hitbox;
    void (*func_ptr)(void *arg, float percent);
    sfRectangleShape *slider;
    sfCircleShape *knob;
} slider_t;


////////////////////////////////////////////////////////////
/// \brief info for the text part of slider object
///
/// \param color      the color of the text
/// \param font_size  the size of the font the part
/// \param font       pointer to a font object (you can init it here)
/// but you must call destroy_slider whit DESTROY_FONT in the mask
/// \param msg        string that will be displayed on the slider
///
/// \return  returns info for the text part of slider object
///
///////////////////////////////////////////////////////////
slider_info_text_t set_up_slider_text(sfColor color, int font_size,
sfFont *font, char *msg);
////////////////////////////////////////////////////////////
/// \brief info for the slider part of slider object
///
/// \param colors     an array of sfColors of 2 , 3 or 4 colors casted as a void pointer
/// 0 - color for the bar(requered), 1 - color for cicle(required),
/// 2 - color for bar outline(put NULL for none),
/// 3 - color for cicle outline(put NULL for none)
/// \param offset     the distance between the text and the slider
/// \param size        the dimenteions of the slider and the cicle
/// \param o_thikness  the thinkness of the outline x - bar, y - cicle
/// put 0 for no change
///
/// \return returns info for the slider part of slider object
///
///////////////////////////////////////////////////////////
slider_info_slide_t set_up_slider_slide(void **colors, sfVector2f offset,
sfVector2f size, sfVector2f o_thick);
////////////////////////////////////////////////////////////
/// \brief innitilizes a slider object
///
/// \param text_info     info for the text part of slider object
/// \param slide_info    info for the slider part of slider object
/// \param func_ptr      function pointer that will be called when the slider
///                      is moved
/// \param location      initial location of the slider (starts with the text)
///
/// \return returns a slider object (malloced)
///
///////////////////////////////////////////////////////////
slider_t *init_slider(slider_info_text_t text_info,
slider_info_slide_t slide_info, void (*func_ptr)(void *arg, float percent),
sfVector2f location);
// destroys a slider object and all of its parts(remember to pass DESTROY_FONT
// if you init iy in the slider_info_text_t)
void destroy_slider(slider_t *slider, int mask);
////////////////////////////////////////////////////////////
/// \brief draws the slider object and executes the function pointer
///
/// \param window     Render window object
/// \param slider     slider object (pointer)
/// \param arg        argument that will be passed to the function pointer
///                  (typecast must be done in the function)
///
///
///////////////////////////////////////////////////////////
void draw_slider(sfRenderWindow *window, slider_t *slider, void *arg);
/*###########################################################################
#######################END OF SLIDER_BUTTON SEGMENT##########################
-----------------------------------------------------------------------------*/
#endif /* !BUTTONS_H_ */
