FROM alpine

RUN apk add --update socat build-base bash openssl-dev

ARG PORT=43281
ARG BIN_NAME="login"

RUN mkdir -p /home/app/vault &&\
    adduser -h /home/app/ app --disabled-password &&\
    chown -R app:app /home/app/

COPY Makefile /home/app/Makefile
COPY $BIN_NAME.c /home/app/$BIN_NAME.c
COPY flag.txt /home/app/flag.txt
COPY phash.txt /home/app/phash.txt

# extra:
COPY vault.c /home/app/vault.c

USER app

WORKDIR /home/app/
RUN make

EXPOSE $PORT
ENV PORT=$PORT
ENV BIN_NAME=$BIN_NAME

CMD ["/bin/sh", "-c", "socat -d -d TCP-L:$PORT,fork EXEC:/home/app/$BIN_NAME,pty,stderr,rawer"]
