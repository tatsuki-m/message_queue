# how to build docker container
```console
$ docker build -f dockerfile .
```

# how to run docker container
```console
$ docker run -it --ipc=host -v /tmp:/tmp [IMAGE ID] /bin/bash
```

