# FROM でベースとなるイメージを指定
FROM ubuntu

# 作者の指定
LABEL maintainer "Futa HIRAKOBA"

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
    lcov \
    python3-pip \
    language-pack-ja-base language-pack-ja \
    clang-format \
    && apt-get clean && rm -rf /var/cache/apt/archives/* /var/lib/apt/lists/*

# localeの変更
ENV LANG=ja_JP.UTF-8

# 作業用フォルダの作成
WORKDIR /home/
RUN mkdir tmp
WORKDIR /home/tmp

# ToppersからMakefileをダウンロード、解凍
RUN wget http://www.toppers.jp/download.cgi/ev3rt-beta7-2-release.zip \
    && unzip ev3rt-beta7-2-release.zip \
    && tar Jxvf ev3rt-beta7-2-release/hrp2.tar.xz \
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
ADD makeLeft.sh /home/hrp2/sdk/workspace 
RUN chmod 755 makeLeft.sh && mv makeLeft.sh /usr/local/bin/makeLeft
ADD makeRight.sh /home/hrp2/sdk/workspace 
RUN chmod 755 makeRight.sh && mv makeRight.sh /usr/local/bin/makeRight
ADD makeSpecial.sh /home/hrp2/sdk/workspace 
RUN chmod 755 makeSpecial.sh && mv makeSpecial.sh /usr/local/bin/makeSpecial

# テスト実行スクリプト
ADD install.sh /home/hrp2/sdk/workspace 
RUN chmod 755 install.sh && mv install.sh /usr/local/bin/gtest_start

# カバレッジ計測用ファイル
RUN pip3 install gcovr
ADD CodeCoverage.cmake /home/hrp2/sdk/workspace 
ADD CMakeLists.txt /home/hrp2/sdk/workspace 

CMD make_src
