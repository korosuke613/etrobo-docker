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

