all: vault login

vault: vault.c
	gcc -o vault vault.c

login: login.c
	gcc -o login login.c -lssl -lcrypto -Wno-format-security

clean:
	rm login vault