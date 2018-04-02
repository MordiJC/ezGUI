#ifndef EZGUI_WINDOW_H_
#define EZGUI_WINDOW_H_

#include <stdint.h>

typedef struct Window_struct {
    uint16_t x;
    uint16_t y;
    uint16_t width;
    uint16_t height;
} Window;

Window * Window_create(unsigned int x, unsigned int y, unsigned int width, unsigned int height);

int Window_resize(Window * restrict, unsigned int width, unsigned int height);

int Window_move(Window * restrict, unsigned int x, unsigned int y);



#endif /* EZGUI_WINDOW_H_ */