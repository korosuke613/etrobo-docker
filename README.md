# ETrobo-Docker
TOPPERS/EV3RTのビルド環境をラッピングしたUbuntuベースのDocker Image

OS : Ubuntu 16.04.3
Imageのサイズ : 約1.8GB

## 使用例
`app.cfg`の存在するディレクトリ(`/some/src/`とする)に移動してから、次のコマンドを実行する。

```
$ docker run -v /some/src/:/home/hrp2/sdk/workspace/src korosuke613/etrobo-docker
```

ビルドがうまく行った場合、`/some/src`に`app`というEV3RT向けの実行ファイルが生成されている。
ちなみに、相対パスを指定したい場合、`$PWD`を利用する。

```
$ cd /some/src/
$ docker run -v $PWD:/home/hrp2/sdk/workspace/src korosuke613/etrobo-docker 
```

### 手っ取り早く動作確認をしたい場合
以下のコマンドを実行する

```
$ git clone --recursive --depth=1 https://github.com/korosuke613/ETrobo-Docker.git
$ cd ETrobo-Docker/sample/src
$ docker run -v $PWD:/home/hrp2/sdk/workspace/src korosuke613/etrobo-docker
```
