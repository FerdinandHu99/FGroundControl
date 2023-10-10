#include <QImage>
#include <QDebug>
#include <QThread>

#include "VideoManage.h"

extern "C"
{
#include "libavcodec/avcodec.h"
#include "libavformat/avformat.h"
#include "libswscale/swscale.h"
#include "libavdevice/avdevice.h"
//#include "libavutil/imgutils.h"
}

VideoManage::VideoManage(QObject *parent)
    : QObject(parent)
{
}

VideoManage::~VideoManage()
{

}

void VideoManage::startVideo()
{
    int ret;
    const QString rtspUrl("rtsp://admin:admin@192.168.31.241:8554/live");
    AVFormatContext* formatCtx = avformat_alloc_context();
    ret = avformat_open_input(&formatCtx,rtspUrl.toStdString().c_str(),NULL,NULL);
    if(ret != 0){
        qDebug() << "Url is invaild !";
        return ;
    }

    int videoIndex = av_find_best_stream(formatCtx, AVMEDIA_TYPE_VIDEO, -1,-1, NULL, 0);
    if (videoIndex < 0) {
        qDebug() << "Video stream is invaild !";
        return ;
    }

    const AVCodec* codec = avcodec_find_decoder(formatCtx->streams[videoIndex]->codecpar->codec_id);
    AVCodecContext* codecCtx = avcodec_alloc_context3(codec);
    avcodec_parameters_to_context(codecCtx,formatCtx->streams[videoIndex]->codecpar);
    ret = avcodec_open2(codecCtx, codec, NULL);
    if(ret != 0){
        qDebug() << "Failed open codec !";
    }

    AVPacket* packet = (AVPacket *)av_malloc(sizeof(AVPacket));
    AVFrame* frame = av_frame_alloc();
    while(av_read_frame(formatCtx,packet) >=0){
        if(packet->stream_index == videoIndex){
            ret = avcodec_send_packet(codecCtx, packet);
            if(ret != 0){
                qDebug() << "Failed to decode video frame !";
            }
            ret = avcodec_receive_frame(codecCtx, frame);
            if (ret == 0) {
                // TODO: process image
                QThread::msleep(1);
            }
        }
        av_packet_unref(packet);
    }

    avformat_close_input(&formatCtx);
    avcodec_close(codecCtx);
    avcodec_free_context(&codecCtx);
}

