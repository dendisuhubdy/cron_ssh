#include "cron.ih"

string Cron::hmac(string const &passPhrase)
{
    HMacBuf hmacbuf(passPhrase, "sha256");

    ostream out(&hmacbuf);
    out << passPhrase << eoi;

    string hash = hmacbuf.hash();

    return hash;
}

