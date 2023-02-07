FROM alpine

RUN apk add --update socat build-base bash

RUN mkdir -p /home/app/vault &&\
    adduser -h /home/app/ app --disabled-password &&\
    chown -R app:app /home/app/

COPY Makefile /home/app/Makefile
COPY license.c /home/app/license.c
COPY ./flag.txt /home/app/vault/flag.txt

USER app

WORKDIR /home/app/
RUN make

EXPOSE 24785

CMD ["/bin/sh", "-c", "socat -d -d TCP-L:24785,fork EXEC:/home/app/license,pty,stderr"]