# FROM でベースとなるイメージを指定
FROM  docker.io/korosuke613/all-in-ubuntu

# 作者の指定
MAINTAINER Futa HIRAKOBA

# リポジトリのクローン
RUN git clone https://github.com/korosuke613/ETrobo-Docker.git ~/etrobo

# hrp2の解凍
WORKDIR ~/etrobo
RUN cd ~/etrobo && tar Jxvf hrp2.tar.xz && rm -f hrp2.tar.xz

# cfgのmake
WORKDIR ~/etrobo/hrp2/cfg 
RUN cd ~/etrobo/hrp2/cfg && make
WORKDIR ~/etrobo/hrp2/sdk

# workspaceの削除
RUN rm -rf hrp2/sdk/workspace/

# workspaceのコピー
RUN git clone https://github.com/korosuke613/etrobocon2017.git workspace

