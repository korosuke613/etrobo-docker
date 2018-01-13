# FROM でベースとなるイメージを指定
FROM  korosuke613/all-in-ubuntu

# 作者の指定
MAINTAINER Futa HIRAKOBA

WORKDIR /home/root/

RUN mkdir tmp

WORKDIR tmp
RUN wget http://www.toppers.jp/download.cgi/ev3rt-beta7-release.zip


RUN unzip ev3rt-beta7-release.zip

# hrp2の解凍
RUN tar Jxvf ev3rt-beta7-release/hrp2.tar.xz
RUN mv hrp2 /home/root/

# cfgのmake
WORKDIR /home/root/hrp2/cfg
RUN make
RUN rm -rf /home/root/tmp
WORKDIR /home/root/hrp2/sdk/workspace

