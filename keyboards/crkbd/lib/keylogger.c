#include <stdio.h>
#include "crkbd.h"

char keylog_str[24] = {};
char keylogs_str[21] = {};
int keylogs_str_idx = 0;

const char code_to_name[60] = {
    ' ', ' ', ' ', ' ', 'a', 'b', 'c', 'd', 'e', 'f',
    'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p',
    'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
    '1', '2', '3', '4', '5', '6', '7', '8', '9', '0',
    'R', 'E', 'B', 'T', ' ', ' ', ' ', '[', ']', ' ',
    ' ', ';', '\'', ' ', ',', '.', '/', ' ', ' ', ' '
};

const char code_sp_name[] = {
  '!','@','#','$','%','^','&','*','(',')'
};

void set_keylog(uint16_t keycode, keyrecord_t *record) {
  char name = ' ';
  switch (keycode) {
    case 44:  case 17452:
    name -=10;
    break ;

    case 29224: case 225:
    name -= 2;
    break;

    case 79: case 243://right
    name -= 6;
    break;

    case 80: case 242: //left
    name -= 5;
    break;

    case 81: case 241: // down 
    name -= 7;
    break;

    case 82: case 240: //up
    name -= 8;
    break;

    case 559:
    name = '{';
    break;

    case 560:
    name = '}';
    break;

    default:
    if (keycode < 60) {
      name = code_to_name[keycode];
    }
    else if (keycode >= 542 && keycode <= 551) {
      name = code_sp_name[keycode - 542];
    }
  }

  // update keylog
  snprintf(keylog_str, sizeof(keylog_str), "%dx%d, k%2d : %c",
           record->event.key.row, record->event.key.col,
           keycode, name);

  // update keylogs
  if (keylogs_str_idx == sizeof(keylogs_str) - 1) {
    keylogs_str_idx = 0;
    for (int i = 0; i < sizeof(keylogs_str) - 1; i++) {
      keylogs_str[i] = ' ';
    }
  }

  keylogs_str[keylogs_str_idx] = name;
  keylogs_str_idx++;
}

const char *read_keylog(void) {
  return keylog_str;
}

const char *read_keylogs(void) {
  return keylogs_str;
}
