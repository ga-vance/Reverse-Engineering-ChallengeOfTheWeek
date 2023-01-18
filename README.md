# Backwards into the Breach
### Developed by Greg (Expergefied)

## Challenge Description
We recovered two binary files from an old server I found on ebay. There might be something useful hidden in them. The company folded after a pretty public security incident, so if we're lucky, the security behind the vault won't be too tough.

## Challenge Hints
1.  What is the input being checked against?
2.  What information does the program give us when it runs?

## Challenge Solution
<details>

1.  The vault binary needs to be reversed to understand what is happening. Upon close inspection of the binary file you will notice that a user provided input is being checked against a string that the program compiles (19#Bk>k{$). By getting this value out of the reversed binary, you can provide it to the program, which causes the program to print out an MD5 hash string.
2.  Take the obtained MD5 hash to an online decryptor to get the plain english password "flashthunder"
3.  The second binary "login" asks for a username and password. The password is what we obtained from the vault binary and decrypted online. To obtain the username, there is a string format vulnerability.
4.  Exploit the string format vulnerability in the username input field which is provided as a command line argument. This will give the username  "mallory"
5. Give the command line arguments with the correct username and password and the flag is printed out to the terminal.

</details>

## Flag
ucsec{r3ver5e_7h3_v4ulTs_s3cr3t5}