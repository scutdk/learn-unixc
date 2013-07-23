#include <stdio.h>
#include <libavformat/avformat.h>
#include <libavcodec/avcodec.h>

int main(int ac, char *av[]) {
    AVFormatContext *pFormatCtx = NULL;

    av_register_all();

    if (avformat_open_input(&pFormatCtx, av[1], NULL, NULL)) 
        return -1;

    if (av_find_stream_info(pFormatCtx) < 0 ) 
        return -1;

    av_dump_format(pFormatCtx, 0, av[1], 0);

    return 0;
}


