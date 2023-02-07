FROM alpine

RUN apk add --update socat build-base bash

RUN mkdir -p /home/app/vault &&\
    adduser -h /home/app/ app --disabled-password &&\
    chown -R app:app /home/app/

COPY Makefile /home/app/Makefile
COPY login.c /home/app/login.c
COPY vault.c /home/app/vault.c 

USER app

WORKDIR /home/app/
RUN make

EXPOSE 1984

CMD ["/bin/sh", "-c", "socat -d -d TCP-L:1984,fork EXEC:/home/app/login,pty,stderr"]