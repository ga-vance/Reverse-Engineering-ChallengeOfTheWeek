# Backwards into the Breach
### Developed by Greg (Expergefied)

## Challenge Description
We recovered a binary file from an old server we found on ebay. The company folded after a pretty public security incident, so if we're lucky, the security behind this vault binary won't be too tough. If you can recover anything useful there is another of their old servers running at <IP> <port> that could give us a flag with some further digging.

## Challenge Hints
1.  What is the input being checked against?
2.  What information does the remote program give us when it runs?

## Challenge Solution
<details>

1.  The vault binary needs to be reversed to understand what is happening. Upon close inspection of the binary file you will notice that a user provided input is being checked against a string that the program compiles (19#Bk>k{$). By getting this value out of the reversed binary, you can provide it to the program, which causes the program to print out an MD5 hash string.
2.  Take the obtained MD5 hash to an online decryptor to get the plain english password "flashthunder"
3.  The second binary "login" asks for a username and password. The password is what we obtained from the vault binary and decrypted online. To obtain the username, there is a string format vulnerability.
4.  This can be exploited by running 'python3 -c "import sys; sys.stdout.buffer.write(b'%p' * 64)" | nc <IP> <port>, and converted using cyber-chef
4.  Exploit the string format vulnerability in the username input field. This will give the username  "mallory"
5.  Give the program the correct username and password and the flag is printed out to the terminal.

</details>

## Flag
ucsec{r3ver5e_7h3_v4ulTs_s3cr3t5}


## Note
There are two branches in this repository. The default branch "release" is the challenge as was hosted and released. The "static" branch contains the Challenge
as a static non-hosted version. They function somewhat the same, however, the static version was too simple for people with more experience in reverse engineering.
The decision was made to change the challenge to obe hosted, to increase the difficulty. This was done with help from e-seng.
