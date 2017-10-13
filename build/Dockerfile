# FROM でベースとなるイメージを指定
FROM ubuntu

# 作者の指定
MAINTAINER Futa HIRAKOBA

# アップデート
RUN apt-get update -y
RUN apt-get install git -y
# xzコマンドのインストール
RUN apt-get install xz-utils -y
# add-apt-repositoryのインストール
RUN apt-get install software-properties-common python-software-properties -y
RUN add-apt-repository ppa:team-gcc-arm-embedded/ppa -y
RUN apt-get update -y
RUN apt-get install gcc-arm-none-eabi u-boot-tools libboost1.58-all-dev -y
RUN apt-get install make -y
RUN apt-get install g++ -y

# リポジトリのクローン
RUN git clone https://github.com/korosuke613/ETrobo-Docker.git ~/etrobo

# hrp2の解凍
WORKDIR ~/etrobo
RUN tar Jxvf hrp2.tar.xz 
RUN rm -f hrp2.tar.xz

# cfgのmake
WORKDIR ~/etrobo/hrp2/cfg 
RUN make
WORKDIR ~/etrobo

# workspaceの削除
RUN rm -rf hrp2/sdk/workspace/

# workspaceのコピー
RUN git clone https://github.com/korosuke613/etrobocon2017.git hrp2/sdk/workspace
