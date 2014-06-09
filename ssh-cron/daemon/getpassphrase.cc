#include "daemon.ih"

void Daemon::getPassPhrase()
{
    Tty tty;
    tty.echo(Tty::OFF);

    ifstream in;
    Exception::open(in, "/dev/tty");

    while (true)
    {
        cout << "Enter pass phrase: " << flush;
        string passphrase1;
        getline(in, passphrase1);
        
        cout << "\nEnter same pass phrase again: " << flush;
        string passphrase2;
        getline(in, passphrase2);
        cout << endl;

        if (passphrase1 == passphrase2)
        {
            d_cron.setPassPhrase(passphrase1);
            break;
        }

        cout << "Different pass phrases. Try again\n\n";
    }

}




