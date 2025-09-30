import argparse
import subprocess
import os


def genkeys(args):
    print("generating keys")
    subprocess.call("openssl genpkey -algorithm Ed25519 -out private.pem", shell=True)
    subprocess.call("openssl pkey -in private.pem -pubout -out public.pem", shell=True)

def sign(args):
    print("signing", args.sign)
    subprocess.call("openssl sha256 " + args.sign[0] + " | awk '{print $2}' | tr -d '\n' | xxd -r -p > image_sha_in_ascii", shell=True)
    subprocess.call("openssl pkeyutl -sign -inkey private.pem -out test_sha_ascii_sig.bin -rawin -in image_sha_in_ascii", shell=True)
    subprocess.call("openssl pkeyutl -verify -pubin -inkey public.pem -rawin -in image_sha_in_ascii -sigfile test_sha_ascii_sig.bin", shell=True)
    print("Signature C declaration:")
    subprocess.call("xxd -i test_sha_ascii_sig.bin", shell=True)
    print("Public key C declarataion:")
    subprocess.call("echo -n \"uint8_t pk[] = {\" ; openssl pkey -pubin -in public.pem -text -noout | tr -d ' \n' | cut -c 22- | sed 's/:/, 0x/g' | cut -c 3- | tr -d '\n' ; echo \"};\"", shell=True)
    
def clean(args):
    subprocess.call("rm -f *.pem ; rm -f test_sha_in_ascii ; rm -f test_sha_ascii_sig.bin", shell=True)
    

if __name__ == "__main__":
    
    parser = argparse.ArgumentParser(description="Create keys and sign app image. If you aren't sure,")
    parser.add_argument(
        "-g",
        "--genkeys",
        action="store_true",  # value is true if argument is provided, false otherwise
        help="generate private and public key pair",
    )

    parser.add_argument(
        "-s",
        "--sign",
        nargs=1, #this flag is optional but if it is provided, expect 1 argument
        metavar='APP_IMAGE',
        help="sign app by prepending hash and signature to binary",
    )
    
    parser.add_argument(
        "-c",
        "--clean",
        action="store_true",
        help="remove keys and signatures"
    )

    args = parser.parse_args()

    if args.genkeys:
        genkeys(args)
    if args.sign:
        sign(args)
    if args.clean:
        clean(args)
