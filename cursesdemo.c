#include <stdio.h>
#include <curses.h>
#include <unistd.h>

int main(void) {
    int i;
    initscr();
    for (i = 0; i < 150; i++) {
        clear();
        move(i, 30);
        standout();
        addstr("Hello world\n");
        standend();
        refresh();
        usleep(100000);
    }
    endwin();
}


