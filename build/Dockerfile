# FROM でベースとなるイメージを指定
FROM ubuntu

# 作者の指定
MAINTAINER Futa HIRAKOBA

# アップデート
RUN apt-get update && apt-get upgrade -y && \
    apt-get clean && rm -rf /var/cache/apt/archives/* /var/lib/apt/lists/*

RUN apt-get update && \
    apt-get install -y \
    git \
    xz-utils \
    software-properties-common \ 
    gcc-arm-none-eabi \
    u-boot-tools \
    make \
    g++ \ 
    wget \
    unzip \
    libboost-all-dev \
    cmake \
    && apt-get clean && rm -rf /var/cache/apt/archives/* /var/lib/apt/lists/*

# 作業用フォルダの作成
WORKDIR /home/
RUN mkdir tmp
WORKDIR /home/tmp

# ToppersからMakefileをダウンロード、解凍
RUN wget http://www.toppers.jp/download.cgi/ev3rt-beta7-1-release.zip \
    && unzip ev3rt-beta7-1-release.zip \
    && tar Jxvf ev3rt-beta7-1-release/hrp2.tar.xz \
    && mv hrp2 /home/ \
    && rm -rf ./*

# cfgをmake
WORKDIR /home/hrp2/cfg
RUN make

# googletestの有効化
WORKDIR /home/hrp2/sdk
RUN git clone https://github.com/google/googletest
WORKDIR /home/hrp2/sdk/googletest
RUN mkdir build
WORKDIR /home/hrp2/sdk/googletest/build
RUN cmake .. && make
#ENV GTEST_ROOT /home/hrp2/sdk/googletest
#ENV GTEST_INCLUDEDIR $GTEST_ROOT/googletest/include 
#ENV GMOCK_INCLUDEDIR $GTESTROOT/googlemock/include 
#ENV GMOCK_LIBDIR $GTEST_ROOT/build/googlemock 
#ENV GTEST_LIBDIR $GTEST_ROOT/build/googlemock/gtest
WORKDIR /home/hrp2/sdk/googletest
RUN mkdir /usr/local/lib/pkgconfig
RUN cp -r googlemock/include/gmock /usr/local/include/gmock \
    && cp -r googletest/include/gtest /usr/local/include/gtest \
    && cp build/googlemock/*.a /usr/local/lib/ \
    && cp build/googlemock/gtest/*.a /usr/lib/ \
    && cp build/*.pc /usr/local/lib/pkgconfig/

# make_src.shを使用可能に
WORKDIR /home/hrp2/sdk/workspace
# makeのラッパースクリプトを追加
ADD make_src.sh /home/hrp2/sdk/workspace 
RUN chmod 755 make_src.sh && mv make_src.sh /usr/local/bin/make_src

ADD install.sh /home/hrp2/sdk/workspace 
RUN chmod 755 install.sh && mv install.sh /usr/local/bin/gtest_start

CMD make_src
