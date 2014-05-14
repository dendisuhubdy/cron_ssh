//                     usage.cc

#include "main.ih"

void usage(std::string const &progname)
{
    cout << "\n" <<
    progname << " by " << Icmbuild::author << "\n" <<
    progname << " V" << Icmbuild::version << " " << Icmbuild::years << "\n"
    "\n"
    "Usage: " << progname << " [options] [crontab]\n"
    "Where:\n"
    "   [options] - optional arguments (short options between parentheses):\n"
    "      --agent agent    - absolute path to the agent program providing "
                                                                    "the\n"
    "                         ssh-keys\n"
    "                         (default `" << 
                                        Options::defaultAgent() << "')\n"
    "      --help (-h)      - provide this help\n"
    "      --list (-l)      - list the currently defined cron-commands\n"
    "                         (the `crontab' file argument must be omitted)\n"
    "      --no-daemon      - do not run as a daemon\n"
    "      --no-syslog      - do not write syslog messages\n"
    "      --pid-file (-p) path - `path' is the path name of the file "
                                                                "containing\n"
    "                            the daemon's PID\n"
    "                           (default `" <<
                                        Options::defaultPIDfile() << "')\n"
    "      --stdout (-s)      - write syslog-equivalent messages to the std "
                                                                "output\n"
    "                            (implied by --verbose; only for " 
                                                            "--no-daemon)\n"
    "      --syslog-facility fac  - fac: syslog facility to use\n"
    "                           (default `" << 
                                Options::defaultSyslogFacility() << "')\n"
    "      --syslog-priority pri  - pri: syslog priority to use\n"
    "                           (default `" << 
                                Options::defaultSyslogPriority() << "')\n"
    "      --syslog-tag id    - id: identifier prefixed to syslog messages\n"
    "                           (default `" << 
                                Options::defaultSyslogIdent() << "')\n"
    "      --terminate (-t) [pid-file] - terminate a running " << progname <<
                                                                    "\n"
    "                           program. Pid-file is the name of a "
                                                            "non-default\n"
    "                           pid file (the `crontab' file argument must "
                                                                    "be\n"
    "                           omitted)\n" 
    "      --verbose          - write additional information:\n"
    "                               with --no-daemon: to stdout;\n"
    "                               with daemons and --no-syslog not "
                                                                "specified:\n"
    "                                                 to the syslog daemon\n"
    "      --version (-v)   - show version information and terminate\n"
    "   crontab     - crontab-like file specifying crontab commands, and\n"
    "                 (optional) environment variable definitions and/or "
                                                                    "long\n"
    "                 options. If a pid-file exists, the commands which are\n"
    "                 defined in `crontab' replace the commands defined for\n"
    "                 the currently running " << progname << "\n" 
    "\n";
}


